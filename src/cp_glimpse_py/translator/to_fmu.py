"""
cp_glimpse_py.translator.to_fmu
=================================
Generic source-to-FMU materialization utilities.

Purpose
-------
This module provides a translator-level interface for converting supported
model sources into Functional Mock-up Units (FMUs), or reusing an existing
FMU when the input is already an FMU artifact.

Current support
---------------
At present, the implemented backend is:

- Modelica source (.mo) -> FMU generation via OpenModelica / OMPython → downstream simulation pipeline

The public API is intentionally generic so that future source types can be
added without changing experiment orchestration code. For example, future
backends may support:

- SSP / system structure descriptions
- intermediate JSON or XML IRs
- other modeling languages that can be lowered to FMU

Design goals
------------
This module provides:

- a stable translator-facing API: ``build_fmu(...)``
- source-type dispatch based on the input path suffix
- deterministic artifact hashing
- per-build isolated working directories
- stable FMU naming (safe filename derived from class name)
- simple caching for repeated builds (skip rebuild if FMU already exists)
- deterministic artifact hashing (via model_artifact_key)
- preservation of generator intermediate files
- collection of build logs into a reproducible location

Typical usage
-------------
artifact = build_fmu(
    source_path="models/rover/Rover.mo",
    class_name="RoverExample.Components.Webserver",
    fmu_type="me",
)

artifact.fmu_path -> ready-to-use FMU file
artifact.work_dir -> artifact directory containing logs/ and intermediates
artifact.key      -> deterministic cache key
artifact.source   -> translator backend identifier

Public API
----------
- build_fmu

Private helpers
----------------
- TBF
"""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
import json
import os
import re
import shutil
import traceback
import zipfile
from datetime import datetime, timezone
from xml.etree import ElementTree as ET

from OMPython import ModelicaSystem

from ..common.paths import get_paths
from ..common.hashing import model_artifact_key
from ..common.logging import get_logger

log = get_logger(__name__)


@dataclass(frozen=True)
class FMUArtifact:
    """
    Represents a reusable FMU artifact.

    Attributes
    ----------
    fmu_path : Path
        Absolute path to the FMU file to be executed downstream.

    work_dir : Path
        Artifact directory associated with this FMU. For built artifacts,
        this is the deterministic translator output directory containing logs
        and preserved intermediates. For pass-through FMUs, this may be the
        FMU parent directory.

    key : str
        Deterministic identifier for the artifact. For generated artifacts,
        this is derived from the source contents and selected build options.
        For pass-through FMUs, this is a stable reuse key.

    source : str
        Translator backend identifier describing how this FMU artifact was
        obtained. Examples:
        - "translator.to_fmu.reuse_existing_fmu"
        - "translator.to_fmu.build_fmu_from_modelica"
    """

    fmu_path: Path
    work_dir: Path
    key: str
    source: str


class _Pushd:
    """
    Simple pushd/popd context manager.

    This helper temporarily changes the process working directory and restores
    the previous directory on exit, even if an exception is raised.
    """

    def __init__(self, new_dir: Path):
        self.new_dir = Path(new_dir)
        self.old_dir: Path | None = None

    def __enter__(self):
        self.old_dir = Path.cwd()
        os.chdir(self.new_dir)
        return self

    def __exit__(self, exc_type, exc, tb):
        if self.old_dir is not None:
            os.chdir(self.old_dir)
        return False


def _write_text(path: Path, text: str) -> None:
    """
    Write UTF-8 text to a file, creating parent directories as needed.
    """
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")


def _safe_copy_if_exists(src: Path, dst: Path) -> None:
    """
    Copy a file if it exists.

    This helper is intentionally silent when the source is absent.
    """
    if src.exists() and src.is_file():
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src, dst)


