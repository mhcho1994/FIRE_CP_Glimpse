"""
Single-FMU execution backend.

Purpose
-------
This module implements the low-level execution path for a scenario whose
simulation composition is `single`. The scenario is expected to contain
exactly one component under `system.components`.

Design
------
This backend assumes the scenario has already been materialized into an
FMU-ready form when necessary. In other words:

- if the original component pointed to a `.mo` file, an earlier stage
  (for example `materialize_single_component(...)`) should have converted
  it into an FMU and updated the component config accordingly,
- if the component already points to an `.fmu`, this backend executes it
  directly.

Responsibilities
----------------
This module is intentionally narrow in scope:
- validate single-component execution inputs,
- resolve the single component identity,
- validate simulation time configuration,
- execute one FMU backend,
- return a stable result dictionary.

Non-responsibilities
--------------------
This module should not:
- decide experiment type (`single`, Monte Carlo, etc.),
- decide simulation composition (`single`, `network`, etc.),
- build FMUs from source models on its own.

That orchestration belongs to higher-level experiment / materialization
layers.

Expected scenario pattern
-------------------------
A typical single-component scenario is expected to look like:

{
    "sim": {
        "composition": "single",
        "backend": "fmu-fmpy",
        "fmu_type": "cs",
        "t0": 0.0,
        "tf": 1.0,
        "dt": 0.01,
        "tol": 1e-6
    },
    "system": {
        "components": [
            {
                "name": "bouncing_ball",
                "class_name": "BouncingBall",
                "model_path": "build/fmus/BouncingBall.fmu"
            }
        ]
    }
}

Supported component identity fields
-----------------------------------
This backend recognizes the following component fields for locating the FMU:

- `model_path`
- `fmu_path`
- `artifact_path`

At execution time, at least one of these must resolve to an existing `.fmu`
file.

Returned schema
---------------
{
    "status": "success",
    "composition": "single",
    "backend": "fmu-fmpy",
    "fmu_type": "cs",
    "component": {...},
    "time": [...],
    "inputs": {...},
    "outputs": {...},
    "metadata": {...}
}
"""

from __future__ import annotations

import math
from pathlib import Path
from typing import Any

import time

from ..inputs import InputProvider, create_input_provider


_COMPONENT_PATH_KEYS = (
    "model_path",
    "fmu_path",
    "artifact_path",
)


def _get_sim_cfg(scn: dict[str, Any]) -> dict[str, Any]:
    """
    Return normalized simulation config.

    Parameters
    ----------
    scn : dict[str, Any]
        Loaded scenario.

    Returns
    -------
    dict[str, Any]
        Simulation configuration dictionary.
    """
    sim_cfg = scn.get("sim", {}) or {}
    if not isinstance(sim_cfg, dict):
        raise ValueError("'sim' must be a dictionary if provided.")
    return sim_cfg


def _get_single_component(scn: dict[str, Any]) -> dict[str, Any]:
    """
    Resolve exactly one component from `system.components`.

    Parameters
    ----------
    scn : dict[str, Any]
        Loaded scenario.

    Returns
    -------
    dict[str, Any]
        The single component configuration.

    Raises
    ------
    ValueError
        If `system.components` is missing, malformed, or does not contain
        exactly one component.
    """
    system_cfg = scn.get("system", {}) or {}
    if not isinstance(system_cfg, dict):
        raise ValueError("'system' must be a dictionary if provided.")

    components = system_cfg.get("components")
    if not isinstance(components, list) or not components:
        raise ValueError(
            "Single-FMU execution requires 'system.components' to be a non-empty list."
        )

    if len(components) != 1:
        raise ValueError(
            "Single-FMU execution requires exactly one component under "
            f"'system.components', but got {len(components)}."
        )

    component = components[0]
    if not isinstance(component, dict) or not component:
        raise ValueError("The single component entry must be a non-empty dictionary.")

    return component


def _resolve_backend(sim_cfg: dict[str, Any]) -> str:
    """
    Resolve execution backend name.

    Parameters
    ----------
    sim_cfg : dict[str, Any]
        Scenario simulation config.

    Returns
    -------
    str
        Normalized backend identifier.
    """
    return str(sim_cfg.get("backend", "fmu-fmpy")).strip().lower()


