"""
cp_glimpse_py.common.paths
==========================
Centralized project path management for CP-Glimpse.

This module provides:
- Automatic project root discovery (via pyproject.toml)
- Structured access to build/ and results/ directories
- Deterministic directory layout for simulation artifacts

Design Goals
------------
1. Avoid hardcoded paths throughout the codebase.
2. Ensure reproducible artifact storage.
3. Keep build outputs separate from results.
4. Support execution from any subdirectory.

Directory Layout
----------------
<project_root>/
│
├── build/
│   ├── modelica_runs/
│   └── translator_runs/
│
└── results/
    └── runs/

It does NOT create directories.
"""

from __future__ import annotations
from dataclasses import dataclass
from pathlib import Path

@dataclass(frozen=True)
class ProjectPaths:
    root: Path
    build: Path
    build_modelica_runs: Path
    build_translator_runs: Path
    results: Path
    results_runs: Path

def discover_project_root(start: Path | None = None) -> Path:
    # find pyproject.toml upwards
    p = (start or Path.cwd()).resolve()
    for parent in [p] + list(p.parents):
        if (parent / "pyproject.toml").exists():
            return parent
    return p

def get_paths() -> ProjectPaths:
    root = discover_project_root()
    build = root / "build"
    results = root / "results"
    return ProjectPaths(
        root=root,
        build=build,
        build_modelica_runs=build / "modelica_runs",
        build_translator_runs=build / "translator_runs",
        results=results,
        results_runs=results / "runs",
    )
