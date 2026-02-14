# src/cp_glimpse_py/runners/run.py
from __future__ import annotations
from pathlib import Path
import json
import time
import pandas as pd

from ..common.paths import get_paths
from ..common.logging import get_logger
from ..scenario.load import load_scenario
from ..backend.rover_closed_loop_fmu import run_rover_closed_loop_fmu
from ..backend.rover_closed_loop_fmu_fmpy import run_rover_cosim_fmpy

log = get_logger(__name__)

def run_from_scenario(scn_path: str | Path) -> Path:
    paths = get_paths()
    scn = load_scenario(scn_path).raw

    backend = scn["sim"]["backend"]
    if backend != "fmu_pyfmi_rover_closed_loop":
        raise ValueError(f"Unsupported backend for this runner: {backend}")

    # df: pd.DataFrame = run_rover_cosim_fmpy(scn=scn)
    df = run_rover_cosim_fmpy(
    rover_fmu_path="/mnt/d/Dropbox/05.Workspace/C02.FIRE/01.LoFiSimulation/FIRE_CP_Glimpse/build/translator_runs/fmu/c74e82b8febe0637/RoverExample_Components_Rover.fmu",
    ctrl_fmu_path="/mnt/d/Dropbox/05.Workspace/C02.FIRE/01.LoFiSimulation/FIRE_CP_Glimpse/build/translator_runs/fmu/aa0f700a11328f99/RoverExample_Components_Controller.fmu",
    web_fmu_path="/mnt/d/Dropbox/05.Workspace/C02.FIRE/01.LoFiSimulation/FIRE_CP_Glimpse/build/translator_runs/fmu/ea2d91c31877a3f4/RoverExample_Components_Webserver.fmu",
    t0=0.0, tf=10.0, dt=0.1,
    fidelity=1,
    heading_rad=0.0,
    turn_radius=5.0,
    )

    out_cfg = scn.get("output", {})
    out_dir = paths.root / out_cfg.get("out_dir", "results/runs")
    out_dir.mkdir(parents=True, exist_ok=True)

    run_name = out_cfg.get("run_name", "run")
    run_id = f"{run_name}_{time.strftime('%Y%m%d_%H%M%S')}"
    run_path = out_dir / run_id
    run_path.mkdir(parents=True, exist_ok=True)

    # persist resolved config + meta
    (run_path / "scenario.raw.json").write_text(json.dumps(scn, indent=2), encoding="utf-8")
    df.to_csv(run_path / "outputs.csv", index=False)

    log.info(f"Saved results: {run_path}")
    return run_path
