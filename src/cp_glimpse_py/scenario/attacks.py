# src/cp_glimpse_py/scenario/attacks.py
from __future__ import annotations
import numpy as np

def init_attack_state(*, scenario: int, params: dict, seed: int | None = None) -> dict:
    rng = np.random.default_rng(seed)
    st: dict = {"scenario": scenario, "rng": rng}

    if scenario == 1:
        st["emi_atk_level"] = params["emi_disturbance"] / 180.0 * np.pi
        st["bias"] = 2.0 * (rng.random() - 0.5)
    elif scenario == 2:
        st["rollover_thr_pwm"] = params["throttle_pwm_level"]
    elif scenario == 3:
        st["gyro_atk_power"] = params["acoustic_power"]
        st["speaker_dist"] = params["speaker_dist"]
        st["gyro_atk_freq"] = (params["drive_freq"] + params["acoustic_freq_range"] * (2 * rng.random() - 1)) * (2 * np.pi)
        st["gyro_misalignment"] = params["gyro_misalignment"] * rng.random() * (np.pi / 180.0)
        st["gyro_atk_dir"] = rng.random() * (np.pi / 2.0)
        st["gyro_atk_phase"] = rng.random() * 2 * np.pi - np.pi
    elif scenario == 4:
        wire_dir_map = {
            1: np.array([1, 0, 0]),
            2: np.array([-1, 0, 0]),
            3: np.array([0, 1, 0]),
            4: np.array([0, -1, 0]),
            5: np.array([0, 0, 1]),
        }
        st["wire_dir"] = wire_dir_map.get(int(params["wire_dir"]), np.array([0, 0, -1]))
        st["wire_dist"] = np.array([0, 0, -params["wire_relative_dist"]])

    return st

def per_step_params_for_rover(*, scenario: int, st: dict) -> dict:
    # returns dict of FMU parameters to set on rover per-step
    if scenario == 3:
        return {
            "W": float(st["gyro_atk_power"]),
            "dist": float(st["speaker_dist"]),
            "w_ac": float(st["gyro_atk_freq"]),
            "phi_0": float(st["gyro_atk_phase"]),
            "psi_ac": float(st["gyro_atk_dir"]),
            "epsilon": float(st["gyro_misalignment"]),
        }
    else:
        # nominal
        return {
            "W": 0.0,
            "dist": 0.01,
            "w_ac": 15000.0,
            "phi_0": 0.0,
            "psi_ac": 0.0,
            "epsilon": 0.0,
        }

def per_step_params_for_emi_wire(*, scenario: int, st: dict) -> dict:
    # applies only to hi-fi rover_8d
    if scenario == 4:
        wd = st["wire_dir"]
        xd = st["wire_dist"]
        return {
            "rover_8d.emi.wire_dir[1]": float(wd[0]),
            "rover_8d.emi.wire_dir[2]": float(wd[1]),
            "rover_8d.emi.wire_dir[3]": float(wd[2]),
            "rover_8d.emi.x_wire[1]": float(xd[0]),
            "rover_8d.emi.x_wire[2]": float(xd[1]),
            "rover_8d.emi.x_wire[3]": float(xd[2]),
        }
    else:
        return {
            "rover_8d.emi.wire_dir[1]": 0.0,
            "rover_8d.emi.wire_dir[2]": 0.0,
            "rover_8d.emi.wire_dir[3]": 1.0,
            "rover_8d.emi.x_wire[1]": 0.0,
            "rover_8d.emi.x_wire[2]": 0.0,
            "rover_8d.emi.x_wire[3]": -0.01,
        }
