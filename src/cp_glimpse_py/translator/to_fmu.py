# src/cp_glimpse_py/translator/to_fmu.py
from __future__ import annotations
from dataclasses import dataclass
from pathlib import Path
import shutil

from OMPython import ModelicaSystem

from ..common.paths import get_paths
from ..common.hashing import model_artifact_key
from ..common.logging import get_logger

log = get_logger(__name__)

@dataclass(frozen=True)
class FMUArtifact:
    fmu_path: Path
    work_dir: Path
    key: str

def build_fmu(*, mo_path: str | Path, class_name: str, fmu_type: str) -> FMUArtifact:
    paths = get_paths()
    mo_path = Path(mo_path)
    if not mo_path.is_absolute():
        mo_path = (paths.root / mo_path).resolve()
    if not mo_path.exists():
        raise FileNotFoundError(mo_path)

    key = model_artifact_key(mo_path=mo_path, class_name=class_name, fmu_type=fmu_type)
    out_dir = paths.build_translator_runs / "fmu" / key
    out_dir.mkdir(parents=True, exist_ok=True)

    # standard filename (safe)
    fmu_name = class_name.replace(".", "_")
    expected = out_dir / f"{fmu_name}.fmu"

    if expected.exists():
        log.info(f"FMU cache hit: {expected}")
        return FMUArtifact(fmu_path=expected, work_dir=out_dir, key=key)

    log.info(f"Building FMU: class={class_name}, type={fmu_type}, mo={mo_path}")
    model = ModelicaSystem(str(mo_path), class_name)
    fmu_gen = model.convertMo2Fmu(fileNamePrefix=fmu_name, fmuType=fmu_type)

    fmu_gen = Path(fmu_gen)
    if not fmu_gen.exists():
        raise RuntimeError(f"FMU generation failed, got path: {fmu_gen}")

    # copy generated fmu into out_dir with stable name
    shutil.copy2(fmu_gen, expected)
    log.info(f"FMU created: {expected}")
    return FMUArtifact(fmu_path=expected, work_dir=out_dir, key=key)
