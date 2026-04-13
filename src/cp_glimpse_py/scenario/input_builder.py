"""
cp_glimpse_py.scenario.input_builder
====================================

Simple time-varying input evaluation utilities for scenario-driven simulation.

Current supported input profiles
--------------------------------
- constant
- step
- piecewise_constant

This module intentionally stays small so that higher-level executors can
evaluate scenario inputs without embedding input-profile logic inline.
"""

from __future__ import annotations

from typing import Any


def normalize_inputs(scn: dict) -> list[dict[str, Any]]:
    """
    Normalize the top-level 'inputs' section from a scenario.

    Parameters
    ----------
    scn : dict
        Scenario dictionary.

    Returns
    -------
    list[dict[str, Any]]
        Normalized list of input definitions.
    """
    inputs = scn.get("inputs", []) or []
    if not isinstance(inputs, list):
        raise ValueError("Scenario 'inputs' must be a list.")

    normalized: list[dict[str, Any]] = []

    for i, inp in enumerate(inputs):
        if not isinstance(inp, dict):
            raise ValueError(f"inputs[{i}] must be a dictionary.")

        target = inp.get("target")
        if not isinstance(target, str) or not target.strip():
            raise ValueError(f"inputs[{i}] must define a non-empty 'target'.")

        kind = str(inp.get("type", "constant")).strip().lower()
        item = dict(inp)
        item["target"] = target.strip()
        item["type"] = kind

        if kind == "constant":
            if "value" not in item:
                raise ValueError(f"inputs[{i}] of type 'constant' requires 'value'.")

        elif kind == "step":
            if "value" not in item or "t_start" not in item:
                raise ValueError(
                    f"inputs[{i}] of type 'step' requires 'value' and 't_start'."
                )
            item["t_start"] = float(item["t_start"])
            item["initial"] = item.get("initial", 0.0)

        elif kind == "piecewise_constant":
            values = item.get("values")
            if not isinstance(values, list) or not values:
                raise ValueError(
                    f"inputs[{i}] of type 'piecewise_constant' requires non-empty 'values'."
                )
            norm_values = []
            for j, pair in enumerate(values):
                if not isinstance(pair, (list, tuple)) or len(pair) != 2:
                    raise ValueError(
                        f"inputs[{i}].values[{j}] must be a [time, value] pair."
                    )
                norm_values.append((float(pair[0]), pair[1]))
            norm_values.sort(key=lambda x: x[0])
            item["values"] = norm_values

        else:
            raise ValueError(f"Unsupported input type: {kind!r}")

        normalized.append(item)

    return normalized


def evaluate_inputs(input_defs: list[dict[str, Any]], t: float) -> dict[str, Any]:
    """
    Evaluate normalized inputs at time t.

    Parameters
    ----------
    input_defs : list[dict[str, Any]]
        Normalized input definitions.
    t : float
        Current simulation time.

    Returns
    -------
    dict[str, Any]
        Mapping from variable name to value.
    """
    values: dict[str, Any] = {}

    for inp in input_defs:
        kind = inp["type"]

        if kind == "constant":
            values[inp["target"]] = inp["value"]

        elif kind == "step":
            values[inp["target"]] = (
                inp["value"] if t >= inp["t_start"] else inp.get("initial", 0.0)
            )

        elif kind == "piecewise_constant":
            current = inp["values"][0][1]
            for tk, vk in inp["values"]:
                if t >= tk:
                    current = vk
                else:
                    break
            values[inp["target"]] = current

        else:
            raise ValueError(f"Unsupported normalized input type: {kind!r}")

    return values