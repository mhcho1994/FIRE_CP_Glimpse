"""
cp_glimpse_py.translator.mo_to_fmu
=================================
This module provides a thin wrapper around OpenModelica (via OMPython)
to generate Functional Mock-up Units (FMUs) from Modelica models.

It implements:
- Deterministic artifact hashing (via model_artifact_key)
- Per-build isolated working directories
- Stable FMU naming (safe filename derived from class name)
- Simple caching (skip rebuild if FMU already exists)
- Preservation of OpenModelica intermediate outputs (omc_work/)
  by snapshotting the actual OpenModelica-generated directory (often under /tmp)
- Collection of OpenModelica/compile logs into logs/

This allows CP-Glimpse to:
    Modelica (.mo) → FMU (ME/CS) → downstream simulation pipeline

Typical usage
-------------
artifact = build_fmu(
    mo_path="models/rover/Rover.mo",
    class_name="RoverExample.Components.Webserver",
    fmu_type="me" or "cs"
)

artifact.fmu_path → ready-to-use FMU file
artifact.work_dir → isolated build directory (contains logs/ and omc_work/)
artifact.key      → content-based hash key
"""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
import json
import os
import shutil
import traceback
from datetime import datetime, timezone

from OMPython import ModelicaSystem

from ..common.paths import get_paths
from ..common.hashing import model_artifact_key
from ..common.logging import get_logger

log = get_logger(__name__)


@dataclass(frozen=True)
class FMUArtifact:
    """
    Represents a built FMU artifact.

    Attributes
    ----------
    fmu_path : Path
        Absolute path to the generated FMU file.

    work_dir : Path
        Build directory used for this artifact. This directory is keyed
        by a deterministic hash and contains:
            - logs/     : captured logs and build metadata
            - omc_work/ : snapshot of OpenModelica work directory (intermediates)

    key : str
        Deterministic hash key derived from:
            - Modelica file contents
            - class name
            - FMU type
        Used for caching and reproducibility.
    """

    fmu_path: Path
    work_dir: Path
    key: str


class _Pushd:
    """Simple pushd/popd context manager for changing working directory safely."""

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
        return False  # never suppress exceptions


def _write_text(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")


def _safe_copy_if_exists(src: Path, dst: Path) -> None:
    if src.exists() and src.is_file():
        dst.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src, dst)


