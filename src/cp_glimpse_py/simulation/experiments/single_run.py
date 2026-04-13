"""
cp_glimpse_py.simulation.experiments.single_run
=================================
Single-run experiment orchestration.

This module sits above low-level executors. It materializes scenario model
sources when needed, then dispatches execution to the appropriate executor.


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

import copy
import time
from typing import Any
from pathlib import Path

from ...common.logging import get_logger
from ...scenario.load import Scenario
from ...translator.to_fmu import build_fmu
from ..executors.multi_fmu import run_multi_fmu_open_loop
from ..executors.single_fmu import run_single_fmu_open_loop

log = get_logger(__name__)


def _materialize_single_model_artifact(scn: Scenario | dict[str, Any], backend: str) -> dict[str, Any]:
    """
    Materialize a single-component scenario into a runnable artifact form.

    Parameters
    ----------
    scn : Scenario | dict[str, Any]
        Input scenario. This function does not mutate the original scenario.

    backend : str
        Resolved simulation backend string.

    Expected schema
    ---------------
    The current single-component convention is:

    system:
      components:
        - name: ...
          class_name: ...
          model_path: path/to/model.mo   # or path/to/model.fmu
          fmu_type: me                   # optional

    Behavior
    --------
    For FMU backends:
    - the first component in `system.components` is treated as the runnable model
    - `model_path` is passed to the translator
    - the translator either:
      - reuses the FMU if the input is already an `.fmu`, or
      - builds an FMU if the input is a supported non-FMU source such as `.mo`

    The scenario is then updated with:
    - `model_path` pointing to the runnable FMU path
    - `_artifact` metadata describing how the FMU was obtained

    Returns
    -------
    dict[str, Any]
        A deep-copied scenario dictionary updated with runnable artifact paths.

    Raises
    ------
    ValueError
        If the scenario does not contain a valid single-component entry.
    KeyError
        If the model entry does not provide `model_path`.
    """
    scn_mutable = copy.deepcopy(scn)

    if not backend.startswith("fmu"):
        log.warning(
            "[cp_glimpse_py.simulation.experiments.single_run] Backend '%s' is not FMU-based, " \
            "which is currently not supported by single-run experiment. " \
            "Returning scenario without materialization.", backend
            )
        return scn_mutable      # TODO: currently only FMU backends are supported. In the future, we may want to condition this logic on the backend type.             

    components_cfg = scn_mutable.get("system",{}).get("components",{})
    if not isinstance(components_cfg, list) or not components_cfg:
        log.error(
            "[cp_glimpse_py.simulation.experiments.single_run] Single-component scenario must contain a non-empty 'system.components' section with a list of model entries."
        )
        raise ValueError(
            "[cp_glimpse_py.simulation.experiments.single_run] Single-component scenario must contain a non-empty 'system.components' section."
        )

    if len(components_cfg) != 1:
        log.warning(
            "[cp_glimpse_py.simulation.experiments.single_run] Single-component scenario must contain exactly one component entry under "
            "'system.components'. Found %d entries and run only the first entry", len(components_cfg)
        )

    model_entry_idx, model_cfg = next(iter(enumerate(components_cfg)))
    if not isinstance(model_cfg, dict):
        log.error(
            "[cp_glimpse_py.simulation.experiments.single_run] Component entry %d is not a dictionary.", model_entry_idx
        )
        raise ValueError(
            f"[cp_glimpse_py.simulation.experiments.single_run] Component entry '{model_entry_idx}' must be a dictionary."
        )

    model_path = model_cfg.get("model_path")
    if not model_path:
        log.error(
            "[cp_glimpse_py.simulation.experiments.single_run] Component entry %d is missing required key 'model_path'.",
            model_entry_idx,
        )
        raise KeyError(
            f"[cp_glimpse_py.simulation.experiments.single_run] Component entry {model_entry_idx} under 'system.components' "
            "must define 'model_path'."
        )


    fmu_type = str(
        model_cfg.get("fmu_type", scn_mutable.get("sim", {}).get("fmu_type", "me"))
    ).lower()

    artifact = build_fmu(
        source_path=model_path,
        class_name=model_cfg.get("class_name", None),
        fmu_type=fmu_type,
    )

    model_cfg["model_path"] = str(artifact.fmu_path)
    model_cfg["_artifact"] = {
        "type": "fmu",
        "build_key": artifact.key,
        "work_dir": str(artifact.work_dir),
        "source": artifact.source,
    }

    log.info(
        "Single-component source materialized to FMU: component=%s, fmu=%s",
        model_cfg.get("name", f"component_{model_entry_idx}"),
        artifact.fmu_path,
    )

    return scn_mutable
  

def _materialize_multi_model_artifacts(
    scn: Scenario | dict[str, Any],
    backend: str,
) -> dict[str, Any]:
    """
    Materialize a multi-component scenario into runnable artifact form.

    Parameters
    ----------
    scn : Scenario | dict[str, Any]
        Input scenario. This function currently returns the scenario unchanged.

    backend : str
        Resolved simulation backend string.

    Returns
    -------
    dict[str, Any]
        A deep-copied scenario dictionary.

    Notes
    -----
    This is currently a placeholder.

    Future versions may:
    - iterate over all components under `system.components`,
    - materialize each source artifact independently,
    - propagate connection-aware execution metadata for multi-FMU scheduling.
    """
    scn_mutable = copy.deepcopy(scn)

    if not backend.startswith("fmu"):
        log.warning(
            "Backend '%s' is not FMU-based. Returning multi-component "
            "scenario without materialization.",
            backend,
        )
        return scn_mutable

    log.info(
        "Multi-component artifact materialization is not yet implemented. "
        "Returning scenario unchanged."
    )
    return scn_mutable


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

    if composition == "single":
        log.info("Materializing single-model artifact for backend '%s'", backend)
        runnable_scn = _materialize_single_model_artifact(scn, backend)
    elif composition == "multi":
        log.info("Materializing multi-model artifacts for backend '%s'", backend)
        runnable_scn = scn
    else:
        raise ValueError(f"Unsupported composition for single experiment: {composition}")

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