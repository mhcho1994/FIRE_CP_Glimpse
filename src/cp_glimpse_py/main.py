# src/cp_glimpse_py/main.py
from __future__ import annotations
import argparse

# from .common.logging import setup_logging
from .simulation.run import run_simulation

def main() -> None:
    ap = argparse.ArgumentParser()
    ap.add_argument(
        "--scenario",
        required=True,
        help="Path to scenario yaml (e.g., scenarios/bouncingball_fmu.yaml)"
    )
    ap.add_argument(
        "--log-level", 
        default="INFO",
        help="Log level (e.g., scenarios/rover_fmu.yaml)"
    )
    args = ap.parse_args()

    # setup_logging(args.log_level)
    run_simulation(args.scenario)
    # run_simulation(run_simulation({
    #         "models": {
    #             "bouncing_ball": {
    #                 "class_name": "BouncingBall",
    #                 "model_path": "models/BouncingBall.mo",
    #             }
    #         },
    #         "sim": {"experiment": "single_run"}
    #     }))

if __name__ == "__main__":
    main()