def _collect_logs(*, work_dir: Path, logs_dir: Path) -> None:
    """
    Best-effort log collection from a directory.

    We copy common OpenModelica/FM U compile logs if present.
    This function should never raise (callers may wrap in try/except anyway).
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

    # Shallow nested scan for common subdirs
    for sub in ("build", "sources", "binaries", "tmp", "OMTmp", "fmu", "FMU"):
        d = work_dir / sub
        if d.exists() and d.is_dir():
            for pat in ("*.log", "*.txt", "*.xml", "*.json", "*makefile*"):
                for p in d.glob(pat):
                    if p.is_file():
                        _safe_copy_if_exists(p, logs_dir / f"{sub}__{p.name}")


def _snapshot_dir(src_dir: Path, dst_dir: Path) -> None:
    """
    Snapshot (copy) an entire directory tree into dst_dir.

    We intentionally snapshot the OpenModelica generated directory (often under /tmp)
    to keep intermediate C code, object files, and build logs for debugging/repro.
    """
    src_dir = src_dir.resolve()
    dst_dir = dst_dir.resolve()

    if not src_dir.exists() or not src_dir.is_dir():
        raise FileNotFoundError(f"snapshot source dir not found: {src_dir}")

    # Avoid copying a directory onto itself
    if src_dir == dst_dir:
        return

    # Replace any existing snapshot to avoid stale files
    shutil.rmtree(dst_dir, ignore_errors=True)
    shutil.copytree(src_dir, dst_dir, dirs_exist_ok=True)


def build_fmu(*, mo_path: str | Path, class_name: str, fmu_type: str) -> FMUArtifact:
    """
    Build (or retrieve from cache) an FMU from a Modelica model.

    OpenModelica/OMPython sometimes generates intermediates under /tmp regardless of CWD.
    To preserve intermediates deterministically, we:
      1) attempt to steer temp directories via TMPDIR/TEMP/TMP (best-effort)
      2) always snapshot the directory that contains the generated FMU
         (fmu_gen.parent) into out_dir/omc_work/

    Layout (per artifact key)
    -------------------------
    build/translator_runs/fmu/<key>/
        <Class_Name>.fmu
        logs/
            build_info.json
            build.log
            (optional copied logs from omc_work and generation dir)
        omc_work/
            (snapshot of OpenModelica intermediates and build outputs)
    """

    paths = get_paths()

    # Resolve Modelica file path
    mo_path = Path(mo_path)
    if not mo_path.is_absolute():
        mo_path = (paths.root / mo_path).resolve()
    if not mo_path.exists():
        raise FileNotFoundError(mo_path)

    # Compute deterministic artifact key
    key = model_artifact_key(mo_path=mo_path, class_name=class_name, fmu_type=fmu_type)

    # Prepare isolated output directory
    out_dir = paths.build_translator_runs / "fmu" / key
    out_dir.mkdir(parents=True, exist_ok=True)

    # Stable filename (filesystem-safe)
    fmu_name = class_name.replace(".", "_")
    expected = out_dir / f"{fmu_name}.fmu"

    # Subdirectories for traceability
    logs_dir = out_dir / "logs"
    omc_work = out_dir / "omc_work"
    logs_dir.mkdir(parents=True, exist_ok=True)
    omc_work.mkdir(parents=True, exist_ok=True)

    build_info_path = logs_dir / "build_info.json"
    build_log_path = logs_dir / "build.log"

    # Cache hit
    if expected.exists():
        log.info(f"FMU cache hit: {expected}")
        return FMUArtifact(fmu_path=expected, work_dir=out_dir, key=key)

    # Metadata (updated as we learn more)
    build_info: dict[str, object] = {
        "timestamp_utc": datetime.now(timezone.utc).isoformat(),
        "key": key,
        "mo_path": str(mo_path),
        "class_name": class_name,
        "fmu_type": fmu_type,
        "expected_fmu": str(expected),
        "work_dir": str(out_dir),
        "logs_dir": str(logs_dir),
        "omc_work_dir": str(omc_work),
    }
    _write_text(build_info_path, json.dumps(build_info, indent=2))

    log.info(f"Building FMU: class={class_name}, type={fmu_type}, mo={mo_path}")

    # Best-effort: steer temp into a deterministic subtree
    try:
        _write_text(
            build_log_path,
            f"[{datetime.now(timezone.utc).isoformat()}] START build_fmu\n"
            f"mo_path={mo_path}\nclass_name={class_name}\nfmu_type={fmu_type}\n"
            f"key={key}\nout_dir={out_dir}\nomc_work={omc_work}\n",
        )

        # Run OMC (CWD change is still useful for any relative outputs)
        with _Pushd(omc_work):
            model = ModelicaSystem(str(mo_path), class_name)

            # Best-effort: record OpenModelica version if available
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
            # Attempt to collect anything we have and fail
            try:
                _collect_logs(work_dir=omc_work, logs_dir=logs_dir)
            except Exception:
                pass
            raise RuntimeError(f"FMU generation failed, got path: {fmu_gen}")

        # 1) Copy final FMU into stable output location
        shutil.copy2(fmu_gen, expected)

        # 2) Snapshot *the actual generation directory* (often /tmp/...) into omc_work/
        gen_dir = fmu_gen.parent
        build_info["fmu_generated_dir"] = str(gen_dir)
        _write_text(build_info_path, json.dumps(build_info, indent=2))

        # If OpenModelica generated into /tmp/... this captures all intermediates.
        _snapshot_dir(gen_dir, omc_work)

        # 3) Collect logs (from snapshot + any residual in omc_work)
        try:
            _collect_logs(work_dir=omc_work, logs_dir=logs_dir)
        except Exception:
            pass

        # Append success
        with build_log_path.open("a", encoding="utf-8") as f:
            f.write(
                f"\n[{datetime.now(timezone.utc).isoformat()}] SUCCESS\n"
                f"generated_fmu={fmu_gen}\n"
                f"copied_to={expected}\n"
                f"snapshot_from={gen_dir}\n"
                f"snapshot_to={omc_work}\n"
            )

        log.info(f"FMU created: {expected}")
        return FMUArtifact(fmu_path=expected, work_dir=out_dir, key=key)

    except Exception as e:
        tb = traceback.format_exc()

        # Best-effort: add failure details
        try:
            with build_log_path.open("a", encoding="utf-8") as f:
                f.write(
                    f"\n[{datetime.now(timezone.utc).isoformat()}] FAILURE\n"
                    f"error={repr(e)}\n\ntraceback:\n{tb}\n"
                )
        except Exception:
            pass

        # Best-effort log collection on failure
        try:
            _collect_logs(work_dir=omc_work, logs_dir=logs_dir)
        except Exception:
            pass

        raise
