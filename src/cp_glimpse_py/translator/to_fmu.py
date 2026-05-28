"""Backward-compatible import shim for FMU materialization."""

from .fmu.to_fmu import FMUArtifact, build_fmu

__all__ = ["FMUArtifact", "build_fmu"]
