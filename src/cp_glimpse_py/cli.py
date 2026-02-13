# src/cp_glimpse_py/cli.py
from __future__ import annotations
import argparse

from .common.logging import setup_logging
from .runners.run import run_from_scenario

def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument("scenario", help="Path to scenario yaml (e.g., scenarios/rover_fmu.yaml)")
    ap.add_argument("--log-level", default="INFO")
    args = ap.parse_args()

    setup_logging(args.log_level)
    run_from_scenario(args.scenario)

if __name__ == "__main__":
    main()
