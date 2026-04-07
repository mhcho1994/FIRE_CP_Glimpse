"""
pyfmi_runner.py
===============

Low-level FMI 2.0 Co-Simulation runtime adapter built on top of PyFMI.

This module provides a lifecycle-safe wrapper for Co-Simulation FMUs loaded
through `pyfmi.load_fmu()`.

Responsibilities
----------------
- load a Co-Simulation FMU
- discover variable metadata from the loaded model
- provide typed set/get helpers
- provide a deterministic fixed-step do_step() interface
- manage the FMU lifecycle safely

Notes
-----
- PyFMI is usually more mature for FMI 2.0 workflows, but availability depends
  on platform and installation.
- This module assumes Co-Simulation usage.
- This adapter intentionally avoids scenario-specific logic.
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Optional

try:
    from pyfmi import load_fmu
except ImportError as e:
    raise ImportError(
        "PyFMI is not installed. Install pyfmi before using pyfmi_runner.py."
    ) from e


@dataclass(frozen=True)
class VarInfo:
    """
    Minimal metadata for a variable discovered from a PyFMI model.

    Attributes
    ----------
    name : str
        Variable name.
    vr : int
        Value reference.
    causality : str | None
        FMI causality, when available.
    variability : str | None
        FMI variability, when available.
    initial : str | None
        FMI initial attribute, when available.
    type_name : str
        Inferred variable type.
    """
    name: str
    vr: int
    causality: Optional[str]
    variability: Optional[str]
    initial: Optional[str]
    type_name: str


def _normalize_type_name(var) -> str:
    """
    Infer a readable type name from a PyFMI variable object.

    PyFMI exposes integer type codes/enums depending on version, so this function
    normalizes them into strings such as real/integer/boolean/string/enumeration.
    """
    type_candidates = [
        getattr(var, "type", None),
        getattr(var, "type_name", None),
    ]

    for item in type_candidates:
        if item is None:
            continue

        s = str(item).lower()
        if "real" in s:
            return "real"
        if "int" in s:
            return "integer"
        if "bool" in s:
            return "boolean"
        if "string" in s:
            return "string"
        if "enum" in s:
            return "enumeration"

    return "unknown"


def build_vr_map(model_variables: dict) -> dict[str, int]:
    """
    Build name -> valueReference mapping from PyFMI model variables.
    """
    out: dict[str, int] = {}
    for name, var in model_variables.items():
        vr = getattr(var, "value_reference", None)
        if vr is not None:
            out[name] = int(vr)
    return out


def extract_io_from_model_variables(model_variables: dict) -> dict[str, list[VarInfo]]:
    """
    Group variables into inputs, outputs, parameters, and locals.

    This uses PyFMI variable metadata when available.
    """
    inputs: list[VarInfo] = []
    outputs: list[VarInfo] = []
    params: list[VarInfo] = []
    locals_: list[VarInfo] = []

    for name, v in model_variables.items():
        info = VarInfo(
            name=str(name),
            vr=int(getattr(v, "value_reference", -1)),
            causality=getattr(v, "causality", None),
            variability=getattr(v, "variability", None),
            initial=getattr(v, "initial", None),
            type_name=_normalize_type_name(v),
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


class PyFMIRunner:
    """
    Safe lifecycle wrapper for a Co-Simulation FMU using PyFMI.

    Parameters
    ----------
    fmu_path : str
        Path to the FMU archive.
    instance_name : str
        Instance name used for logging/debugging.
    start_time : float
        Simulation start time.
    stop_time : float | None
        Optional stop time.
    visible : bool
        Reserved for API symmetry. PyFMI does not typically use this.
    debug_logging : bool
        Reserved for API symmetry. FMU logging support depends on backend.
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

        # Require Co-Simulation FMU.
        self.fmu = load_fmu(self.fmu_path, kind="CS")

        model_variables = self.fmu.get_model_variables()
        self.vrs = build_vr_map(model_variables)
        self.io = extract_io_from_model_variables(model_variables)

        self._type_map: dict[str, str] = {}
        for group in self.io.values():
            for var in group:
                self._type_map[var.name] = var.type_name

        self._instantiated = False
        self._initialized = False
        self._terminated = False

    def instantiate_and_initialize(self) -> None:
        """
        Move the FMU to simulation-ready state.

        PyFMI lifecycle used here:
            instantiate -> setup_experiment -> initialize
        """
        if self._terminated:
            raise RuntimeError("Cannot initialize a terminated FMU.")
        if self._initialized:
            return

        if not self._instantiated:
            self.fmu.instantiate()
            self._instantiated = True

        if self.stop_time is None:
            self.fmu.setup_experiment(start_time=self.start_time)
        else:
            self.fmu.setup_experiment(
                start_time=self.start_time,
                stop_time=self.stop_time,
            )

        self.fmu.initialize()
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
                try:
                    self.fmu.terminate()
                except Exception:
                    # Some FMUs/PyFMI combinations may already be partially torn down.
                    pass
        finally:
            if self._instantiated:
                try:
                    self.fmu.free_instance()
                except Exception:
                    pass
            self._terminated = True

    def __enter__(self) -> "PyFMIRunner":
        self.instantiate_and_initialize()
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        self.terminate_and_free()

    def variable_type(self, name: str) -> str:
        """
        Return the discovered type of a variable.
        """
        t = self._type_map.get(name)
        if t is None:
            raise KeyError(f"Unknown variable name: {name}")
        return t

    def set_real(self, name: str, value: float) -> None:
        self.fmu.set(name, float(value))

    def set_integer(self, name: str, value: int) -> None:
        self.fmu.set(name, int(value))

    def set_boolean(self, name: str, value: bool) -> None:
        self.fmu.set(name, bool(value))

    def get_real(self, name: str, default: Optional[float] = None) -> float:
        try:
            return float(self.fmu.get(name))
        except Exception:
            if default is None:
                raise
            return float(default)

    def get_integer(self, name: str, default: Optional[int] = None) -> int:
        try:
            return int(self.fmu.get(name))
        except Exception:
            if default is None:
                raise
            return int(default)

    def get_boolean(self, name: str, default: Optional[bool] = None) -> bool:
        try:
            return bool(self.fmu.get(name))
        except Exception:
            if default is None:
                raise
            return bool(default)

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

    def step(self, t: float, dt: float) -> int:
        """
        Execute one co-simulation step.

        Returns
        -------
        int
            A normalized status code:
            - 0: accepted
            - 1: accepted with warning/reserved
            PyFMI does not usually expose FMI status codes the same way FMPy does,
            so successful completion is normalized to 0.
        """
        if not self._initialized:
            raise RuntimeError("FMU not initialized.")
        if self._terminated:
            raise RuntimeError("FMU already terminated.")

        self.fmu.do_step(
            current_t=float(t),
            step_size=float(dt),
            new_step=True,
        )
        return 0

    def step_or_raise(self, t: float, dt: float) -> None:
        """
        Step once and let PyFMI exceptions propagate as failures.
        """
        self.step(t, dt)