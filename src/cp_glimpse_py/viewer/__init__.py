"""Read-only browser viewer for CP-Glimpse result artifacts."""

from .server import create_server, discover_runs

__all__ = ["create_server", "discover_runs"]
