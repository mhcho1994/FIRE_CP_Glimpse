"""
cp_glimpse_py.common.logging
============================
Centralized logging configuration utilities for CP-Glimpse.

This module provides:
- A simple project-wide logging setup function (`setup_logging`)
- A lightweight logger factory (`get_logger`)

Design Goals
------------
1. Ensure consistent log formatting across the entire project.
2. Avoid duplicate log handlers when imported multiple times.
3. Keep configuration simple and CLI-friendly.
4. Default to stdout (suitable for CI and pipelines).

Typical usage
-------------
At program entry point (CLI / main script):
    from cp_glimpse_py.common.logging import setup_logging
    setup_logging("INFO")

In modules:
    from cp_glimpse_py.common.logging import get_logger
    log = get_logger(__name__)
    log.info("Something happened")

Log format example:
    [INFO] cp_glimpse_py.translator.mo_to_fmu: FMU created: ...
"""

from __future__ import annotations
import logging
import sys


def setup_logging(level: str = "INFO") -> None:
    """
    Configure the root logger for CP-Glimpse.

    Parameters
    ----------
    level : str
        Logging level as a string.
        Examples:
            - "DEBUG"
            - "INFO"
            - "WARNING"
            - "ERROR"
            - "CRITICAL"

    Behavior
    --------
    - Sets the root logger level.
    - Attaches a StreamHandler to stdout (if not already attached).
    - Uses a compact log format:
        [LEVEL] module.name: message

    Idempotency
    -----------
    This function is safe to call multiple times.
    It avoids adding duplicate StreamHandlers by checking
    existing handlers before adding a new one.

    Notes
    -----
    - Logs are written to stdout (not stderr) to integrate cleanly
      with CLI tools, CI systems, and structured pipelines.
    - This function does not remove existing handlers (e.g., file handlers).
    """

    # Convert string level to logging constant
    lvl = getattr(logging, level.upper(), logging.INFO)

    root = logging.getLogger()
    root.setLevel(lvl)

    # Avoid duplicate StreamHandlers if setup_logging() is called multiple times
    if any(isinstance(h, logging.StreamHandler) for h in root.handlers):
        return

    # Create stdout handler
    h = logging.StreamHandler(sys.stdout)

    # Compact, pipeline-friendly format
    fmt = logging.Formatter("[%(levelname)s] %(name)s: %(message)s")
    h.setFormatter(fmt)

    root.addHandler(h)


def get_logger(name: str) -> logging.Logger:
    """
    Return a module-specific logger.

    Parameters
    ----------
    name : str
        Typically __name__ of the calling module.

    Returns
    -------
    logging.Logger
        A logger instance scoped to the provided name.

    Rationale
    ---------
    Using module-scoped loggers allows:

    - Clear identification of log origin
    - Selective filtering (e.g., per-module debug)
    - Cleaner debugging in large pipelines

    Example
    -------
    log = get_logger(__name__)
    log.debug("Debug message")
    log.info("Info message")
    """
    return logging.getLogger(name)