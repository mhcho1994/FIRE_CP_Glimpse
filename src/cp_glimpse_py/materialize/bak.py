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