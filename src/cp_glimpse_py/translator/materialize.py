"""
Scenario materialization utilities.

This module converts source-oriented scenario component declarations into
executor-ready artifacts. Experiment code should call this once before handing
a scenario to low-level executors.
"""

from __future__ import annotations

import copy
from typing import Any

from ..common.logging import get_logger
from ..scenario.load import Scenario
from .fmu.to_fmu import build_fmu

log = get_logger(__name__)

_COMPONENT_PATH_KEYS = ("model_path", "fmu_path", "artifact_path")


def _as_mutable_dict(scn: Scenario | dict[str, Any]) -> dict[str, Any]:
    if isinstance(scn, Scenario):
        return copy.deepcopy(scn.to_dict())
    return copy.deepcopy(scn)


def _component_name(component: dict[str, Any], index: int) -> str:
    return str(component.get("name") or f"component_{index}")


def _component_source_path(component: dict[str, Any]) -> tuple[str, Any]:
    for key in _COMPONENT_PATH_KEYS:
        value = component.get(key)
        if value:
            return key, value
    raise KeyError(
        "Component must define one artifact/source path field: "
        f"{', '.join(_COMPONENT_PATH_KEYS)}"
    )


def _component_fmu_type(
    component: dict[str, Any],
    scenario: dict[str, Any],
) -> str:
    return str(component.get("fmu_type", scenario.get("sim", {}).get("fmu_type", "cs"))).lower()


def _merge_component_initialization(
    scenario: dict[str, Any],
    component_name: str,
    component: dict[str, Any],
) -> None:
    init_cfg = scenario.get("initialization", {}) or {}
    component_init = init_cfg.get(component_name)
    if not isinstance(component_init, dict):
        return

    start_values = component_init.get("start_values")
    if isinstance(start_values, dict):
        merged = dict(component.get("start_values", {}) or {})
        merged.update(start_values)
        component["start_values"] = merged

    parameters = component_init.get("parameters")
    if isinstance(parameters, dict):
        merged = dict(component.get("parameters", {}) or {})
        merged.update(parameters)
        component["parameters"] = merged


def _materialize_component(
    scenario: dict[str, Any],
    component: dict[str, Any],
    *,
    component_name: str,
) -> dict[str, Any]:
    materialized = copy.deepcopy(component)
    path_key, source_path = _component_source_path(materialized)
    fmu_type = _component_fmu_type(materialized, scenario)

    artifact = build_fmu(
        source_path=source_path,
        class_name=materialized.get("class_name"),
        fmu_type=fmu_type,
    )

    materialized[path_key] = str(artifact.fmu_path)
    materialized["model_path"] = str(artifact.fmu_path)
    materialized["_artifact"] = {
        "type": "fmu",
        "build_key": artifact.key,
        "work_dir": str(artifact.work_dir),
        "source": artifact.source,
    }

    _merge_component_initialization(scenario, component_name, materialized)

    log.info(
        "Component materialized: component=%s, fmu=%s",
        component_name,
        artifact.fmu_path,
    )
    return materialized


def _get_system_components(scenario: dict[str, Any]) -> list[dict[str, Any]]:
    system_cfg = scenario.get("system", {}) or {}
    components = system_cfg.get("components")
    if isinstance(components, list):
        return components
    return []


def _models_from_components(components: list[dict[str, Any]]) -> dict[str, dict[str, Any]]:
    models: dict[str, dict[str, Any]] = {}
    for index, component in enumerate(components):
        name = _component_name(component, index)
        models[name] = copy.deepcopy(component)
    return models


def _sync_models_section(
    scenario: dict[str, Any],
    components: list[dict[str, Any]],
) -> None:
    models = scenario.get("models")
    if not isinstance(models, dict):
        models = {}

    for index, component in enumerate(components):
        name = _component_name(component, index)
        model_entry = dict(models.get(name, {}) or {})
        model_entry.update(copy.deepcopy(component))
        models[name] = model_entry

    scenario["models"] = models


def apply_scenario_initialization(scn: Scenario | dict[str, Any]) -> dict[str, Any]:
    """
    Apply top-level initialization entries to component-level start values.

    This does not build or reuse artifacts. It exists so Monte Carlo runs can
    sample `initialization.*` after a scenario has already been materialized.
    """
    scenario = _as_mutable_dict(scn)
    components = _get_system_components(scenario)

    for index, component in enumerate(components):
        if not isinstance(component, dict):
            continue
        _merge_component_initialization(
            scenario,
            _component_name(component, index),
            component,
        )

    scenario.setdefault("system", {})["components"] = components
    _sync_models_section(scenario, components)
    return scenario


def materialize_single_component(
    scn: Scenario | dict[str, Any],
    *,
    backend: str,
) -> dict[str, Any]:
    scenario = _as_mutable_dict(scn)

    if not backend.startswith("fmu"):
        log.warning("Backend '%s' is not FMU-based; returning scenario unchanged.", backend)
        return scenario

    components = _get_system_components(scenario)
    if not components:
        raise ValueError("Single-component materialization requires system.components.")
    if len(components) != 1:
        log.warning(
            "Single-component materialization expected 1 component, found %d; "
            "only the first component will be materialized.",
            len(components),
        )

    component_name = _component_name(components[0], 0)
    components[0] = _materialize_component(
        scenario,
        components[0],
        component_name=component_name,
    )
    scenario.setdefault("system", {})["components"] = components
    _sync_models_section(scenario, components)
    return scenario


def materialize_multi_components(
    scn: Scenario | dict[str, Any],
    *,
    backend: str,
) -> dict[str, Any]:
    scenario = _as_mutable_dict(scn)

    if not backend.startswith("fmu"):
        log.warning("Backend '%s' is not FMU-based; returning scenario unchanged.", backend)
        return scenario

    components = _get_system_components(scenario)
    if not components:
        models = scenario.get("models")
        if isinstance(models, dict) and models:
            components = [
                {"name": name, **copy.deepcopy(model_cfg)}
                for name, model_cfg in models.items()
                if isinstance(model_cfg, dict)
            ]
        else:
            raise ValueError("Multi-component materialization requires system.components or models.")

    materialized_components: list[dict[str, Any]] = []
    for index, component in enumerate(components):
        if not isinstance(component, dict):
            raise ValueError(f"Component entry {index} must be a dictionary.")

        component_name = _component_name(component, index)
        materialized_components.append(
            _materialize_component(
                scenario,
                component,
                component_name=component_name,
            )
        )

    scenario.setdefault("system", {})["components"] = materialized_components
    _sync_models_section(scenario, materialized_components)
    return scenario


def materialize_scenario(
    scn: Scenario | dict[str, Any],
    *,
    composition: str,
    backend: str,
) -> dict[str, Any]:
    normalized_composition = str(composition).lower()

    if normalized_composition == "single":
        return materialize_single_component(scn, backend=backend)
    if normalized_composition == "multi":
        return materialize_multi_components(scn, backend=backend)

    raise ValueError(f"Unsupported composition for materialization: {composition}")