def _infer_class_name_from_fmu(fmu_path: Path) -> str | None:
    """
    Infer the FMU model name from ``modelDescription.xml``.

    Parameters
    ----------
    fmu_path : Path
        Path to an FMU archive.

    Returns
    -------
    str | None
        The FMU model name if available, otherwise None.
    """
    try:
        with zipfile.ZipFile(fmu_path) as zf:
            with zf.open("modelDescription.xml") as fh:
                root = ET.parse(fh).getroot()
        model_name = root.attrib.get("modelName")
        if model_name:
            return str(model_name)
    except Exception:
        return None
    return None


def _infer_class_name_from_modelica(mo_path: Path) -> str | None:
    """
    Infer a Modelica class name from a ``.mo`` file.

    This is intentionally conservative:
    - if exactly one top-level ``model <Name>`` match is found, return it
    - otherwise return None

    Parameters
    ----------
    mo_path : Path
        Path to a Modelica source file.

    Returns
    -------
    str | None
        Inferred class name if unambiguous, otherwise None.
    """
    text = mo_path.read_text(encoding="utf-8", errors="ignore")
    matches = re.findall(r"(?m)^\s*model\s+([A-Za-z_][A-Za-z0-9_]*)\b", text)
    unique = list(dict.fromkeys(matches))
    if len(unique) == 1:
        return unique[0]
    return None


def _resolve_source_class_name(
    *,
    source_path: str | Path,
    class_name: str | None = None,
) -> str:
    """
    Resolve a model/class name for a supported source.

    Parameters
    ----------
    source_path : str | Path
        Input source path. Currently supported:
        - .fmu
        - .mo

    class_name : str | None, optional
        Explicit class/model name. If provided, it takes precedence over any
        automatic inference.

    Returns
    -------
    str
        Resolved class/model name.

    Raises
    ------
    KeyError
        If no class name was provided and automatic inference fails.
    """
    if class_name:
        return str(class_name)

    path = Path(source_path)
    suffix = path.suffix.lower()

    if suffix == ".fmu":
        inferred = _infer_class_name_from_fmu(path)
        if inferred:
            return inferred

    if suffix == ".mo":
        inferred = _infer_class_name_from_modelica(path)
        if inferred:
            return inferred

    raise KeyError(
        f"Unable to resolve model.class_name automatically from source: {source_path}"
    )


def _collect_logs(*, work_dir: Path, logs_dir: Path) -> None:
    """
    Best-effort log collection from a directory tree.

    The function scans common build locations and copies files that are likely
    to contain OpenModelica or native compilation diagnostics into ``logs_dir``.

    This helper is intentionally forgiving and is suitable for both success and
    failure cleanup paths.
    """
    logs_dir.mkdir(parents=True, exist_ok=True)

    patterns = [
        "*.log",
        "*.txt",
        "*.json",
        "*.xml",
        "stdout",
        "stderr",
        "buildlog*",
        "omc*.log",
        "*FMU*.log",
        "*compile*.log",
        "*makefile*",
    ]

    for pat in patterns:
        for p in work_dir.glob(pat):
            if p.is_file():
                _safe_copy_if_exists(p, logs_dir / p.name)

    for sub in ("build", "sources", "binaries", "tmp", "OMTmp", "fmu", "FMU"):
        d = work_dir / sub
        if d.exists() and d.is_dir():
            for pat in ("*.log", "*.txt", "*.xml", "*.json", "*makefile*"):
                for p in d.glob(pat):
                    if p.is_file():
                        _safe_copy_if_exists(p, logs_dir / f"{sub}__{p.name}")


