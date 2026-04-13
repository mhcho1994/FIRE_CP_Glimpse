"""
cp_glimpse_py.backend.fmi2_cs
=============================

FMI 2.0 Co-Simulation backend for CP-Glimpse.

Purpose
-------
This backend executes an already-prepared FMI 2.0 Co-Simulation FMU artifact.

Design boundary
---------------
This module is intentionally execution-focused.

It is responsible for:
- loading an FMU artifact
- creating and owning a runtime adapter
- routing variable reads/writes by discovered FMI type
- advancing fixed communication steps
- normalizing backend-native status into StepResult

It is NOT responsible for:
- deciding how scenario model sources should be translated
- building FMUs from Modelica source directly
- organizing translation/build pipelines

Those concerns belong to:
- cp_glimpse_py.materialize.*
- cp_glimpse_py.translator.*
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Any, Optional

from fmpy.fmi2 import fmi2Discard, fmi2Error, fmi2OK, fmi2Warning

from .base import BackendArtifact, SimulationBackend, StepResult
from .runtimes.fmpy_runner import FMPYRunner
from ..common.logging import get_logger

log = get_logger(__name__)


@dataclass
class FMI2CSBackendConfig:
    """
    Configuration for an FMI 2.0 Co-Simulation backend instance.
    """
    fmu_path: str
    instance_name: str
    start_time: float = 0.0
    stop_time: Optional[float] = None
    visible: bool = False
    debug_logging: bool = False
    treat_discard_as_error: bool = True


class FMI2CSBackend(SimulationBackend):
    """
    Generic FMI 2.0 Co-Simulation backend.
    """

    def __init__(
        self,
        *,
        artifact: BackendArtifact,
        config: FMI2CSBackendConfig,
    ):
        if artifact.kind != "fmu":
            raise ValueError(
                f"FMI2CSBackend requires artifact.kind == 'fmu', got {artifact.kind!r}"
            )

        self._artifact = artifact
        self.config = config

        self._runner = FMPYRunner(
            fmu_path=config.fmu_path,
            instance_name=config.instance_name,
            start_time=config.start_time,
            stop_time=config.stop_time,
            visible=config.visible,
            debug_logging=config.debug_logging,
        )

        self._type_map: dict[str, str] = {}
        for group in self._runner.io.values():
            for var in group:
                self._type_map[var.name] = var.type_name

    @classmethod
    def from_artifact(
        cls,
        artifact: BackendArtifact,
        *,
        sim_cfg: Optional[dict] = None,
        instance_name: Optional[str] = None,
    ) -> "FMI2CSBackend":
        """
        Construct an FMI 2.0 CS backend from a prepared FMU artifact.
        """
        if artifact.kind != "fmu":
            raise ValueError(
                f"FMI2CSBackend.from_artifact() requires artifact.kind='fmu', "
                f"got {artifact.kind!r}."
            )

        sim_cfg = sim_cfg or {}
        meta = artifact.metadata or {}

        fmu_type = str(meta.get("fmu_type", sim_cfg.get("fmu_type", "cs"))).lower()
        if fmu_type != "cs":
            raise ValueError(
                f"FMI2CSBackend requires fmu_type='cs', got {fmu_type!r}."
            )

        resolved_instance_name = (
            instance_name
            or meta.get("class_name")
            or _default_instance_name_from_path(artifact.path)
        )

        config = FMI2CSBackendConfig(
            fmu_path=str(artifact.path),
            instance_name=str(resolved_instance_name),
            start_time=float(sim_cfg.get("t0", 0.0)),
            stop_time=float(sim_cfg["tf"]) if "tf" in sim_cfg else None,
            visible=bool(sim_cfg.get("visible", False)),
            debug_logging=bool(sim_cfg.get("debug_logging", False)),
            treat_discard_as_error=bool(sim_cfg.get("treat_discard_as_error", True)),
        )

        return cls(artifact=artifact, config=config)

    @classmethod
    def from_component(
        cls,
        component_cfg: dict[str, Any],
        *,
        sim_cfg: Optional[dict] = None,
    ) -> "FMI2CSBackend":
        """
        Construct the backend directly from a materialized component config.

        Expected component fields
        -------------------------
        - model_path: path to a runnable FMU
        - class_name: optional instance/class name hint
        - _artifact: optional materialization metadata
        """
        sim_cfg = sim_cfg or {}

        model_path = component_cfg.get("model_path") or component_cfg.get("fmu_path")
        if not model_path:
            raise KeyError("Component must define 'model_path' or 'fmu_path'.")

        artifact = BackendArtifact(
            kind="fmu",
            path=str(model_path),
            metadata={
                "class_name": component_cfg.get("class_name"),
                "fmu_type": str(sim_cfg.get("fmu_type", "cs")).lower(),
                **(component_cfg.get("_artifact", {}) or {}),
            },
        )

        return cls.from_artifact(
            artifact,
            sim_cfg=sim_cfg,
            instance_name=component_cfg.get("name") or component_cfg.get("class_name"),
        )

    @property
    def artifact(self) -> BackendArtifact:
        return self._artifact

    @property
    def io(self) -> dict[str, list[Any]]:
        return self._runner.io

    def initialize(self) -> None:
        log.info(
            "Initializing FMI2CS backend: fmu=%s, instance=%s",
            self.config.fmu_path,
            self.config.instance_name,
        )
        self._runner.instantiate_and_initialize()

    def terminate(self) -> None:
        self._runner.terminate_and_free()

    def _var_type(self, name: str) -> str:
        t = self._type_map.get(name)
        if t is None:
            raise KeyError(f"Unknown variable name: {name}")
        return t

    def set_variable(self, name: str, value: Any) -> None:
        """
        Set a variable using discovered FMI type routing.
        """
        t = self._var_type(name)

        if t == "real":
            self._runner.set_real(name, float(value))
            return

        if t in ("integer", "enumeration"):
            self._runner.set_integer(name, int(value))
            return

        if t == "boolean":
            self._runner.set_boolean(name, bool(value))
            return

        raise TypeError(f"Setting variable {name!r} of unsupported type {t!r}")

    def get_variable(self, name: str, default: Any = None) -> Any:
        """
        Get a variable using discovered FMI type routing.
        """
        t = self._type_map.get(name)
        if t is None:
            if default is not None:
                return default
            raise KeyError(f"Unknown variable name: {name}")

        if t == "real":
            return self._runner.get_real(name, default)
        if t in ("integer", "enumeration"):
            return self._runner.get_integer(name, default)
        if t == "boolean":
            return self._runner.get_boolean(name, default)

        if default is not None:
            return default

        raise TypeError(f"Getting variable {name!r} of unsupported type {t!r}")

    def step(self, t: float, dt: float) -> StepResult:
        """
        Advance the FMU by one communication step.

        Policy
        ------
        - fmi2OK / fmi2Warning: accepted
        - fmi2Discard: configurable fatal/non-fatal
        - fmi2Error: fatal
        """
        status = self._runner.step(t, dt)

        if status == fmi2OK:
            return StepResult(t=t + dt, raw_status=status, accepted=True)

        if status == fmi2Warning:
            return StepResult(
                t=t + dt,
                raw_status=status,
                accepted=True,
                message="FMU step completed with warning.",
            )

        if status == fmi2Discard:
            msg = (
                f"FMU discarded step at t={t:.6g} (dt={dt:.6g}). "
                "Try smaller dt or inspect FMU event handling."
            )
            if self.config.treat_discard_as_error:
                raise RuntimeError(msg)
            return StepResult(t=t, raw_status=status, accepted=False, message=msg)

        if status == fmi2Error:
            raise RuntimeError(
                f"FMU doStep returned error at t={t:.6g} (dt={dt:.6g})."
            )

        raise RuntimeError(f"Unexpected FMI status code: {status}")

    def discovered_inputs(self) -> list[str]:
        """Return discovered input variable names."""
        return [v.name for v in self.io["inputs"]]

    def discovered_outputs(self) -> list[str]:
        """Return discovered output variable names."""
        return [v.name for v in self.io["outputs"]]

    def discovered_parameters(self) -> list[str]:
        """Return discovered parameter variable names."""
        return [v.name for v in self.io["parameters"]]


def _default_instance_name_from_path(path: str) -> str:
    """
    Derive a reasonable FMI instance name from an artifact path.
    """
    import os
    return os.path.splitext(os.path.basename(path))[0]