def _resolve_fmu_type(sim_cfg: dict[str, Any]) -> str:
    """
    Resolve requested FMU type.

    Parameters
    ----------
    sim_cfg : dict[str, Any]
        Scenario simulation config.

    Returns
    -------
    str
        Normalized FMU type (`cs` or `me`).

    Raises
    ------
    ValueError
        If the type is unsupported.
    """
    fmu_type = str(sim_cfg.get("fmu_type", "cs")).strip().lower()
    if fmu_type not in {"cs", "me"}:
        raise ValueError(f"Unsupported fmu_type '{fmu_type}'. Expected 'cs' or 'me'.")
    return fmu_type


def _validate_time_config(sim_cfg: dict[str, Any]) -> tuple[float, float, float, float]:
    """
    Validate and normalize simulation time settings.

    Parameters
    ----------
    sim_cfg : dict[str, Any]
        Scenario simulation config.

    Returns
    -------
    tuple[float, float, float, float]
        `(t0, tf, dt, tol)`

    Raises
    ------
    ValueError
        If time settings are invalid.
    """
    t0 = float(sim_cfg.get("t0", 0.0))
    tf = float(sim_cfg.get("tf", 1.0))
    dt = float(sim_cfg.get("dt", 0.01))
    tol = float(sim_cfg.get("tol", 1.0e-6))

    if tf < t0:
        raise ValueError(f"Invalid time range: tf ({tf}) < t0 ({t0}).")
    if dt <= 0.0:
        raise ValueError(f"dt must be positive, got {dt}.")
    if tol <= 0.0:
        raise ValueError(f"tol must be positive, got {tol}.")

    return t0, tf, dt, tol


def _resolve_fmu_path(component_cfg: dict[str, Any]) -> Path:
    """
    Resolve the FMU artifact path from a component config.

    Parameters
    ----------
    component_cfg : dict[str, Any]
        Single component configuration.

    Returns
    -------
    Path
        Resolved existing FMU path.

    Raises
    ------
    ValueError
        If no supported path field is present.
    FileNotFoundError
        If the resolved path does not exist.
    ValueError
        If the resolved file is not an FMU.
    """
    for key in _COMPONENT_PATH_KEYS:
        value = component_cfg.get(key)
        if not value:
            continue

        path = Path(value)
        if not path.exists():
            raise FileNotFoundError(f"FMU artifact not found for '{key}': {path}")

        if path.suffix.lower() != ".fmu":
            raise ValueError(
                f"Single-FMU executor expects an FMU artifact, but '{key}' "
                f"resolved to a non-FMU path: {path}"
            )

        return path

    raise ValueError(
        "Single component must contain an FMU artifact path in one of: "
        f"{', '.join(_COMPONENT_PATH_KEYS)}"
    )


def _resolve_output_names(
    model_description: Any,
    component_cfg: dict[str, Any],
) -> list[str]:
    """
    Resolve which variables to record as outputs.

    Resolution order
    ----------------
    1. `component_cfg["outputs"]` if explicitly provided,
    2. model variables with causality == "output",
    3. empty list if none found.

    Parameters
    ----------
    model_description : Any
        FMPy model description object.
    component_cfg : dict[str, Any]
        Single component configuration.

    Returns
    -------
    list[str]
        Output variable names.
    """
    explicit = component_cfg.get("outputs")
    if isinstance(explicit, list) and explicit:
        return [str(x) for x in explicit]

    output_names: list[str] = []
    for var in model_description.modelVariables:
        if getattr(var, "causality", None) == "output":
            output_names.append(var.name)

    return output_names


def _resolve_start_values(component_cfg: dict[str, Any]) -> dict[str, Any]:
    """
    Extract FMU start values from the component config.

    Supported aliases
    -----------------
    - `start_values`
    - `parameters`

    Parameters
    ----------
    component_cfg : dict[str, Any]
        Single component configuration.

    Returns
    -------
    dict[str, Any]
        Start-value dictionary.
    """
    resolved: dict[str, Any] = {}
    parameters = component_cfg.get("parameters")
    if isinstance(parameters, dict):
        resolved.update(parameters)

    start_values = component_cfg.get("start_values")
    if isinstance(start_values, dict):
        resolved.update(start_values)

    return resolved


