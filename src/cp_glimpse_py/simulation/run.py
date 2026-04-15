"""
cp_glimpse_py.simulation.run
=================================
Top-level simulation dispatcher.

Purpose
-------
This module provides the main public entry points for the simulation package.

It is responsible for:
- loading a scenario from file or accepting a preloaded dictionary,
- resolving simulation composition, experiment type, backend,
- dispatching execution,
- saving results and summary artifacts.
"""

from __future__ import annotations

from dataclasses import asdict, is_dataclass
from pathlib import Path
from typing import Any
import json
import time

from ..common import get_paths, get_logger
from ..scenario import Scenario, load_scenario
from ..scenario import resolve_composition, resolve_backend, resolve_experiment, count_valid_models
from .experiments import run_single_experiment
from .experiments import run_monte_carlo_experiment

log = get_logger(__name__)


def _json_ready(obj: Any) -> Any:
    """
    Convert an object into a JSON-serializable form when possible.

    Parameters
    ----------
    obj : Any
        Input object.

    Returns
    -------
    Any
        JSON-ready object.
    """
    if is_dataclass(obj):
        return asdict(obj)
    if isinstance(obj, Path):
        return str(obj)
    if isinstance(obj, dict):
        return {str(k): _json_ready(v) for k, v in obj.items()}
    if isinstance(obj, list):
        return [_json_ready(v) for v in obj]
    return obj


def _default_output_dir(scn: dict[str, Any], scenario_path: Path | None = None) -> Path:
    """
    Get a default output directory for one simulation execution.

    Parameters
    ----------
    scn : dict[str, Any]
        Scenario dictionary.
    scenario_path : Path | None
        Original scenario file path, if available.

    Returns
    -------
    Path
        Output directory path.

    Notes
    -----
    This function tries to be compatible with a `get_paths()` helper but
    remains conservative. If your project's `get_paths()` returns a richer
    object, you can customize this function accordingly.
    """
    paths = get_paths()

    # Common pattern: a project root or results root is available from get_paths().
    # We defensively support both styles.
    results_root = getattr(paths, "results_dir", None)
    if results_root is None:
        results_root = getattr(paths, "results", None)
    if results_root is None:
        results_root = Path("results")

    results_root = Path(results_root)

    scenario_stem = "inline_scenario"
    if scenario_path is not None:
        scenario_stem = scenario_path.stem

    # 여기 고칠 것
    # paths = get_paths()
    # results_root = getattr(paths, "results_runs", None)
    # if results_root is None:
    #     results_root = getattr(paths, "results", None)
    # if results_root is None:
    #     results_root = Path("results")

    # results_root = Path(results_root)

    # scenario_stem = "inline_scenario"
    # if scenario_path is not None:
    #     scenario_stem = scenario_path.stem


    return results_root / "simulation_runs" / scenario_stem


def _save_json(data: Any, path: Path) -> None:
    """
    Save a JSON artifact.

    Parameters
    ----------
    data : Any
        JSON-serializable object.
    path : Path
        Output file path.
    """
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(json.dumps(_json_ready(data), indent=2), encoding="utf-8")


def _build_summary(
    scn: dict[str, Any],
    scenario_path: Path | None,
    composition: str,
    experiment: str,
    result: dict[str, Any],
    wall_time_sec: float,
) -> dict[str, Any]:

    """
    Build a compact summary artifact for quick inspection.

    Parameters
    ----------
    scn : dict[str, Any]
        Scenario dictionary.
    scenario_path : Path | None
        Scenario path if loaded from file.
    composition : str
        Resolved composition.
    experiment : str
        Resolved experiment type.
    result : dict[str, Any]
        Full result object.
    wall_time_sec : float
        End-to-end elapsed time.

    Returns
    -------
    dict[str, Any]
        Summary dictionary.
    """
    summary: dict[str, Any] = {
        "status": result.get("status", "unknown"),
        "composition": composition,
        "experiment": experiment,
        "wall_time_sec": wall_time_sec,
        "scenario_path": str(scenario_path) if scenario_path else None,
    }

    if experiment == "single":
        inner = result.get("result", {})
        records = inner.get("records", [])
        if not records and isinstance(inner.get("result"), dict):
            records = inner["result"].get("records", []) or []
        summary["result_status"] = inner.get("status")
        summary["n_time_points"] = len(records)

    elif experiment == "montecarlo":
        summary["n_runs"] = result.get("n_runs")
        summary["n_success"] = result.get("n_success")
        summary["n_failed"] = result.get("n_failed")

    if "sim" in scn:
        summary["sim"] = scn["sim"]

    return summary