def _snapshot_dir(src_dir: Path, dst_dir: Path) -> None:
    """
    Snapshot an entire directory tree into ``dst_dir``.

    This is used to preserve the actual generator output directory, which may
    reside outside the requested working directory, for example under ``/tmp``.

    Parameters
    ----------
    src_dir : Path
        Source directory to snapshot.

    dst_dir : Path
        Destination directory.

    Raises
    ------
    FileNotFoundError
        If ``src_dir`` does not exist or is not a directory.
    """
    src_dir = src_dir.resolve()
    dst_dir = dst_dir.resolve()

    if not src_dir.exists() or not src_dir.is_dir():
        raise FileNotFoundError(f"snapshot source dir not found: {src_dir}")

    if src_dir == dst_dir:
        return

    shutil.rmtree(dst_dir, ignore_errors=True)
    shutil.copytree(src_dir, dst_dir, dirs_exist_ok=True)


def _normalize_source_path(source_path: str | Path) -> Path:
    """
    Resolve a source path relative to the project root when needed.

    Parameters
    ----------
    source_path : str | Path
        Input source path, absolute or project-relative.

    Returns
    -------
    Path
        Resolved absolute path.

    Raises
    ------
    FileNotFoundError
        If the source path does not exist.
    """
    paths = get_paths()

    path = Path(source_path)
    if not path.is_absolute():
        path = (paths.root / path).resolve()

    if not path.exists():
        raise FileNotFoundError(path)

    return path


def _reuse_existing_fmu(
    *,
    fmu_path: str | Path,
    class_name: str | None = None,
    fmu_type: str | None = None,
) -> FMUArtifact:
    """
    Reuse an already existing FMU as an artifact.

    This path is useful when scenario materialization receives an FMU input and
    the translator should simply standardize it into the common artifact shape.

    Parameters
    ----------
    fmu_path : str | Path
        Path to an existing FMU file.

    class_name : str | None, optional
        Optional explicit model name. When omitted, the FMU model name is
        inferred from ``modelDescription.xml`` if possible.

    fmu_type : str | None, optional
        Reserved for interface symmetry with generated artifacts. Currently it
        is not used for pass-through reuse.

    Returns
    -------
    FMUArtifact
        Standardized artifact describing the reusable FMU.

    Raises
    ------
    ValueError
        If the provided path does not point to an ``.fmu`` file.
    """
    path = _normalize_source_path(fmu_path)
    if path.suffix.lower() != ".fmu":
        raise ValueError(f"Expected an .fmu path, got: {path}")

    resolved_name = _resolve_source_class_name(source_path=path, class_name=class_name)
    key = model_artifact_key(mo_path=path, class_name=resolved_name, fmu_type=fmu_type or "reuse")

    return FMUArtifact(
        fmu_path=path,
        work_dir=path.parent,
        key=key,
        source="translator.to_fmu.reuse_existing_fmu",
    )


