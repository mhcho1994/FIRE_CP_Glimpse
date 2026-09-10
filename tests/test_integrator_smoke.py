"""End-to-end STR smoke test for the canonical Modelica integrator."""

from __future__ import annotations

import csv
import json
from pathlib import Path
import shutil
import subprocess
import tomllib

import pytest

from cp_glimpse_py.simulation.run import run_simulation


PROJECT_ROOT = Path(__file__).resolve().parents[1]
SCENARIO = PROJECT_ROOT / "scenarios" / "integrator_single_run.toml"
BOUNCING_BALL_SCENARIO = PROJECT_ROOT / "scenarios" / "bouncingball_single_run.toml"
ABS_TOL = 1.0e-5


def test_integrator_constant_input_cli(tmp_path: Path) -> None:
    save_dir = tmp_path / "integrator_run"
    cli = shutil.which("cp-glimpse")
    assert cli is not None, "The installed cp-glimpse console entry point was not found."
    completed = subprocess.run(
        [
            cli,
            "--scenario",
            str(SCENARIO),
            "--save-dir",
            str(save_dir),
        ],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True,
        check=False,
    )

    assert completed.returncode == 0, (
        f"CP-Glimpse CLI failed.\nstdout:\n{completed.stdout}\n"
        f"stderr:\n{completed.stderr}"
    )

    expected_artifacts = {
        "outputs.csv",
        "result.json",
        "summary.json",
        "scenario_resolved.json",
    }
    assert expected_artifacts <= {path.name for path in save_dir.iterdir()}

    result = json.loads((save_dir / "result.json").read_text(encoding="utf-8"))
    simulation = result["result"]
    assert result["status"] == "success"
    assert simulation["status"] == "success"
    assert simulation["time"][-1] == pytest.approx(5.0, abs=ABS_TOL)
    assert simulation["inputs"]["u"] == pytest.approx(
        [1.0] * len(simulation["time"]), abs=ABS_TOL
    )
    assert "y" in simulation["outputs"]
    assert simulation["outputs"]["y"][0] == pytest.approx(0.0, abs=ABS_TOL)
    assert simulation["outputs"]["y"][-1] == pytest.approx(5.0, abs=ABS_TOL)
    assert simulation["metadata"]["applied_inputs"] == {
        "type": "constant",
        "values": {"u": 1.0},
    }
    assert simulation["component"]["_artifact"]["type"] == "fmu"
    fmu_path = Path(simulation["component"]["resolved_fmu_path"])
    assert fmu_path.is_file()
    assert fmu_path.suffix == ".fmu"

    resolved = json.loads(
        (save_dir / "scenario_resolved.json").read_text(encoding="utf-8")
    )
    resolved = resolved.get("raw", resolved)
    assert resolved["inputs"]["constant"] == {"u": 1.0}

    with (save_dir / "outputs.csv").open(newline="", encoding="utf-8") as stream:
        rows = list(csv.DictReader(stream))
    assert rows
    assert float(rows[-1]["time"]) == pytest.approx(5.0, abs=ABS_TOL)
    assert float(rows[-1]["u"]) == pytest.approx(1.0, abs=ABS_TOL)
    assert float(rows[-1]["y"]) == pytest.approx(5.0, abs=ABS_TOL)


def test_integrator_time_history_input() -> None:
    scenario = {
        "sim": {
            "experiment": "single",
            "composition": "auto",
            "backend": "fmu-fmpy",
            "fmu_type": "cs",
            "t0": 0.0,
            "tf": 5.0,
            "dt": 0.01,
            "tol": 1.0e-6,
            "show_progress": False,
        },
        "system": {
            "components": [
                {
                    "name": "simple_integrator",
                    "class_name": "SimpleIntegrator",
                    "model_path": "models/benchmarks/SimpleIntegrator.mo",
                }
            ]
        },
        "inputs": {
            "type": "time_history",
            "interpolation": "zero-order-hold",
            "time": [0.0, 2.0, 5.0],
            "values": {"u": [1.0, 2.0, 2.0]},
        },
    }

    result = run_simulation(scenario, save_results=False)
    simulation = result["result"]

    # Integral: 1 * (2 - 0) + 2 * (5 - 2) = 8.
    assert simulation["time"][-1] == pytest.approx(5.0, abs=ABS_TOL)
    assert len(simulation["inputs"]["u"]) == len(simulation["time"])
    assert simulation["inputs"]["u"][0] == pytest.approx(1.0, abs=ABS_TOL)
    assert simulation["inputs"]["u"][-1] == pytest.approx(2.0, abs=ABS_TOL)
    assert simulation["outputs"]["y"][-1] == pytest.approx(8.0, abs=ABS_TOL)
    assert simulation["metadata"]["applied_inputs"]["type"] == "time_history"


def test_single_fmu_step_grid_does_not_exceed_stop_time() -> None:
    with BOUNCING_BALL_SCENARIO.open("rb") as stream:
        scenario = tomllib.load(stream)
    scenario["sim"]["show_progress"] = False

    simulation = run_simulation(scenario, save_results=False)["result"]

    assert len(simulation["time"]) == 101
    assert simulation["time"][-1] == 1.0
