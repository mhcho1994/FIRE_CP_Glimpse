# src/cp_glimpse_py/backend/fmu_wrapper.py
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

class FMUWrapper:
    def __init__(self, fmu_path: str, fmu_type: str, t0: float, tol: float = 1e-10):
        self.model = pyfmi.load_fmu(fmu_path, kind=fmu_type)
        self.t0 = float(t0)
        self.t = float(t0)

        self.model.initialize(start_time=self.t0)

        self.state_names = list(self.model.get_states_list().keys())
        self.input_names = list(self.model.get_input_list().keys())
        self.out_names = list(self.model.get_output_list().keys())
        self.var_names = list(self.model.get_model_variables().keys())

        self._input = np.zeros((len(self.input_names),), dtype=float)
        self._timed_input = np.hstack([np.zeros((0, 1)), np.zeros((0, len(self.input_names)))])  # [dt, u...]

        self.opts = self.model.simulate_options()
        self.opts["solver"] = "CVode"
        self.opts["result_handling"] = "memory"
        self.opts["result_store_variable_description"] = False
        self.opts["ncp"] = 10

        cv = self.opts["CVode_options"]
        cv["atol"] = tol
        cv["rtol"] = tol
        cv["discr"] = "BDF"
        cv["maxord"] = 5

        # log buffers
        self._t_log = [self.t0]
        self._u_log = []
        self._x_log = []
        self._v_log = []
        self._y_log = []

    def reset(self) -> None:
        self.model.reset()
        self.model.initialize(start_time=self.t0)
        self.t = self.t0
        self._input[:] = 0.0
        self._timed_input = np.hstack([np.zeros((0, 1)), np.zeros((0, len(self.input_names)))])
        self._t_log = [self.t0]
        self._u_log.clear(); self._x_log.clear(); self._v_log.clear(); self._y_log.clear()

    def set_param(self, param_dict: dict) -> None:
        for k, v in param_dict.items():
            self.model.set(k, v)

    def set_input_zoh(self, t_next: float, input_dict: dict) -> None:
        # piecewise constant input from current t to t_next
        if not self.input_names:
            return
        u = np.array([float(input_dict[n]) for n in self.input_names], dtype=float)
        dt = float(t_next - self.t)
        if dt < 0:
            raise ValueError("t_next must be >= current time")

        self._timed_input = np.vstack(
            [self._timed_input,
             np.hstack([0.0, u]),
             np.hstack([dt,  u])]
        )
        self._input = u

    def step(self, t_next: float) -> None:
        dt = float(t_next - self.t)
        if dt < 0:
            raise ValueError("t_next must be >= current time")
        if dt == 0:
            return

        if self._input.size == 0:
            self.model.simulate(start_time=0, final_time=dt, options=self.opts)
        else:
            input_tuple = (self.input_names, self._timed_input)
            self.model.simulate(start_time=0, final_time=dt, options=self.opts, input=input_tuple)

        x = np.array(self.model.get(self.state_names)).flatten() if self.state_names else np.zeros((0,))
        v = np.array(self.model.get(self.var_names)).flatten() if self.var_names else np.zeros((0,))
        y = np.array(self.model.get(self.out_names)).flatten() if self.out_names else np.zeros((0,))

        self._t_log.append(t_next)
        self._u_log.append(self._input.copy())
        self._x_log.append(x)
        self._v_log.append(v)
        self._y_log.append(y)

        # re-init for next chunk (your original pattern)
        self.model.reset()
        self.model.initialize(start_time=self.t0)
        if self.state_names:
            self.model.set(self.state_names, x)
        if self.var_names:
            self.model.set(self.var_names, v)

        self._timed_input = np.hstack([np.zeros((0, 1)), np.zeros((0, len(self.input_names)))])
        self.t = t_next

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
