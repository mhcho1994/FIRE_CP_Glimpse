from __future__ import annotations

from dataclasses import dataclass, field
from pathlib import Path
from typing import Any, Iterator
import yaml

from ..common.paths import get_paths


@dataclass
class Scenario:
    """
    Thin dict-like wrapper around a loaded scenario configuration.

    Purpose
    -------
    This class preserves convenient attribute-style access for common
    scenario sections such as `sim`, `model`, and `params`, while also
    supporting dictionary-style methods like `.get(...)`, `.keys()`,
    and item access `scn["sim"]`.

    Why this exists
    ---------------
    Some parts of the codebase treat the loaded scenario as a structured
    object with properties, while others treat it as a plain dictionary.
    This wrapper supports both styles so that callers do not need to care
    whether the underlying representation is a dataclass or a dict.

    Notes
    -----
    - `raw` stores the original normalized scenario dictionary.
    - Missing optional sections are normalized during loading.
    - Missing required sections such as `sim` are also defaulted to an empty
      dictionary so downstream code can safely call `scn.get("sim", {})`.
    """

    raw: dict[str, Any] = field(default_factory=dict)

    # ------------------------------------------------------------------
    # Common scenario sections
    # ------------------------------------------------------------------
    @property
    def model(self) -> dict[str, Any]:
        """
        Return the single-model section.

        Returns
        -------
        dict[str, Any]
            Scenario `model` section, or an empty dict if absent.
        """
        return self.raw.get("model", {})

    @property
    def models(self) -> dict[str, Any]:
        """
        Return the multi-model section.

        Returns
        -------
        dict[str, Any]
            Scenario `models` section, or an empty dict if absent.
        """
        return self.raw.get("models", {})

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
    def params(self) -> dict[str, Any]:
        """
        Return the parameter section.

        Returns
        -------
        dict[str, Any]
            Scenario `params` section, or an empty dict if absent.
        """
        return self.raw.get("params", {})

    @property
    def attack(self) -> dict[str, Any]:
        """
        Return the attack configuration section.

        Returns
        -------
        dict[str, Any]
            Scenario `attack` section, defaulting to `{"scenario": 0}`.
        """
        return self.raw.get("attack", {"scenario": 0})

    @property
    def output(self) -> dict[str, Any]:
        """
        Return the output configuration section.

        Returns
        -------
        dict[str, Any]
            Scenario `output` section, or an empty dict if absent.
        """
        return self.raw.get("output", {})

    @property
    def montecarlo(self) -> dict[str, Any]:
        """
        Return the Monte Carlo configuration section.

        Returns
        -------
        dict[str, Any]
            Scenario `montecarlo` section, or an empty dict if absent.
        """
        return self.raw.get("montecarlo", {})

    @property
    def connections(self) -> list[dict[str, Any]]:
        """
        Return the model connection list for multi-model scenarios.

        Returns
        -------
        list[dict[str, Any]]
            Scenario `connections` section, or an empty list if absent.
        """
        return self.raw.get("connections", [])

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
    raw.setdefault("sim", {})
    raw.setdefault("params", {})
    raw.setdefault("attack", {"scenario": 0})
    raw.setdefault("output", {})
    raw.setdefault("montecarlo", {})
    raw.setdefault("connections", [])

    # Do not force both `model` and `models` to exist with non-empty values,
    # but normalize their presence so callers can safely access them.
    raw.setdefault("model", {})
    raw.setdefault("models", {})

    return Scenario(raw=raw)