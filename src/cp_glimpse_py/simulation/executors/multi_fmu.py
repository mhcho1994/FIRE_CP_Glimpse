"""
Fixed-order multi-FMU execution backend.

This executor implements a deliberately simple master algorithm:
- instantiate one runner per component,
- apply scenario connections before each component step,
- propagate components in `sim.stepping.order`,
- record requested outputs.

It does not yet implement event-aware ME synchronization or adaptive macro-step
splitting. The structure is meant to leave room for that policy later.
"""

from __future__ import annotations

from pathlib import Path
from types import SimpleNamespace
from typing import Any
import ast
import time

from .single_fmu import (
    _apply_start_values_to_runner,
    _make_step_runner,
    _resolve_start_values,
)

_MODEL_HINT_KEYS = (
    "fmu_path",
    "mo_path",
    "class_name",
    "model_path",
    "model_file",
    "uri",
)


def _extract_model_identity(model_cfg: dict[str, Any]) -> dict[str, Any]:
    identity = {k: model_cfg.get(k) for k in _MODEL_HINT_KEYS if model_cfg.get(k)}
    if not identity:
        raise ValueError(
            "Each model in 'models' must contain at least one model identity field. "
            f"Expected one of: {', '.join(_MODEL_HINT_KEYS)}"
        )
    return identity


def _validate_optional_existing_paths(model_identity: dict[str, Any], model_name: str) -> None:
    for key in ("fmu_path", "mo_path", "model_path", "model_file"):
        value = model_identity.get(key)
        if not value:
            continue
        path = Path(value)
        if not path.exists():
            raise FileNotFoundError(
                f"Model file not found for model '{model_name}', field '{key}': {path}"
            )


def _resolve_time_config(sim_cfg: dict[str, Any]) -> tuple[float, float, float, float]:
    t0 = float(sim_cfg.get("t0", sim_cfg.get("start_time", 0.0)))
    tf = float(sim_cfg.get("tf", sim_cfg.get("stop_time", 1.0)))
    dt = float(sim_cfg.get("dt", sim_cfg.get("step_size", 0.1)))
    tol = float(sim_cfg.get("tol", sim_cfg.get("tolerance", 1.0e-6)))

    if tf < t0:
        raise ValueError(f"Invalid time range: tf ({tf}) < t0 ({t0}).")
    if dt <= 0.0:
        raise ValueError(f"dt must be positive, got {dt}.")
    if tol <= 0.0:
        raise ValueError(f"tol must be positive, got {tol}.")
    return t0, tf, dt, tol


def _resolve_fmu_path(model_name: str, model_cfg: dict[str, Any]) -> Path:
    for key in ("model_path", "fmu_path", "artifact_path"):
        value = model_cfg.get(key)
        if not value:
            continue
        path = Path(value)
        if not path.exists():
            raise FileNotFoundError(f"FMU artifact not found for model '{model_name}': {path}")
        if path.suffix.lower() != ".fmu":
            raise ValueError(f"Model '{model_name}' must resolve to an .fmu artifact: {path}")
        return path
    raise ValueError(f"Model '{model_name}' does not define model_path/fmu_path/artifact_path.")


def _resolve_step_order(models_cfg: dict[str, dict[str, Any]], sim_cfg: dict[str, Any]) -> list[str]:
    stepping = sim_cfg.get("stepping", {}) or {}
    order = stepping.get("order")
    if not order:
        return list(models_cfg.keys())

    normalized = [str(item) for item in order]
    unknown = [item for item in normalized if item not in models_cfg]
    if unknown:
        raise ValueError(f"sim.stepping.order references unknown models: {unknown}")
    return normalized


def _parse_endpoint(endpoint: str, model_names: set[str]) -> tuple[str, str]:
    endpoint = str(endpoint)
    for name in sorted(model_names, key=len, reverse=True):
        prefix = f"{name}."
        if endpoint.startswith(prefix):
            return name, endpoint[len(prefix):]
    raise ValueError(f"Connection endpoint does not start with a known component name: {endpoint}")


def _normalize_connections(
    connections: list[dict[str, Any]],
    model_names: set[str],
) -> list[dict[str, Any]]:
    normalized: list[dict[str, Any]] = []
    for item in connections:
        src = item.get("from", item.get("src"))
        dst = item.get("to", item.get("dst"))
        if not src or not dst:
            raise ValueError(f"Connection must define from/to or src/dst: {item}")

        src_model, src_var = _parse_endpoint(str(src), model_names)
        dst_model, dst_var = _parse_endpoint(str(dst), model_names)
        conn = {
            "src": str(src),
            "dst": str(dst),
            "src_model": src_model,
            "src_var": src_var,
            "dst_model": dst_model,
            "dst_var": dst_var,
        }
        if "nominal_override" in item:
            conn["nominal_override"] = item["nominal_override"]
        normalized.append(conn)
    return normalized


