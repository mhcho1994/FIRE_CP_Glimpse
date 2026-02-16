"""
fmu_runner.py
=============
A safe, minimal orchestration layer for FMI 2.0 Co-Simulation FMUs
built on top of FMPy (FMU2Slave).

This module provides:

1. ModelDescription utilities
   - Extraction of variable metadata (inputs, outputs, parameters, locals)
   - Construction of name -> valueReference maps
   - Lightweight interface discovery for scenario-level wiring

2. FMI2CSRunner
   - A lifecycle-safe wrapper around FMU2Slave
   - Enforces correct FMI state machine call ordering
   - Provides typed set/get helpers (Real, Integer, Boolean)
   - Provides safe stepping utilities with explicit error handling
   - Supports context-manager usage for automatic termination/free

----------------------------------------------------------------------
Why This Exists
----------------------------------------------------------------------

FMI 2.0 Co-Simulation follows a strict state machine:

    (created)
        ↓
    fmi2Instantiate
        ↓
    fmi2SetupExperiment
        ↓
    fmi2EnterInitializationMode
        ↓
    fmi2ExitInitializationMode
        ↓
    Step Mode (fmi2DoStep loop)
        ↓
    fmi2Terminate
        ↓
    fmi2FreeInstance

Common orchestration mistakes include:

- Forgetting to call instantiate()
- Calling doStep() before exiting initialization mode
- Forgetting terminate/freeInstance()
- Passing a stopTime that prevents stepping beyond a boundary
- Ignoring fmi2Discard return codes

FMI2CSRunner ensures:
- Correct call ordering
- Idempotent lifecycle management
- Clear error semantics
- Minimal boilerplate in simulation backends

----------------------------------------------------------------------
Design Philosophy (CP-Glimpse Context)
----------------------------------------------------------------------

This wrapper is intentionally:

- Minimal: does not implement a full master algorithm
- Deterministic: no adaptive step-size logic
- Explicit: all state transitions are visible
- Extensible: suitable for building FMU networks

It is meant to serve as the foundation for:

- Open-loop simulation backends
- Multi-FMU network simulation
- Scenario-driven connection graphs
- ICD validation layers
- Cyber-physical vulnerability analysis workflows

----------------------------------------------------------------------
ModelDescription Utilities
----------------------------------------------------------------------

The module also provides:

    extract_io_from_model_description(md)

This function classifies variables into:
    - inputs      (causality == "input")
    - outputs     (causality == "output")
    - parameters  (variability == "parameter" or causality == "parameter")
    - locals      (everything else)

Note:
Toolchains differ in how they encode parameters and internal states.
For robust integration, an ICD (Interface Control Document) should
be validated against modelDescription during scenario load.

----------------------------------------------------------------------
Minimal Usage Example
----------------------------------------------------------------------

Example: running a single FMU in open-loop mode.

    with FMI2CSRunner(
            fmu_path="Target.fmu",
            instance_name="vehicle",
            start_time=0.0,
            stop_time=35.0,
            debug_logging=True) as vehicle:

        t = 0.0
        dt = 0.1

        for k in range(10):

            # Set input variables
            vehicle.set_real("input1", 0.2)
            vehicle.set_real("input2", 0.0)

            # Advance simulation
            vehicle.step_or_raise(t, dt)

            # Read outputs
            output1 = vehicle.get_real("output1")
            output2 = vehicle.get_real("output2")

            t += dt

What this example demonstrates:

- Safe lifecycle management via context manager
- Explicit time stepping
- Named variable access via valueReference mapping
- Clear error propagation on invalid doStep()

----------------------------------------------------------------------
Error Handling Semantics
----------------------------------------------------------------------

fmi2DoStep may return:

    fmi2OK        → normal step
    fmi2Warning   → step succeeded with warning
    fmi2Discard   → step rejected (e.g., event or step size issue)
    fmi2Error     → fatal error

This wrapper:
- Raises RuntimeError on fmi2Error (via step_or_raise)
- Leaves fmi2Discard policy to the caller (explicit design choice)

----------------------------------------------------------------------
Intended Scope
----------------------------------------------------------------------

This module is NOT:
- A full-featured FMI master
- An event-mode solver
- An adaptive step integrator
- A multi-rate orchestration engine

It is a deterministic, explicit master suitable for:

- Lo-Fi CPS simulation
- Controlled experimentation
- Research-grade orchestration layers
- Building higher-level FMU mutli-runners

----------------------------------------------------------------------
"""

