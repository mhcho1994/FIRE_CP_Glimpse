"""
cp_glimpse_py.materialize.materialize
=====================================

Scenario-aware artifact preparation for CP-Glimpse.

This module resolves source model references under `system.components`
into runnable executable artifacts, typically FMUs.

Design boundary
---------------
This module is responsible for *preparing* executable artifacts. It does not
execute simulations itself.

Current scope
-------------
- single-component scenario materialization
- Modelica source (.mo) -> FMU via translator
- existing FMU reuse

Expected scenario pattern
-------------------------
system:
  components:
    - name: my_component
      model_path: path/to/model.mo   # or .fmu
      class_name: MyModel            # optional if inferable
"""

from __future__ import annotations

import copy
from typing import Any

from ..common import get_logger
from ..translator import build_fmu

log = get_logger(__name__)


def materialize_single_component_scenario(scn: dict[str, Any], backend:str) -> dict[str, Any]:
    """
    Materialize a single-component scenario into a runnable artifact form.

    Parameters
    ----------
    scn : dict[str, Any]
        Input scenario. This function does not mutate the original scenario.
    backend : str
        Resolved simulation backend string.

    Returns
    -------
    dict[str, Any]
        Deep-copied scenario with the component's `model_path` updated to the
        runnable FMU path and `_artifact` metadata attached.

    Raises
    ------
    ValueError
        If the scenario does not describe exactly one valid component.
    """
    scn_mutable = copy.deepcopy(scn)

    if not backend.startswith("fmu"):
        log.warning(
            "[cp_glimpse_py.materialize.materialize] Backend '%s' is not FMU-based, " \
            "which is currently not supported by single-run experiment. " \
            "Returning scenario without materialization.", backend
            )
        return scn_mutable      # TODO: currently only FMU backends are supported. In the future, we may want to condition this logic on the backend type.

    components = scn_mutable.get("system",{}).get("components",{})

    if not isinstance(components, list) or not components:
        log.error(
            "[cp_glimpse_py.materialize.materialize] Single-component scenario must contain a non-empty 'system.components' section with a list of model entries."
        )
        raise ValueError(
            "[cp_glimpse_py.materialize.materialize] Single-component scenario must contain a non-empty 'system.components' section."
        )

    if len(components) != 1:
        log.warning(
            "[cp_glimpse_py.materialize.materialize] Single-component scenario must contain exactly one component entry under "
            "'system.components'. Found %d entries and run only the first entry", len(components)
        )

    component_idx, component = next(iter(enumerate(components)))
    if not isinstance(component, dict):
        log.error(
            "[cp_glimpse_py.materialize.materialize] Component entry %d is not a dictionary.", component_idx
        )
        raise ValueError(
            f"[cp_glimpse_py.materialize.materialize] Component entry '{component_idx}' must be a dictionary."
        )
    
    model_path = component.get("model_path") or component.get("fmu_path")
    if not model_path:
        log.error("[cp_glimpse_py.materialize.materialize] Component entry %d is missing required key 'model_path' or 'fmu_path'.", component_idx)
        raise KeyError(f"[cp_glimpse_py.materialize.materialize] Component entry '{component_idx}' is missing required key 'model_path' or 'fmu_path'.")

    sim_cfg = scn_mutable.get("sim", {}) or {}
    fmu_type = str(component.get("fmu_type", sim_cfg.get("fmu_type", "me"))).lower()

    artifact = build_fmu(
        source_path=model_path,
        class_name=component.get("class_name", None),
        fmu_type=fmu_type,
    )

    component["model_path"] = str(artifact.fmu_path)
    component["_artifact"] = {
        "kind": "fmu",
        "key": artifact.key,
        "work_dir": str(artifact.work_dir),
        "source": artifact.source,
        "fmu_type": fmu_type,
        "class_name": component.get("class_name"),
    }

    log.info(
        "Materialized component '%s' to FMU: %s",
        component.get("name", "component_0"),
        artifact.fmu_path,
    )

    return scn_mutable