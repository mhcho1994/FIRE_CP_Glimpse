"""
pyfmi_runner.py
===============

Low-level FMI 2.0 runtime adapter built on top of PyFMI.

This module provides a lifecycle-safe wrapper for FMUs loaded through
`pyfmi.load_fmu()`.

Responsibilities
----------------
- load a Co-Simulation or Model Exchange FMU
- discover variable metadata from the loaded model
- provide typed set/get helpers
- provide a deterministic fixed-step interface
- manage the FMU lifecycle safely

Notes
-----
- PyFMI is usually more mature for FMI 2.0 workflows, but availability depends
  on platform and installation.
- Co-Simulation uses `do_step()`.
- Model Exchange currently uses short local `simulate()` segments and restores
  the terminal state, mirroring the legacy examples.
- This adapter intentionally avoids scenario-specific logic.
"""

from __future__ import annotations

import contextlib
import io
from dataclasses import dataclass
from typing import Any, Optional


_MISSING = object()


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


def _normalize_pyfmi_value(value):
    """
    Convert PyFMI get() results into plain Python values where possible.

    PyFMI often returns NumPy arrays even for scalar variables. Scalar-like
    arrays are unwrapped; vector values are returned as Python lists.
    """
    if hasattr(value, "shape") and hasattr(value, "size"):
        if value.size == 1:
            return value.reshape(-1)[0].item()
        return value.tolist()

    if isinstance(value, (list, tuple)):
        if len(value) == 1:
            item = value[0]
            return item.item() if hasattr(item, "item") else item
        return [
            item.item() if hasattr(item, "item") else item
            for item in value
        ]

    return value.item() if hasattr(value, "item") else value


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
    Safe lifecycle wrapper for an FMU using PyFMI.

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
        fmu_type: str = "cs",
        start_time: float = 0.0,
        stop_time: Optional[float] = None,
        tolerance: float = 1.0e-6,
        visible: bool = False,
        debug_logging: bool = False,
        show_solver_log: bool = False,
    ):
        self.fmu_path = str(fmu_path)
        self.instance_name = str(instance_name)
        self.fmu_type = str(fmu_type).lower()
        self.start_time = float(start_time)
        self.stop_time = None if stop_time is None else float(stop_time)
        self.tolerance = float(tolerance)
        self.visible = bool(visible)
        self.debug_logging = bool(debug_logging)
        self.show_solver_log = bool(show_solver_log)

        try:
            from pyfmi import load_fmu
        except ImportError as e:
            raise ImportError(
                "PyFMI is not installed. Install pyfmi before using the "
                "fmu-pyfmi backend."
            ) from e

        kind = "me" if self.fmu_type == "me" else "cs"
        self.fmu = load_fmu(self.fmu_path, kind=kind)

        model_variables = self.fmu.get_model_variables()
        self.vrs = build_vr_map(model_variables)
        self.io = extract_io_from_model_variables(model_variables)
        self.state_names = list(getattr(self.fmu, "get_states_list", lambda: {})().keys())
        self.variable_names = list(model_variables.keys())

        self._type_map: dict[str, str] = {}
        for group in self.io.values():
            for var in group:
                self._type_map[var.name] = var.type_name
        for name in self.variable_names:
            if self._type_map.get(name) in {None, "unknown"}:
                self._type_map[name] = "real"

        self.opts = None
        if hasattr(self.fmu, "simulate_options"):
            self.opts = self.fmu.simulate_options()
            self.opts["result_handling"] = "memory"
            self.opts["result_store_variable_description"] = False
            if "ncp" in self.opts:
                self.opts["ncp"] = 10
            if self.fmu_type == "me":
                self.opts["solver"] = "CVode"
                cvode = self.opts.get("CVode_options")
                if isinstance(cvode, dict):
                    cvode["atol"] = self.tolerance
                    cvode["rtol"] = self.tolerance

        self._instantiated = False
        self._initialized = False
        self._terminated = False
        self._me_io_ready = False
        self._pending_values: dict[str, Any] = {}
        self._last_values: dict[str, Any] = {}

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

        if self.fmu_type == "me":
            # Keep ME FMUs in an IO-capable initialized state between macro
            # steps. Right before a segment simulation we reset, apply the
            # current values as starts/inputs, and let simulate() set up its
            # own local experiment.
            self.fmu.initialize(start_time=self.start_time)
            self._instantiated = True
            self._initialized = True
            self._me_io_ready = True
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
            if self._instantiated and (self.fmu_type != "me" or self._me_io_ready):
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

    def get_real(self, name: str, default: Any = _MISSING):
        try:
            value = _normalize_pyfmi_value(self.fmu.get(name))
            if isinstance(value, list):
                return [float(item) for item in value]
            return float(value)
        except Exception:
            if default is _MISSING:
                raise
            return default

    def get_integer(self, name: str, default: Any = _MISSING):
        try:
            value = _normalize_pyfmi_value(self.fmu.get(name))
            if isinstance(value, list):
                return [int(item) for item in value]
            return int(value)
        except Exception:
            if default is _MISSING:
                raise
            return default

    def get_boolean(self, name: str, default: Any = _MISSING):
        try:
            value = _normalize_pyfmi_value(self.fmu.get(name))
            if isinstance(value, list):
                return [bool(item) for item in value]
            return bool(value)
        except Exception:
            if default is _MISSING:
                raise
            return default

    def set_value(self, name: str, value) -> None:
        """
        Set a variable using automatic type routing.
        """
        if self.fmu_type == "me":
            self._pending_values[str(name)] = value
            self._last_values[str(name)] = value
            if not self._me_io_ready:
                return

        t = self._type_map.get(name)
        if t is None:
            self.fmu.set(name, value)
            return

        if t == "real":
            self.set_real(name, float(value))
        elif t in ("integer", "enumeration"):
            self.set_integer(name, int(value))
        elif t == "boolean":
            self.set_boolean(name, bool(value))
        else:
            self.fmu.set(name, value)

    def get_value(self, name: str, default: Any = _MISSING):
        """
        Get a variable using automatic type routing.
        """
        if self.fmu_type == "me" and not self._me_io_ready:
            if name in self._last_values:
                return self._last_values[name]
            if default is not _MISSING:
                return default
            raise RuntimeError(f"ME FMU value '{name}' is not available before initialization.")

        t = self._type_map.get(name)
        if t is None:
            try:
                return _normalize_pyfmi_value(self.fmu.get(name))
            except Exception:
                if default is not _MISSING:
                    return default
                raise

        if t == "real":
            return self.get_real(name, default)
        if t in ("integer", "enumeration"):
            return self.get_integer(name, default)
        if t == "boolean":
            return self.get_boolean(name, default)

        try:
            return _normalize_pyfmi_value(self.fmu.get(name))
        except Exception:
            if default is not _MISSING:
                return default
            raise

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

        if self.fmu_type == "me":
            self._simulate_me_segment(float(dt))
            return 0

        self.fmu.do_step(current_t=float(t), step_size=float(dt), new_step=True)
        return 0

    def step_or_raise(self, t: float, dt: float) -> None:
        """
        Step once and let PyFMI exceptions propagate as failures.
        """
        self.step(t, dt)

    def _simulate_me_segment(self, dt: float) -> None:
        """
        Advance a Model Exchange FMU by one macro step using PyFMI simulate().

        This mirrors the legacy examples: simulate a short local interval,
        snapshot states/variables, reset/reinitialize, then restore the
        snapshot. It is intentionally simple and deterministic; event-aware
        stepping can replace this policy later.
        """
        start_values = self._snapshot_me_values()
        start_values.update(self._pending_values)
        self.fmu.reset()
        self._me_io_ready = False

        self._apply_raw_values(start_values)

        if self.show_solver_log:
            self._simulate_me_segment_once(dt)
        else:
            with contextlib.redirect_stdout(io.StringIO()), contextlib.redirect_stderr(io.StringIO()):
                self._simulate_me_segment_once(dt)

        terminal_values = self._snapshot_me_values()
        self._last_values.update(terminal_values)

        self.fmu.reset()
        self.fmu.initialize(start_time=0.0)
        self._me_io_ready = True

        self._apply_raw_values(terminal_values)
        self._pending_values.clear()

    def _snapshot_me_values(self) -> dict[str, Any]:
        names = list(dict.fromkeys([*self.state_names, *self.variable_names]))
        if not names:
            return {}

        try:
            values = self.fmu.get(names)
        except Exception:
            return {}

        normalized = _normalize_pyfmi_value(values)
        if not isinstance(normalized, list):
            normalized = [normalized]
        return {
            name: value
            for name, value in zip(names, normalized)
        }

    def _simulate_me_segment_once(self, dt: float) -> None:
        if self.opts is None:
            self.fmu.simulate(start_time=0.0, final_time=float(dt))
            return

        self.fmu.simulate(
            start_time=0.0,
            final_time=float(dt),
            options=self.opts,
        )

    def _apply_raw_values(self, values: dict[str, Any]) -> None:
        for name, value in values.items():
            try:
                self.fmu.set(name, value)
            except Exception:
                continue
