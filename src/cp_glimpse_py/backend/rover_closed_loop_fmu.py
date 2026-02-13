# src/cp_glimpse_py/backend/rover_closed_loop_fmu.py
from __future__ import annotations
import numpy as np
import pandas as pd

from ..common.logging import get_logger
from ..scenario.attacks import (
    init_attack_state,
    per_step_params_for_rover,
    per_step_params_for_emi_wire,
)
from ..backend.fmu_wrapper import FMUWrapper
from ..backend.fmu_wrapper_cs import FMUWrapperCS
from ..translator.to_fmu import build_fmu

log = get_logger(__name__)

def eul2quat(eul: np.ndarray) -> np.ndarray:
    phi, theta, psi = float(eul[0]), float(eul[1]), float(eul[2])
    out = np.zeros((4,), dtype=float)
    out[0] = np.cos(psi/2)*np.cos(theta/2)*np.cos(phi/2) + np.sin(psi/2)*np.sin(theta/2)*np.sin(phi/2)
    out[1] = np.cos(psi/2)*np.cos(theta/2)*np.sin(phi/2) - np.sin(psi/2)*np.sin(theta/2)*np.cos(phi/2)
    out[2] = np.cos(psi/2)*np.sin(theta/2)*np.cos(phi/2) + np.sin(psi/2)*np.cos(theta/2)*np.sin(phi/2)
    out[3] = np.sin(psi/2)*np.cos(theta/2)*np.cos(phi/2) - np.cos(psi/2)*np.sin(theta/2)*np.sin(phi/2)
    return out

