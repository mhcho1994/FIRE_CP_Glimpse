"""
base.py
=======

Abstract backend interface for CP-Glimpse simulation backends.

This module defines a small, explicit contract for simulation backends so that
higher-level orchestration code can run different execution engines through a
common API.

Typical backend responsibilities
--------------------------------
A backend should:
- build or load a model artifact
- initialize the runtime
- expose discovered interface metadata
- apply inputs
- advance the simulation by one step
- read variables
- terminate cleanly

This interface is intentionally minimal. It is designed to support:
- single-FMU simulation
- multi-FMU/network orchestration
- future non-FMU backends (e.g., CasADi, direct Modelica, reachability analysis)

Design note
-----------
This interface does not assume:
- a specific vehicle model
- open-loop or closed-loop logic
- a specific scenario format beyond basic model/sim/input/output sections

Those concerns should live in higher orchestration layers.
"""

from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass, field
from typing import Any, Optional


@dataclass
class BackendArtifact:
    """
    Generic description of a built/loaded executable model artifact.

    Attributes
    ----------
    kind : str
        Artifact kind, e.g. "modelica", "fmu", "casadi".
    path : str
        Filesystem path to the primary artifact.
    metadata : dict[str, Any]
        Extra backend-specific metadata.
    """
    kind: str
    path: str
    metadata: dict[str, Any] = field(default_factory=dict)


@dataclass
class StepResult:
    """
    Result returned by a backend step.

    Attributes
    ----------
    t : float
        New simulation time after stepping.
    raw_status : Any
        Backend-native step status (e.g., FMI integer status code).
    accepted : bool
        Whether the step was accepted.
    message : str | None
        Optional human-readable information.
    """
    t: float
    raw_status: Any
    accepted: bool
    message: Optional[str] = None


class SimulationBackend(ABC):
    """
    Abstract base class for CP-Glimpse simulation backends.
    """

    @property
    @abstractmethod
    def artifact(self) -> BackendArtifact:
        """Return the loaded/built artifact metadata."""

    @property
    @abstractmethod
    def io(self) -> dict[str, list[Any]]:
        """
        Return discovered interface metadata.

        For FMU backends, this may mirror modelDescription-derived groupings such as:
            {"inputs": [...], "outputs": [...], "parameters": [...], "locals": [...]}
        """

    @abstractmethod
    def initialize(self) -> None:
        """Initialize the runtime and make it ready for stepping."""

    @abstractmethod
    def terminate(self) -> None:
        """Terminate and release all backend resources."""

    @abstractmethod
    def set_variable(self, name: str, value: Any) -> None:
        """Set a variable by name using backend-specific type routing."""

    @abstractmethod
    def get_variable(self, name: str, default: Any = None) -> Any:
        """Get a variable by name using backend-specific type routing."""

    @abstractmethod
    def step(self, t: float, dt: float) -> StepResult:
        """Advance the simulation by one step."""

    def __enter__(self) -> "SimulationBackend":
        self.initialize()
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        self.terminate()