def _fmpy_input_signal(
    model_description: Any,
    input_provider: InputProvider,
) -> Any:
    """Convert an input provider to the structured signal array FMPy expects."""
    if not input_provider.input_names:
        return None

    import numpy as np

    variables = {var.name: var for var in model_description.modelVariables}
    dtype_by_fmi_type = {
        "Real": np.float64,
        "Float32": np.float32,
        "Float64": np.float64,
        "Integer": np.int32,
        "Enumeration": np.int32,
        "Boolean": np.bool_,
    }
    dtype = [("time", np.float64)]
    for name in input_provider.input_names:
        variable = variables.get(name)
        if variable is None:
            raise ValueError(f"Unknown FMU input in scenario inputs: {name!r}.")
        if getattr(variable, "causality", None) != "input":
            raise ValueError(f"Scenario input {name!r} is not an FMU input.")
        fmi_type = getattr(variable, "type", None)
        if fmi_type not in dtype_by_fmi_type:
            raise ValueError(f"Unsupported FMI input type for {name!r}: {fmi_type!r}.")
        dtype.append((name, dtype_by_fmi_type[fmi_type]))

    times, values = input_provider.signal_points()
    signal = np.empty(len(times), dtype=dtype)
    signal["time"] = times
    for name in input_provider.input_names:
        signal[name] = values[name]

    return signal


def _structured_to_dict_array(result: Any) -> dict[str, list[Any]]:
    """
    Convert FMPy structured simulation result into a JSON-friendly dict.

    Parameters
    ----------
    result : Any
        Return value from `simulate_fmu(...)`, typically a structured NumPy array.

    Returns
    -------
    dict[str, list[Any]]
        Mapping from field name to Python list.
    """
    if result is None:
        return {}

    dtype = getattr(result, "dtype", None)
    names = getattr(dtype, "names", None)
    if not names:
        return {}

    outputs: dict[str, list[Any]] = {}
    for name in names:
        outputs[name] = result[name].tolist()
    return outputs


def _sample_input_provider(
    input_provider: InputProvider,
    time_values: list[float],
) -> dict[str, list[Any]]:
    """Sample scenario inputs on the result time grid for artifact logging."""
    recorded = {name: [] for name in input_provider.input_names}
    for t in time_values:
        values = input_provider.value_at(float(t))
        for name in input_provider.input_names:
            recorded[name].append(values[name])
    return recorded


def _simulate_with_fmpy(
    fmu_path: Path,
    *,
    t0: float,
    tf: float,
    dt: float,
    tol: float,
    fmu_type: str,
    component_cfg: dict[str, Any],
    input_provider: InputProvider,
) -> dict[str, Any]:
    """
    Execute an FMU using FMPy.

    Parameters
    ----------
    fmu_path : Path
        FMU artifact path.
    t0 : float
        Start time.
    tf : float
        Final time.
    dt : float
        Communication / output step size.
    tol : float
        Solver tolerance.
    fmu_type : str
        `cs` or `me`.
    component_cfg : dict[str, Any]
        Single component configuration.

    Returns
    -------
    dict[str, Any]
        Output dictionary with time and recorded variables.
    """
    from fmpy import simulate_fmu, read_model_description

    model_description = read_model_description(str(fmu_path))
    output_names = _resolve_output_names(model_description, component_cfg)
    start_values = _resolve_start_values(component_cfg)
    input_signal = _fmpy_input_signal(
        model_description,
        input_provider,
    )

    result = simulate_fmu(
        filename=str(fmu_path),
        start_time=t0,
        stop_time=tf,
        step_size=dt,
        output_interval=dt,
        record_events=True,
        start_values=start_values or {},
        input=input_signal,
        output=output_names if output_names else None,
        solver="CVode" if fmu_type == "me" else None,
        relative_tolerance=tol,
        fmi_type="ModelExchange" if fmu_type == "me" else "CoSimulation",
    )

    outputs = _structured_to_dict_array(result)

    time_values = outputs.pop("time", None)
    if time_values is None:
        raise RuntimeError("FMPy result did not contain a 'time' field.")

    return {
        "time": time_values,
        "inputs": _sample_input_provider(input_provider, time_values),
        "outputs": outputs,
        "output_names": output_names,
        "start_values": start_values,
        "input_description": input_provider.describe(),
        "model_description": model_description,
    }