def _namespace(obj: Any) -> Any:
    if isinstance(obj, dict):
        return SimpleNamespace(**{k: _namespace(v) for k, v in obj.items()})
    return obj


def _safe_eval_expr(expr: str, scn: dict[str, Any]) -> Any:
    tree = ast.parse(expr, mode="eval")
    allowed_nodes = (
        ast.Expression,
        ast.BinOp,
        ast.UnaryOp,
        ast.Add,
        ast.Sub,
        ast.Mult,
        ast.Div,
        ast.Pow,
        ast.USub,
        ast.UAdd,
        ast.Constant,
        ast.Name,
        ast.Load,
        ast.Attribute,
    )
    for node in ast.walk(tree):
        if not isinstance(node, allowed_nodes):
            raise ValueError(f"Unsupported expression in scenario value: {expr}")

    env = {
        "sim": _namespace(scn.get("sim", {}) or {}),
        "params": _namespace(scn.get("params", {}) or {}),
        "parameters": _namespace(scn.get("parameters", {}) or {}),
    }
    return eval(compile(tree, "<scenario-value>", "eval"), {"__builtins__": {}}, env)


def _resolve_scenario_value(value: Any, scn: dict[str, Any]) -> Any:
    if not isinstance(value, str):
        return value
    if value.startswith(("sim.", "params.", "parameters.")) or any(op in value for op in "+-*/"):
        return _safe_eval_expr(value, scn)
    return value


def _apply_per_step_parameters(
    *,
    runner: Any,
    model_name: str,
    scn: dict[str, Any],
) -> None:
    params_cfg = scn.get("parameters", {}) or {}
    per_step = params_cfg.get("per_step", {}) or {}
    model_params = per_step.get(model_name, {}) or {}
    if not isinstance(model_params, dict):
        return
    for var_name, raw_value in model_params.items():
        runner.set_value(str(var_name), _resolve_scenario_value(raw_value, scn))


def _apply_incoming_connections(
    *,
    model_name: str,
    runners: dict[str, Any],
    incoming: dict[str, list[dict[str, Any]]],
    scn: dict[str, Any],
) -> None:
    for conn in incoming.get(model_name, []):
        if "nominal_override" in conn:
            value = _resolve_scenario_value(conn["nominal_override"], scn)
        else:
            value = runners[conn["src_model"]].get_value(conn["src_var"])
        try:
            dst_runner = runners[conn["dst_model"]]
            if hasattr(dst_runner, "set_input_value") and dst_runner.is_input(conn["dst_var"]):
                dst_runner.set_input_value(conn["dst_var"], value)
            else:
                dst_runner.set_value(conn["dst_var"], value)
        except Exception as exc:
            raise RuntimeError(
                "Failed to apply connection "
                f"{conn['src']} -> {conn['dst']} with value {value!r}."
            ) from exc


def _resolve_output_endpoints(
    scn: dict[str, Any],
    models_cfg: dict[str, dict[str, Any]],
    connections: list[dict[str, Any]],
) -> list[tuple[str, str, str]]:
    output_cfg = scn.get("outputs", scn.get("output", {})) or {}
    explicit = output_cfg.get("log")
    model_names = set(models_cfg)

    endpoints: list[str]
    if isinstance(explicit, list) and explicit:
        endpoints = [str(item) for item in explicit]
    else:
        endpoints = sorted({conn["src"] for conn in connections})

    resolved: list[tuple[str, str, str]] = []
    for endpoint in endpoints:
        model_name, var_name = _parse_endpoint(endpoint, model_names)
        resolved.append((endpoint, model_name, var_name))
    return resolved


def _record_outputs(
    *,
    runners: dict[str, Any],
    output_endpoints: list[tuple[str, str, str]],
    outputs: dict[str, list[Any]],
) -> None:
    for endpoint, model_name, var_name in output_endpoints:
        outputs.setdefault(endpoint, []).append(runners[model_name].get_value(var_name, None))


def _make_progress_bar(*, enabled: bool, style: str, total: int, desc: str):
    if not enabled or style != "tqdm":
        return None

    try:
        from tqdm.auto import tqdm
    except ImportError:
        return None

    return tqdm(total=total, desc=desc, unit="step", leave=True)


