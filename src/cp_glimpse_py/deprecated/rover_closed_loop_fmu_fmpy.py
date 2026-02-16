from __future__ import annotations

import shutil
import numpy as np
import pandas as pd

from fmpy import read_model_description, extract
from fmpy.fmi2 import FMU2Slave


def _vrs(md):
    """name -> valueReference dict"""
    return {v.name: v.valueReference for v in md.modelVariables}


def _instantiate_fmu2_cs(fmu_path: str, instance_name: str) -> tuple[FMU2Slave, str, dict]:
    unzipdir = extract(fmu_path)
    md = read_model_description(unzipdir)
    if md.coSimulation is None and md.modelExchange is not None and md.fmiVersion != "2.0":
        raise RuntimeError(f"{fmu_path} is not FMI2 Co-Simulation (no coSimulation section).")
    vrs = _vrs(md)

    fmu = FMU2Slave(
        guid=md.guid,
        unzipDirectory=unzipdir,
        modelIdentifier=md.coSimulation.modelIdentifier,
        instanceName=instance_name,
    )
    return fmu, unzipdir, vrs


def _safe_set_real(fmu: FMU2Slave, vrs: dict, values: dict[str, float]) -> None:
    """Set only existing variables; ignore missing."""
    vr_list = []
    val_list = []
    for k, v in values.items():
        if k in vrs:
            vr_list.append(vrs[k])
            val_list.append(float(v))
    if vr_list:
        fmu.setReal(vr_list, val_list)


def _safe_set_int(fmu: FMU2Slave, vrs: dict, values: dict[str, int]) -> None:
    vr_list = []
    val_list = []
    for k, v in values.items():
        if k in vrs:
            vr_list.append(vrs[k])
            val_list.append(int(v))
    if vr_list:
        fmu.setInteger(vr_list, val_list)


def _safe_set_bool(fmu: FMU2Slave, vrs: dict, values: dict[str, bool]) -> None:
    vr_list = []
    val_list = []
    for k, v in values.items():
        if k in vrs:
            vr_list.append(vrs[k])
            val_list.append(bool(v))
    if vr_list:
        fmu.setBoolean(vr_list, val_list)


def _get_real1(fmu: FMU2Slave, vrs: dict, name: str, default: float = 0.0) -> float:
    if name not in vrs:
        return default
    return float(fmu.getReal([vrs[name]])[0])


