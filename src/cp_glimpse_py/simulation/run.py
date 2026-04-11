"""
Top-level simulation dispatcher.

Purpose
-------
This module provides the main public entry points for the simulation package.

It is responsible for:
- loading a scenario from file or accepting a preloaded dictionary,
- resolving simulation topology,
- resolving experiment type,
- dispatching execution,
- saving results and summary artifacts.

Topology resolution
-------------------
Topology can be resolved in two ways.

1. Explicit:
   `sim.topology` is set to something other than "auto".

2. Inferred:
   The dispatcher inspects:
   - 'model'
   - 'models'
   and checks whether they contain actual model identity fields such as:
   - fmu_path
   - mo_path
   - class_name
   - model_path
   - model_file
   - uri

Inference rules
---------------
- 'models' & contains one or more valid model entries -> multi-fmu
- 'model' & contains model identity information -> single_fmu
- otherwise: resolution fails with an error

Experiment resolution
---------------------
- sim.experiment == "montecarlo" -> Monte-Carlo run
- sim.experiment == "single_run" -> single run
- sim.experimenht == "sensitivity" -> TODO: implement this experiment type
- sim.experiment == "sweep": TODO: implement this experiment type
- sim.experiment not provided: default to "single_run"
"""

from __future__ import annotations

from dataclasses import asdict, is_dataclass
from pathlib import Path
from typing import Any
import json
import time

from ..common.paths import get_paths
from ..common.logging import get_logger
from ..scenario.load import load_scenario
from .experiments.single_run import run_single_experiment
from .experiments.monte_carlo import run_monte_carlo

log = get_logger(__name__)

_MODEL_HINT_KEYS = (
    "fmu_path",
    "mo_path",
    "class_name",
    "model_path",
    "model_file",
    "uri",
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
    if not isinstance(models_cfg, dict):
        return 0
    count = 0
    for _, cfg in models_cfg.items():
        if _has_model_identity(cfg):
            count += 1
    return count


def resolve_topology(scn: dict[str, Any]) -> str:
    """
    Resolve simulation topology from scenario contents.

    Resolution order
    ----------------
    1. If `sim.topology` is explicitly provided and not "auto", respect it.
    2. If `models` contains one or more valid model definitions, use "multi_fmu".
    3. If `model` contains a valid model definition, use "single_fmu".
    4. Otherwise raise an error.

    Parameters
    ----------
    scn : dict[str, Any]
        Scenario dictionary.

    Returns
    -------
    str
        Resolved topology string.

    Raises
    ------
    ValueError
        If topology cannot be determined.
    """
    sim_cfg = scn.get("sim", {}) or {}
    topology = str(sim_cfg.get("topology", "auto")).lower()

    if topology != "auto":
        return topology

    valid_model_count = _count_valid_models(scn.get("models"))
    has_single_model = _has_model_identity(scn.get("model"))

    if valid_model_count > 0:
        return "multi_fmu"
    if has_single_model:
        return "single_fmu"

    raise ValueError(
        "Could not resolve simulation topology. "
        "Provide sim.topology explicitly or include valid model identity fields "
        f"under 'model' or 'models'. Expected keys include: {', '.join(_MODEL_HINT_KEYS)}"
    )


def resolve_experiment(scn: dict[str, Any]) -> str:
    """
    Resolve experiment type from scenario contents.

    Parameters
    ----------
    scn : dict[str, Any]
        Scenario dictionary.

    Returns
    -------
    str
        Experiment type.
    """
    sim_cfg = scn.get("sim", {}) or {}
    experiment = str(sim_cfg.get("experiment", "single_run")).lower()

    if experiment in {"single", "single_run"}:
        return "single_run"
    if experiment in {"mc", "montecarlo", "monte_carlo"}:
        return "montecarlo"

    raise ValueError(f"Unsupported experiment type: {experiment}")


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
    Compute a default output directory for one simulation execution.

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

    return results_root / "simulation_runs" / scenario_stem


def _save_json(data: Any, path: Path) -> None:
    """
    Save a JSON artifact to disk.

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
    topology: str,
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
    topology : str
        Resolved topology.
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
        "topology": topology,
        "experiment": experiment,
        "wall_time_sec": wall_time_sec,
        "scenario_path": str(scenario_path) if scenario_path else None,
    }

    if experiment == "single_run":
        inner = result.get("result", {})
        summary["result_status"] = inner.get("status")
        summary["n_time_points"] = len(inner.get("time", []) or [])
    elif experiment == "montecarlo":
        summary["n_runs"] = result.get("n_runs")
        summary["n_success"] = result.get("n_success")
        summary["n_failed"] = result.get("n_failed")

    if "sim" in scn:
        summary["sim"] = scn["sim"]

    return summary


def run_simulation_from_dict(
    scn: dict[str, Any],
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

    topology = resolve_topology(scn)
    experiment = resolve_experiment(scn)

    log.info("Resolved simulation topology: %s", topology)
    log.info("Resolved experiment type: %s", experiment)

    if experiment == "single_run":
        result_obj = run_single_experiment(scn, topology)
    elif experiment == "montecarlo":
        result_obj = run_monte_carlo(scn, topology)
    else:
        raise ValueError(f"Unhandled experiment type: {experiment}")

    result = _json_ready(result_obj)
    wall_time_sec = time.time() - t_wall_0

    result.setdefault("metadata", {})
    result["metadata"]["dispatch_wall_time_sec"] = wall_time_sec
    result["metadata"]["resolved_topology"] = topology
    result["metadata"]["resolved_experiment"] = experiment

    if save_results:
        out_dir = Path(output_dir) if output_dir is not None else _default_output_dir(scn, scenario_path)
        summary = _build_summary(
            scn=scn,
            scenario_path=scenario_path,
            topology=topology,
            experiment=experiment,
            result=result,
            wall_time_sec=wall_time_sec,
        )

        _save_json(result, out_dir / "result.json")
        _save_json(summary, out_dir / "summary.json")

        # Save the resolved scenario alongside artifacts for reproducibility.
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
            "model": {
                "mo_path": "models/MySys.mo",
                "class_name": "Pkg.MySys"
            },
            "sim": {"experiment": "single_run"}
        })
    """
    if isinstance(scenario, dict):
        scn = scenario
        scenario_path = None
    else:
        scenario_path = Path(scenario)
        scn = load_scenario(scenario_path)

    return run_simulation_from_dict(
        scn,
        scenario_path=scenario_path,
        save_results=save_results,
        output_dir=Path(output_dir) if output_dir is not None else None,
    )