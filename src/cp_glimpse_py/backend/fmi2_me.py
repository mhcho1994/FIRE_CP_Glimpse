"""
FMI 2.0 Model Exchange backend.

This backend expects an existing ME FMU. Source-to-FMU materialization belongs
to `translator.materialize`, not backend runtime code.
"""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path
from typing import Any, Optional

from .base import BackendArtifact, SimulationBackend, StepResult
from ..common.logging import get_logger

log = get_logger(__name__)


def _component_from_scenario(scn: dict[str, Any]) -> dict[str, Any]:
    system_cfg = scn.get("system", {}) or {}
    components = system_cfg.get("components")
    if isinstance(components, list) and components:
        component = components[0]
        if isinstance(component, dict):
            return component

    model_cfg = scn.get("model", {}) or {}
    if isinstance(model_cfg, dict) and model_cfg:
        return model_cfg

    raise ValueError("FMI2MEBackend.from_scenario requires a materialized FMU component.")


def _resolve_fmu_path(component_cfg: dict[str, Any]) -> str:
    for key in ("model_path", "fmu_path", "artifact_path"):
        value = component_cfg.get(key)
        if not value:
            continue
        path = Path(value)
        if not path.exists():
            raise FileNotFoundError(f"FMU artifact not found for '{key}': {path}")
        if path.suffix.lower() != ".fmu":
            raise ValueError(f"FMI2MEBackend requires an .fmu artifact, got: {path}")
        return str(path)
    raise ValueError("Materialized component must define model_path/fmu_path/artifact_path.")


@dataclass
class FMI2MEBackendConfig:
    fmu_path: str
    instance_name: str = "fmi2_me"
    start_time: float = 0.0
    stop_time: Optional[float] = None
    tolerance: float = 1.0e-6
    visible: bool = False
    debug_logging: bool = False
    show_solver_log: bool = False


class FMI2MEBackend(SimulationBackend):
    """
    Generic FMI 2.0 Model Exchange backend for an existing FMU artifact.
    """

    def __init__(self, *, config: FMI2MEBackendConfig):
        self.config = config

        from .runtimes.pyfmi_runner import PyFMIRunner

        self._artifact = BackendArtifact(
            kind="fmu",
            path=config.fmu_path,
            metadata={"fmu_type": "me", "instance_name": config.instance_name},
        )
        self._runner = PyFMIRunner(
            fmu_path=config.fmu_path,
            instance_name=config.instance_name,
            fmu_type="me",
            start_time=config.start_time,
            stop_time=config.stop_time,
            tolerance=config.tolerance,
            visible=config.visible,
            debug_logging=config.debug_logging,
            show_solver_log=config.show_solver_log,
        )

    @classmethod
    def from_scenario(cls, scn: dict[str, Any]) -> "FMI2MEBackend":
        sim_cfg = scn.get("sim", {}) or {}
        fmu_type = str(sim_cfg.get("fmu_type", "me")).lower()
        if fmu_type != "me":
            raise ValueError(f"FMI2MEBackend requires fmu_type='me', got {fmu_type!r}")

        component = _component_from_scenario(scn)
        instance_name = str(component.get("name", component.get("class_name", "fmi2_me")))
        return cls(
            config=FMI2MEBackendConfig(
                fmu_path=_resolve_fmu_path(component),
                instance_name=instance_name,
                start_time=float(sim_cfg.get("t0", 0.0)),
                stop_time=float(sim_cfg["tf"]) if "tf" in sim_cfg else None,
                tolerance=float(sim_cfg.get("tol", 1.0e-6)),
                visible=bool(sim_cfg.get("visible", False)),
                debug_logging=bool(sim_cfg.get("debug_logging", False)),
                show_solver_log=bool(sim_cfg.get("show_solver_log", False)),
            )
        )

    @property
    def artifact(self) -> BackendArtifact:
        return self._artifact

    @property
    def io(self) -> dict[str, list[Any]]:
        return self._runner.io

    def initialize(self) -> None:
        log.info("Initializing FMI2 ME backend for %s", self.config.instance_name)
        self._runner.instantiate_and_initialize()

    def terminate(self) -> None:
        self._runner.terminate_and_free()

    def set_variable(self, name: str, value: Any) -> None:
        self._runner.set_value(name, value)

    def get_variable(self, name: str, default: Any = None) -> Any:
        return self._runner.get_value(name, default)

    def step(self, t: float, dt: float) -> StepResult:
        self._runner.step_or_raise(t, dt)
        return StepResult(t=t + dt, raw_status=0, accepted=True)

    def discovered_inputs(self) -> list[str]:
        return [v.name for v in self.io["inputs"]]