def run_rover_cosim_fmpy(
    *,
    rover_fmu_path: str,
    ctrl_fmu_path: str,
    web_fmu_path: str,
    t0: float = 0.0,
    tf: float = 10.0,
    dt: float = 0.1,
    fidelity: int = 1,
    heading_rad: float = 0.0,
    turn_radius: float = 5.0,
) -> pd.DataFrame:
    # --- load & instantiate ---
    rover, rover_dir, vrs_r = _instantiate_fmu2_cs(rover_fmu_path, "rover")
    ctrl,  ctrl_dir,  vrs_c = _instantiate_fmu2_cs(ctrl_fmu_path,  "controller")
    web,   web_dir,   vrs_w = _instantiate_fmu2_cs(web_fmu_path,   "webserver")

    unzipdirs = [rover_dir, ctrl_dir, web_dir]

    try:
        # instantiate
        for f in (rover, ctrl, web):
            f.instantiate()

        # setup experiment
        for f in (rover, ctrl, web):
            f.setupExperiment(startTime=t0, stopTime=tf)

        # init mode
        for f in (rover, ctrl, web):
            f.enterInitializationMode()

        # ---- set IC/params in init mode ----
        # sample_interval (if exists)
        _safe_set_real(rover, vrs_r, {"sample_interval": dt + 1e-9})
        _safe_set_real(ctrl,  vrs_c, {"sample_interval": dt + 1e-9})
        _safe_set_real(web,   vrs_w, {"sample_interval": dt + 1e-9})

        # rover IC depends on fidelity
        if fidelity == 1:
            _safe_set_real(rover, vrs_r, {
                "rover_3d.x": 0.0, "rover_3d.y": 0.0, "rover_3d.z": 0.0,
                "rover_3d.vx": 0.0, "rover_3d.vy": 0.0, "rover_3d.vz": 0.0,
                "rover_3d.psi": heading_rad, "rover_3d.theta": 0.0, "rover_3d.phi": 0.0,
                "rover_3d.p": 0.0, "rover_3d.q": 0.0, "rover_3d.r": 0.0,
            })
            l_total = _get_real1(rover, vrs_r, "rover_3d.l_total", 0.0)
        else:
            _safe_set_real(rover, vrs_r, {
                "rover_8d.x": 0.0, "rover_8d.y": 0.0, "rover_8d.z": 0.0,
                "rover_8d.vx": 0.0, "rover_8d.vy": 0.0, "rover_8d.vz": 0.0,
                "rover_8d.psi": heading_rad, "rover_8d.theta": 0.0, "rover_8d.phi": 0.0,
                "rover_8d.p": 0.0, "rover_8d.q": 0.0, "rover_8d.r": 0.0,
                "rover_8d.omega_fl": 0.0, "rover_8d.omega_fr": 0.0,
                "rover_8d.omega_rl": 0.0, "rover_8d.omega_rr": 0.0,
                "rover_8d.omega": 0.0,
            })
            l_total = _get_real1(rover, vrs_r, "rover_8d.l_total", 0.0)

        # controller IC / references
        delta_turn = float(np.arctan(l_total / float(turn_radius))) if turn_radius != 0 else 0.0
        _safe_set_int(ctrl, vrs_c, {"s": 0})
        _safe_set_real(ctrl, vrs_c, {
            "x_ref": 0.0, "y_ref": 0.0, "psi_ref": 0.0,
            "v": 0.0, "delta": 0.0,
            "delta_turn": delta_turn,
            # if these exist as Reals (Modelica filtered quat typically Real)
            "quaternion_filtered[1]": 1.0,
            "quaternion_filtered[2]": 0.0,
            "quaternion_filtered[3]": 0.0,
            "quaternion_filtered[4]": 0.0,
        })

        # IMPORTANT: seed controller inputs to safe values (prevents first-step failure)
        _safe_set_real(ctrl, vrs_c, {
            "ax_acc": 0.0, "ay_acc": 0.0, "az_acc": 0.0,
            "mx_mag": 0.0, "my_mag": 0.0, "mz_mag": 0.0,
            "phi_gyro": 0.0, "theta_gyro": 0.0, "psi_gyro": heading_rad,
            "p_gyro": 0.0, "q_gyro": 0.0, "r_gyro": 0.0,
            "x": 0.0, "y": 0.0,
        })
        _safe_set_real(rover, vrs_r, {"pwm_steering": 0.0, "pwm_throttle": 0.0})

        # exit init mode
        for f in (rover, ctrl, web):
            f.exitInitializationMode()

        # --- connection maps (timed) ---
        rover_to_ctrl = {
            "ax_meas": "ax_acc",
            "ay_meas": "ay_acc",
            "az_meas": "az_acc",
            "mx_meas": "mx_mag",
            "my_meas": "my_mag",
            "mz_meas": "mz_mag",
            "phi_meas": "phi_gyro",
            "theta_meas": "theta_gyro",
            "psi_meas": "psi_gyro",
            "p_meas": "p_gyro",
            "q_meas": "q_gyro",
            "r_meas": "r_gyro",
            "x_meas": "x",
            "y_meas": "y",
        }
        ctrl_to_rover = {
            "pwm_steering": "pwm_steering",
            "pwm_throttle": "pwm_throttle",
        }

        # --- sim loop ---
        rows = []
        t = t0
        while t < tf - 1e-12:
            # (1) webserver step
            web.doStep(t, dt, True)
            turn_cmd = _get_real1(web, vrs_w, "turn", 0.0)

            # ctrl.turn is not an input? try set anyway (ignore if absent)
            _safe_set_real(ctrl, vrs_c, {"turn": turn_cmd})

            # (2) relay rover -> ctrl (sample-and-hold)
            # read rover meas at current time (outputs from previous step)
            ctrl_inputs = {}
            for y, u in rover_to_ctrl.items():
                if y in vrs_r and u in vrs_c:
                    ctrl_inputs[u] = _get_real1(rover, vrs_r, y, 0.0)
            _safe_set_real(ctrl, vrs_c, ctrl_inputs)

            # (3) controller step
            ctrl.doStep(t, dt, True)

            # (4) relay ctrl -> rover (ZOH)
            rover_inputs = {}
            for y, u in ctrl_to_rover.items():
                if y in vrs_c and u in vrs_r:
                    rover_inputs[u] = _get_real1(ctrl, vrs_c, y, 0.0)
            _safe_set_real(rover, vrs_r, rover_inputs)

            # (5) rover step
            rover.doStep(t, dt, True)

            # (6) log a few signals (extend as needed)
            rows.append({
                "time": t + dt,
                "web.turn": turn_cmd,
                "ctrl.pwm_steering": _get_real1(ctrl, vrs_c, "pwm_steering", 0.0),
                "ctrl.pwm_throttle": _get_real1(ctrl, vrs_c, "pwm_throttle", 0.0),
                "rover.x_meas": _get_real1(rover, vrs_r, "x_meas", 0.0),
                "rover.y_meas": _get_real1(rover, vrs_r, "y_meas", 0.0),
                "rover.psi_meas": _get_real1(rover, vrs_r, "psi_meas", 0.0),
            })

            t += dt

        return pd.DataFrame(rows)

    finally:
        # terminate/free + cleanup temp dirs
        for f in (rover, ctrl, web):
            try:
                f.terminate()
            except Exception:
                pass
            try:
                f.freeInstance()
            except Exception:
                pass
        for d in unzipdirs:
            shutil.rmtree(d, ignore_errors=True)