from __future__ import annotations

from dataclasses import dataclass
from typing import Optional

from fmpy import read_model_description, extract
from fmpy.fmi2 import (
    FMU2Slave,
    fmi2OK,
    fmi2Warning,
    fmi2Discard,
    fmi2Error,
)

# ==============================
# ModelDescription helpers
# ==============================
@dataclass(frozen=True)
class VarInfo:
    """
    Lightweight, serializable metadata for a variable described in modelDescription.xml.

    We keep only the fields that are practically useful for:
      - building a name->valueReference map (VR map)
      - determining interface roles (input/output/parameter)
      - basic type routing (Real/Integer/Boolean/String/Enumeration)

    Notes
    -----
    - In FMI, *port direction* is typically encoded via `causality`:
        - input, output, parameter, local, independent, ...
    - Constant/parameter classification is typically encoded via `variability`:
        - constant, parameter, discrete, continuous, ...
    - Toolchains vary: some emit parameters as causality="parameter",
      others emit variability="parameter" (or both). We treat either as parameter.
    """
    name: str
    vr: int
    causality: Optional[str]
    variability: Optional[str]
    initial: Optional[str]
    type_name: str


def _var_type_name(v) -> str:
    """
    Infer a variable's FMI base type from FMPy's parsed modelDescription objects.

    FMPy typically materializes exactly one of these sub-objects on each variable:
      - v.real, v.integer, v.boolean, v.string, v.enumeration

    Returns
    -------
    str
        One of: "real", "integer", "boolean", "string", "enumeration", or "unknown".
    """
    for t in ("real", "integer", "boolean", "string", "enumeration"):
        if getattr(v, t, None) is not None:
            return t
    return "unknown"


def build_vr_map(md) -> dict[str, int]:
    """
    Build a name -> valueReference map from an FMPy ModelDescription.

    FMI getters/setters use "value references" (integers) to address variables.
    Having this map lets you do:
        fmu.setReal([vrs["thr"]], [0.2])
    instead of hunting through modelVariables every time.

    Parameters
    ----------
    md
        FMPy ModelDescription object (from read_model_description()).

    Returns
    -------
    dict[str, int]
        Map from variable name to VR.
    """
    return {v.name: v.valueReference for v in md.modelVariables}


