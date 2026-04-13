"""
cp_glimpse_py.scenario.load
=======

Scenario loading utilities.

This module defines the scenario container used across CP Glimpse and
provides the YAML loading entry point.

Purpose
-------
Scenario configuration files are the main user-facing way to describe
a simulation run. They may include:
- simulation settings under `sim`,
- system/component structure under `system.components`,
- inter-component wiring under `system.connections`,
- initialization values under `initialization`,
- input profiles under `inputs`,
- parameter overrides under `parameters`,
- disturbances under `disturbances`,
- output selection under `outputs`,
- validation checks under `validation`,
- metadata such as scenario name under `metadata`.

This module provides two things:

1. `Scenario`
   A thin dict-like wrapper around the normalized scenario dictionary.
   It supports both attribute-style access such as `scn.sim` and
   dictionary-style access such as `scn.get("sim", {})`.

2. `load_scenario(...)`
   A helper that loads a YAML scenario file, resolves relative paths
   against the project root, validates the top-level structure, and
   inserts commonly expected default sections.

Design notes
------------
The codebase currently mixes two access patterns:
- structured object access through properties,
- dictionary-like access through `.get(...)`, `[...]`, and iteration.

The `Scenario` wrapper exists to support both styles so that higher-level
simulation and orchestration code can remain simple and backward-compatible.

Normalization behavior
----------------------
When a scenario is loaded, optional top-level sections are normalized so
downstream code can safely assume they exist. For example:
- `sim` defaults to `{experiment: "single", composition: "auto", backend: "auto", start_time: 0.0, stop_time: 1.0, step_size: 0.01, tolerance: 1e-6}`,
- `system` defaults to `{components: [], connections: []}`,
- `initialization` defaults to `[],
- `inputs` defaults to `[]`,
- `parameters` defaults to `[]`,
- `disturbances` defaults to `[]`,
- `outputs` defaults to `{log: [], save_dir: "results", save_name: "run", save_log: False, log_format: "csv", save_metadata: False}`,
"""

from __future__ import annotations

from dataclasses import dataclass, field
from logging import log
from pathlib import Path
from typing import Any, Iterator
import yaml

from ..common.paths import get_paths


