"""
cp_glimpse_py.simulation.experiments.single_run
=================================
Single-run experiment orchestration.

This module sits above low-level executors. It materializes scenario model
sources when needed, then dispatches execution to the appropriate executor.
"""

from __future__ import annotations

import time
from typing import Any

from ...common import get_logger
from ...materialize.materialize import materialize_single_component_scenario
from ..executors import run_multi_fmu_open_loop
from ..executors import run_single_fmu_open_loop

log = get_logger(__name__)


def run_single_experiment(
        scn: dict[str, Any], 
        composition: str, 
        backend: str
) -> dict[str, Any]:
    """
    Run one simulation experiment for a resolved topology.

    Parameters
    ----------
    scn : dict[str, Any]
        Loaded scenario dictionary.
    composition : str
        Resolved composition string.
    backend : str
        Resolved backend string.

    Returns
    -------
    dict[str, Any]
        Structured single-run result with:

    Raises
    ------
    ValueError
        If the composition/backend combination is unsupported.
    """
    t_wall_0 = time.time()

    if composition == "single":
        if backend.startswith("fmu"):
            runnable_scn = materialize_single_component_scenario(scn, backend)
            exec_result = run_single_fmu_open_loop(runnable_scn)

    elif composition == "multi":
        log.info("Materializing multi-model artifacts for backend '%s'", backend)
        # TODO: implement multi-materialization
        runnable_scn = scn
        exec_result = run_multi_fmu_open_loop(runnable_scn)

    else:
        raise ValueError(f"Unsupported composition for single experiment: {composition}")

    return {
        "status": "success",
        "experiment": "single",
        "composition": composition,
        "backend": backend,
        "result": exec_result,
        "metadata": {
            "wall_time_sec": time.time() - t_wall_0,
        },
    }