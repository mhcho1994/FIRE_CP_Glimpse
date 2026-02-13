# src/cp_glimpse_py/common/paths.py
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
