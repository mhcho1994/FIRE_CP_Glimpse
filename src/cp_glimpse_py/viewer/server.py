"""Small read-only HTTP server for browsing CP-Glimpse result artifacts."""

from __future__ import annotations

import argparse
from datetime import datetime, timezone
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import json
import mimetypes
from pathlib import Path
from typing import Any
from urllib.parse import unquote, urlsplit
import webbrowser


STATIC_DIR = Path(__file__).with_name("static")
ARTIFACT_NAMES = (
    "result.json",
    "summary.json",
    "scenario_resolved.json",
    "outputs.csv",
)


def _read_json(path: Path, default: Any = None) -> Any:
    try:
        return json.loads(path.read_text(encoding="utf-8"))
    except (FileNotFoundError, json.JSONDecodeError, OSError):
        return default


def discover_runs(results_dir: str | Path) -> list[dict[str, Any]]:
    """Return a compact, newest-first index of result directories."""
    root = Path(results_dir).expanduser().resolve()
    if not root.is_dir():
        return []

    runs: list[dict[str, Any]] = []
    for directory in root.iterdir():
        result_path = directory / "result.json"
        if not directory.is_dir() or not result_path.is_file():
            continue

        summary = _read_json(directory / "summary.json", {})
        if not isinstance(summary, dict):
            summary = {}
        stat = result_path.stat()
        sim = summary.get("sim", {})
        if not isinstance(sim, dict):
            sim = {}
        runs.append(
            {
                "id": directory.name,
                "status": summary.get("result_status", summary.get("status", "unknown")),
                "composition": summary.get("composition"),
                "experiment": summary.get("experiment"),
                "backend": sim.get("backend"),
                "fmu_type": sim.get("fmu_type"),
                "n_time_points": summary.get("n_time_points"),
                "wall_time_sec": summary.get("wall_time_sec"),
                "modified_at": datetime.fromtimestamp(
                    stat.st_mtime, tz=timezone.utc
                ).isoformat(),
                "result_bytes": stat.st_size,
            }
        )

    runs.sort(key=lambda item: item["modified_at"], reverse=True)
    return runs


class ViewerHTTPServer(ThreadingHTTPServer):
    """HTTP server carrying the configured results and static roots."""

    daemon_threads = True

    def __init__(self, address: tuple[str, int], results_dir: Path):
        self.results_dir = results_dir.expanduser().resolve()
        super().__init__(address, ViewerRequestHandler)


