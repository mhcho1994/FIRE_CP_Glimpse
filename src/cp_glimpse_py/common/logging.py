# src/cp_glimpse_py/common/logging.py
from __future__ import annotations
import logging
import sys

def setup_logging(level: str = "INFO") -> None:
    lvl = getattr(logging, level.upper(), logging.INFO)
    root = logging.getLogger()
    root.setLevel(lvl)

    # avoid duplicate handlers
    if any(isinstance(h, logging.StreamHandler) for h in root.handlers):
        return

    h = logging.StreamHandler(sys.stdout)
    fmt = logging.Formatter("[%(levelname)s] %(name)s: %(message)s")
    h.setFormatter(fmt)
    root.addHandler(h)

def get_logger(name: str) -> logging.Logger:
    return logging.getLogger(name)
