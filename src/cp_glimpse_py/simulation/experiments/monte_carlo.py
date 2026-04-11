"""
Monte Carlo experiment orchestration.

Purpose
-------
This module implements repeated simulation runs with scenario overrides.
The sampling logic is intentionally separated from low-level executors so
that the same Monte Carlo framework can be reused for different backends.

Current sampling behavior
-------------------------
This version implements deterministic cyclic override selection from
`montecarlo.overrides[*].values`.

Example
-------
{
    "sim": {
        "experiment": "montecarlo",
        "n_runs": 10
    },
    "montecarlo": {
        "overrides": [
            {"path": "parameters.mass", "values": [0.9, 1.0, 1.1]},
            {"path": "sim.step_size", "values": [0.01, 0.02]}
        ]
    }
}
"""

from __future__ import annotations

from dataclasses import dataclass, asdict
from typing import Any
import copy
import time

from ..executors.single_fmu import run_single_fmu_open_loop
from ..executors.multi_fmu import run_multi_fmu_open_loop


@dataclass
class MonteCarloResult:
    """
    Summary dataclass for Monte Carlo experiments.
    """

    status: str
    topology: str
    n_runs: int
    n_success: int
    n_failed: int
    runs: list[dict[str, Any]]
    metadata: dict[str, Any]


def _set_nested_value(root: dict[str, Any], dotted_path: str, value: Any) -> None:
    """
    Set a nested dictionary value using a dotted path.

    Parameters
    ----------
    root : dict[str, Any]
        Target dictionary.
    dotted_path : str
        Dotted key path such as 'parameters.mass'.
    value : Any
        Value to assign.
    """
    if not dotted_path:
        raise ValueError("Override path must be a non-empty string.")

    keys = dotted_path.split(".")
    cur = root
    for key in keys[:-1]:
        if key not in cur or not isinstance(cur[key], dict):
            cur[key] = {}
        cur = cur[key]
    cur[keys[-1]] = value


def _apply_monte_carlo_overrides(base_scn: dict[str, Any], run_idx: int) -> dict[str, Any]:
    """
    Apply deterministic run-specific overrides to a scenario copy.

    Parameters
    ----------
    base_scn : dict[str, Any]
        Base scenario dictionary.
    run_idx : int
        Zero-based run index.

    Returns
    -------
    dict[str, Any]
        Scenario copy with run-specific overrides applied.
    """
    scn = copy.deepcopy(base_scn)
    mc_cfg = scn.get("montecarlo", {}) or {}
    overrides = mc_cfg.get("overrides", []) or []

    for item in overrides:
        path = item.get("path")
        values = item.get("values", [])
        if not path or not values:
            continue
        value = values[run_idx % len(values)]
        _set_nested_value(scn, path, value)

    return scn


def _run_once_for_topology(scn: dict[str, Any], topology: str) -> dict[str, Any]:
    """
    Execute one run using the appropriate executor for a resolved topology.
    """
    if topology == "single_fmu":
        return run_single_fmu_open_loop(scn)
    if topology == "multi_fmu":
        return run_multi_fmu_open_loop(scn)
    raise ValueError(f"Unsupported topology for Monte Carlo: {topology}")


def run_monte_carlo(scn: dict[str, Any], topology: str) -> MonteCarloResult:
    """
    Execute a Monte Carlo experiment.

    Parameters
    ----------
    scn : dict[str, Any]
        Loaded scenario dictionary.
    topology : str
        Resolved topology.

    Returns
    -------
    MonteCarloResult
        Aggregate experiment summary.
    """
    sim_cfg = scn.get("sim", {}) or {}
    n_runs = int(sim_cfg.get("n_runs", 1))
    if n_runs <= 0:
        raise ValueError(f"sim.n_runs must be positive, got {n_runs}")

    t_wall_0 = time.time()
    per_run_results: list[dict[str, Any]] = []
    n_success = 0
    n_failed = 0

    for run_idx in range(n_runs):
        run_scn = _apply_monte_carlo_overrides(scn, run_idx)
        try:
            run_result = _run_once_for_topology(run_scn, topology)
            per_run_results.append(
                {
                    "run_idx": run_idx,
                    "status": "success",
                    "result": run_result,
                }
            )
            n_success += 1
        except Exception as exc:  # noqa: BLE001
            per_run_results.append(
                {
                    "run_idx": run_idx,
                    "status": "failed",
                    "error": repr(exc),
                }
            )
            n_failed += 1

    return MonteCarloResult(
        status="success" if n_failed == 0 else "partial_success",
        topology=topology,
        n_runs=n_runs,
        n_success=n_success,
        n_failed=n_failed,
        runs=per_run_results,
        metadata={
            "wall_time_sec": time.time() - t_wall_0,
            "experiment": "montecarlo",
        },
    )


def monte_carlo_result_to_dict(result: MonteCarloResult) -> dict[str, Any]:
    """
    Convert MonteCarloResult to a plain dictionary.
    """
    return asdict(result)