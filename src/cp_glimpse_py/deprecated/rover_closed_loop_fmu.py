# src/cp_glimpse_py/backend/rover_closed_loop_fmu.py
from __future__ import annotations

import numpy as np
import pandas as pd

from pyfmi import load_fmu
from pyfmi.master import Master

from ..common.logging import get_logger
from ..scenario.attacks import (
    init_attack_state,
    per_step_params_for_rover,
    per_step_params_for_emi_wire,
)
from ..translator.mo_to_fmu import build_fmu

log = get_logger(__name__)


def eul2quat(eul: np.ndarray) -> np.ndarray:
    phi, theta, psi = float(eul[0]), float(eul[1]), float(eul[2])
    out = np.zeros((4,), dtype=float)
    out[0] = np.cos(psi / 2) * np.cos(theta / 2) * np.cos(phi / 2) + np.sin(psi / 2) * np.sin(theta / 2) * np.sin(phi / 2)
    out[1] = np.cos(psi / 2) * np.cos(theta / 2) * np.sin(phi / 2) - np.sin(psi / 2) * np.sin(theta / 2) * np.cos(phi / 2)
    out[2] = np.cos(psi / 2) * np.sin(theta / 2) * np.cos(phi / 2) + np.sin(psi / 2) * np.cos(theta / 2) * np.sin(phi / 2)
    out[3] = np.sin(psi / 2) * np.cos(theta / 2) * np.cos(phi / 2) - np.cos(psi / 2) * np.sin(theta / 2) * np.sin(phi / 2)
    return out


def _set_many(model, values: dict) -> None:
    """
    Robust bulk setter.
    - PyFMI models generally support model.set(name, value) and model.set(list_of_names, array_of_values).
    - We keep it simple and robust (loop) because FMU variable presence can differ per fidelity.
    """
    for k, v in values.items():
        try:
            model.set(k, v)
        except Exception:
            # silently ignore missing vars (common when fidelity changes)
            pass


def _get_one(model, name: str, default: float | None = None):
    try:
        return model.get(name)
    except Exception:
        return default


def _last(res, model, var: str):
    """
    PyFMI Master returns a result object where you can do res[model]['var'] (arrays).
    We take the last point of the most recent chunk.
    """
    try:
        arr = res[model][var]
        if np.ndim(arr) == 0:
            return float(arr)
        return float(arr[-1])
    except Exception:
        return None


