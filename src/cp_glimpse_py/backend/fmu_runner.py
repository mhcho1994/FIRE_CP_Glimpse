"""
FMU runner factory and backward-compatible runtime exports.

Concrete implementations live in:
- `backend.runtimes.fmpy_runner.FMPYRunner`
- `backend.runtimes.pyfmi_runner.PyFMIRunner`

This module intentionally avoids importing FMPy/PyFMI at module import time.
"""

from __future__ import annotations

from pathlib import Path
from typing import Any


def create_fmu_runner(
    *,
    backend: str,
    fmu_path: str | Path,
    instance_name: str,
    fmu_type: str = "cs",
    start_time: float = 0.0,
    stop_time: float | None = None,
    tolerance: float = 1.0e-6,
    visible: bool = False,
    debug_logging: bool = False,
    show_solver_log: bool = False,
) -> Any:
    """
    Create a backend-specific FMU runtime runner.
    """
    backend = str(backend).lower()
    fmu_type = str(fmu_type).lower()

    if backend == "fmu-fmpy":
        if fmu_type != "cs":
            raise ValueError("fmu-fmpy runner currently supports CS FMUs only.")
        from .runtimes.fmpy_runner import FMPYRunner

        return FMPYRunner(
            fmu_path=str(fmu_path),
            instance_name=instance_name,
            start_time=start_time,
            stop_time=stop_time,
            visible=visible,
            debug_logging=debug_logging,
        )

    if backend == "fmu-pyfmi":
        from .runtimes.pyfmi_runner import PyFMIRunner

        return PyFMIRunner(
            fmu_path=str(fmu_path),
            instance_name=instance_name,
            fmu_type=fmu_type,
            start_time=start_time,
            stop_time=stop_time,
            tolerance=tolerance,
            visible=visible,
            debug_logging=debug_logging,
            show_solver_log=show_solver_log,
        )

    raise ValueError(f"Unsupported FMU runner backend: {backend}")


def __getattr__(name: str):
    if name in {"FMPYRunner", "FMI2CSRunner"}:
        from .runtimes.fmpy_runner import FMPYRunner

        return FMPYRunner
    if name == "PyFMIRunner":
        from .runtimes.pyfmi_runner import PyFMIRunner

        return PyFMIRunner
    raise AttributeError(f"module {__name__!r} has no attribute {name!r}")


__all__ = [
    "create_fmu_runner",
    "FMPYRunner",
    "FMI2CSRunner",
    "PyFMIRunner",
]