def run_multi_fmu_open_loop(scn: dict[str, Any]) -> dict[str, Any]:
    """
    Execute a fixed-order multi-FMU scenario.
    """
    models_cfg = scn.get("models")
    if not isinstance(models_cfg, dict) or not models_cfg:
        raise ValueError("Multi-model scenario must contain a non-empty 'models' section.")

    sim_cfg = scn.get("sim", {}) or {}
    backend = str(sim_cfg.get("backend", "fmu-fmpy")).lower()
    fmu_type_default = str(sim_cfg.get("fmu_type", "cs")).lower()
    t0, tf, dt, tol = _resolve_time_config(sim_cfg)
    step_order = _resolve_step_order(models_cfg, sim_cfg)
    show_solver_log = bool(sim_cfg.get("show_solver_log", False))
    show_progress = bool(sim_cfg.get("show_progress", not show_solver_log))
    progress_style = str(sim_cfg.get("progress_style", "tqdm")).strip().lower()

    resolved_models: dict[str, dict[str, Any]] = {}
    for model_name, cfg in models_cfg.items():
        if not isinstance(cfg, dict) or not cfg:
            raise ValueError(f"Model '{model_name}' configuration must be a non-empty dict.")
        model_identity = _extract_model_identity(cfg)
        _validate_optional_existing_paths(model_identity, model_name)
        resolved_models[model_name] = {**cfg, **model_identity}

    connections = _normalize_connections(scn.get("connections", []) or [], set(resolved_models))
    incoming: dict[str, list[dict[str, Any]]] = {}
    for conn in connections:
        incoming.setdefault(conn["dst_model"], []).append(conn)

    output_endpoints = _resolve_output_endpoints(scn, resolved_models, connections)
    outputs = {endpoint: [] for endpoint, _, _ in output_endpoints}
    time_grid: list[float] = []

    runners: dict[str, Any] = {}
    progress_bar = None
    t_wall_0 = time.time()

    try:
        for model_name, cfg in resolved_models.items():
            fmu_path = _resolve_fmu_path(model_name, cfg)
            fmu_type = str(cfg.get("fmu_type", fmu_type_default)).lower()
            runner = _make_step_runner(
                backend=backend,
                fmu_path=fmu_path,
                component_name=model_name,
                t0=t0,
                tf=tf,
                tol=tol,
                fmu_type=fmu_type,
                show_solver_log=bool(cfg.get("show_solver_log", show_solver_log)),
            )
            _apply_start_values_to_runner(runner, _resolve_start_values(cfg))
            runner.instantiate_and_initialize()
            runners[model_name] = runner

        n_steps = int(round((tf - t0) / dt))
        progress_bar = _make_progress_bar(
            enabled=show_progress,
            style=progress_style,
            total=n_steps,
            desc="simulation progress",
        )
        t = t0
        time_grid.append(t)
        _record_outputs(runners=runners, output_endpoints=output_endpoints, outputs=outputs)

        for _ in range(n_steps):
            for model_name in step_order:
                runner = runners[model_name]
                if progress_bar is not None:
                    progress_bar.set_postfix_str(f"{model_name} t={t + dt:.6g}/{tf:.6g}s")

                _apply_incoming_connections(
                    model_name=model_name,
                    runners=runners,
                    incoming=incoming,
                    scn=scn,
                )

                _apply_per_step_parameters(runner=runner, model_name=model_name, scn=scn)
                runner.step_or_raise(t, dt)

            t = t + dt
            if progress_bar is not None:
                progress_bar.set_postfix_str(f"completed t={t:.6g}/{tf:.6g}s")
                progress_bar.update(1)
            elif show_progress:
                print(f"[simulation progress] t={t:.6g}/{tf:.6g}s")
            time_grid.append(t)
            _record_outputs(runners=runners, output_endpoints=output_endpoints, outputs=outputs)

    finally:
        if progress_bar is not None:
            progress_bar.close()
        for runner in runners.values():
            runner.terminate_and_free()

    return {
        "status": "success",
        "topology": "multi_fmu",
        "models": resolved_models,
        "connections": connections,
        "time": time_grid,
        "outputs": outputs,
        "metadata": {
            "t0": t0,
            "tf": tf,
            "dt": dt,
            "tol": tol,
            "backend": backend,
            "step_order": step_order,
            "wall_time_sec": time.time() - t_wall_0,
            "executor": "run_multi_fmu_open_loop",
            "n_models": len(resolved_models),
            "n_connections": len(connections),
        },
    }