def run_rover_closed_loop_fmu(*, scn: dict) -> pd.DataFrame:
    model_cfg = scn["model"]
    sim = scn["sim"]
    params = scn.get("params", {})
    attack_cfg = scn.get("attack", {"scenario": 0})

    mo_path = model_cfg["mo_path"]
    comps = model_cfg["components"]

    # IMPORTANT: PyFMI Master is for FMI 2.0 Co-Simulation FMUs (CS).
    # (ME FMUs are not driven by do_step in the same way.)
    fmu_type = sim.get("fmu_type", "cs")
    if str(fmu_type).lower() != "cs":
        log.warning("PyFMI Master co-simulation requires CS FMUs. Overriding fmu_type=%r -> 'cs'.", fmu_type)
        fmu_type = "cs"

    fidelity = int(sim.get("fidelity", 1))
    t0 = float(sim.get("t0", 0.0))
    tf = float(sim.get("tf", 10.0))
    dt = float(sim.get("dt", 0.1))

    atk_scenario = int(attack_cfg.get("scenario", 0))
    seed = attack_cfg.get("seed", None)
    atk_state = init_attack_state(scenario=atk_scenario, params=params, seed=seed)

    # --- Build FMUs (cached) ---
    art_rover = build_fmu(mo_path=mo_path, class_name=comps["rover"], fmu_type=fmu_type)
    art_ctrl  = build_fmu(mo_path=mo_path, class_name=comps["controller"], fmu_type=fmu_type)
    art_web   = build_fmu(mo_path=mo_path, class_name=comps["webserver"], fmu_type=fmu_type)

    # --- Load FMUs into PyFMI ---
    rover = load_fmu(str(art_rover.fmu_path))
    ctrl  = load_fmu(str(art_ctrl.fmu_path))
    web   = load_fmu(str(art_web.fmu_path))

    # --- init parameters / IC ---
    heading_rad = float(params["heading"]) / 180.0 * np.pi
    ic_quat = eul2quat(np.array([0.0, 0.0, heading_rad], dtype=float))

    # rover initial conditions depend on fidelity
    # if fidelity == 1:
    #     _set_many(rover, {
    #         "rover_3d.x": 0.0, "rover_3d.y": 0.0, "rover_3d.z": 0.0,
    #         "rover_3d.vx": 0.0, "rover_3d.vy": 0.0, "rover_3d.vz": 0.0,
    #         "rover_3d.psi": heading_rad, "rover_3d.theta": 0.0, "rover_3d.phi": 0.0,
    #         "rover_3d.p": 0.0, "rover_3d.q": 0.0, "rover_3d.r": 0.0,
    #     })
    #     l_total = float(_get_one(rover, "rover_3d.l_total", 0.0) or 0.0)
    # else:
    #     _set_many(rover, {
    #         "rover_8d.x": 0.0, "rover_8d.y": 0.0, "rover_8d.z": 0.0,
    #         "rover_8d.vx": 0.0, "rover_8d.vy": 0.0, "rover_8d.vz": 0.0,
    #         "rover_8d.psi": heading_rad, "rover_8d.theta": 0.0, "rover_8d.phi": 0.0,
    #         "rover_8d.p": 0.0, "rover_8d.q": 0.0, "rover_8d.r": 0.0,
    #         "rover_8d.omega_fl": 0.0, "rover_8d.omega_fr": 0.0,
    #         "rover_8d.omega_rl": 0.0, "rover_8d.omega_rr": 0.0,
    #         "rover_8d.omega": 0.0,
    #     })
    #     l_total = float(_get_one(rover, "rover_8d.l_total", 0.0) or 0.0)

    # _set_many(ctrl, {
    #     "s": 0,
    #     "x_ref": 0.0, "y_ref": 0.0, "psi_ref": 0.0,
    #     "v": 0.0, "delta": 0.0,
    #     "quaternion_filtered[1]": float(ic_quat[0]),
    #     "quaternion_filtered[2]": float(ic_quat[1]),
    #     "quaternion_filtered[3]": float(ic_quat[2]),
    #     "quaternion_filtered[4]": float(ic_quat[3]),
    #     "delta_turn": float(np.atan(l_total / float(params["turn_radius"]))),
    # })

    # sample interval vars (if they exist)
    _set_many(web,  {"sample_interval": dt + 1e-9})
    _set_many(ctrl, {"sample_interval": dt + 1e-9})
    _set_many(rover, {"sample_interval": dt + 1e-9})

    # --- Define Master connections (signal relay) ---
    # 1) rover meas -> controller sensors (except psi_gyro: we may override for attack scenario 1)
    rover_to_ctrl = [
        ("ax_meas", "ax_acc"),
        ("ay_meas", "ay_acc"),
        ("az_meas", "az_acc"),
        ("mx_meas", "mx_mag"),
        ("my_meas", "my_mag"),
        ("mz_meas", "mz_mag"),
        ("phi_meas", "phi_gyro"),
        ("theta_meas", "theta_gyro"),
        ("psi_meas", "psi_gyro"),  # leave unconnected to allow attack override
        ("p_meas", "p_gyro"),
        ("q_meas", "q_gyro"),
        ("r_meas", "r_gyro"),
        ("x_meas", "x"),
        ("y_meas", "y"),
    ]

    # 2) controller -> rover actuators (except pwm_throttle: we may override for attack scenario 2)
    ctrl_to_rover = [
        ("pwm_steering", "pwm_steering"),
        ("pwm_throttle", "pwm_throttle"),  # leave unconnected to allow attack override
    ]

    connections = []
    for y, u in rover_to_ctrl:
        connections.append((rover, y, ctrl, u))
    for y, u in ctrl_to_rover:
        connections.append((ctrl, y, rover, u))

    # NOTE: web.turn -> ctrl.turn is not connected here because (per your comment)
    # ctrl.turn is not an FMU input in your model. We apply it manually each step (ZOH).

    models = [ctrl, rover]
    master = Master(models, connections)

    # --- Master options ---
    opts = master.simulate_options()
    opts["step_size"] = dt
    # opts["initialize"] = True
    # opts["block_initialization"] = True  # helps with feed-through/algebraic loops when present
    opts["linear_correction"] = False     # stabilization option (if FMUs support needed features)
    # opts["extrapolation_order"] = 0      # constant extrapolation between comm points
    # opts["result_handling"] = "memory"   # keep results in memory (easy to aggregate)

    # Initialize once
    master.initialize(start_time=t0, final_time=tf, opts=opts)

    # --- Simulation loop (step-wise Master simulate) ---
    n_steps = int(np.floor((tf - t0) / dt))
    t_cur = t0

    rows: list[dict] = []

    # Keep ZOH command from web to controller (since ctrl.turn isn't an FMU input)
    last_turn_cmd = 0.0

    for k in range(n_steps):
        t_next = t_cur + dt

        # 0) per-step attack params into rover (and wire model if needed)
        _set_many(rover, per_step_params_for_rover(scenario=atk_scenario, st=atk_state))
        if fidelity == 2:
            _set_many(rover, per_step_params_for_emi_wire(scenario=atk_scenario, st=atk_state))

        # 1) apply web->ctrl command (ZOH: use last web output as "current" command)
        # If ctrl.turn exists as internal variable, set it. (If not, ignore.)
        if last_turn_cmd is not None:
            try:
                ctrl.set("turn", float(last_turn_cmd))
            except Exception:
                pass

        # 2) attack scenario 1: override ctrl.psi_gyro input (since we did NOT connect it)
        if atk_scenario == 1:
            # we bias psi when ctrl state 's' >= 3
            try:
                s_val = float(ctrl.get("s"))
            except Exception:
                s_val = 0.0

            # read rover psi measurement directly from rover FMU (current comm point)
            psi_meas = _get_one(rover, "psi_meas", 0.0) or 0.0
            if s_val >= 3.0:
                psi_meas = float(psi_meas) + float(atk_state["emi_atk_level"]) * float(atk_state["bias"])

            try:
                ctrl.set("psi_gyro", float(psi_meas))
            except Exception:
                pass
        else:
            # non-attack: just pass-through psi_meas manually (since it's not connected)
            psi_meas = _get_one(rover, "psi_meas", 0.0) or 0.0
            try:
                ctrl.set("psi_gyro", float(psi_meas))
            except Exception:
                pass

        # 3) attack scenario 2: override rover throttle (since we did NOT connect pwm_throttle)
        if atk_scenario == 2:
            try:
                rover.set("pwm_throttle", float(atk_state["rollover_thr_pwm"]))
            except Exception:
                pass
        else:
            # non-attack: pass-through controller pwm_throttle manually
            pwm_thr = _get_one(ctrl, "pwm_throttle", 0.0) or 0.0
            try:
                rover.set("pwm_throttle", float(pwm_thr))
            except Exception:
                pass

        # 4) run one communication step via Master
        # IMPORTANT: initialize=False for subsequent steps
        step_opts = opts.copy()
        step_opts["initialize"] = False

        res = master.simulate(start_time=t_cur, final_time=t_next, options=step_opts)

        # 5) update last_turn_cmd from *web output* at end of this step
        # next step will apply it as ZOH
        turn_val = _last(res, web, "turn")
        if turn_val is not None:
            last_turn_cmd = float(turn_val)

        # 6) collect a compact row (add more vars if you want)
        row = {
            "time": float(_last(res, rover, "time") or t_next),
            # web
            "web.turn": float(turn_val or 0.0),
            # ctrl outputs
            "ctrl.pwm_steering": float(_last(res, ctrl, "pwm_steering") or 0.0),
            "ctrl.pwm_throttle": float(_last(res, ctrl, "pwm_throttle") or 0.0),
            "ctrl.s": float(_last(res, ctrl, "s") or 0.0),
            # rover key outputs (extend as needed)
            "rover.x_meas": float(_last(res, rover, "x_meas") or 0.0),
            "rover.y_meas": float(_last(res, rover, "y_meas") or 0.0),
            "rover.psi_meas": float(_last(res, rover, "psi_meas") or 0.0),
        }
        rows.append(row)

        t_cur = t_next

    df = pd.DataFrame(rows)
    return df
