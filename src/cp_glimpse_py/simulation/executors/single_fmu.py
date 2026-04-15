"""
cp_glimpse_py.simulation.executors.single_fmu
=============================================
Single-FMU execution backend.

Purpose
-------
This module assumes the scenario has already been materialized into a runnable
single-component FMU form. It uses the backend abstraction rather than calling
FMPy high-level helpers directly.

Responsibilities
----------------
- validate single-component execution assumptions
- construct the backend from a materialized component
- apply initialization values
- evaluate scenario-defined inputs over time
- step the backend in a fixed-step loop
- sample requested outputs

Non-responsibilities
--------------------
- FMU building / source translation
- experiment-type dispatch
- multi-component master algorithm logic
"""

from __future__ import annotations

from typing import Any

import time

from ...common import get_logger
from ...backend import FMI2CSBackend
from ...scenario import evaluate_inputs, normalize_inputs

log = get_logger(__name__)


def _get_single_component(scn: dict[str, Any]) -> dict[str, Any]:
    """
    Return the single component from `system.components`.
    """
    system_cfg = scn.get("system", {}) or {}
    components = system_cfg.get("components")

    if not isinstance(components, list) or not components:
        msg = ("Single-FMU execution requires exactly one component under "
                "'system.components'.")
        log.error(msg)
        raise ValueError(msg)
    
    if len(components) != 1:
        msg = ("Single-FMU execution requires exactly one component under "
               "'system.components'. Found %d entries and run only the first entry", len(components))
        log.warning(msg)

    component = components[0]
    if not isinstance(component, dict):
        msg = ("The single component entry must be a dictionary.")
        log.error(msg)
        raise ValueError(msg)
    
    return component


# def _resolve_output_names(
#     scn: dict[str, Any],
#     backend: FMI2CSBackend,
#     component_cfg: dict[str, Any],
# ) -> list[str]:
#     """
#     Resolve output names to sample.

#     Resolution order
#     ----------------
#     1. top-level `outputs`
#     2. component-level `outputs`
#     3. backend discovered outputs
#     """
#     top_outputs = scn.get("outputs")
#     if isinstance(top_outputs, list) and top_outputs:
#         return [str(x) for x in top_outputs]

#     comp_outputs = component_cfg.get("outputs")
#     if isinstance(comp_outputs, list) and comp_outputs:
#         return [str(x) for x in comp_outputs]

#     return backend.discovered_outputs()


def _apply_named_values(
    backend: FMI2CSBackend,
    values: list[dict[str, Any]],
) -> None:
    """
    Apply name->value assignments through the backend.
    """
    for item in values:
        name = item["variable"]
        value = item["value"]
        backend.set_variable(name, value)


def run_single_fmu_open_loop(scn: dict[str, Any]) -> dict[str, Any]:
    """
    Execute a single-component FMU scenario through the backend abstraction.

    Parameters
    ----------
    scn : dict[str, Any]
        Fully loaded and materialized scenario dictionary.

    Returns
    -------
    dict[str, Any]
        Structured execution result.

    Notes
    -----
    This executor currently supports FMI 2.0 Co-Simulation (`fmu_type='cs'`)
    and fixed-step open-loop execution.
    """
    sim_cfg = scn.get("sim", {}) or {}
    component_cfg = _get_single_component(scn)

    backend = str(sim_cfg.get("backend", "fmu-fmpy")).lower()
    if not backend.startswith("fmu"):
        msg = ( f"Unsupported backend {backend!r} for single FMU executor.")
        log.error(msg)
        raise ValueError(msg)

    fmu_type = str(sim_cfg.get("fmu_type", "cs")).lower()
    if fmu_type != "cs":
        msg = (f"Single FMU executor currently supports only type 'cs', got {fmu_type!r}.")
        log.error(msg)
        raise ValueError(msg)

    t0 = float(sim_cfg.get("start_time", 0.0))
    tf = float(sim_cfg.get("stop_time", 1.0))
    dt = float(sim_cfg.get("step_size", 0.01))

    if tf < t0:
        msg = (f"Invalid time range: tf ({tf}) < t0 ({t0}).")
        log.error(msg)
        raise ValueError(msg)
    if dt <= 0.0:
        msg = (f"Invalid step size: dt ({dt}) must be positive.")
        log.error(msg)
        raise ValueError(msg)

    init_list = scn.get("initialization", []) or []
    if not isinstance(init_list, list):
        msg = ("Initialization section must be a list of initialization variables or states.")
        log.error(msg)
        raise ValueError(msg)
    
    param_list = scn.get("parameters", []) or []
    if not isinstance(param_list, list):
        msg = ("Parameters section must be a list of parameter variables.")
        log.error(msg)
        raise ValueError(msg)

    input_defs = normalize_inputs(scn)

    backend = FMI2CSBackend.from_component(component_cfg, sim_cfg=sim_cfg)

    records: list[dict[str, Any]] = []
    accepted_steps = 0

    with backend:
        # Apply initialization after backend initialization.
        # This matches the current runner/backend lifecycle.
        if len(init_list) > 0:
            _apply_named_values(backend, init_list)
        if len(param_list):
            _apply_named_values(backend, param_list)

        output_names = _resolve_output_names(scn, backend, component_cfg)

        t = t0
        eps = max(1e-12, abs(dt) * 1e-12)

        while t <= tf + eps:
            input_values = evaluate_inputs(input_defs, t)
            if input_values:
                _apply_named_values(backend, input_values)

            row = {"time": float(t)}
            for name in output_names:
                row[name] = backend.get_variable(name)
            records.append(row)

            if t + dt > tf + eps:
                break

            step_result = backend.step(t=t, dt=dt)
            if not step_result.accepted:
                return {
                    "status": "stopped_early",
                    "composition": "single",
                    "backend": backend_name,
                    "fmu_type": fmu_type,
                    "component": component_cfg,
                    "records": records,
                    "metadata": {
                        "t0": t0,
                        "tf": tf,
                        "dt": dt,
                        "accepted_steps": accepted_steps,
                        "stop_reason": step_result.message,
                    },
                }

            accepted_steps += 1
            t = float(step_result.t)

    return {
        "status": "success",
        "composition": "single",
        "backend": backend_name,
        "fmu_type": fmu_type,
        "component": component_cfg,
        "records": records,
        "metadata": {
            "t0": t0,
            "tf": tf,
            "dt": dt,
            "accepted_steps": accepted_steps,
            "recorded_outputs": output_names,
            "artifact": backend.artifact,
        },
    }