def _make_step_runner(
    *,
    backend: str,
    fmu_path: Path,
    component_name: str,
    t0: float,
    tf: float,
    tol: float,
    fmu_type: str,
    show_solver_log: bool = False,
):
    """
    Create a backend-specific fixed-step runner.

    The returned object provides a small common surface:
    `set_value(name, value)`, `get_value(name)`, `step_or_raise(t, dt)`,
    `instantiate_and_initialize()`, and `terminate_and_free()`.
    """
    from ...backend.fmu_runner import create_fmu_runner

    return create_fmu_runner(
        backend=backend,
        fmu_path=fmu_path,
        instance_name=component_name,
        fmu_type=fmu_type,
        start_time=t0,
        stop_time=tf,
        tolerance=tol,
        show_solver_log=show_solver_log,
        debug_logging=False,
    )


def _apply_start_values_to_runner(runner: Any, start_values: dict[str, Any]) -> None:
    for name, value in start_values.items():
        runner.set_value(str(name), value)


def _apply_inputs_to_runner(runner: Any, values: dict[str, Any]) -> None:
    """Apply external inputs using the same runner API as multi-FMU execution."""
    for name, value in values.items():
        if hasattr(runner, "set_input_value") and runner.is_input(name):
            runner.set_input_value(name, value)
        else:
            runner.set_value(name, value)


def _runner_output_names(runner: Any, component_cfg: dict[str, Any]) -> list[str]:
    explicit = component_cfg.get("outputs")
    if isinstance(explicit, list) and explicit:
        return [str(x) for x in explicit]

    io = getattr(runner, "io", {}) or {}
    outputs = io.get("outputs", []) or []
    return [str(getattr(v, "name", v)) for v in outputs]


def _make_progress_bar(*, enabled: bool, style: str, total: int, desc: str):
    if not enabled or style != "tqdm":
        return None

    try:
        from tqdm.auto import tqdm
    except ImportError:
        return None

    return tqdm(total=total, desc=desc, unit="step", leave=True)


def _simulate_with_step_runner(
    fmu_path: Path,
    *,
    backend: str,
    t0: float,
    tf: float,
    dt: float,
    tol: float,
    fmu_type: str,
    component_cfg: dict[str, Any],
    input_provider: InputProvider,
    show_solver_log: bool = False,
    show_progress: bool = False,
    progress_style: str = "tqdm",
) -> dict[str, Any]:
    component_name = str(component_cfg.get("name", fmu_path.stem))
    start_values = _resolve_start_values(component_cfg)
    runner = _make_step_runner(
        backend=backend,
        fmu_path=fmu_path,
        component_name=component_name,
        t0=t0,
        tf=tf,
        tol=tol,
        fmu_type=fmu_type,
        show_solver_log=show_solver_log,
    )

    progress_bar = None
    try:
        _apply_start_values_to_runner(runner, start_values)
        _apply_inputs_to_runner(runner, input_provider.value_at(t0))
        runner.instantiate_and_initialize()

        output_names = _runner_output_names(runner, component_cfg)
        outputs = {name: [] for name in output_names}
        time_values: list[float] = []

        step_ratio = (tf - t0) / dt
        # Avoid an extra step when an integral ratio rounds one ULP above an integer.
        n_steps = int(math.ceil(math.nextafter(step_ratio, -math.inf)))
        progress_bar = _make_progress_bar(
            enabled=show_progress,
            style=progress_style,
            total=n_steps,
            desc=f"single_fmu:{component_name}",
        )
        time_values.append(t0)
        for name in output_names:
            outputs[name].append(runner.get_value(name, None))

        for step_index in range(n_steps):
            current_t = t0 + step_index * dt
            next_t = min(t0 + (step_index + 1) * dt, tf)
            step_dt = next_t - current_t

            _apply_inputs_to_runner(runner, input_provider.value_at(current_t))
            runner.step_or_raise(current_t, step_dt)
            if progress_bar is not None:
                progress_bar.set_postfix_str(f"t={next_t:.6g}/{tf:.6g}s")
                progress_bar.update(1)
            elif show_progress:
                print(f"[single_fmu] {component_name}: t={next_t:.6g}/{tf:.6g}s")
            time_values.append(next_t)
            for name in output_names:
                outputs[name].append(runner.get_value(name, None))

        return {
            "time": time_values,
            "inputs": _sample_input_provider(input_provider, time_values),
            "outputs": outputs,
            "output_names": output_names,
            "start_values": start_values,
            "input_description": input_provider.describe(),
            "model_description": None,
        }
    finally:
        if progress_bar is not None:
            progress_bar.close()
        runner.terminate_and_free()