def extract_io_from_model_description(md) -> dict[str, list[VarInfo]]:
    """
    Extract interface-like groupings (inputs/outputs/parameters/locals) from modelDescription.

    This is the "best-effort" automatic interface discovery.

    Classification rules
    --------------------
    - inputs:      causality == "input"
    - outputs:     causality == "output"
    - parameters:  variability == "parameter" OR causality == "parameter"
    - locals:      everything else

    Caveats
    -------
    - Some toolchains export additional internal states with causality="local".
      Those are not true "outputs" (but may still be readable).
    - For robust systems integration, consider maintaining an ICD (Interface Control Document)
      and validating ICD ports against modelDescription during CI / scenario load.

    Returns
    -------
    dict[str, list[VarInfo]]
        {"inputs": [...], "outputs": [...], "parameters": [...], "locals": [...]}
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

    # Deterministic ordering helps reproducibility/log readability
    inputs.sort(key=lambda x: x.name)
    outputs.sort(key=lambda x: x.name)
    params.sort(key=lambda x: x.name)
    locals_.sort(key=lambda x: x.name)

    return {"inputs": inputs, "outputs": outputs, "parameters": params, "locals": locals_}


# ==============================
# FMI2 Co-Simulation Runner
# ==============================
class FMI2CSRunner:
    """
    Safe lifecycle wrapper for an FMI 2.0 Co-Simulation FMU (FMU2Slave).

    Motivation
    ----------
    FMI 2.0 CS follows a strict state machine. Common bugs in orchestration code are:
      - forgetting instantiate()
      - calling doStep() before initialization mode exit
      - forgetting terminate/free
      - setting stopTime too small (doStep fails once stopTime reached)
      - missing handling for fmi2Discard

    This wrapper makes the *legal call order* explicit and hard to misuse.

    FMI state machine (simplified)
    ------------------------------
      (created) -> instantiate -> setupExperiment -> enterInit -> exitInit -> StepMode
                 -> doStep* -> terminate -> freeInstance

    Parameters
    ----------
    fmu_path : str
        Path to the .fmu archive.
    instance_name : str
        Instance name used by FMI (useful for logging).
    start_time : float
        Simulation start time passed to setupExperiment.
    stop_time : float | None
        If provided, passed to setupExperiment. If None, stopTime is omitted.
        Omitting stopTime avoids a common failure mode where FMU refuses to step
        beyond stopTime.
    visible : bool
        Whether the FMU may show UI (rarely used).
    debug_logging : bool
        Whether to ask FMU to emit internal log messages (if FMU supports logging).

    Attributes
    ----------
    md
        Parsed model description (FMPy ModelDescription object).
    vrs
        Dict mapping variable names to value references (VR).
    io
        Dict grouping variables by causality/variability (inputs/outputs/parameters/locals).
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
        self.fmu_path = fmu_path
        self.instance_name = instance_name
        self.start_time = float(start_time)
        self.stop_time = None if stop_time is None else float(stop_time)
        self.visible = visible
        self.debug_logging = debug_logging

        # 1) Extract FMU contents so we can load binaries + modelDescription.xml
        self.unzipdir = extract(self.fmu_path)

        # 2) Parse modelDescription.xml for metadata + validation
        self.md = read_model_description(self.unzipdir)
        if self.md.coSimulation is None:
            raise RuntimeError(f"{fmu_path} has no CoSimulation section (not FMI2 CS).")

        # Build fast lookup maps for variables
        self.vrs = build_vr_map(self.md)
        self.io = extract_io_from_model_description(self.md)

        # 3) Create the Python wrapper for the underlying FMI component
        #    NOTE: this does NOT call fmi2Instantiate yet.
        self.fmu = FMU2Slave(
            guid=self.md.guid,
            unzipDirectory=self.unzipdir,
            modelIdentifier=self.md.coSimulation.modelIdentifier,
            instanceName=self.instance_name,
        )

        # Internal state flags to keep lifecycle safe/idempotent
        self._instantiated = False
        self._initialized = False
        self._terminated = False

    # -------------------------------------------------------------------------
    # Lifecycle
    # -------------------------------------------------------------------------

    def instantiate_and_initialize(self) -> None:
        """
        Bring the FMU into "Step Mode" (ready for doStep loops).

        This method is idempotent: calling it multiple times is safe.

        Call order performed:
          1) fmi2Instantiate
          2) fmi2SetupExperiment(startTime[, stopTime])
          3) fmi2EnterInitializationMode
          4) fmi2ExitInitializationMode

        Raises
        ------
        RuntimeError
            If called after termination/free (should not happen in normal use).
        """
        if self._terminated:
            raise RuntimeError("Cannot initialize: FMU already terminated/freed.")
        if self._initialized:
            return

        if not self._instantiated:
            # fmi2Instantiate: allocates internal component instance
            # loggingOn requests FMU-side logging; visible toggles UI.
            self.fmu.instantiate(visible=self.visible, loggingOn=self.debug_logging)
            self._instantiated = True

        # fmi2SetupExperiment: defines start/stop time bounds (stopTime optional)
        if self.stop_time is None:
            self.fmu.setupExperiment(startTime=self.start_time)
        else:
            self.fmu.setupExperiment(startTime=self.start_time, stopTime=self.stop_time)

        # Initialization mode is where parameters should be set for strict FMUs.
        self.fmu.enterInitializationMode()
        # (Optional) set parameters here if you want to enforce strict compliance
        self.fmu.exitInitializationMode()

        self._initialized = True

    def terminate_and_free(self) -> None:
        """
        Terminate the FMU and free its instance.

        This method is idempotent: calling it multiple times is safe.

        Call order performed:
          1) fmi2Terminate
          2) fmi2FreeInstance
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

    # Context manager integration:
    #   with FMI2CSRunner(...) as fmu:
    #       fmu.step(...)
    def __enter__(self) -> "FMI2CSRunner":
        self.instantiate_and_initialize()
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        self.terminate_and_free()

    # -------------------------------------------------------------------------
    # Value accessors (typed)
    # -------------------------------------------------------------------------

    def _vr(self, name: str) -> int:
        """Resolve a variable name into a valueReference (VR)."""
        vr = self.vrs.get(name)
        if vr is None:
            raise KeyError(f"Unknown variable name: {name}")
        return vr

    def set_real(self, name: str, value: float) -> None:
        """Set a Real variable by name."""
        self.fmu.setReal([self._vr(name)], [float(value)])

    def set_integer(self, name: str, value: int) -> None:
        """Set an Integer variable by name."""
        self.fmu.setInteger([self._vr(name)], [int(value)])

    def set_boolean(self, name: str, value: bool) -> None:
        """Set a Boolean variable by name."""
        self.fmu.setBoolean([self._vr(name)], [bool(value)])

    def get_real(self, name: str, default: Optional[float] = None) -> float:
        """
        Get a Real variable by name.

        Parameters
        ----------
        default : float | None
            If provided and `name` doesn't exist, return default instead of raising.
        """
        vr = self.vrs.get(name)
        if vr is None:
            if default is None:
                raise KeyError(f"Unknown variable name: {name}")
            return float(default)
        return float(self.fmu.getReal([vr])[0])

    def get_integer(self, name: str, default: Optional[int] = None) -> int:
        """Get an Integer variable by name (with optional default)."""
        vr = self.vrs.get(name)
        if vr is None:
            if default is None:
                raise KeyError(f"Unknown variable name: {name}")
            return int(default)
        return int(self.fmu.getInteger([vr])[0])

    def get_boolean(self, name: str, default: Optional[bool] = None) -> bool:
        """Get a Boolean variable by name (with optional default)."""
        vr = self.vrs.get(name)
        if vr is None:
            if default is None:
                raise KeyError(f"Unknown variable name: {name}")
            return bool(default)
        return bool(self.fmu.getBoolean([vr])[0])

    # -------------------------------------------------------------------------
    # Stepping
    # -------------------------------------------------------------------------

    def step(
        self,
        t: float,
        dt: float,
        *,
        no_set_fmu_state_prior: bool = True,
    ) -> int:
        """
        Perform a single communication step (doStep).

        Parameters
        ----------
        t : float
            Current communication point (time at beginning of the step).
        dt : float
            Communication step size.
        no_set_fmu_state_prior : bool
            FMI hint. When True, indicates the master will NOT call
            fmi2SetFMUState/fmi2FreeFMUState to rewind. Many masters set True.

        Returns
        -------
        int
            FMI status code: fmi2OK(0), fmi2Warning(1), fmi2Discard(2), fmi2Error(3)

        Notes
        -----
        - fmi2Discard often indicates the FMU could not accept the proposed step size
          (e.g., due to internal events). A robust master may:
            - reduce dt and retry
            - query lastSuccessfulTime (if supported)
            - switch to an event-handling policy
        """
        if not self._initialized:
            raise RuntimeError("FMU not initialized. Call instantiate_and_initialize() first.")
        if self._terminated:
            raise RuntimeError("FMU already terminated/freed.")

        return self.fmu.doStep(
            currentCommunicationPoint=float(t),
            communicationStepSize=float(dt),
            noSetFMUStatePriorToCurrentPoint=no_set_fmu_state_prior,
        )

    def step_or_raise(self, t: float, dt: float) -> None:
        """
        Step and raise an exception on fmi2Error (and optionally on fmi2Discard).

        This is a convenience for quick debugging and for masters that choose to
        treat discard as fatal.

        Raises
        ------
        RuntimeError
            If doStep returns fmi2Error (or if you change policy to include discard).
        """
        status = self.step(t, dt)

        if status == fmi2Error:
            raise RuntimeError(f"FMU doStep failed at t={t} dt={dt} (status={status}).")

        # Optional policy: treat discard as error
        # if status == fmi2Discard:
        #     raise RuntimeError(f"FMU discarded step at t={t}; try smaller dt or check events.")