def _build_fmu_from_modelica(
    *,
    source_path: str | Path,
    class_name: str | None,
    fmu_type: str,
) -> FMUArtifact:
    """
    Build or retrieve from cache an FMU from a Modelica source file.

    Parameters
    ----------
    source_path : str | Path
        Path to a Modelica ``.mo`` file.

    class_name : str | None
        Fully qualified Modelica class name, or a simple class name when the
        source file is unambiguous. If omitted, the translator attempts a
        conservative inference from the source file.

    fmu_type : str
        Requested FMU type, typically ``"me"`` or ``"cs"``.

    Returns
    -------
    FMUArtifact
        Deterministically located FMU artifact.

    Raises
    ------
    ValueError
        If the source file is not a ``.mo`` file.
    FileNotFoundError
        If the source path does not exist.
    RuntimeError
        If OpenModelica reports success but no FMU file is found.
    Exception
        Propagates unexpected translator or OpenModelica failures after
        recording best-effort logs.
    """
    paths = get_paths()

    mo_path = _normalize_source_path(source_path)
    if mo_path.suffix.lower() != ".mo":
        raise ValueError(f"Expected a .mo source path, got: {mo_path}")

    class_name = _resolve_source_class_name(source_path=mo_path, class_name=class_name)

    key = model_artifact_key(mo_path=mo_path, class_name=class_name, fmu_type=fmu_type)

    out_dir = paths.build_translator_runs / "fmu" / key
    out_dir.mkdir(parents=True, exist_ok=True)

    fmu_name = class_name.replace(".", "_")
    expected = out_dir / f"{fmu_name}.fmu"

    logs_dir = out_dir / "logs"
    omc_work = out_dir / "omc_work"
    logs_dir.mkdir(parents=True, exist_ok=True)
    omc_work.mkdir(parents=True, exist_ok=True)

    build_info_path = logs_dir / "build_info.json"
    build_log_path = logs_dir / "build.log"

    if expected.exists():
        log.info("FMU cache hit: %s", expected)
        return FMUArtifact(
            fmu_path=expected,
            work_dir=out_dir,
            key=key,
            source="translator.to_fmu.build_fmu_from_modelica",
        )

    build_info: dict[str, object] = {
        "timestamp_utc": datetime.now(timezone.utc).isoformat(),
        "key": key,
        "source_path": str(mo_path),
        "source_type": "modelica",
        "class_name": class_name,
        "fmu_type": fmu_type,
        "expected_fmu": str(expected),
        "work_dir": str(out_dir),
        "logs_dir": str(logs_dir),
        "omc_work_dir": str(omc_work),
        "translator_backend": "translator.to_fmu.build_fmu_from_modelica",
    }
    _write_text(build_info_path, json.dumps(build_info, indent=2))

    log.info(
        "Building FMU from Modelica: class=%s, type=%s, source=%s",
        class_name,
        fmu_type,
        mo_path,
    )

    try:
        _write_text(
            build_log_path,
            (
                f"[{datetime.now(timezone.utc).isoformat()}] START build_fmu_from_modelica\n"
                f"source_path={mo_path}\n"
                f"class_name={class_name}\n"
                f"fmu_type={fmu_type}\n"
                f"key={key}\n"
                f"out_dir={out_dir}\n"
                f"omc_work={omc_work}\n"
            ),
        )

        with _Pushd(omc_work):
            model = ModelicaSystem(str(mo_path), class_name)

            try:
                omc_ver = None
                for attr in ("getOMCVersion", "get_omc_version", "getOMVersion"):
                    fn = getattr(model, attr, None)
                    if callable(fn):
                        omc_ver = fn()
                        break
                if omc_ver:
                    build_info["openmodelica_version"] = str(omc_ver)
                    _write_text(build_info_path, json.dumps(build_info, indent=2))
            except Exception:
                pass

            fmu_gen = model.convertMo2Fmu(fileNamePrefix=fmu_name, fmuType=fmu_type)

        fmu_gen = Path(fmu_gen).resolve()
        build_info["fmu_generated_path"] = str(fmu_gen)
        _write_text(build_info_path, json.dumps(build_info, indent=2))

        if not fmu_gen.exists():
            try:
                _collect_logs(work_dir=omc_work, logs_dir=logs_dir)
            except Exception:
                pass
            raise RuntimeError(f"FMU generation failed, got path: {fmu_gen}")

        shutil.copy2(fmu_gen, expected)

        gen_dir = fmu_gen.parent
        build_info["fmu_generated_dir"] = str(gen_dir)
        _write_text(build_info_path, json.dumps(build_info, indent=2))

        _snapshot_dir(gen_dir, omc_work)

        try:
            _collect_logs(work_dir=omc_work, logs_dir=logs_dir)
        except Exception:
            pass

        with build_log_path.open("a", encoding="utf-8") as f:
            f.write(
                f"\n[{datetime.now(timezone.utc).isoformat()}] SUCCESS\n"
                f"generated_fmu={fmu_gen}\n"
                f"copied_to={expected}\n"
                f"snapshot_from={gen_dir}\n"
                f"snapshot_to={omc_work}\n"
            )

        log.info("FMU created: %s", expected)
        return FMUArtifact(
            fmu_path=expected,
            work_dir=out_dir,
            key=key,
            source="translator.to_fmu.build_fmu_from_modelica",
        )

    except Exception as e:
        tb = traceback.format_exc()

        try:
            with build_log_path.open("a", encoding="utf-8") as f:
                f.write(
                    f"\n[{datetime.now(timezone.utc).isoformat()}] FAILURE\n"
                    f"error={repr(e)}\n\ntraceback:\n{tb}\n"
                )
        except Exception:
            pass

        try:
            _collect_logs(work_dir=omc_work, logs_dir=logs_dir)
        except Exception:
            pass

        raise