@dataclass
class Scenario:
    """
    Thin dict-like wrapper around a loaded scenario configuration.

    Why this exists
    ---------------
    Some parts of the codebase treat the loaded scenario as a structured
    object with properties, while others treat it as a plain dictionary.
    This wrapper supports both styles so that callers do not need to care
    whether the underlying representation is a dataclass or a dict.
    """

    raw: dict[str, Any] = field(default_factory=dict)

    # ------------------------------------------------------------------
    # Common scenario sections
    # ------------------------------------------------------------------
    @property
    def sim(self) -> dict[str, Any]:
        """
        Return the simulation configuration section.

        Returns
        -------
        dict[str, Any]
            Scenario `sim` section, or an empty dict if absent.
        """
        return self.raw.get("sim", {})

    @property
    def system(self) -> dict[str, Any]:
        """
        Return the system configuration section.

        Returns
        -------
        dict[str, Any]
            Scenario `system` section, or an empty dict if absent.
        """
        return self.raw.get("system", {})

    @property
    def initialization(self) -> list[dict[str, Any]]:
        """
        Return the initialization section.

        Returns
        -------
        list[dict[str, Any]]
            Scenario `initialization` section, or an empty list if absent.
        """
        return self.raw.get("initialization", [])

    @property
    def inputs(self) -> list[dict[str, Any]]:
        """
        Return the Monte Carlo configuration section.

        Returns
        -------
        list[dict[str, Any]]
            Scenario `inputs` section, or an empty list if absent.
        """
        return self.raw.get("inputs", [])

    @property
    def parameters(self) -> list[dict[str, Any]]:
        """
        Return the parameter section.

        Returns
        -------
        list[dict[str, Any]]
            Scenario `parameters` section, or an empty list if absent.
        """
        return self.raw.get("parameters", [])

    @property
    def outputs(self) -> dict[str, Any]:
        """
        Return the output configuration section.

        Returns
        -------
        dict[str, Any]
            Scenario `outputs` section, or an empty dict if absent.
        """
        return self.raw.get("outputs", {})

    @property
    def validation(self) -> dict[str, Any]:
        """
        Return the validation configuration section.

        Returns
        -------
        dict[str, Any]
            Scenario `validation` section, or an empty dict if absent.
        """
        return self.raw.get("validation", {})
    
    @property
    def metadata(self) -> dict[str, Any]:
        """
        Return the metadata configuration section.

        Returns
        -------
        dict[str, Any]
            Scenario `metadata` section, or an empty dict if absent.
        """
        return self.raw.get("metadata", {})

    # ------------------------------------------------------------------
    # Dict-like compatibility layer
    # ------------------------------------------------------------------
    def get(self, key: str, default: Any = None) -> Any:
        """
        Dictionary-style `.get(...)` access.

        Parameters
        ----------
        key : str
            Top-level scenario key.
        default : Any, optional
            Default value returned if the key is absent.

        Returns
        -------
        Any
            Value from the raw scenario dictionary or `default`.
        """
        return self.raw.get(key, default)

    def setdefault(self, key: str, default: Any) -> Any:
        """
        Dictionary-style `.setdefault(...)` access.

        Parameters
        ----------
        key : str
            Top-level scenario key.
        default : Any
            Default value to insert if the key is absent.

        Returns
        -------
        Any
            Existing or inserted value.
        """
        return self.raw.setdefault(key, default)

    def keys(self):
        """Return top-level scenario keys."""
        return self.raw.keys()

    def values(self):
        """Return top-level scenario values."""
        return self.raw.values()

    def items(self):
        """Return top-level scenario items."""
        return self.raw.items()

    def __getitem__(self, key: str) -> Any:
        """
        Dictionary-style index access.

        Parameters
        ----------
        key : str
            Top-level scenario key.

        Returns
        -------
        Any
            Value associated with `key`.
        """
        return self.raw[key]

    def __setitem__(self, key: str, value: Any) -> None:
        """
        Dictionary-style item assignment.

        Parameters
        ----------
        key : str
            Top-level scenario key.
        value : Any
            Value to assign.
        """
        self.raw[key] = value

    def __contains__(self, key: object) -> bool:
        """
        Support `key in scn`.

        Parameters
        ----------
        key : object
            Candidate key.

        Returns
        -------
        bool
            True if present in the raw scenario dictionary.
        """
        return key in self.raw

    def __iter__(self) -> Iterator[str]:
        """
        Iterate over top-level scenario keys.

        Returns
        -------
        Iterator[str]
            Iterator over dictionary keys.
        """
        return iter(self.raw)

    def __len__(self) -> int:
        """
        Return the number of top-level scenario keys.

        Returns
        -------
        int
            Number of keys in the raw scenario dictionary.
        """
        return len(self.raw)

    def to_dict(self) -> dict[str, Any]:
        """
        Return a shallow copy of the underlying scenario dictionary.

        Returns
        -------
        dict[str, Any]
            Copy of `raw`.
        """
        return dict(self.raw)


def load_scenario(path: str | Path) -> Scenario:
    """
    Load a scenario YAML file and normalize optional sections.

    Parameters
    ----------
    path : str | Path
        Scenario file path. If a relative path is given, it is resolved
        relative to the project root returned by `get_paths()`.

    Returns
    -------
    Scenario
        Loaded and normalized scenario wrapper.

    Raises
    ------
    FileNotFoundError
        If the scenario file does not exist.
    ValueError
        If the YAML content is empty or not a dictionary.
    """
    paths = get_paths()
    p = Path(path)
    if not p.is_absolute():
        p = (paths.root / p).resolve()

    if not p.exists():
        raise FileNotFoundError(f"Scenario file not found: {p}")

    with p.open("r", encoding="utf-8") as f:
        raw = yaml.safe_load(f)

    if raw is None:
        raise ValueError(f"Scenario file is empty: {p}")
    if not isinstance(raw, dict):
        raise ValueError(f"Scenario YAML must load to a dictionary: {p}")

    # ------------------------------------------------------------------
    # Normalize commonly expected top-level sections
    # ------------------------------------------------------------------
    raw.setdefault("sim", 
                   {"experiment": "single", 
                    "composition": "auto", 
                    "backend": "auto", 
                    "start_time": 0.0, 
                    "stop_time": 1.0, 
                    "step_size": 0.01, 
                    "tolerance": 1e-6})
    raw.setdefault("system", {"components": [], "connections": []})
    raw.setdefault("initialization", [])
    raw.setdefault("inputs", [])
    raw.setdefault("parameters", [])
    raw.setdefault("disturbances", [])
    raw.setdefault("output", 
                   {"log": [], 
                    "save_dir": "results", 
                    "save_name": "run", 
                    "save_log": False, 
                    "log_format": "csv", 
                    "save_metadata": False})

    return Scenario(raw=raw)