"""
cp_glimpse_py.common.hashing
============================
Deterministic hashing utilities for CP-Glimpse artifact management.

This module provides content-based hashing functions used to generate
stable, reproducible artifact keys for build outputs such as:
    - FMUs
    - CasADi-generated code
    - C codegen artifacts
    - Simulation pipelines

Design Goals
------------
1. Artifact keys must depend on *model content*, not file timestamps.
2. Identical inputs should always produce identical keys.
3. Keys should be short enough for directory names.
4. Hash computation should scale to large Modelica files.

Typical usage
-------------
key = model_artifact_key(
    mo_path=Path("models/Rover.mo"),
    class_name="RoverExample.Components.Webserver",
    fmu_type="me",
)

This key is then used as:

    build/translator_runs/fmu/<key>/

so that artifacts are automatically cached and reproducible.
"""

from __future__ import annotations
import hashlib
from pathlib import Path

def sha256_text(s: str) -> str:
    """
    Compute SHA-256 hash of a UTF-8 encoded string.

    Parameters
    ----------
    s : str
        Input string.

    Returns
    -------
    str
        Hexadecimal SHA-256 digest (64 characters).

    Notes
    -----
    Used for hashing structured metadata (e.g., file hash + class name).
    """
    return hashlib.sha256(s.encode("utf-8")).hexdigest()

def sha256_file(path: Path) -> str:
    """
    Compute SHA-256 hash of a file's contents.

    Parameters
    ----------
    path : Path
        Path to file.

    Returns
    -------
    str
        Hexadecimal SHA-256 digest (64 characters).

    Implementation Details
    ----------------------
    - File is read in 1MB chunks to avoid high memory usage.
    - Suitable for large Modelica files or generated code.
    - Hash depends purely on file contents, not metadata.
    """
    h = hashlib.sha256()

    with path.open("rb") as f:
        while True:
            b = f.read(1024 * 1024)  # 1MB chunk
            if not b:
                break
            h.update(b)

    return h.hexdigest()

def model_artifact_key(
    *,
    mo_path: Path,
    class_name: str,
    fmu_type: str,
    extra: str = "",
) -> str:
    """
    Generate a deterministic artifact key for a Modelica-based build.

    Parameters
    ----------
    mo_path : Path
        Path to Modelica (.mo) file.

    class_name : str
        Fully-qualified Modelica class name being exported.

    fmu_type : str
        FMU type ("me" or "cs").

    extra : str, optional
        Additional configuration string to incorporate into the hash.
        Useful for:
            - OpenModelica version
            - compiler flags
            - optimization level
            - CasADi options
            - experimental features

    Returns
    -------
    str
        16-character short hash key.

    Hash Structure
    --------------
    The key is computed as:

        SHA256(
            SHA256(file_contents)
            | class_name
            | fmu_type
            | extra
        )

    and truncated to 16 hex characters.

    Rationale
    ---------
    - File content hash ensures rebuild only when model changes.
    - class_name ensures different submodels produce different artifacts.
    - fmu_type distinguishes ME vs CS builds.
    - extra allows future-proof extension without breaking interface.
    - Truncation keeps directory names short while collision risk remains negligible
      for practical CPS development workflows.

    Example
    -------
    If:
        file hash = abc123...
        class_name = RoverExample.Components.Webserver
        fmu_type = me

    Then:
        key = "ea2d91c31877a3f4"
    """

    # Hash the raw Modelica file contents
    file_h = sha256_file(mo_path)

    # Combine with structured build metadata
    combined = f"{file_h}|{class_name}|{fmu_type}|{extra}"

    # Hash again to avoid leaking raw file hash structure
    full_hash = sha256_text(combined)

    # Shorten for directory usability
    return full_hash[:16]