def build_fmu(
    *,
    source_path: str | Path,
    class_name: str | None = None,
    fmu_type: str = "me",
) -> FMUArtifact:
    """
    Materialize a supported source as an FMU artifact.

    This is the main translator-facing entrypoint. It dispatches to a
    source-specific backend based on the input path suffix.

    Current dispatch rules
    ----------------------
    - .fmu -> reuse the existing FMU
    - .mo  -> build an FMU from Modelica via OpenModelica

    Parameters
    ----------
    source_path : str | Path
        Path to a supported source artifact.

    class_name : str | None, optional
        Explicit class/model name. When omitted, the translator tries to infer
        it where feasible.

    fmu_type : str, optional
        Requested FMU flavor. Typical values are ``"me"`` and ``"cs"``.
        For pass-through ``.fmu`` inputs this value is currently accepted for
        API symmetry and future extensibility.

    Returns
    -------
    FMUArtifact
        Standardized FMU artifact.

    Raises
    ------
    ValueError
        If the source suffix is unsupported.
    """
    path = _normalize_source_path(source_path)
    suffix = path.suffix.lower()

    if suffix == ".fmu":
        return _reuse_existing_fmu(
            fmu_path=path,
            class_name=class_name,
            fmu_type=fmu_type,
        )

    elif suffix == ".mo":
        return _build_fmu_from_modelica(
            source_path=path,
            class_name=class_name,
            fmu_type=fmu_type,
        )

    raise ValueError(
        f"Unsupported source type for FMU materialization: {path}. "
        "Currently supported suffixes are '.fmu' and '.mo'."
    )






# def resolve_model_class_name(*, mo_path: str | Path, class_name: str | None = None) -> str:
#     if class_name:
#         return str(class_name)

#     path = Path(mo_path)
#     if path.suffix.lower() == ".fmu":
#         inferred = _infer_class_name_from_fmu(path)
#         if inferred:
#             return inferred

#     if path.suffix.lower() == ".mo":
#         inferred = _infer_class_name_from_mo(path)
#         if inferred:
#             return inferred

#     raise KeyError("Unable to resolve model.class_name automatically.")





# def _collect_logs(*, work_dir: Path, logs_dir: Path) -> None:
#     """
#     Best-effort log collection from a directory.

#     We copy common OpenModelica/FM U compile logs if present.
#     This function should never raise (callers may wrap in try/except anyway).
#     """
#     logs_dir.mkdir(parents=True, exist_ok=True)

#     patterns = [
#         "*.log",
#         "*.txt",
#         "*.json",
#         "*.xml",
#         "stdout",
#         "stderr",
#         "buildlog*",
#         "omc*.log",
#         "*FMU*.log",
#         "*compile*.log",
#         "*makefile*",
#     ]

#     for pat in patterns:
#         for p in work_dir.glob(pat):
#             if p.is_file():
#                 _safe_copy_if_exists(p, logs_dir / p.name)

#     # Shallow nested scan for common subdirs
#     for sub in ("build", "sources", "binaries", "tmp", "OMTmp", "fmu", "FMU"):
#         d = work_dir / sub
#         if d.exists() and d.is_dir():
#             for pat in ("*.log", "*.txt", "*.xml", "*.json", "*makefile*"):
#                 for p in d.glob(pat):
#                     if p.is_file():
#                         _safe_copy_if_exists(p, logs_dir / f"{sub}__{p.name}")


