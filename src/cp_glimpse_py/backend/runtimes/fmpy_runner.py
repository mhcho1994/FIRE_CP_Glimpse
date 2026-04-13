"""
cp_glimpse_py.backend.runtimes.fmpy_runner
=======

Low-level FMI 2.0 Co-Simulation runtime adapter built on top of FMPy.

This module is responsible for:
- extracting and reading the FMU model description
- building name -> valueReference lookup tables
- classifying variables by causality / variability
- managing the FMI 2.0 Co-Simulation lifecycle safely
- providing typed set/get helpers
- exposing a minimal step() API

This is a runtime adapter, not a scenario runner.
Higher-level orchestration (single-FMU simulation, coupled FMU simulation,
closed-loop execution, attack injection, etc.) should live elsewhere.

Notes
-----
- This module is designed for FMI 2.0 Co-Simulation FMUs.
- It uses FMPy's FMU2Slave wrapper directly.
- It does not implement a full master algorithm.
- It keeps the control flow explicit and deterministic.
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Optional

from fmpy import extract, read_model_description
from fmpy.fmi2 import (
    FMU2Slave,
    fmi2Discard,
    fmi2Error,
    fmi2OK,
    fmi2Warning,
)


@dataclass(frozen=True)
class VarInfo:
    """
    Minimal metadata for a variable discovered from modelDescription.xml.

    Attributes
    ----------
    name : str
        Variable name.
    vr : int
        FMI value reference.
    causality : str | None
        FMI causality such as input, output, parameter, local.
    variability : str | None
        FMI variability such as continuous, discrete, parameter.
    initial : str | None
        FMI initial attribute if present.
    type_name : str
        One of real, integer, boolean, string, enumeration, unknown.
    """
    name: str
    vr: int
    causality: Optional[str]
    variability: Optional[str]
    initial: Optional[str]
    type_name: str


def _var_type_name(v) -> str:
    """
    Infer the FMI base type from an FMPy variable object.
    """
    for t in ("real", "integer", "boolean", "string", "enumeration"):
        if getattr(v, t, None) is not None:
            return t
    return "unknown"


def build_vr_map(md) -> dict[str, int]:
    """
    Build a name -> valueReference mapping from an FMPy model description.
    """
    return {v.name: v.valueReference for v in md.modelVariables}


def extract_io_from_model_description(md) -> dict[str, list[VarInfo]]:
    """
    Group variables into inputs, outputs, parameters, and locals.

    Classification rules
    --------------------
    - inputs: causality == "input"
    - outputs: causality == "output"
    - parameters: variability == "parameter" or causality == "parameter"
    - locals: everything else
    """
    inputs: list[VarInfo] = []
    outputs: list[VarInfo] = []
    params: list[VarInfo] = []
    locals_: list[VarInfo] = []

    for v in md.modelVariables:
        info = VarInfo(
            name=v.name,
            vr=v.valueReference,
            causality=getattr(v, "causality", None),
            variability=getattr(v, "variability", None),
            initial=getattr(v, "initial", None),
            type_name=_var_type_name(v),
        )

        if info.causality == "input":
            inputs.append(info)
        elif info.causality == "output":
            outputs.append(info)
        elif info.variability == "parameter" or info.causality == "parameter":
            params.append(info)
        else:
            locals_.append(info)

    inputs.sort(key=lambda x: x.name)
    outputs.sort(key=lambda x: x.name)
    params.sort(key=lambda x: x.name)
    locals_.sort(key=lambda x: x.name)

    return {
        "inputs": inputs,
        "outputs": outputs,
        "parameters": params,
        "locals": locals_,
    }


class FMPYRunner:
    """
    Safe lifecycle wrapper for an FMI 2.0 Co-Simulation FMU using FMPy.

    Parameters
    ----------
    fmu_path : str
        Path to the FMU archive.
    instance_name : str
        FMI instance name.
    start_time : float
        Simulation start time.
    stop_time : float | None
        Optional stop time passed to setupExperiment.
    visible : bool
        Whether the FMU may display a UI.
    debug_logging : bool
        Whether to request FMU-side logging if supported.

    Attributes
    ----------
    md
        Parsed model description.
    vrs
        Variable name -> valueReference map.
    io
        Grouped interface metadata.
    """

    def __init__(
        self,
        *,
        fmu_path: str,
        instance_name: str,
        start_time: float = 0.0,
        stop_time: Optional[float] = None,
        visible: bool = False,
        debug_logging: bool = False,
    ):
        self.fmu_path = str(fmu_path)
        self.instance_name = str(instance_name)
        self.start_time = float(start_time)
        self.stop_time = None if stop_time is None else float(stop_time)
        self.visible = bool(visible)
        self.debug_logging = bool(debug_logging)

        self.unzipdir = extract(self.fmu_path)
        self.md = read_model_description(self.unzipdir)

        if self.md.coSimulation is None:
            raise RuntimeError(f"{self.fmu_path} has no CoSimulation section.")

        self.vrs = build_vr_map(self.md)
        self.io = extract_io_from_model_description(self.md)

        self.fmu = FMU2Slave(
            guid=self.md.guid,
            unzipDirectory=self.unzipdir,
            modelIdentifier=self.md.coSimulation.modelIdentifier,
            instanceName=self.instance_name,
        )

        self._instantiated = False
        self._initialized = False
        self._terminated = False

        self._type_map: dict[str, str] = {}
        for group in self.io.values():
            for var in group:
                self._type_map[var.name] = var.type_name

    def instantiate_and_initialize(self) -> None:
        """
        Move the FMU into step mode.

        Lifecycle:
            instantiate -> setupExperiment -> enterInitializationMode
            -> exitInitializationMode
        """
        if self._terminated:
            raise RuntimeError("Cannot initialize a terminated FMU.")
        if self._initialized:
            return

        if not self._instantiated:
            self.fmu.instantiate(
                visible=self.visible,
                loggingOn=self.debug_logging,
            )
            self._instantiated = True

        if self.stop_time is None:
            self.fmu.setupExperiment(startTime=self.start_time)
        else:
            self.fmu.setupExperiment(
                startTime=self.start_time,
                stopTime=self.stop_time,
            )

        self.fmu.enterInitializationMode()
        self.fmu.exitInitializationMode()

        self._initialized = True

    def terminate_and_free(self) -> None:
        """
        Terminate the FMU and release resources.

        This method is idempotent.
        """
        if self._terminated:
            return

        try:
            if self._instantiated:
                self.fmu.terminate()
        finally:
            if self._instantiated:
                self.fmu.freeInstance()
            self._terminated = True

    def __enter__(self) -> "FMPYRunner":
        self.instantiate_and_initialize()
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        self.terminate_and_free()

    def _vr(self, name: str) -> int:
        vr = self.vrs.get(name)
        if vr is None:
            raise KeyError(f"Unknown variable name: {name}")
        return vr

    def variable_type(self, name: str) -> str:
        """
        Return the discovered FMI type of a variable.
        """
        t = self._type_map.get(name)
        if t is None:
            raise KeyError(f"Unknown variable name: {name}")
        return t

    def set_real(self, name: str, value: float) -> None:
        self.fmu.setReal([self._vr(name)], [float(value)])

    def set_integer(self, name: str, value: int) -> None:
        self.fmu.setInteger([self._vr(name)], [int(value)])

    def set_boolean(self, name: str, value: bool) -> None:
        self.fmu.setBoolean([self._vr(name)], [bool(value)])

    def get_real(self, name: str, default: Optional[float] = None) -> float:
        vr = self.vrs.get(name)
        if vr is None:
            if default is None:
                raise KeyError(f"Unknown variable name: {name}")
            return float(default)
        return float(self.fmu.getReal([vr])[0])

    def get_integer(self, name: str, default: Optional[int] = None) -> int:
        vr = self.vrs.get(name)
        if vr is None:
            if default is None:
                raise KeyError(f"Unknown variable name: {name}")
            return int(default)
        return int(self.fmu.getInteger([vr])[0])

    def get_boolean(self, name: str, default: Optional[bool] = None) -> bool:
        vr = self.vrs.get(name)
        if vr is None:
            if default is None:
                raise KeyError(f"Unknown variable name: {name}")
            return bool(default)
        return bool(self.fmu.getBoolean([vr])[0])

    def set_value(self, name: str, value) -> None:
        """
        Set a variable using automatic type routing.
        """
        t = self.variable_type(name)

        if t == "real":
            self.set_real(name, float(value))
        elif t in ("integer", "enumeration"):
            self.set_integer(name, int(value))
        elif t == "boolean":
            self.set_boolean(name, bool(value))
        else:
            raise TypeError(f"Unsupported set type for {name!r}: {t!r}")

    def get_value(self, name: str, default=None):
        """
        Get a variable using automatic type routing.
        """
        t = self._type_map.get(name)
        if t is None:
            if default is not None:
                return default
            raise KeyError(f"Unknown variable name: {name}")

        if t == "real":
            return self.get_real(name, default)
        if t in ("integer", "enumeration"):
            return self.get_integer(name, default)
        if t == "boolean":
            return self.get_boolean(name, default)

        if default is not None:
            return default
        raise TypeError(f"Unsupported get type for {name!r}: {t!r}")

    def step(
        self,
        t: float,
        dt: float,
        *,
        no_set_fmu_state_prior: bool = True,
    ) -> int:
        """
        Execute one FMI doStep call.

        Returns
        -------
        int
            FMI status code such as fmi2OK, fmi2Warning, fmi2Discard, fmi2Error.
        """
        if not self._initialized:
            raise RuntimeError("FMU not initialized.")
        if self._terminated:
            raise RuntimeError("FMU already terminated.")

        return self.fmu.doStep(
            currentCommunicationPoint=float(t),
            communicationStepSize=float(dt),
            noSetFMUStatePriorToCurrentPoint=bool(no_set_fmu_state_prior),
        )

    def step_or_raise(self, t: float, dt: float) -> None:
        """
        Step once and raise on discard/error.
        """
        status = self.step(t, dt)

        if status == fmi2Discard:
            raise RuntimeError(
                f"FMU discarded step at t={t:.6g}, dt={dt:.6g}."
            )
        if status == fmi2Error:
            raise RuntimeError(
                f"FMU doStep failed at t={t:.6g}, dt={dt:.6g}."
            )

    @staticmethod
    def ok_statuses() -> tuple[int, int]:
        """
        Return status codes typically treated as accepted.
        """
        return (fmi2OK, fmi2Warning)