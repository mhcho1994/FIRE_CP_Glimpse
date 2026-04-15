"""
cp_glimpse_py.materialize.materialize
=======

Scenario-aware artifact preparation for CP-Glimpse.

Purpose
-------
This module resolves scenario model references into executable artifacts
that can be consumed by simulation backends.

Why this layer exists
---------------------
The preparation of a simulation artifact is conceptually different from
executing it.

Examples:
- Modelica source (.mo) -> FMU build
- Existing FMU path -> direct reuse
- Future: Modelica -> CasADi IR
- Future: direct Modelica execution descriptors

This module keeps that responsibility out of backend classes so that:
- backends remain execution-focused
- artifact caching can evolve independently
- scenario orchestration stays cleaner
- multiple backends can share the same preparation logic

Current scope
-------------
This initial implementation supports single-artifact materialization for
FMI 2.0 Co-Simulation runs.

Supported scenario model fields
-------------------------------
Preferred modern forms:
    model:
      model_path: path/to/model.fmu

or:
    model:
      model_path: path/to/model.mo
      class_name: MyModel

Legacy-compatible forms:
    model:
      fmu_path: path/to/model.fmu

    model:
      mo_path: path/to/model.mo
      class_name: MyModel

Behavior
--------
- If the resolved model path ends with .fmu, it is reused directly.
- If it ends with .mo, it is translated to an FMU by calling translator.to_fmu.
- Artifact metadata records enough information for execution backends.
"""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Optional

from ..backend.base import BackendArtifact
from ..common.logging import get_logger
from ..translator.to_fmu import build_fmu, resolve_model_class_name

log = get_logger(__name__)


@dataclass(frozen=True)
class MaterializedModel:
    """
    Internal description of a scenario model after path normalization.

    Attributes
    ----------
    source_kind : str
        One of 'fmu' or 'modelica'.
    source_path : str
        Path to the original referenced source.
    class_name : str | None
        Model class name if known or needed.
    fmu_type : str
        Intended FMU type, typically 'cs' or 'me'.
    """
    source_kind: str
    source_path: str
    class_name: Optional[str]
    fmu_type: str = "cs"


def _require_dict(scn: dict, key: str) -> dict:
    value = scn.get(key)
    if not isinstance(value, dict) or not value:
        raise ValueError(f"Scenario must include a non-empty '{key}' section.")
    return value


def _resolve_model_reference(model_cfg: dict) -> tuple[str, Optional[str]]:
    """
    Resolve the scenario model reference into (path, class_name).

    Accepted keys
    -------------
    Preferred:
    - model_path

    Backward-compatible:
    - fmu_path
    - mo_path
    """
    if model_cfg.get("model_path"):
        return str(model_cfg["model_path"]), model_cfg.get("class_name")

    if model_cfg.get("fmu_path"):
        return str(model_cfg["fmu_path"]), model_cfg.get("class_name")

    if model_cfg.get("mo_path"):
        return str(model_cfg["mo_path"]), model_cfg.get("class_name")

    raise ValueError(
        "Scenario 'model' section must include one of: "
        "'model_path', 'fmu_path', or 'mo_path'."
    )


def _normalize_single_model(scn: dict) -> MaterializedModel:
    """
    Normalize a single-model scenario description.

    This function does not build artifacts yet. It only resolves
    what kind of source was requested.
    """
    model_cfg = _require_dict(scn, "model")
    sim_cfg = scn.get("sim", {}) or {}

    model_path, class_name = _resolve_model_reference(model_cfg)
    fmu_type = str(sim_cfg.get("fmu_type", "cs")).lower()

    path = Path(model_path)
    suffix = path.suffix.lower()

    if suffix == ".fmu":
        return MaterializedModel(
            source_kind="fmu",
            source_path=str(path),
            class_name=class_name,
            fmu_type=fmu_type,
        )

    if suffix == ".mo":
        if not class_name:
            class_name = resolve_model_class_name(
                mo_path=str(path),
                class_name=None,
            )

        return MaterializedModel(
            source_kind="modelica",
            source_path=str(path),
            class_name=str(class_name),
            fmu_type=fmu_type,
        )

    raise ValueError(
        f"Unsupported model source extension {suffix!r} for path {model_path!r}. "
        "Currently supported: .fmu, .mo"
    )


def materialize_single_artifact(scn: dict) -> BackendArtifact:
    """
    Materialize the executable artifact for a single-model scenario.

    Parameters
    ----------
    scn : dict
        Parsed scenario dictionary.

    Returns
    -------
    BackendArtifact
        Artifact ready to be consumed by a simulation backend.

    Current policy
    --------------
    - .fmu input: reuse directly
    - .mo input: build FMU via translator
    """
    mm = _normalize_single_model(scn)

    if mm.source_kind == "fmu":
        fmu_path = str(Path(mm.source_path))
        log.info("Reusing existing FMU artifact: %s", fmu_path)

        return BackendArtifact(
            kind="fmu",
            path=fmu_path,
            metadata={
                "source_kind": "fmu",
                "source_path": mm.source_path,
                "class_name": mm.class_name,
                "fmu_type": mm.fmu_type,
            },
        )

    if mm.source_kind == "modelica":
        log.info(
            "Building FMU from Modelica source: %s (class=%s, fmu_type=%s)",
            mm.source_path,
            mm.class_name,
            mm.fmu_type,
        )

        art = build_fmu(
            mo_path=mm.source_path,
            class_name=mm.class_name,
            fmu_type=mm.fmu_type,
        )

        return BackendArtifact(
            kind="fmu",
            path=str(art.fmu_path),
            metadata={
                "source_kind": "modelica",
                "source_path": mm.source_path,
                "class_name": mm.class_name,
                "fmu_type": mm.fmu_type,
            },
        )

    raise RuntimeError(f"Unhandled materialized model kind: {mm.source_kind!r}")