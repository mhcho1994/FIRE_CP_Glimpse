"""
Single-run experiment orchestration.

Purpose
-------
This module defines the experiment-level logic for executing exactly one
simulation run. It delegates actual execution to the appropriate low-level
executor selected by topology.

Why this layer exists
---------------------
Keeping experiment orchestration separate from execution backends makes it
easy to add:
- per-run metadata,
- result persistence hooks,
- logging,
- post-processing,
- future run identifiers and reproducibility tracking.
"""

from __future__ import annotations

from typing import Any
import time

from ..executors.single_fmu import run_single_fmu_open_loop
from ..executors.multi_fmu import run_multi_fmu_open_loop


def run_single_experiment(scn: dict[str, Any], topology: str) -> dict[str, Any]:
    """
    Run one simulation experiment for a resolved topology.

    Parameters
    ----------
    scn : dict[str, Any]
        Loaded scenario dictionary.
    topology : str
        Resolved topology string.

    Returns
    -------
    dict[str, Any]
        Structured single-run result.

    Raises
    ------
    ValueError
        If topology is unsupported.
    """
    t_wall_0 = time.time()

    if topology == "single_fmu":
        exec_result = run_single_fmu_open_loop(scn)
    elif topology == "multi_fmu":
        exec_result = run_multi_fmu_open_loop(scn)
    else:
        raise ValueError(f"Unsupported topology for single experiment: {topology}")

    return {
        "status": "success",
        "experiment": "single_run",
        "topology": topology,
        "result": exec_result,
        "metadata": {
            "wall_time_sec": time.time() - t_wall_0,
        },
    }