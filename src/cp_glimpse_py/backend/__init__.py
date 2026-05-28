"""
Backend package exports.
"""

from .base import BackendArtifact, SimulationBackend, StepResult

__all__ = [
    "BackendArtifact",
    "SimulationBackend",
    "StepResult",
    "FMI2CSBackend",
    "FMI2CSBackendConfig",
    "FMI2MEBackend",
    "FMI2MEBackendConfig",
]


def __getattr__(name: str):
    if name in {"FMI2CSBackend", "FMI2CSBackendConfig"}:
        from .fmi2_cs import FMI2CSBackend, FMI2CSBackendConfig

        return {
            "FMI2CSBackend": FMI2CSBackend,
            "FMI2CSBackendConfig": FMI2CSBackendConfig,
        }[name]

    if name in {"FMI2MEBackend", "FMI2MEBackendConfig"}:
        from .fmi2_me import FMI2MEBackend, FMI2MEBackendConfig

        return {
            "FMI2MEBackend": FMI2MEBackend,
            "FMI2MEBackendConfig": FMI2MEBackendConfig,
        }[name]

    raise AttributeError(f"module {__name__!r} has no attribute {name!r}")
