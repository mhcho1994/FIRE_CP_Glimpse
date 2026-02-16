"""
run_single_fmu.py
======================

A generic "single FMU" open-loop simulation backend for CP-Glimpse.

This backend is intentionally *not* tied to any specific vehicle model (rover, quadrotor, ...).
It provides a minimal execution harness for a single FMI 2.0 Co-Simulation FMU by using
`FMI2CSRunner` (see `backend/fmu_runner.py`).

Why this backend exists
-----------------------
- Many issues encountered during development (e.g., `fmi2DoStep failed with status 3`) are
  orchestration/lifecycle problems rather than model problems.
- A generic single-FMU runner makes it easy to validate:
    * FMU lifecycle correctness (instantiate → init → step → terminate/free)
    * step-size behavior and discard/errors
    * basic variable I/O availability from modelDescription
- Closed-loop / multi-FMU orchestration will be handled by a separate "network runner"
  driven by an explicit scenario connection graph. This backend stays single-FMU only.

Scenario contract (expected keys)
---------------------------------
The runner supports a couple of scenario formats for convenience.

Required:
- scn["sim"]["t0"], scn["sim"]["tf"], scn["sim"]["dt"]
- scn["model"]["mo_path"]
- scn["model"]["class_name"]  (preferred)
  OR scn["model"]["components"] with exactly one entry (legacy compatibility)

Optional:
- scn["sim"]["fmu_type"] : "cs" (default). This backend is for Co-Simulation.
- scn["output"]["log"] : list[str] variable names to log each step
  (if omitted, logs all outputs discovered from modelDescription)
- scn["inputs"]["constant"] : dict[name -> value] to set each step before doStep
  (simple open-loop forcing)

Return value
------------
Returns a pandas DataFrame with at least:
- "t" column
- one column per logged variable in output.log (or auto outputs)

Notes on FMI statuses
---------------------
`fmi2DoStep` may return:
- fmi2OK / fmi2Warning : accept step
- fmi2Discard          : step rejected (often indicates event/step-size mismatch)
- fmi2Error            : fatal error

This backend treats `fmi2Discard` and `fmi2Error` as exceptions by default, since
CP-Glimpse currently uses fixed-step deterministic simulation. If later you want
adaptive retry on discard, this is the place to implement it.
"""

import pandas as pd

from fmpy.fmi2 import fmi2Discard, fmi2Error

from ..common.logging import get_logger
from ..translator.mo_to_fmu import build_fmu
from .fmu_runner import FMI2CSRunner

log = get_logger(__name__)


def _resolve_class_name(model_cfg: dict) -> str:
    """
    Resolve the Modelica class name to build into an FMU.

    Preferred scenario:
        model:
          mo_path: ...
          class_name: MyModel

    Legacy compatibility:
        model:
          mo_path: ...
          components:
            rover: Rover3D

    If multiple components exist, we pick one deterministically (sorted by key),
    but for clarity you should use `class_name`.
    """
    if "class_name" in model_cfg and model_cfg["class_name"]:
        return str(model_cfg["class_name"])

    comps = model_cfg.get("components", {})
    if isinstance(comps, dict) and len(comps) >= 1:
        k = sorted(comps.keys())[0]
        return str(comps[k])

    raise KeyError("Scenario missing model.class_name (or model.components).")


def run_single_fmu_open_loop(*, scn: dict) -> pd.DataFrame:
    """
    Run a single FMI 2.0 Co-Simulation FMU in an open-loop fixed-step simulation.

    Parameters
    ----------
    scn : dict
        Scenario dictionary (already parsed YAML).
        See module docstring for expected keys.

    Returns
    -------
    pandas.DataFrame
        Time series log of requested variables.

    Raises
    ------
    RuntimeError
        If the FMU returns fmi2Discard or fmi2Error during stepping.
    KeyError
        If scenario config is missing required fields.
    """
    model_cfg = scn["model"]
    sim = scn["sim"]

    t0 = float(sim.get("t0", 0.0))
    tf = float(sim["tf"])
    dt = float(sim["dt"])
    fmu_type = str(sim.get("fmu_type", "cs"))

    if fmu_type.lower() != "cs":
        raise ValueError(f"This backend expects Co-Simulation (cs). Got fmu_type={fmu_type!r}")

    mo_path = model_cfg["mo_path"]
    class_name = _resolve_class_name(model_cfg)

    # Optional constant input forcing:
    #   inputs:
    #     constant:
    #       thr: 0.2
    #       delta: 0.0
    const_inputs = (scn.get("inputs", {}) or {}).get("constant", {}) or {}

    # Which variables to log?
    # - If output.log exists, respect it
    # - Else default to all modelDescription outputs (causality="output")
    out_cfg = scn.get("output", {}) or {}
    log_vars = out_cfg.get("log", None)

    # --- Build FMU (cached) ---
    art = build_fmu(mo_path=mo_path, class_name=class_name, fmu_type=fmu_type)
    log.info("FMU ready: %s", art.fmu_path)

    rows: list[dict] = []

    # --- Execute FMU ---
    with FMI2CSRunner(
        fmu_path=art.fmu_path,
        instance_name=class_name,
        start_time=t0,
        stop_time=tf,               # ok; if you suspect stopTime issues, set None here
        debug_logging=True,         # show FMU logs if supported
    ) as fmu:

        # If caller didn't specify log variables, default to all outputs.
        if log_vars is None:
            log_vars = [v.name for v in fmu.io["outputs"]]

        # Helpful for debugging: show discovered interface once.
        log.info("Discovered inputs (%d): %s", len(fmu.io["inputs"]), [v.name for v in fmu.io["inputs"]])
        log.info("Discovered outputs (%d): %s", len(fmu.io["outputs"]), [v.name for v in fmu.io["outputs"]])
        log.info("Logging variables (%d): %s", len(log_vars), log_vars)

        t = t0
        n_steps = int((tf - t0) / dt)

        for k in range(n_steps):
            # 1) Apply constant inputs for this step (simple open-loop forcing).
            #    If you later want piecewise/time-varying inputs, extend this section.
            for name, val in const_inputs.items():
                # We assume Real for simplicity. If you need Integer/Boolean routing,
                # we can route based on modelDescription type_name.
                fmu.set_real(str(name), float(val))

            # 2) Step the FMU forward by dt.
            status = fmu.step(t, dt)

            if status == fmi2Discard:
                # In robust masters, discard often triggers smaller dt + retry.
                raise RuntimeError(
                    f"FMU discarded step at t={t:.6g} (dt={dt:.6g}). "
                    "Try smaller dt or inspect FMU event handling."
                )
            if status == fmi2Error:
                raise RuntimeError(
                    f"FMU doStep returned error at t={t:.6g} (dt={dt:.6g}). "
                    "Enable debug_logging and check FMU logs."
                )

            # 3) Sample/log outputs after step.
            row = {"t": t + dt}  # record end-of-step time (common convention)
            for name in log_vars:
                try:
                    row[name] = fmu.get_real(name)
                except Exception:
                    # If variable isn't Real or isn't found, keep it explicit.
                    # You can tighten this by validating log_vars vs vrs before sim.
                    row[name] = float("nan")
            rows.append(row)

            t += dt

    return pd.DataFrame(rows)
