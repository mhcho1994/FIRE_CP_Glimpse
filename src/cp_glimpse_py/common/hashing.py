# src/cp_glimpse_py/common/hashing.py
from __future__ import annotations
import hashlib
from pathlib import Path

def sha256_text(s: str) -> str:
    return hashlib.sha256(s.encode("utf-8")).hexdigest()

def sha256_file(path: Path) -> str:
    h = hashlib.sha256()
    with path.open("rb") as f:
        while True:
            b = f.read(1024 * 1024)
            if not b:
                break
            h.update(b)
    return h.hexdigest()

def model_artifact_key(*, mo_path: Path, class_name: str, fmu_type: str, extra: str = "") -> str:
    # mo file content hash + class + fmu type + extra
    file_h = sha256_file(mo_path)
    return sha256_text(f"{file_h}|{class_name}|{fmu_type}|{extra}")[:16]
