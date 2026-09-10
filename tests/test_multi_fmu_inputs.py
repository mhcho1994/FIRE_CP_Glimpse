"""Tests for input time-series logging in multi-FMU execution."""

from __future__ import annotations

from pathlib import Path
from types import SimpleNamespace
from typing import Any

from cp_glimpse_py.simulation.executors import multi_fmu


class _FakeRunner:
    def __init__(self, name: str) -> None:
        self.name = name
        self.io = {
            "inputs": [SimpleNamespace(name="u")],
            "outputs": [SimpleNamespace(name="y")],
        }
        self.values: dict[str, Any] = {"u": 0.0, "y": 0.0}
        self.steps: list[tuple[float, float]] = []

    def set_value(self, name: str, value: Any) -> None:
        self.values[name] = value

    def set_input_value(self, name: str, value: Any) -> None:
        self.values[name] = value

    def is_input(self, name: str) -> bool:
        return name == "u"

    def get_value(self, name: str, default: Any = None) -> Any:
        return self.values.get(name, default)

    def instantiate_and_initialize(self) -> None:
        pass

    def step_or_raise(self, t: float, dt: float) -> None:
        self.steps.append((t, dt))
        self.values["y"] += self.values["u"] * dt

    def terminate_and_free(self) -> None:
        pass


def test_multi_fmu_records_component_qualified_inputs(
    tmp_path: Path,
    monkeypatch,
) -> None:
    fmu_path = tmp_path / "dummy.fmu"
    fmu_path.write_bytes(b"not used by fake runner")

    runners: dict[str, _FakeRunner] = {}

    def make_runner(**kwargs: Any) -> _FakeRunner:
        runner = _FakeRunner(kwargs["component_name"])
        runners[runner.name] = runner
        return runner

    monkeypatch.setattr(multi_fmu, "_make_step_runner", make_runner)

    result = multi_fmu.run_multi_fmu_open_loop(
        {
            "sim": {
                "backend": "fmu-fmpy",
                "fmu_type": "cs",
                "t0": 0.0,
                "tf": 2.0,
                "dt": 1.0,
                "show_progress": False,
            },
            "models": {
                "source": {
                    "model_path": str(fmu_path),
                    "parameters": {"u": 1.0},
                },
                "sink": {"model_path": str(fmu_path)},
            },
            "connections": [{"from": "source.y", "to": "sink.u"}],
            "outputs": {"log": ["source.y", "sink.y"]},
        }
    )

    assert result["time"] == [0.0, 1.0, 2.0]
    assert result["inputs"] == {
        "source.u": [1.0, 1.0, 1.0],
        "sink.u": [0.0, 1.0, 2.0],
    }
    assert result["metadata"]["recorded_inputs"] == ["source.u", "sink.u"]


def test_multi_fmu_step_grid_does_not_exceed_stop_time(
    tmp_path: Path,
    monkeypatch,
) -> None:
    fmu_path = tmp_path / "dummy.fmu"
    fmu_path.write_bytes(b"not used by fake runner")

    runners: dict[str, _FakeRunner] = {}

    def make_runner(**kwargs: Any) -> _FakeRunner:
        runner = _FakeRunner(kwargs["component_name"])
        runners[runner.name] = runner
        return runner

    monkeypatch.setattr(multi_fmu, "_make_step_runner", make_runner)

    result = multi_fmu.run_multi_fmu_open_loop(
        {
            "sim": {
                "backend": "fmu-fmpy",
                "fmu_type": "cs",
                "t0": 0.0,
                "tf": 1.0,
                "dt": 0.01,
                "show_progress": False,
            },
            "models": {
                "model": {
                    "model_path": str(fmu_path),
                    "parameters": {"u": 1.0},
                },
            },
            "outputs": {"log": ["model.y"]},
        }
    )

    assert result["time"][-1] == 1.0
    assert len(runners["model"].steps) == 100
    last_t, last_dt = runners["model"].steps[-1]
    assert last_t == 0.99
    assert last_t + last_dt == 1.0
