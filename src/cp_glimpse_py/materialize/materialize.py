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

from ..common.logging import get_logger
from ..translator.to_fmu import build_fmu

log = get_logger(__name__)


def materialize_single_component_scenario(scn: dict[str, Any]) -> dict[str, Any]:
    """
    Materialize a single-component scenario into a runnable FMU-backed form.

    Parameters
    ----------
    scn : dict[str, Any]
        Scenario dictionary.

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

    system_cfg = scn_mutable.get("system", {}) or {}
    components = system_cfg.get("components")

    if not isinstance(components, list) or len(components) != 1:
        raise ValueError(
            "materialize_single_component_scenario() requires exactly one "
            "entry under 'system.components'."
        )

    component = components[0]
    if not isinstance(component, dict):
        raise ValueError("The single component entry must be a dictionary.")

    model_path = component.get("model_path") or component.get("fmu_path")
    if not model_path:
        raise KeyError("Single component must define 'model_path' or 'fmu_path'.")

    sim_cfg = scn_mutable.get("sim", {}) or {}
    fmu_type = str(component.get("fmu_type", sim_cfg.get("fmu_type", "cs"))).lower()

    artifact = build_fmu(
        source_path=model_path,
        class_name=component.get("class_name"),
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