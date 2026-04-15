"""
cp_glimpse_py.scenario.resolve
=================================
Scenario resolution utilities for CP-Glimpse.

Purpose
-------



Composition resolution
----------------------
Composition can be resolved in two ways.

1. Explicit:
   `sim.composition` is set to something other than "auto".

2. Inferred:
   The dispatcher inspects `system.components`.

Inference rules
---------------
- one valid component  -> single
- two or more          -> multi
- otherwise: resolution fails with an error

Experiment resolution
---------------------
- sim.experiment == "montecarlo" -> Monte-Carlo run
- sim.experiment == "single" -> single run
- sim.experimenht == "sensitivity" -> TODO
- sim.experiment == "sweep": TODO
- sim.experiment not provided: default to "single"
"""

from __future__ import annotations

from ..common import get_logger
from typing import Any

from .load import Scenario

log = get_logger(__name__)

_MODEL_HINT_KEYS = (
    "class_name",
    "model_path",
    "uri",
)

_VALID_BACKENDS = (
    "fmu-fmpy",
    # "fmu-pyfmi",
)


def _has_model_identity(model_cfg: Any) -> bool:
    """
    Return True if an object looks like a single model specification.

    Parameters
    ----------
    model_cfg : Any
        Candidate model configuration.

    Returns
    -------
    bool
        True if at least one recognizable model identity key is present
        and non-empty.
    """
    return isinstance(model_cfg, dict) and any(model_cfg.get(k) for k in _MODEL_HINT_KEYS)


def count_valid_models(models_cfg: Any) -> int:
    """
    Count how many valid model entries exist in `models`.

    Parameters
    ----------
    models_cfg : Any
        Candidate multi-model configuration.

    Returns
    -------
    int
        Number of valid model entries.
    """
    if not isinstance(models_cfg, list) and isinstance(models_cfg, dict):
        models_cfg = [models_cfg]
    elif not isinstance(models_cfg, list):
        return 0
    
    count = 0
    for _, model_cfg in enumerate(models_cfg):
        if _has_model_identity(model_cfg):
            count += 1
    
    if count == 0:
        msg = ("No valid model entries found in 'system.components'. "
               f"Expected at least one entry with one of: {', '.join(_MODEL_HINT_KEYS)}")
        log.error(msg)
        raise ValueError(msg)

    return count

def resolve_experiment(scn: Scenario | dict[str, Any]) -> str:
    """
    Resolve experiment type from scenario contents.

    Parameters
    ----------
    scn : Scenario | dict[str, Any]
        Scenario object or dictionary.

    Returns
    -------
    str
        Experiment type.

    Raises
    ------
    ValueError
        If experiment cannot be determined.
    """
    sim_cfg = scn.get("sim", {}) or {}
    experiment = str(sim_cfg.get("experiment", "single")).lower()

    if experiment in {"single", "single_run"}:
        return "single"
    if experiment in {"montecarlo", "monte_carlo"}:
        return "montecarlo"

    msg = f"Unsupported experiment type: {experiment}"
    log.error(msg)
    raise ValueError(msg)

def resolve_composition(scn: Scenario | dict[str, Any]) -> str:
    """
    Resolve simulation composition from scenario contents.

    Resolution order
    ----------------
    1. If `sim.composition` is explicitly provided and not "auto", respect it.
    2. If `system.components` contains one or more valid model definitions, determine "single" or "multi".
    3. Otherwise raise an error.

    Parameters
    ----------
    scn : Scenario | dict[str, Any]
        Scenario object or dictionary.

    Returns
    -------
    str
        Resolved composition string.

    Raises
    ------
    ValueError
        If composition cannot be determined.
    """
    sim_cfg = scn.get("sim", {}) or {}
    explicit = str(sim_cfg.get("composition", "auto")).lower()

    if explicit not in {"single", "multi", "auto"}:
        msg = f"Unsupported sim.composition value: {explicit}"
        log.error(msg)
        raise ValueError(msg)

    system_cfg = scn.get("system", {}) or {}
    components = system_cfg.get("components")
    n_components = count_valid_models(components)
    inferred = "single" if n_components == 1 else "multi"

    if explicit == "auto":
        return inferred

    if explicit != inferred:
        msg = ("Explicit sim.composition '%s' conflicts with system.components count=%d (inferred: '%s'). "
                "Using explicit value.",
                explicit,
                n_components,
                inferred)
        log.warning(msg)
    return explicit


def resolve_backend(scn: Scenario | dict[str, Any]) -> str:
    """
    Resolve simulation backend from scenario contents.

    Parameters
    ----------
    scn : Scenario | dict[str, Any]
        Scenario object or dictionary.

    Returns
    -------
    str
        Resolved backend string.
    """
    sim_cfg = scn.get("sim", {}) or {}
    backend = str(sim_cfg.get("backend", "fmu-fmpy")).lower()

    if backend in _VALID_BACKENDS:
        return backend

    msg = ("Could not resolve simulation backend. "
            "Provide sim.backend explicitly or use a valid backend. "
            f"Valid backends: {', '.join(_VALID_BACKENDS)}")
    log.error(msg)
    raise ValueError(msg)