class ViewerRequestHandler(BaseHTTPRequestHandler):
    """Serve packaged viewer assets and a narrow, read-only results API."""

    server: ViewerHTTPServer

    def _send_bytes(
        self,
        data: bytes,
        *,
        content_type: str,
        status: HTTPStatus = HTTPStatus.OK,
        disposition: str | None = None,
        cache_control: str = "no-store",
    ) -> None:
        self.send_response(status)
        self.send_header("Content-Type", content_type)
        self.send_header("Content-Length", str(len(data)))
        self.send_header("Cache-Control", cache_control)
        self.send_header("X-Content-Type-Options", "nosniff")
        self.send_header("Content-Security-Policy", "default-src 'self'; connect-src 'self'; img-src 'self' data:; style-src 'self'; script-src 'self'")
        if disposition:
            self.send_header("Content-Disposition", disposition)
        self.end_headers()
        self.wfile.write(data)

    def _send_json(
        self,
        value: Any,
        status: HTTPStatus = HTTPStatus.OK,
    ) -> None:
        data = json.dumps(value, separators=(",", ":"), ensure_ascii=False).encode("utf-8")
        self._send_bytes(data, content_type="application/json; charset=utf-8", status=status)

    def _send_error_json(self, status: HTTPStatus, message: str) -> None:
        self._send_json({"error": message}, status=status)

    def _run_dir(self, run_id: str) -> Path | None:
        if not run_id or run_id in {".", ".."} or "/" in run_id or "\\" in run_id:
            return None
        candidate = (self.server.results_dir / run_id).resolve()
        if candidate.parent != self.server.results_dir or not candidate.is_dir():
            return None
        if not (candidate / "result.json").is_file():
            return None
        return candidate

    def _serve_static(self, relative: str) -> None:
        path = (STATIC_DIR / relative).resolve()
        if not path.is_relative_to(STATIC_DIR.resolve()) or not path.is_file():
            self._send_error_json(HTTPStatus.NOT_FOUND, "Static asset not found")
            return
        content_type = mimetypes.guess_type(path.name)[0] or "application/octet-stream"
        if content_type.startswith("text/") or content_type in {"application/javascript", "application/json"}:
            content_type += "; charset=utf-8"
        self._send_bytes(
            path.read_bytes(),
            content_type=content_type,
            cache_control="public, max-age=300",
        )

    def _serve_run(self, run_id: str) -> None:
        directory = self._run_dir(run_id)
        if directory is None:
            self._send_error_json(HTTPStatus.NOT_FOUND, "Run not found")
            return

        result = _read_json(directory / "result.json")
        if result is None:
            self._send_error_json(HTTPStatus.UNPROCESSABLE_ENTITY, "Invalid result.json")
            return
        summary = _read_json(directory / "summary.json", {})
        scenario = _read_json(directory / "scenario_resolved.json", {})
        artifacts = [name for name in ARTIFACT_NAMES if (directory / name).is_file()]
        self._send_json(
            {
                "id": run_id,
                "result": result,
                "summary": summary,
                "scenario": scenario,
                "artifacts": artifacts,
            }
        )

    def _serve_artifact(self, run_id: str, filename: str) -> None:
        directory = self._run_dir(run_id)
        if directory is None or filename not in ARTIFACT_NAMES:
            self._send_error_json(HTTPStatus.NOT_FOUND, "Artifact not found")
            return
        path = directory / filename
        if not path.is_file():
            self._send_error_json(HTTPStatus.NOT_FOUND, "Artifact not found")
            return
        content_type = mimetypes.guess_type(filename)[0] or "application/octet-stream"
        self._send_bytes(
            path.read_bytes(),
            content_type=f"{content_type}; charset=utf-8",
            disposition=f'attachment; filename="{filename}"',
        )

    def do_GET(self) -> None:  # noqa: N802 - BaseHTTPRequestHandler API
        path = unquote(urlsplit(self.path).path)
        if path in {"/", "/index.html"}:
            self._serve_static("index.html")
            return
        if path == "/api/runs":
            self._send_json({"runs": discover_runs(self.server.results_dir)})
            return
        if path.startswith("/assets/"):
            self._serve_static(path.removeprefix("/assets/"))
            return

        parts = [part for part in path.split("/") if part]
        if len(parts) == 3 and parts[:2] == ["api", "runs"]:
            self._serve_run(parts[2])
            return
        if (
            len(parts) == 5
            and parts[:2] == ["api", "runs"]
            and parts[3] == "artifacts"
        ):
            self._serve_artifact(parts[2], parts[4])
            return
        self._send_error_json(HTTPStatus.NOT_FOUND, "Not found")

    def log_message(self, format: str, *args: Any) -> None:
        # Keep the normal access log, but give it a recognizable prefix.
        print(f"[cp-glimpse-viewer] {self.address_string()} - {format % args}")


def create_server(
    results_dir: str | Path = "results",
    *,
    host: str = "127.0.0.1",
    port: int = 8000,
) -> ViewerHTTPServer:
    """Create a configured viewer server without starting its event loop."""
    root = Path(results_dir).expanduser().resolve()
    if not root.is_dir():
        raise FileNotFoundError(f"Results directory not found: {root}")
    return ViewerHTTPServer((host, port), root)


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Browse CP-Glimpse result artifacts in a local web viewer."
    )
    parser.add_argument(
        "--results-dir",
        default="results",
        help="Directory containing one result directory per run (default: results)",
    )
    parser.add_argument("--host", default="127.0.0.1", help="Bind address")
    parser.add_argument("--port", default=8000, type=int, help="HTTP port")
    parser.add_argument("--open", action="store_true", help="Open the viewer in a browser")
    args = parser.parse_args()

    try:
        server = create_server(args.results_dir, host=args.host, port=args.port)
    except (FileNotFoundError, OSError) as exc:
        parser.error(str(exc))

    display_host = "127.0.0.1" if args.host in {"0.0.0.0", "::"} else args.host
    actual_port = server.server_address[1]
    url = f"http://{display_host}:{actual_port}/"
    print(f"CP-Glimpse result viewer: {url}")
    print(f"Reading results from: {server.results_dir}")
    if args.open:
        webbrowser.open(url)
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\nStopping CP-Glimpse result viewer.")
    finally:
        server.server_close()


__all__ = ["create_server", "discover_runs", "main"]
