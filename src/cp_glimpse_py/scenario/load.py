# src/cp_glimpse_py/scenario/load.py
from __future__ import annotations
from dataclasses import dataclass
from pathlib import Path
import yaml

from ..common.paths import get_paths

@dataclass
class Scenario:
    raw: dict

    @property
    def model(self) -> dict:
        return self.raw["model"]

    @property
    def sim(self) -> dict:
        return self.raw["sim"]

    @property
    def params(self) -> dict:
        return self.raw.get("params", {})

    @property
    def attack(self) -> dict:
        return self.raw.get("attack", {"scenario": 0})

    @property
    def output(self) -> dict:
        return self.raw.get("output", {})

def load_scenario(path: str | Path) -> Scenario:
    paths = get_paths()
    p = Path(path)
    if not p.is_absolute():
        p = (paths.root / p).resolve()

    with p.open("r", encoding="utf-8") as f:
        raw = yaml.safe_load(f)

    # basic defaults
    raw.setdefault("attack", {"scenario": 0})
    raw.setdefault("params", {})
    raw.setdefault("output", {})
    return Scenario(raw=raw)
