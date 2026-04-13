"""
cp_glimpse_py.common.paths
==========================
Centralized project path management for CP-Glimpse.

This module provides:
- automatic project root discovery via ``pyproject.toml``
- structured access to build/ and /artifacts directories         TODO: consider adding more subdirectories as needed
- deterministic directory layout for generated artifacts and run results

Directory layout
----------------
<project_root>/
├── build/
├── artifacts/
└── results/

This module does not create directories automatically. Callers should create
directories explicitly when they actually need them.
"""

from __future__ import annotations

from dataclasses import dataclass
from pathlib import Path


@dataclass(frozen=True)
class ProjectPaths:
    """
    Structured paths for CP-Glimpse project directories.

    Attributes
    ----------
    root : Path
        Absolute path to the project root directory (where pyproject.toml is located).
    """
    root: Path
    build: Path
    artifacts: Path
    results: Path

def discover_project_root(start: Path | None = None) -> Path:
    """
    Find pyproject.toml upwards.
    """
    p = (start or Path.cwd()).resolve()
    for parent in [p] + list(p.parents):
        if (parent / "pyproject.toml").exists():
            return parent
    return p

def get_paths() -> ProjectPaths:
    """
    Discover and return structured project paths.
    """
    root = discover_project_root()
    build = root / "build"
    artifacts = root / "artifacts"
    results = root / "results"

    return ProjectPaths(
        root=root,
        build=build,
        artifacts=artifacts,
        results=results,
    )
