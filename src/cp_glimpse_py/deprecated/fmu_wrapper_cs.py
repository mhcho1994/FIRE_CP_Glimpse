from __future__ import annotations
from dataclasses import dataclass
import numpy as np
import pyfmi

@dataclass
class FMUStepLog:
    time: np.ndarray
    input_names: list[str]
    state_names: list[str]
    var_names: list[str]
    out_names: list[str]
    input_values: np.ndarray
    state_values: np.ndarray
    var_values: np.ndarray
    out_values: np.ndarray

class FMUWrapperCS:
    """
    FMU Co-Simulation wrapper for external fixed-step stepping (doStep).
    - Supports ZOH inputs (set inputs then do_step)
    - Logs states/vars/outputs after each step
    """
    def __init__(self, fmu_path: str, t0: float, tol: float = 1e-10):
        self.model = pyfmi.load_fmu(fmu_path)  # CS kind auto-detected usually OK
        self.t0 = float(t0)
        self.t = float(t0)

        # FMI2 CS: setup experiment + initialize
        # (Some FMUs ignore tolerance, but safe)
        try:
            self.model.setup_experiment(start_time=self.t0, tolerance=tol)
        except Exception:
            self.model.setup_experiment(start_time=self.t0)
        self.model.initialize(start_time=self.t0)

        self.state_names = list(self.model.get_states_list().keys())
        self.input_names = list(self.model.get_input_list().keys())
        self.out_names = list(self.model.get_output_list().keys())
        self.var_names = list(self.model.get_model_variables().keys())

        self._u = np.zeros((len(self.input_names),), dtype=float)

        # logs (after each step)
        self._t_log = [self.t0]
        self._u_log = []
        self._x_log = []
        self._v_log = []
        self._y_log = []

    def reset(self) -> None:
        self.model.reset()
        try:
            self.model.setup_experiment(start_time=self.t0)
        except Exception:
            pass
        self.model.initialize(start_time=self.t0)
        self.t = self.t0
        self._u[:] = 0.0
        self._t_log = [self.t0]
        self._u_log.clear(); self._x_log.clear(); self._v_log.clear(); self._y_log.clear()

    def set_param(self, param_dict: dict) -> None:
        for k, v in param_dict.items():
            self.model.set(k, v)

    def set_input_zoh(self, input_dict: dict) -> None:
        # Set inputs immediately (ZOH until next update)
        if not self.input_names:
            return
        self._u = np.array([float(input_dict[n]) for n in self.input_names], dtype=float)
        self.model.set(self.input_names, self._u)

    def step(self, dt: float) -> None:
        dt = float(dt)
        if dt <= 0:
            return

        # doStep for CS
        # Some pyfmi versions use do_step, others doStep; do_step is common
        if hasattr(self.model, "do_step"):
            self.model.do_step(current_t=self.t, step_size=dt)
        else:
            self.model.doStep(self.t, dt)

        self.t = self.t + dt

        x = np.array(self.model.get(self.state_names)).flatten() if self.state_names else np.zeros((0,))
        v = np.array(self.model.get(self.var_names)).flatten() if self.var_names else np.zeros((0,))
        y = np.array(self.model.get(self.out_names)).flatten() if self.out_names else np.zeros((0,))

        self._t_log.append(self.t)
        self._u_log.append(self._u.copy())
        self._x_log.append(x)
        self._v_log.append(v)
        self._y_log.append(y)

    def get_output_dict(self) -> dict:
        if not self.out_names:
            return {}
        vals = np.array(self.model.get(self.out_names)).flatten()
        return {self.out_names[i]: float(vals[i]) for i in range(len(self.out_names))}

    def export_log(self) -> FMUStepLog:
        t = np.array(self._t_log, dtype=float)
        u = np.vstack(self._u_log) if self._u_log else np.zeros((0, len(self.input_names)))
        x = np.vstack(self._x_log) if self._x_log else np.zeros((0, len(self.state_names)))
        v = np.vstack(self._v_log) if self._v_log else np.zeros((0, len(self.var_names)))
        y = np.vstack(self._y_log) if self._y_log else np.zeros((0, len(self.out_names)))
        return FMUStepLog(
            time=t,
            input_names=self.input_names,
            state_names=self.state_names,
            var_names=self.var_names,
            out_names=self.out_names,
            input_values=u,
            state_values=x,
            var_values=v,
            out_values=y,
        )
