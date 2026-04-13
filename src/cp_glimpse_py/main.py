"""
cp_glimpse_py.main
==================

CLI entry point for CP-Glimpse.

This module parses command-line arguments, configures project-wide logging,
and dispatches scenario execution to the top-level simulation runner.
"""

from __future__ import annotations

import argparse

from .common import setup_logging
from .simulation import run_simulation


def main() -> None:
    """
    Run the CP-Glimpse CLI entry point.
    """
    ap = argparse.ArgumentParser(description="CP-Glimpse simulation runner")
    ap.add_argument(
        "--scenario",
        required=True,
        help="Path to scenario YAML (e.g., scenarios/bouncingball_fmu.yaml)",
    )
    ap.add_argument(
        "--log-level",
        default="INFO",
        help="Logging level (e.g., DEBUG, INFO, WARNING, ERROR).",
    )
    args = ap.parse_args()

    setup_logging(args.log_level)
    run_simulation(args.scenario)
    
    # Test code for development:
    # run_simulation(run_simulation({
    #         "sim": {"experiment": "single_run"},
    #         "system": {
    #             "components": {
    #                 "bouncing_ball": {
    #                     "class_name": "BouncingBall",
    #                     "model_path": "models/BouncingBall.mo",
    #                 },
    #             },
    #         },
    #     }))

if __name__ == "__main__":
    main()
