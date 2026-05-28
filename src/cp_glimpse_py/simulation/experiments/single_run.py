"""
cp_glimpse_py.simulation.experiments.single_run
=================================
Single-run experiment orchestration.

Purpose
-------
This module defines the experiment-level logic for executing exactly one
simulation run. It is responsible for:

1. materializing scenario model sources into runnable artifacts when needed,
2. selecting the appropriate low-level executor based on composition/backend,
3. collecting lightweight run metadata such as wall-clock duration.

Design notes
------------
This module intentionally sits above executor implementations.

- Translators are responsible for converting source artifacts
  (for example, `.mo`) into executable artifacts (for example, `.fmu`).
- Executors are responsible for actually running a prepared scenario.
- This module orchestrates the boundary between the two.

Current behavior
----------------
At present, single-run execution supports FMU-oriented execution flows.

For a single-component scenario:
- if `model_path` already points to an `.fmu`, it is reused,
- otherwise the source is passed to the translator, which attempts to
  materialize it as an FMU.

For a multi-component scenario:
- the scenario is currently passed through as-is.
- future work may materialize each component independently.

This separation makes it easier to later add:
- result persistence hooks,
- structured run identifiers,
- richer metadata,
- post-processing,
- backend-specific materialization rules.

Public API
----------
- run_single_experiment

Private helpers
----------------
- _materialize_single_model_artifact
"""

from __future__ import annotations

import time
from typing import Any

from ...common.logging import get_logger
from ...translator.materialize import materialize_scenario
from ..executors.single_fmu import run_single_fmu_open_loop
from ..executors.multi_fmu import run_multi_fmu_open_loop

log = get_logger(__name__)

def run_single_experiment(scn: dict[str, Any], composition: str, backend: str) -> dict[str, Any]:
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
        Current supported execution paths are FMU-oriented backends.

    Returns
    -------
    dict[str, Any]
        Structured single-run result with:
        - status
        - experiment type
        - composition
        - backend
        - executor result
        - metadata


    Raises
    ------
    ValueError
        If the composition/backend combination is unsupported.
    """
    t_wall_0 = time.time()

    if composition not in {"single", "multi"}:
        raise ValueError(f"Unsupported composition for single experiment: {composition}")

    log.info("Materializing scenario for backend '%s'", backend)
    runnable_scn = materialize_scenario(scn, composition=composition, backend=backend)

    if composition == "single":
        if not backend.startswith("fmu"):
            raise ValueError(
                f"Unsupported backend for single-component execution: {backend}"
            )
        exec_result = run_single_fmu_open_loop(runnable_scn)
    elif composition == "multi":
        if not backend.startswith("fmu"):
            raise ValueError(
                f"Unsupported backend for multi-component execution: {backend}"
            )
        exec_result = run_multi_fmu_open_loop(runnable_scn)
    else:
        raise ValueError(f"Unsupported composition for execution: {composition}")


    return {
        "status": "success",
        "experiment": "single_run",
        "composition": composition,
        "result": exec_result,
        "metadata": {
            "wall_time_sec": time.time() - t_wall_0,
        },
    }