def run_rover_closed_loop_fmu(*, scn: dict) -> pd.DataFrame:
    model = scn["model"]
    sim = scn["sim"]
    params = scn.get("params", {})
    attack_cfg = scn.get("attack", {"scenario": 0})

    mo_path = model["mo_path"]
    comps = model["components"]
    fmu_type = sim.get("fmu_type", "me")
    fidelity = int(sim.get("fidelity", 1))
    t0 = float(sim.get("t0", 0.0))
    tf = float(sim.get("tf", 10.0))
    dt = float(sim.get("dt", 0.1))
    tol = float(sim.get("tol", 1e-6))

    atk_scenario = int(attack_cfg.get("scenario", 0))
    seed = attack_cfg.get("seed", None)
    atk_state = init_attack_state(scenario=atk_scenario, params=params, seed=seed)

    # --- Build FMUs (cached) ---
    art_rover = build_fmu(mo_path=mo_path, class_name=comps["rover"], fmu_type=fmu_type)
    art_ctrl  = build_fmu(mo_path=mo_path, class_name=comps["controller"], fmu_type=fmu_type)
    art_web   = build_fmu(mo_path=mo_path, class_name=comps["webserver"], fmu_type=fmu_type)

    # rover = FMUWrapper(str(art_rover.fmu_path), fmu_type, t0, tol=tol)
    # ctrl  = FMUWrapper(str(art_ctrl.fmu_path),  fmu_type, t0, tol=tol)
    # web   = FMUWrapper(str(art_web.fmu_path),   fmu_type, t0, tol=tol)
    web = FMUWrapperCS(str(art_web.fmu_path), t0, tol=tol)
    ctrl = FMUWrapperCS(str(art_ctrl.fmu_path), t0, tol=tol)
    rover = FMUWrapperCS(str(art_rover.fmu_path), t0, tol=tol)

    # --- init parameters ---
    heading_rad = float(params["heading"]) / 180.0 * np.pi
    ic_quat = eul2quat(np.array([0.0, 0.0, heading_rad], dtype=float))

    # rover initial conditions depend on fidelity
    if fidelity == 1:
        rover.set_param({
            "rover_3d.x": 0.0, "rover_3d.y": 0.0, "rover_3d.z": 0.0,
            "rover_3d.vx": 0.0, "rover_3d.vy": 0.0, "rover_3d.vz": 0.0,
            "rover_3d.psi": heading_rad, "rover_3d.theta": 0.0, "rover_3d.phi": 0.0,
            "rover_3d.p": 0.0, "rover_3d.q": 0.0, "rover_3d.r": 0.0,
        })
        # l_total needed for delta_turn
        l_total = float(rover.model.get("rover_3d.l_total"))
    else:
        rover.set_param({
            "rover_8d.x": 0.0, "rover_8d.y": 0.0, "rover_8d.z": 0.0,
            "rover_8d.vx": 0.0, "rover_8d.vy": 0.0, "rover_8d.vz": 0.0,
            "rover_8d.psi": heading_rad, "rover_8d.theta": 0.0, "rover_8d.phi": 0.0,
            "rover_8d.p": 0.0, "rover_8d.q": 0.0, "rover_8d.r": 0.0,
            "rover_8d.omega_fl": 0.0, "rover_8d.omega_fr": 0.0,
            "rover_8d.omega_rl": 0.0, "rover_8d.omega_rr": 0.0,
            "rover_8d.omega": 0.0,
        })
        l_total = float(rover.model.get("rover_8d.l_total"))

    ctrl.set_param({
        "s": 0,
        "x_ref": 0.0, "y_ref": 0.0, "psi_ref": 0.0,
        "v": 0.0, "delta": 0.0,
        "quaternion_filtered[1]": float(ic_quat[0]),
        "quaternion_filtered[2]": float(ic_quat[1]),
        "quaternion_filtered[3]": float(ic_quat[2]),
        "quaternion_filtered[4]": float(ic_quat[3]),
        "delta_turn": float(np.atan(l_total / float(params["turn_radius"]))),
    })

    # --- simulation loop ---
    times = np.linspace(t0, tf, int((tf - t0) / dt) + 1)

    # for t_cur in times[:-1]:
    #     t_next = t_cur + dt

    #     # webserver
    #     web.set_param({"sample_interval": dt + 1e-6})
    #     web.step(t_next)
    #     turn_cmd = web.export_log().out_values[-1, web.export_log().out_names.index("turn")] if "turn" in web.out_names else None

    #     # controller inputs (turn is not an input; set directly on internal var)
    #     if turn_cmd is not None:
    #         ctrl.model.set("turn", turn_cmd)

    #     rover_out = rover.get_output_dict()

    #     # build controller sensor input dict
    #     # (attack scenario 1 modifies psi_gyro during turns & s>=3)
    #     ctrl_in = {
    #         "ax_acc": rover_out.get("ax_meas", 0.0),
    #         "ay_acc": rover_out.get("ay_meas", 0.0),
    #         "az_acc": rover_out.get("az_meas", 0.0),
    #         "mx_mag": rover_out.get("mx_meas", 0.0),
    #         "my_mag": rover_out.get("my_meas", 0.0),
    #         "mz_mag": rover_out.get("mz_meas", 0.0),
    #         "phi_gyro": rover_out.get("phi_meas", 0.0),
    #         "theta_gyro": rover_out.get("theta_meas", 0.0),
    #         "psi_gyro": rover_out.get("psi_meas", 0.0),
    #         "p_gyro": rover_out.get("p_meas", 0.0),
    #         "q_gyro": rover_out.get("q_meas", 0.0),
    #         "r_gyro": rover_out.get("r_meas", 0.0),
    #         "x": rover_out.get("x_meas", 0.0),
    #         "y": rover_out.get("y_meas", 0.0),
    #     }

    #     if atk_scenario == 1:
    #         # if ctrl state 's' exists and >=3 (turning), inject bias
    #         try:
    #             s_val = float(ctrl.model.get("s"))
    #         except Exception:
    #             s_val = 0.0
    #         if s_val >= 3.0:
    #             ctrl_in["psi_gyro"] = ctrl_in["psi_gyro"] + float(atk_state["emi_atk_level"]) * float(atk_state["bias"])

    #     ctrl.set_input_zoh(t_next, ctrl_in)
    #     ctrl.set_param({"sample_interval": dt + 1e-6})
    #     ctrl.step(t_next)

    #     ctrl_out = ctrl.get_output_dict()
    #     pwm_steering = ctrl_out.get("pwm_steering", 0.0)
    #     pwm_throttle = ctrl_out.get("pwm_throttle", 0.0)

    #     if atk_scenario == 2:
    #         pwm_throttle = float(atk_state["rollover_thr_pwm"])

    #     rover.set_input_zoh(t_next, {"pwm_steering": pwm_steering, "pwm_throttle": pwm_throttle})

    #     # attack params (gyro acoustic / wire emi vulnerability)
    #     rover.set_param(per_step_params_for_rover(scenario=atk_scenario, st=atk_state))
    #     if fidelity == 2:
    #         rover.set_param(per_step_params_for_emi_wire(scenario=atk_scenario, st=atk_state))

    #     rover.set_param({"sample_interval": dt + 1e-6})
    #     rover.step(t_next)

    #     # correct internal timer counters (your original workaround)
    #     try:
    #         web.model.set(["timer_count"], [np.float64(t_cur / dt)])
    #     except Exception:
    #         pass
    #     try:
    #         rover.model.set(["gyroatk.timer_count"], [np.float64(t_cur / dt)])
    #     except Exception:
    #         pass

    for t_cur in times[:-1]:
        # -------------------------
        # 1) webserver
        # -------------------------
        web.set_param({"sample_interval": dt + 1e-6})
        web.step(dt)

        # turn command (output)
        web_out = web.get_output_dict()
        turn_cmd = web_out.get("turn", None)

        # controller inputs (turn is not an input; set directly on internal var)
        if turn_cmd is not None:
            try:
                ctrl.model.set("turn", turn_cmd)
            except Exception:
                pass

        # -------------------------
        # 2) controller
        # -------------------------
        rover_out = rover.get_output_dict()

        ctrl_in = {
            "ax_acc": rover_out.get("ax_meas", 0.0),
            "ay_acc": rover_out.get("ay_meas", 0.0),
            "az_acc": rover_out.get("az_meas", 0.0),
            "mx_mag": rover_out.get("mx_meas", 0.0),
            "my_mag": rover_out.get("my_meas", 0.0),
            "mz_mag": rover_out.get("mz_meas", 0.0),
            "phi_gyro": rover_out.get("phi_meas", 0.0),
            "theta_gyro": rover_out.get("theta_meas", 0.0),
            "psi_gyro": rover_out.get("psi_meas", 0.0),
            "p_gyro": rover_out.get("p_meas", 0.0),
            "q_gyro": rover_out.get("q_meas", 0.0),
            "r_gyro": rover_out.get("r_meas", 0.0),
            "x": rover_out.get("x_meas", 0.0),
            "y": rover_out.get("y_meas", 0.0),
        }

        if atk_scenario == 1:
            # if ctrl state 's' exists and >=3 (turning), inject bias
            try:
                s_val = float(ctrl.model.get("s"))
            except Exception:
                s_val = 0.0
            if s_val >= 3.0:
                ctrl_in["psi_gyro"] = ctrl_in["psi_gyro"] + float(atk_state["emi_atk_level"]) * float(atk_state["bias"])

        ctrl.set_input_zoh(ctrl_in)
        ctrl.set_param({"sample_interval": dt + 1e-6})
        ctrl.step(dt)

        ctrl_out = ctrl.get_output_dict()
        pwm_steering = ctrl_out.get("pwm_steering", 0.0)
        pwm_throttle = ctrl_out.get("pwm_throttle", 0.0)

        if atk_scenario == 2:
            pwm_throttle = float(atk_state["rollover_thr_pwm"])

        # -------------------------
        # 3) rover dynamics
        # -------------------------
        rover.set_input_zoh({"pwm_steering": pwm_steering, "pwm_throttle": pwm_throttle})

        # attack params (gyro acoustic / wire emi vulnerability)
        rover.set_param(per_step_params_for_rover(scenario=atk_scenario, st=atk_state))
        if fidelity == 2:
            rover.set_param(per_step_params_for_emi_wire(scenario=atk_scenario, st=atk_state))

        rover.set_param({"sample_interval": dt + 1e-6})
        rover.step(dt)

        # -------------------------
        # 4) correct internal timer counters (legacy workaround)
        # -------------------------
        try:
            web.model.set(["timer_count"], [np.float64(t_cur / dt)])
        except Exception:
            pass
        try:
            rover.model.set(["gyroatk.timer_count"], [np.float64(t_cur / dt)])
        except Exception:
            pass

    # --- assemble output dataframe similar to your previous save_data ---
    rover_log = rover.export_log()
    ctrl_log = ctrl.export_log()
    web_log = web.export_log()

    # align lengths: we log after each step, time includes t0 plus steps
    t = rover_log.time
    def stack(parts):
        return np.hstack(parts) if parts else np.zeros((len(t), 0))

    cols = ["time"]
    data = [t.reshape(-1, 1)]

    # rover
    cols += rover_log.state_names + rover_log.var_names
    data += [rover_log.state_values, rover_log.var_values]
    # controller
    cols += ctrl_log.state_names + ctrl_log.var_names
    data += [ctrl_log.state_values, ctrl_log.var_values]
    # webserver
    cols += web_log.state_names + web_log.var_names
    data += [web_log.state_values, web_log.var_values]

    df = pd.DataFrame(stack(data), columns=cols)
    return df
