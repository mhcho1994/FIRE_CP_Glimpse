"""
cp_glimpse_py.main
=================================
CLI-based entry point for the simulation package.
"""

from __future__ import annotations

import argparse
import csv
from pathlib import Path
from typing import Any

# from .common.logging import setup_logging
from .simulation.run import run_simulation


def _resolve_path(save_dir_arg: str | None) -> Path | None:
    if not save_dir_arg:
        return None

    path = Path(save_dir_arg)

    if path.suffix.lower() == ".csv" and not path.is_dir():
        path.parent.mkdir(parents=True, exist_ok=True)
        return path

    if path.exists() and path.is_file():
        raise FileExistsError(f"Save directory path is an existing file: {path}")

    path.mkdir(parents=True, exist_ok=True)
    return path / "outputs.csv"


def _timeseries_from_result(result: dict[str, Any]) -> tuple[list[dict[str, Any]], list[str]]:
    inner = result.get("result", result)

    time_values = inner.get("time")
    outputs = inner.get("outputs", {})

    if time_values is None and isinstance(inner.get("result"), dict):
        inner = inner["result"]
        time_values = inner.get("time")
        outputs = inner.get("outputs", {})

    if not isinstance(time_values, list):
        raise ValueError("Simulation result does not contain a time series to save as CSV.")
    if not isinstance(outputs, dict):
        outputs = {}

    fieldnames = ["time", *[str(name) for name in outputs.keys()]]
    rows: list[dict[str, Any]] = []
    for idx, t in enumerate(time_values):
        row: dict[str, Any] = {"time": t}
        for name, values in outputs.items():
            if isinstance(values, list) and idx < len(values):
                row[str(name)] = values[idx]
            else:
                row[str(name)] = None
        rows.append(row)

    return rows, fieldnames


def _save_result_csv(result: dict[str, Any], csv_path: Path) -> None:
    rows, fieldnames = _timeseries_from_result(result)
    with csv_path.open("w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        writer.writerows(rows)


def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument(
        "--scenario",
        required=True,
        help="Path to scenario YAML or TOML file (e.g., scenarios/bouncingball_single_run.yaml)"
    )

    ap.add_argument(
        "--save-dir",
        help="Path to a directory where outputs.csv will be saved"
    )

    # TODO
    # ap.add_argument(
    #     "--log-level", 
    #     default="INFO",
    #     help="Log level"
    # )
    args = ap.parse_args()

    csv_path = _resolve_path(args.save_dir)

    # setup_logging(args.log_level)
    artifact_dir = csv_path.parent if csv_path is not None else None
    result = run_simulation(args.scenario, output_dir=artifact_dir)

    if csv_path is not None:
        _save_result_csv(result, csv_path)
        print(f"Saved CSV results to: {csv_path}")

if __name__ == "__main__":
    main()