def _run_simulation_from_dict(
    scn: Scenario | dict[str, Any],
    *,
    scenario_path: Path | None = None,
    save_results: bool = True,
    output_dir: Path | None = None,
) -> dict[str, Any]:
    """
    Run a simulation from an already-loaded scenario dictionary.

    Parameters
    ----------
    scn : dict[str, Any]
        Loaded scenario dictionary.
    scenario_path : Path | None, optional
        Original scenario file path for metadata and default output location.
    save_results : bool, optional
        Whether to save result artifacts.
    output_dir : Path | None, optional
        Explicit output directory. If omitted, a default directory is derived.

    Returns
    -------
    dict[str, Any]
        Structured simulation result.

    Notes
    -----
    This is the main reusable entry point for internal Python callers.
    """
    t_wall_0 = time.time()

    experiment = resolve_experiment(scn)
    composition = resolve_composition(scn)
    backend = resolve_backend(scn)

    log.info("Resolved simulation composition: %s", composition)
    log.info("Resolved experiment type: %s", experiment)
    log.info("Resolved simulation backend: %s", backend)

    if experiment == "single":
        result_obj = run_single_experiment(scn, composition, backend)
    elif experiment == "montecarlo":                        # TODO: implement this experiment type
        result_obj = run_monte_carlo_experiment(scn, composition, backend)
    else:
        raise ValueError(f"Unhandled experiment type: {experiment}")

    result = _json_ready(result_obj)
    wall_time_sec = time.time() - t_wall_0
    result.setdefault("metadata", {})
    result["metadata"]["dispatch_wall_time_sec"] = wall_time_sec
    result["metadata"]["resolved_composition"] = composition
    result["metadata"]["resolved_experiment"] = experiment
    result["metadata"]["resolved_backend"] = backend

    if save_results:
        out_dir = Path(output_dir) if output_dir is not None else _default_output_dir(
            scn, scenario_path
        )

        summary = _build_summary(
            scn=scn,
            scenario_path=scenario_path,
            composition=composition,
            experiment=experiment,
            result=result,
            wall_time_sec=wall_time_sec,
        )

        _save_json(result, out_dir / "result.json")
        _save_json(summary, out_dir / "summary.json")
        _save_json(scn, out_dir / "scenario_resolved.json")

        result["artifact_dir"] = str(out_dir)
        log.info("Saved simulation artifacts to: %s", out_dir)

    return result



def run_simulation(
    scenario: str | Path | dict[str, Any],
    *,
    save_results: bool = True,
    output_dir: str | Path | None = None,
) -> dict[str, Any]:
    """
    Run a simulation from either a scenario file path or a scenario dictionary.

    Parameters
    ----------
    scenario : str | Path | dict[str, Any]
        Scenario YAML/JSON path or an already-loaded scenario dictionary.
    save_results : bool, optional
        Whether to save artifacts under the results directory.
    output_dir : str | Path | None, optional
        Explicit output directory for artifacts.

    Returns
    -------
    dict[str, Any]
        Structured simulation result.

    Examples
    --------
    Run from file:
        result = run_simulation("scenarios/rover_fmu.yaml")

    Run from dict:
        result = run_simulation({
            "sim": {"experiment": "single"},
            "system": {
                "components": [
                    {"name": "bouncing_ball", 
                     "class_name": "BouncingBall",
                     "model_path": "models/BouncingBall.mo"}
                ]
            },
        })
    """
    if isinstance(scenario, dict):
        scenario_path = None
        scn = scenario
    else:
        scenario_path = Path(scenario)
        scn = load_scenario(scenario_path)

    return _run_simulation_from_dict(
        scn,
        scenario_path=scenario_path,
        save_results=save_results,
        output_dir=Path(output_dir) if output_dir is not None else None,
    )