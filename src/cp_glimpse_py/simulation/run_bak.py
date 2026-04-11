from __future__ import annotations

from pathlib import Path
import json
import time
import pandas as pd

from ..common.paths import get_paths
from ..common.logging import get_logger
from ..scenario.load import load_scenario
from .single_fmu import run_single_fmu_open_loop
from .montecarlo import run_monte_carlo, MonteCarloResult

log = get_logger(__name__)


def resolve_topology(scn: dict) -> str:
    """
    Resolve simulation topology from scenario contents.

    Rules
    -----
    1. If sim.topology is explicitly provided and not 'auto', respect it.
    2. If 'models' exists, use 'multi_fmu'.
    3. If 'model' exists, use 'single_fmu'.
    """
    sim_cfg = scn.get("sim", {}) or {}
    topology = str(sim_cfg.get("topology", "auto")).lower()

    if topology != "auto":
        return topology

    has_model = "model" in scn and bool(scn["model"])
    has_models = "models" in scn and bool(scn["models"])

    if has_model and has_models:
        raise ValueError("Scenario must not define both 'model' and 'models'.")

    if has_models:
        return "multi_fmu"

    if has_model:
        return "single_fmu"

    raise ValueError("Scenario must define either 'model' or 'models'.")


def resolve_experiment(scn: dict) -> str:
    """
    Resolve experiment mode from scenario contents.
    """
    sim_cfg = scn.get("sim", {}) or {}
    return str(sim_cfg.get("experiment", "single_run")).lower()


def _select_base_runner(topology: str):
    """
    Select the one-shot simulation function for the resolved topology.
    """
    if topology == "single_fmu":
        return run_single_fmu_open_loop

    if topology == "multi_fmu":
        # TODO: implement multi_fmu runner
        raise NotImplementedError("multi_fmu runner is not implemented yet.")

    raise ValueError(f"Unsupported topology: {topology}")


def _save_single_run_outputs(run_path: Path, df: pd.DataFrame) -> None:
    """
    Save outputs for a single-run simulation.
    """
    df.to_csv(run_path / "outputs.csv", index=False)


def _save_monte_carlo_outputs(run_path: Path, mc: MonteCarloResult, scn: dict) -> None:
    """
    Save outputs for a Monte Carlo simulation.
    """
    out_cfg = scn.get("output", {}) or {}
    save_csv = bool(out_cfg.get("save_csv", True))

    mc.summary.to_csv(run_path / "summary.csv", index=False)

    if save_csv and mc.traces:
        traces_dir = run_path / "traces"
        traces_dir.mkdir(parents=True, exist_ok=True)
        for trial, df in mc.traces.items():
            df.to_csv(traces_dir / f"trial_{trial:04d}.csv", index=False)


def run_from_scenario(scn_path: str | Path) -> Path:
    """
    Load a scenario, auto-dispatch to the appropriate simulation flow,
    and save results to a run directory.
    """
    paths = get_paths()
    scn = load_scenario(scn_path).raw

    topology = resolve_topology(scn)
    experiment = resolve_experiment(scn)
    base_runner = _select_base_runner(topology)

    out_cfg = scn.get("output", {}) or {}
    out_dir = paths.root / out_cfg.get("out_dir", "results/runs")
    out_dir.mkdir(parents=True, exist_ok=True)

    run_name = out_cfg.get("run_name", "run")
    run_id = f"{run_name}_{time.strftime('%Y%m%d_%H%M%S')}"
    run_path = out_dir / run_id
    run_path.mkdir(parents=True, exist_ok=True)

    (run_path / "scenario.raw.json").write_text(
        json.dumps(scn, indent=2),
        encoding="utf-8",
    )

    log.info("Resolved topology=%s experiment=%s", topology, experiment)

    if experiment == "single_run":
        df: pd.DataFrame = base_runner(scn=scn)
        _save_single_run_outputs(run_path, df)

    elif experiment == "monte_carlo":
        mc = run_monte_carlo(scn=scn, base_runner=base_runner)
        _save_monte_carlo_outputs(run_path, mc, scn)

    else:
        raise ValueError(f"Unsupported sim.experiment: {experiment}")

    log.info("Saved results: %s", run_path)
    return run_path