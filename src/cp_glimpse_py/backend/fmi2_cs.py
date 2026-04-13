"""
cp_glimpse_py.backend.fmi2_cs
=======


FMI 2.0 Co-Simulation backend for CP-Glimpse.

This backend wraps:
- FMU build/loading
- FMI2CSRunner lifecycle management
- variable type routing
- fixed-step stepping interface

It is intentionally generic and model-agnostic. Vehicle-specific logic
(rover, quadrotor, etc.) should live outside this module.

Expected usage
--------------
    backend = FMI2CSBackend.from_scenario(scn)
    with backend:
        backend.set_variable("u", 0.2)
        result = backend.step(t=0.0, dt=0.1)
        y = backend.get_variable("y")
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Any, Optional

from fmpy.fmi2 import fmi2Discard, fmi2Error, fmi2OK, fmi2Warning

from .base import BackendArtifact, SimulationBackend, StepResult
from .fmu_runner import FMI2CSRunner
from ..common.logging import get_logger
from ..translator.mo_to_fmu import build_fmu, resolve_model_class_name

log = get_logger(__name__)


def _resolve_class_name(model_cfg: dict) -> str:
    """
    Resolve the Modelica class name from scenario config.

    Preferred:
        model:
          mo_path: ...
          class_name: MyModel

    Legacy compatibility:
        model:
          mo_path: ...
          components:
            rover: Rover3D
    """
    if "class_name" in model_cfg and model_cfg["class_name"]:
        return str(model_cfg["class_name"])

    comps = model_cfg.get("components", {})
    if isinstance(comps, dict) and len(comps) >= 1:
        k = sorted(comps.keys())[0]
        return str(comps[k])

    return resolve_model_class_name(mo_path=model_cfg["mo_path"], class_name=None)


@dataclass
class FMI2CSBackendConfig:
    """
    Configuration for an FMI 2.0 Co-Simulation backend instance.
    """
    mo_path: str
    class_name: str
    fmu_type: str = "cs"
    start_time: float = 0.0
    stop_time: Optional[float] = None
    visible: bool = False
    debug_logging: bool = False
    treat_discard_as_error: bool = True


class FMI2CSBackend(SimulationBackend):
    """
    Generic FMI 2.0 Co-Simulation backend.

    Responsibilities
    ----------------
    - Build/load a Co-Simulation FMU
    - Initialize and own an FMI2CSRunner
    - Route typed variable reads/writes by inspecting modelDescription metadata
    - Normalize step return information into StepResult
    """

    def __init__(self, *, config: FMI2CSBackendConfig):
        self.config = config

        art = build_fmu(
            mo_path=config.mo_path,
            class_name=config.class_name,
            fmu_type=config.fmu_type,
        )

        self._artifact = BackendArtifact(
            kind="fmu",
            path=str(art.fmu_path),
            metadata={
                "mo_path": config.mo_path,
                "class_name": config.class_name,
                "fmu_type": config.fmu_type,
            },
        )

        self._runner = FMI2CSRunner(
            fmu_path=str(art.fmu_path),
            instance_name=config.class_name,
            start_time=config.start_time,
            stop_time=config.stop_time,
            visible=config.visible,
            debug_logging=config.debug_logging,
        )

        # Cache type information for variable routing.
        self._type_map = {}
        for group in self._runner.io.values():
            for var in group:
                self._type_map[var.name] = var.type_name

    @classmethod
    def from_scenario(cls, scn: dict) -> "FMI2CSBackend":
        """
        Create a backend from a CP-Glimpse scenario dictionary.
        """
        model_cfg = scn["model"]
        sim_cfg = scn["sim"]

        fmu_type = str(sim_cfg.get("fmu_type", "cs")).lower()
        if fmu_type != "cs":
            raise ValueError(f"FMI2CSBackend requires fmu_type='cs', got {fmu_type!r}")

        config = FMI2CSBackendConfig(
            mo_path=model_cfg["mo_path"],
            class_name=_resolve_class_name(model_cfg),
            fmu_type=fmu_type,
            start_time=float(sim_cfg.get("t0", 0.0)),
            stop_time=float(sim_cfg["tf"]) if "tf" in sim_cfg else None,
            visible=bool(sim_cfg.get("visible", False)),
            debug_logging=bool(sim_cfg.get("debug_logging", False)),
            treat_discard_as_error=bool(sim_cfg.get("treat_discard_as_error", True)),
        )
        return cls(config=config)

    @property
    def artifact(self) -> BackendArtifact:
        return self._artifact

    @property
    def io(self) -> dict[str, list[Any]]:
        return self._runner.io

    def initialize(self) -> None:
        """
        Initialize the underlying FMI runner.
        """
        log.info("Initializing FMI2CS backend for %s", self.config.class_name)
        self._runner.instantiate_and_initialize()

    def terminate(self) -> None:
        """
        Terminate and free the underlying FMI runner.
        """
        self._runner.terminate_and_free()

    def _var_type(self, name: str) -> str:
        """
        Return the discovered FMI base type of a variable.
        """
        t = self._type_map.get(name)
        if t is None:
            raise KeyError(f"Unknown variable name: {name}")
        return t

    def set_variable(self, name: str, value: Any) -> None:
        """
        Set a variable using modelDescription-derived type routing.
        """
        t = self._var_type(name)

        if t == "real":
            self._runner.set_real(name, float(value))
        elif t in ("integer", "enumeration"):
            self._runner.set_integer(name, int(value))
        elif t == "boolean":
            self._runner.set_boolean(name, bool(value))
        else:
            raise TypeError(f"Setting variable {name!r} of unsupported type {t!r}")

    def get_variable(self, name: str, default: Any = None) -> Any:
        """
        Get a variable using modelDescription-derived type routing.
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