# def _snapshot_dir(src_dir: Path, dst_dir: Path) -> None:
#     """
#     Snapshot (copy) an entire directory tree into dst_dir.

#     We intentionally snapshot the OpenModelica generated directory (often under /tmp)
#     to keep intermediate C code, object files, and build logs for debugging/repro.
#     """
#     src_dir = src_dir.resolve()
#     dst_dir = dst_dir.resolve()

#     if not src_dir.exists() or not src_dir.is_dir():
#         raise FileNotFoundError(f"snapshot source dir not found: {src_dir}")

#     # Avoid copying a directory onto itself
#     if src_dir == dst_dir:
#         return

#     # Replace any existing snapshot to avoid stale files
#     shutil.rmtree(dst_dir, ignore_errors=True)
#     shutil.copytree(src_dir, dst_dir, dirs_exist_ok=True)


# def build_fmu(*, mo_path: str | Path, class_name: str | None, fmu_type: str) -> FMUArtifact:
#     """
#     Build (or retrieve from cache) an FMU from a Modelica model.

#     OpenModelica/OMPython sometimes generates intermediates under /tmp regardless of CWD.
#     To preserve intermediates deterministically, we:
#       1) attempt to steer temp directories via TMPDIR/TEMP/TMP (best-effort)
#       2) always snapshot the directory that contains the generated FMU
#          (fmu_gen.parent) into out_dir/omc_work/

#     Layout (per artifact key)
#     -------------------------
#     build/translator_runs/fmu/<key>/
#         <Class_Name>.fmu
#         logs/
#             build_info.json
#             build.log
#             (optional copied logs from omc_work and generation dir)
#         omc_work/
#             (snapshot of OpenModelica intermediates and build outputs)
#     """

#     paths = get_paths()

#     # Resolve Modelica file path
#     mo_path = Path(mo_path)
#     if not mo_path.is_absolute():
#         mo_path = (paths.root / mo_path).resolve()
#     if not mo_path.exists():
#         raise FileNotFoundError(mo_path)
#     class_name = resolve_model_class_name(mo_path=mo_path, class_name=class_name)

#     # Compute deterministic artifact key
#     key = model_artifact_key(mo_path=mo_path, class_name=class_name, fmu_type=fmu_type)

#     # Prepare isolated output directory
#     out_dir = paths.build_translator_runs / "fmu" / key
#     out_dir.mkdir(parents=True, exist_ok=True)

#     # Stable filename (filesystem-safe)
#     fmu_name = class_name.replace(".", "_")
#     expected = out_dir / f"{fmu_name}.fmu"

#     # Subdirectories for traceability
#     logs_dir = out_dir / "logs"
#     omc_work = out_dir / "omc_work"
#     logs_dir.mkdir(parents=True, exist_ok=True)
#     omc_work.mkdir(parents=True, exist_ok=True)

#     build_info_path = logs_dir / "build_info.json"
#     build_log_path = logs_dir / "build.log"

#     # Cache hit
#     if expected.exists():
#         log.info(f"FMU cache hit: {expected}")
#         return FMUArtifact(fmu_path=expected, work_dir=out_dir, key=key)

#     # Metadata (updated as we learn more)
#     build_info: dict[str, object] = {
#         "timestamp_utc": datetime.now(timezone.utc).isoformat(),
#         "key": key,
#         "mo_path": str(mo_path),
#         "class_name": class_name,
#         "fmu_type": fmu_type,
#         "expected_fmu": str(expected),
#         "work_dir": str(out_dir),
#         "logs_dir": str(logs_dir),
#         "omc_work_dir": str(omc_work),
#     }
#     _write_text(build_info_path, json.dumps(build_info, indent=2))

#     log.info(f"Building FMU: class={class_name}, type={fmu_type}, mo={mo_path}")

