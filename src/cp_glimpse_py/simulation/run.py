"""
cp_glimpse_py.simulation.run
=================================
Top-level simulation dispatcher.

Purpose
-------
This module provides the main public entry points for the simulation package.

It is responsible for:
- loading a scenario from file or accepting a preloaded dictionary,
- resolving simulation composition,
- resolving experiment type,
- dispatching execution,
- saving results and summary artifacts.

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
- sim.experimenht == "sensitivity" -> TODO: implement this experiment type
- sim.experiment == "sweep": TODO: implement this experiment type
- sim.experiment not provided: default to "single"
"""

from __future__ import annotations

from dataclasses import asdict, is_dataclass
from pathlib import Path
from typing import Any
import json
import time

from ..common import get_paths, get_logger
from ..scenario import Scenario, load_scenario
from .experiments import run_single_experiment
from .experiments import run_monte_carlo_experiment

log = get_logger(__name__)

_MODEL_HINT_KEYS = (
    "class_name",
    "model_path",
    "fmu_path",
    "artifact_path",
    "model_file",
    "uri",
)

_VALID_BACKENDS = (
    "fmu-fmpy",
    # "fmu-pyfmi",  # TODO: implement this backend
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


def _count_valid_models(models_cfg: Any) -> int:
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
    if not isinstance(models_cfg, list):
        return 0
    
    count = 0
    for _, model_cfg in enumerate(models_cfg):
        if _has_model_identity(model_cfg):
            count += 1
    
    if count == 0:
        log.error(
            "[cp_glimpse_py.simulation.run] No valid model entries found in 'models'. "
            "Expected at least one entry with a recognizable model identity field."
        )
        raise ValueError(
            "No valid model entries found in 'system.components'. "
            f"Expected at least one entry with one of: {', '.join(_MODEL_HINT_KEYS)}"
        )

    return count


def _resolve_experiment(scn: Scenario | dict[str, Any]) -> str:
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

    log.error("[cp_glimpse_py.simulation.run] Unsupported experiment type: %s", experiment)
    raise ValueError(f"Unsupported experiment type: {experiment}")


def _resolve_composition(scn: Scenario | dict[str, Any]) -> str:
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
        log.error("[cp_glimpse_py.simulation.run] Unsupported sim.composition: %s", explicit)
        raise ValueError(f"Unsupported sim.composition: {explicit}")

    system_cfg = scn.get("system", {}) or {}
    components = system_cfg.get("components")
    n_components = _count_valid_models(components)
    inferred = "single" if n_components == 1 else "multi"

    if explicit == "auto":
        return inferred

    if explicit != inferred:
        log.warning(
            "[cp_glimpse_py.simulation.run] sim.composition='%s' conflicts with "
            "system.components count=%d (inferred: '%s'). Using explicit value.",
            explicit,
            n_components,
            inferred
        )
    return explicit


def _resolve_backend(scn: Scenario | dict[str, Any]) -> str:
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

    log.error("[cp_glimpse_py.simulation.run] Could not resolve simulation backend. "
              "Provide sim.backend explicitly or use a valid backend. "
              f"Valid backends: {', '.join(_VALID_BACKENDS)}")
    raise ValueError(
        "Could not resolve simulation backend. "
        f"Valid backends: {', '.join(_VALID_BACKENDS)}"
    )


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

    experiment = _resolve_experiment(scn)
    composition = _resolve_composition(scn)
    backend = _resolve_backend(scn)

    log.info("[cp_glimpse_py.simulation.run] Resolved simulation composition: %s", composition)
    log.info("[cp_glimpse_py.simulation.run] Resolved experiment type: %s", experiment)
    log.info("[cp_glimpse_py.simulation.run] Resolved simulation backend: %s", backend)

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
            "models": {
                "bouncing_ball": {
                    "mo_path": "models/BouncingBall.mo",
                    "class_name": "BouncingBall"
                }
            },
            "sim": {"experiment": "single_run"}
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