"""
Multi-model execution backend.

Purpose
-------
This module implements the low-level execution path for scenarios that
contain multiple model instances, typically representing a composed system
such as plant/controller/sensor/attacker FMUs or Modelica-defined
subsystems.

This layer is responsible for:
- validating multi-model configuration,
- normalizing model identity information,
- returning a stable result schema.

Experiment control such as Monte Carlo looping is intentionally handled in
`simulation.experiments`.

Expected scenario pattern
-------------------------
{
    "models": {
        "plant": {
            "fmu_path": "build/fmus/plant.fmu"
        },
        "controller": {
            "mo_path": "models/Controller.mo",
            "class_name": "Pkg.Controller"
        }
    },
    "connections": [
        {"src": "controller.u", "dst": "plant.u"},
        {"src": "plant.y", "dst": "controller.y"}
    ],
    "sim": {
        "start_time": 0.0,
        "stop_time": 5.0,
        "step_size": 0.01
    }
}

Returned schema
---------------
{
    "status": "success",
    "topology": "multi_fmu",
    "models": {...},
    "connections": [...],
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
    Extract normalized identity information from one model config.

    Parameters
    ----------
    model_cfg : dict[str, Any]
        Per-model configuration.

    Returns
    -------
    dict[str, Any]
        Normalized model identity dictionary.

    Raises
    ------
    ValueError
        If the configuration does not contain any recognizable model identity.
    """
    identity = {k: model_cfg.get(k) for k in _MODEL_HINT_KEYS if model_cfg.get(k)}

    if not identity:
        raise ValueError(
            "Each model in 'models' must contain at least one model identity field. "
            f"Expected one of: {', '.join(_MODEL_HINT_KEYS)}"
        )

    return identity


def _validate_optional_existing_paths(model_identity: dict[str, Any], model_name: str) -> None:
    """
    Validate model path fields that are expected to exist on disk when present.

    Parameters
    ----------
    model_identity : dict[str, Any]
        Normalized model identity.
    model_name : str
        Model name for error messages.

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
            raise FileNotFoundError(
                f"Model file not found for model '{model_name}', field '{key}': {path}"
            )


def run_multi_fmu_open_loop(scn: dict[str, Any]) -> dict[str, Any]:
    """
    Execute a multi-model simulation scenario.

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
        If configuration is malformed.
    FileNotFoundError
        If any configured model artifact is missing.
    """
    models_cfg = scn.get("models")
    if not isinstance(models_cfg, dict) or not models_cfg:
        raise ValueError("Multi-model scenario must contain a non-empty 'models' section.")

    sim_cfg = scn.get("sim", {}) or {}
    connections = scn.get("connections", []) or []

    start_time = float(sim_cfg.get("start_time", 0.0))
    stop_time = float(sim_cfg.get("stop_time", 1.0))
    step_size = float(sim_cfg.get("step_size", 0.1))

    if stop_time < start_time:
        raise ValueError(
            f"Invalid time range: stop_time ({stop_time}) < start_time ({start_time})."
        )
    if step_size <= 0.0:
        raise ValueError(f"step_size must be positive, got {step_size}.")

    resolved_models: dict[str, dict[str, Any]] = {}

    for model_name, cfg in models_cfg.items():
        if not isinstance(cfg, dict) or not cfg:
            raise ValueError(f"Model '{model_name}' configuration must be a non-empty dict.")

        model_identity = _extract_model_identity(cfg)
        _validate_optional_existing_paths(model_identity, model_name)

        resolved_models[model_name] = {
            **cfg,
            **model_identity,
        }

    t_wall_0 = time.time()

    # ------------------------------------------------------------------
    # Placeholder execution logic
    # Replace with actual co-simulation / composition runtime.
    # ------------------------------------------------------------------
    n_steps = int(round((stop_time - start_time) / step_size)) + 1
    time_grid = [start_time + i * step_size for i in range(n_steps)]

    return {
        "status": "success",
        "topology": "multi_fmu",
        "models": resolved_models,
        "connections": connections,
        "time": time_grid,
        "outputs": {},
        "metadata": {
            "start_time": start_time,
            "stop_time": stop_time,
            "step_size": step_size,
            "wall_time_sec": time.time() - t_wall_0,
            "executor": "run_multi_fmu_open_loop",
            "n_models": len(resolved_models),
            "n_connections": len(connections),
        },
    }