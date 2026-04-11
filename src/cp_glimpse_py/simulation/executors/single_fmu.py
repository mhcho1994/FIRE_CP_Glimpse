"""
Single-model execution backend.

Purpose
-------
This module implements the low-level execution path for a scenario that
contains exactly one model instance. The model may already be exported as
an FMU, or it may be specified by Modelica source information such as
`mo_path` and `class_name`.

This layer is intentionally narrow in scope:
- validate one-model simulation inputs,
- execute one simulation backend,
- return a stable result dictionary.

It should not decide whether the run is part of a Monte Carlo experiment
or a one-off experiment. That orchestration belongs to
`simulation.experiments`.

Current behavior
----------------
The implementation below is written as a production-friendly skeleton:
- it validates the scenario,
- resolves model metadata,
- constructs a deterministic time grid,
- returns a structured result.

The marked execution section can later be replaced by:
- FMU execution using FMPy / PyFMI,
- direct OpenModelica invocation,
- or another backend chosen by scenario configuration.

Expected scenario patterns
--------------------------
A single-model scenario may look like one of the following.

1) FMU-based
{
    "model": {
        "fmu_path": "build/models/plant.fmu",
        "start_time": 0.0,
        "stop_time": 10.0,
        "step_size": 0.01
    }
}

2) Modelica-source-based
{
    "model": {
        "mo_path": "models/MySystem.mo",
        "class_name": "MyPkg.MySystem",
        "start_time": 0.0,
        "stop_time": 10.0,
        "step_size": 0.01
    }
}

Returned schema
---------------
{
    "status": "success",
    "topology": "single_fmu",
    "model": {...},
    "time": [...],
    "outputs": {},
    "metadata": {...}
}
"""

from __future__ import annotations

from pathlib import Path
from typing import Any
import time


_MODEL_HINT_KEYS = (
    "fmu_path",
    "mo_path",
    "class_name",
    "model_path",
    "model_file",
    "uri",
)


def _extract_model_identity(model_cfg: dict[str, Any]) -> dict[str, Any]:
    """
    Extract model identity fields from a single-model config.

    Parameters
    ----------
    model_cfg : dict[str, Any]
        Configuration under `scenario["model"]`.

    Returns
    -------
    dict[str, Any]
        Normalized model identity dictionary.

    Raises
    ------
    ValueError
        If no recognizable model identity field is present.
    """
    identity = {k: model_cfg.get(k) for k in _MODEL_HINT_KEYS if model_cfg.get(k)}

    if not identity:
        raise ValueError(
            "Single-model scenario must contain at least one model identity field. "
            f"Expected one of: {', '.join(_MODEL_HINT_KEYS)}"
        )

    return identity


def _validate_optional_existing_paths(model_identity: dict[str, Any]) -> None:
    """
    Validate model path fields that are expected to exist on disk when present.

    Parameters
    ----------
    model_identity : dict[str, Any]
        Normalized model identity.

    Raises
    ------
    FileNotFoundError
        If a provided local file path does not exist.
    """
    for key in ("fmu_path", "mo_path", "model_path", "model_file"):
        value = model_identity.get(key)
        if not value:
            continue

        path = Path(value)
        if not path.exists():
            raise FileNotFoundError(f"Model file not found for '{key}': {path}")


def run_single_fmu_open_loop(scn: dict[str, Any]) -> dict[str, Any]:
    """
    Execute a single-model simulation scenario.

    Parameters
    ----------
    scn : dict[str, Any]
        Fully loaded scenario dictionary.

    Returns
    -------
    dict[str, Any]
        Structured execution result.

    Raises
    ------
    ValueError
        If required configuration is missing or invalid.
    FileNotFoundError
        If configured local model artifacts do not exist.

    Notes
    -----
    Despite the function name, this executor now supports topology resolution
    from either FMU identity fields or Modelica identity fields. The actual
    backend implementation can later branch on these fields as needed.
    """
    model_cfg = scn.get("model")
    if not isinstance(model_cfg, dict) or not model_cfg:
        raise ValueError("Single-model scenario must contain a non-empty 'model' section.")

    model_identity = _extract_model_identity(model_cfg)
    _validate_optional_existing_paths(model_identity)

    start_time = float(model_cfg.get("start_time", scn.get("sim", {}).get("start_time", 0.0)))
    stop_time = float(model_cfg.get("stop_time", scn.get("sim", {}).get("stop_time", 1.0)))
    step_size = float(model_cfg.get("step_size", scn.get("sim", {}).get("step_size", 0.1)))

    if stop_time < start_time:
        raise ValueError(
            f"Invalid time range: stop_time ({stop_time}) < start_time ({start_time})."
        )
    if step_size <= 0.0:
        raise ValueError(f"step_size must be positive, got {step_size}.")

    t_wall_0 = time.time()

    # ------------------------------------------------------------------
    # Placeholder execution logic
    # Replace this block with the actual runtime backend.
    # ------------------------------------------------------------------
    n_steps = int(round((stop_time - start_time) / step_size)) + 1
    time_grid = [start_time + i * step_size for i in range(n_steps)]

    return {
        "status": "success",
        "topology": "single_fmu",
        "model": {
            **model_cfg,
            **model_identity,
        },
        "time": time_grid,
        "outputs": {},
        "metadata": {
            "start_time": start_time,
            "stop_time": stop_time,
            "step_size": step_size,
            "wall_time_sec": time.time() - t_wall_0,
            "executor": "run_single_fmu_open_loop",
        },
    }