def run_single_fmu_open_loop(scn: dict[str, Any]) -> dict[str, Any]:
    """
    Execute a single-component FMU scenario.

    Parameters
    ----------
    scn : dict[str, Any]
        Fully loaded and already materialized scenario dictionary.

    Returns
    -------
    dict[str, Any]
        Structured execution result.

    Raises
    ------
    ValueError
        If required configuration is missing or invalid.
    FileNotFoundError
        If the FMU artifact does not exist.

    Notes
    -----
    This executor is intentionally open-loop and single-component only.

    Assumptions
    -----------
    - `sim.composition` is conceptually `single`,
    - `system.components` contains exactly one component,
    - that component already resolves to an FMU artifact,
    - backend is currently `fmu-fmpy`.
    """
    sim_cfg = _get_sim_cfg(scn)
    component_cfg = _get_single_component(scn)

    backend = _resolve_backend(sim_cfg)
    if backend not in {"fmu-fmpy", "fmu-pyfmi"}:
        raise ValueError(
            f"Unsupported backend '{backend}' for single FMU execution. "
            "Currently supported backends: 'fmu-fmpy', 'fmu-pyfmi'."
        )

    fmu_type = _resolve_fmu_type(sim_cfg)
    t0, tf, dt, tol = _validate_time_config(sim_cfg)
    fmu_path = _resolve_fmu_path(component_cfg)
    input_provider = create_input_provider(
        scn.get("inputs", {}),
        t0=t0,
        tf=tf,
    )
    show_solver_log = bool(
        sim_cfg.get("show_solver_log", component_cfg.get("show_solver_log", False))
    )
    show_progress = bool(sim_cfg.get("show_progress", not show_solver_log))
    progress_style = str(sim_cfg.get("progress_style", "tqdm")).strip().lower()

    wall_t0 = time.time()

    if backend == "fmu-fmpy" and fmu_type == "me":
        sim_result = _simulate_with_fmpy(
            fmu_path=fmu_path,
            t0=t0,
            tf=tf,
            dt=dt,
            tol=tol,
            fmu_type=fmu_type,
            component_cfg=component_cfg,
            input_provider=input_provider,
        )
    else:
        sim_result = _simulate_with_step_runner(
            fmu_path=fmu_path,
            backend=backend,
            t0=t0,
            tf=tf,
            dt=dt,
            tol=tol,
            fmu_type=fmu_type,
            component_cfg=component_cfg,
            input_provider=input_provider,
            show_solver_log=show_solver_log,
            show_progress=show_progress,
            progress_style=progress_style,
        )

    wall_time_sec = time.time() - wall_t0

    return {
        "status": "success",
        "composition": "single",
        "backend": backend,
        "fmu_type": fmu_type,
        "component": {
            **component_cfg,
            "resolved_fmu_path": str(fmu_path),
        },
        "time": sim_result["time"],
        "inputs": sim_result["inputs"],
        "outputs": sim_result["outputs"],
        "metadata": {
            "t0": t0,
            "tf": tf,
            "dt": dt,
            "tol": tol,
            "wall_time_sec": wall_time_sec,
            "executor": "run_single_fmu_open_loop",
            "recorded_inputs": list(sim_result["inputs"]),
            "recorded_outputs": sim_result["output_names"],
            "applied_start_values": sim_result["start_values"],
            "applied_inputs": sim_result["input_description"],
            "model_name": getattr(sim_result["model_description"], "modelName", None),
            "fmi_version": getattr(sim_result["model_description"], "fmiVersion", None),
        },
    }