#     # Best-effort: steer temp into a deterministic subtree
#     try:
#         _write_text(
#             build_log_path,
#             f"[{datetime.now(timezone.utc).isoformat()}] START build_fmu\n"
#             f"mo_path={mo_path}\nclass_name={class_name}\nfmu_type={fmu_type}\n"
#             f"key={key}\nout_dir={out_dir}\nomc_work={omc_work}\n",
#         )

#         # Run OMC (CWD change is still useful for any relative outputs)
#         with _Pushd(omc_work):
#             model = ModelicaSystem(str(mo_path), class_name)

#             # Best-effort: record OpenModelica version if available
#             try:
#                 omc_ver = None
#                 for attr in ("getOMCVersion", "get_omc_version", "getOMVersion"):
#                     fn = getattr(model, attr, None)
#                     if callable(fn):
#                         omc_ver = fn()
#                         break
#                 if omc_ver:
#                     build_info["openmodelica_version"] = str(omc_ver)
#                     _write_text(build_info_path, json.dumps(build_info, indent=2))
#             except Exception:
#                 pass

#             fmu_gen = model.convertMo2Fmu(fileNamePrefix=fmu_name, fmuType=fmu_type)

#         fmu_gen = Path(fmu_gen).resolve()
#         build_info["fmu_generated_path"] = str(fmu_gen)
#         _write_text(build_info_path, json.dumps(build_info, indent=2))

#         if not fmu_gen.exists():
#             # Attempt to collect anything we have and fail
#             try:
#                 _collect_logs(work_dir=omc_work, logs_dir=logs_dir)
#             except Exception:
#                 pass
#             raise RuntimeError(f"FMU generation failed, got path: {fmu_gen}")

#         # 1) Copy final FMU into stable output location
#         shutil.copy2(fmu_gen, expected)

#         # 2) Snapshot *the actual generation directory* (often /tmp/...) into omc_work/
#         gen_dir = fmu_gen.parent
#         build_info["fmu_generated_dir"] = str(gen_dir)
#         _write_text(build_info_path, json.dumps(build_info, indent=2))

#         # If OpenModelica generated into /tmp/... this captures all intermediates.
#         _snapshot_dir(gen_dir, omc_work)

#         # 3) Collect logs (from snapshot + any residual in omc_work)
#         try:
#             _collect_logs(work_dir=omc_work, logs_dir=logs_dir)
#         except Exception:
#             pass

#         # Append success
#         with build_log_path.open("a", encoding="utf-8") as f:
#             f.write(
#                 f"\n[{datetime.now(timezone.utc).isoformat()}] SUCCESS\n"
#                 f"generated_fmu={fmu_gen}\n"
#                 f"copied_to={expected}\n"
#                 f"snapshot_from={gen_dir}\n"
#                 f"snapshot_to={omc_work}\n"
#             )

#         log.info(f"FMU created: {expected}")
#         return FMUArtifact(fmu_path=expected, work_dir=out_dir, key=key)

#     except Exception as e:
#         tb = traceback.format_exc()

#         # Best-effort: add failure details
#         try:
#             with build_log_path.open("a", encoding="utf-8") as f:
#                 f.write(
#                     f"\n[{datetime.now(timezone.utc).isoformat()}] FAILURE\n"
#                     f"error={repr(e)}\n\ntraceback:\n{tb}\n"
#                 )
#         except Exception:
#             pass

#         # Best-effort log collection on failure
#         try:
#             _collect_logs(work_dir=omc_work, logs_dir=logs_dir)
#         except Exception:
#             pass

#         raise


def resolve_model_class_name(
    *,
    source_path: str | Path,
    class_name: str | None = None,
) -> str:
    """
    Public helper that resolves a model/class name from a supported source.

    This is a thin public wrapper around the internal source-class-name resolver.
    """
    return _resolve_source_class_name(
        source_path=source_path,
        class_name=class_name,
    )