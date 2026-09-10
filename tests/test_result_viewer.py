"""Tests for the read-only CP-Glimpse result viewer."""

from __future__ import annotations

import json
from pathlib import Path
from threading import Thread
from urllib.error import HTTPError
from urllib.request import urlopen

import pytest

from cp_glimpse_py.viewer.server import create_server, discover_runs


def _write_run(root: Path, name: str = "integrator") -> Path:
    run = root / name
    run.mkdir()
    (run / "result.json").write_text(
        json.dumps(
            {
                "status": "success",
                "result": {
                    "status": "success",
                    "composition": "single",
                    "backend": "fmu-fmpy",
                    "fmu_type": "cs",
                    "time": [0.0, 1.0],
                    "inputs": {"u": [1.0, 1.0]},
                    "outputs": {"y": [0.0, 1.0]},
                    "metadata": {"wall_time_sec": 0.01},
                },
            }
        ),
        encoding="utf-8",
    )
    (run / "summary.json").write_text(
        json.dumps(
            {
                "status": "success",
                "result_status": "success",
                "composition": "single",
                "experiment": "single",
                "n_time_points": 2,
                "sim": {"backend": "fmu-fmpy", "fmu_type": "cs"},
            }
        ),
        encoding="utf-8",
    )
    (run / "scenario_resolved.json").write_text(
        json.dumps(
            {
                "raw": {
                    "system": {
                        "components": [
                            {"name": "source", "class_name": "Example.Source"},
                            {"name": "plant", "class_name": "Example.Plant"},
                        ]
                    },
                    "connections": [
                        {"from": "source.y", "to": "plant.u"},
                    ],
                    "sim": {"stepping": {"order": ["source", "plant"]}},
                }
            }
        ),
        encoding="utf-8",
    )
    (run / "outputs.csv").write_text("time,y,u\n0,0,1\n1,1,1\n", encoding="utf-8")
    return run


@pytest.fixture
def viewer_url(tmp_path: Path):
    _write_run(tmp_path)
    _write_run(tmp_path, "comparison")
    server = create_server(tmp_path, port=0)
    thread = Thread(target=server.serve_forever, daemon=True)
    thread.start()
    host, port = server.server_address[:2]
    try:
        yield f"http://{host}:{port}"
    finally:
        server.shutdown()
        server.server_close()
        thread.join(timeout=2)


def _get_json(url: str) -> dict:
    with urlopen(url, timeout=2) as response:
        assert response.status == 200
        return json.loads(response.read())


def test_discover_runs_uses_existing_summary(tmp_path: Path) -> None:
    _write_run(tmp_path)
    (tmp_path / "not-a-run").mkdir()

    runs = discover_runs(tmp_path)

    assert [run["id"] for run in runs] == ["integrator"]
    assert runs[0]["status"] == "success"
    assert runs[0]["backend"] == "fmu-fmpy"
    assert runs[0]["n_time_points"] == 2


def test_viewer_serves_page_and_result_api(viewer_url: str) -> None:
    with urlopen(f"{viewer_url}/", timeout=2) as response:
        page = response.read().decode("utf-8")
    assert "CP-Glimpse" in page
    assert "/assets/app.js" in page
    assert "Axis range" in page
    assert "Multi-FMU topology" in page
    assert "Compare runs" in page

    with urlopen(f"{viewer_url}/assets/app.js", timeout=2) as response:
        script = response.read().decode("utf-8")
    assert "renderTopology" in script
    assert "comparisonStatistics" in script

    index = _get_json(f"{viewer_url}/api/runs")
    assert {run["id"] for run in index["runs"]} == {"integrator", "comparison"}

    detail = _get_json(f"{viewer_url}/api/runs/integrator")
    simulation = detail["result"]["result"]
    assert simulation["inputs"] == {"u": [1.0, 1.0]}
    assert simulation["outputs"] == {"y": [0.0, 1.0]}
    assert detail["scenario"]["raw"]["connections"] == [
        {"from": "source.y", "to": "plant.u"}
    ]
    assert set(detail["artifacts"]) == {
        "result.json",
        "summary.json",
        "scenario_resolved.json",
        "outputs.csv",
    }


def test_viewer_rejects_paths_outside_results_root(viewer_url: str) -> None:
    with pytest.raises(HTTPError) as error:
        urlopen(f"{viewer_url}/api/runs/%2e%2e", timeout=2)
    assert error.value.code == 404
