# src/translator/casadi_translator.py

from __future__ import annotations
import argparse
import importlib.util
import json
import os
import re
import traceback
from dataclasses import dataclass, asdict
from pathlib import Path
from typing import Optional, Dict, Any, List

import rumoca


# -----------------------------
# Config / Data structures
# -----------------------------

@dataclass(frozen=True)
class CasadiTranslateConfig:
    """
    Modelica(.mo) -> rumoca.compile -> rumoca.export(template) -> CasADi Builder python code.

    Artifacts (per run):
      build/translator_runs/<run_name>/
        - model.py
        - base_modelica.json
        - manifest.json
        - translator.log
    """
    repo_root: Path
    build_dir: Path

    runs_dirname: str = "translator_runs"

    # Use rumoca system binary first (native bindings fallback is handled by rumoca)
    prefer_system_rumoca: bool = False

    # Path to the Jinja2 template that emits CasADi Builder python
    # (e.g., (repo_root)/"examples"/"templates"/"casadi_daebuilder.py.jinja")
    template_path: Path = Path("examples/templates/casadi_daebuilder.jinja")

    # Save BaseModelica JSON (recommended for reproducibility/debug)
    save_base_modelica_json: bool = True


@dataclass(frozen=True)
class CasadiTranslateRequest:
    model_path: Path                 # .mo file
    run_name: str                    # e.g., "bouncingball"
    class_name: Optional[str] = None # optional metadata only (rumoca extracts model name from file)


@dataclass(frozen=True)
class CasadiTranslateResult:
    out_dir: Path
    casadi_py_path: Path
    base_modelica_json_path: Optional[Path]
    manifest_path: Path
    log_path: Path


# -----------------------------
# Utilities
# -----------------------------

def _ensure_dir(p: Path) -> None:
    p.mkdir(parents=True, exist_ok=True)


def _sanitize_name(name: str) -> str:
    s = re.sub(r"[^a-zA-Z0-9._-]+", "_", name.strip())
    return s or "run"


def _write_text(p: Path, s: str) -> None:
    p = Path(p).expanduser().resolve()
    if not p.parent.exists():
        _ensure_dir(p.parent)
    p.write_text(s, encoding="utf-8")


def _write_json(p: Path, obj: Dict[str, Any]) -> None:
    p.write_text(json.dumps(obj, indent=2, ensure_ascii=False), encoding="utf-8")


def _load_module_from_path(module_name: str, file_path: Path):
    spec = importlib.util.spec_from_file_location(module_name, str(file_path))
    if spec is None or spec.loader is None:
        raise ImportError(f"Failed to create import spec for {file_path}")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod


# -----------------------------
# Main translator
# -----------------------------

class CasadiTranslator:
    """
    Translate Modelica to CasADi Python using rumoca.

    - compile(.mo) -> BaseModelica
    - export(template) -> python code (CasADi DaeBuilder Model class)
    - write artifacts under build/translator_runs/<run_name>/
    """

    def __init__(self, cfg: CasadiTranslateConfig):
        self.cfg = cfg

        # Set global behavior inside rumoca module
        rumoca.set_prefer_system_binary(cfg.prefer_system_rumoca)

    def translate(self, req: CasadiTranslateRequest) -> CasadiTranslateResult:
        cfg = self.cfg

        model_path = req.model_path.resolve()
        if not model_path.exists():
            raise FileNotFoundError(f"Modelica file not found: {model_path}")

        run_name = _sanitize_name(req.run_name)
        out_dir = (cfg.build_dir / cfg.runs_dirname / run_name).resolve()
        _ensure_dir(out_dir)

        log_path = out_dir / "translator.log"
        manifest_path = out_dir / "manifest.json"
        casadi_py_path = out_dir / "model.py"
        base_modelica_json_path = out_dir / "base_modelica.json" if cfg.save_base_modelica_json else None

        template_path = (cfg.repo_root / cfg.template_path).resolve()
        if not template_path.exists():
            raise FileNotFoundError(
                f"Template not found: {template_path}\n"
                f"Set CasadiTranslateConfig.template_path to the correct location."
            )

        log_lines: List[str] = []
        log_lines.append(f"[casadi_translator] model_path={model_path}")
        log_lines.append(f"[casadi_translator] run_name={run_name}")
        log_lines.append(f"[casadi_translator] prefer_system_rumoca={cfg.prefer_system_rumoca}")
        log_lines.append(f"[casadi_translator] template_path={template_path}")
        if req.class_name:
            log_lines.append(f"[casadi_translator] class_name(meta)={req.class_name}")

        try:
            # Compile: native if available else subprocess fallback is handled inside rumoca
            result = rumoca.compile(str(model_path), prefer_system=cfg.prefer_system_rumoca)
            log_lines.append(f"[rumoca] compiled ok; is_native={getattr(result, 'is_native', None)}")

            # Save Base Modelica JSON (recommended)
            if cfg.save_base_modelica_json and base_modelica_json_path is not None:
                base_json = result.to_base_modelica_json()
                _write_text(base_modelica_json_path, base_json)
                log_lines.append(f"[artifact] wrote {base_modelica_json_path}")

            # Export using your Jinja template -> CasADi DaeBuilder python code
            # NOTE: rumoca.export(template) requires rumoca binary per the bindings.
            py_code = result.export(template_path)
            _write_text(casadi_py_path, py_code)
            log_lines.append(f"[artifact] wrote {casadi_py_path}")

            # Manifest
            manifest: Dict[str, Any] = {
                "request": asdict(req),
                "config": {
                    **asdict(cfg),
                    "repo_root": str(cfg.repo_root),
                    "build_dir": str(cfg.build_dir),
                    "template_path": str(cfg.template_path),
                },
                "outputs": {
                    "out_dir": str(out_dir),
                    "casadi_py_path": str(casadi_py_path),
                    "base_modelica_json_path": str(base_modelica_json_path) if base_modelica_json_path else None,
                    "log_path": str(log_path),
                    "manifest_path": str(manifest_path),
                },
            }
            _write_json(manifest_path, manifest)
            log_lines.append(f"[artifact] wrote {manifest_path}")

            _write_text(log_path, "\n".join(log_lines) + "\n")

            return CasadiTranslateResult(
                out_dir=out_dir,
                casadi_py_path=casadi_py_path,
                base_modelica_json_path=base_modelica_json_path,
                manifest_path=manifest_path,
                log_path=log_path,
            )

        except Exception as e:
            log_lines.append("[error] translation failed")
            log_lines.append(str(e))
            log_lines.append(traceback.format_exc())
            _write_text(log_path, "\n".join(log_lines) + "\n")
            raise


# -----------------------------
# CasADi -> C codegen helper
# -----------------------------

def generate_c_code_from_generated_model(
    generated_model_py: Path,
    out_dir: Path,
    *,
    model_name: str = "Model",
    tf: float = 0.0,
    integrator: Optional[str] = None,
) -> Path:
    """
    Generate C code using CasADi from the generated DaeBuilder model.py.

    Your template generates something like:
      class Model:
          def __init__(...):
              self.dae = ca.DaeBuilder(...)
    and may include simulate().

    This helper:
      - imports the generated module
      - instantiates Model(model_name)
      - builds a CasADi Function from dae.create()
      - uses ca.CodeGenerator to produce C code

    Notes:
      - `ca.DaeBuilder.create()` returns a DAE dict compatible with integrator.
      - For "just the model", we codegen a residual function (dae.create()) as `ca.Function`.
      - Optionally, you can codegen an integrator Function too (heavier).

    Returns:
      Path to generated C file (model.c).
    """
    import casadi as ca

    generated_model_py = Path(generated_model_py).resolve()
    out_dir = Path(out_dir).resolve()
    _ensure_dir(out_dir)

    mod = _load_module_from_path("rumoca_generated_model", generated_model_py)

    if not hasattr(mod, "Model"):
        raise AttributeError(
            f"{generated_model_py} does not define `class Model`. "
            "Check your template output."
        )

    m = mod.Model(model_name)
    if not hasattr(m, "dae"):
        raise AttributeError(
            "Generated Model instance has no attribute `dae`. "
            "Check your template output."
        )

    dae_builder = m.dae
    dae_struct = dae_builder.create()

    # Build a "residual" function for codegen:
    # DAE dict typically contains fields: x, z, p, t, ode, alg, ... depending on builder
    # We'll create a single function returning (ode, alg) if they exist.
    x = dae_struct.get("x", ca.SX.sym("x", 0))
    z = dae_struct.get("z", ca.SX.sym("z", 0))
    p = dae_struct.get("p", ca.SX.sym("p", 0))
    t = dae_struct.get("t", ca.SX.sym("t"))

    ode = dae_struct.get("ode", ca.SX.zeros(x.size1()))
    alg = dae_struct.get("alg", ca.SX.zeros(z.size1()))

    f_res = ca.Function("dae_residuals", [x, z, p, t], [ode, alg])

    c_path = out_dir / "model.c"
    cg = ca.CodeGenerator(str(c_path))
    cg.add(f_res)

    # Optional: also generate an integrator (can be huge; only do if requested)
    if integrator is not None:
        # If tf is 0, caller should set it; otherwise CasADi may complain.
        opts = {}
        if tf and tf > 0:
            opts["tf"] = float(tf)
        F = ca.integrator("F", integrator, dae_struct, opts)
        cg.add(F)

    cg.generate()
    return c_path


def create_casadi_translator(
    repo_root: Path = Path.cwd(),
    build_dir: Path = "",
    *,
    dump_base_json: bool = True,
    template_path: Path = Path.cwd() / "examples/templates/casadi_daebuilder.jinja",
    prefer_system_rumoca: bool = False,
) -> CasadiTranslator:
    
    repo_root = Path(repo_root).resolve()
    cfg = CasadiTranslateConfig(
        repo_root=repo_root,
        build_dir=build_dir if build_dir else repo_root / "build",
        runs_dirname="translator_runs",
        prefer_system_rumoca=prefer_system_rumoca,
        template_path=template_path,
        save_base_modelica_json=dump_base_json,
    )
    return CasadiTranslator(cfg)


def main():
    ap = argparse.ArgumentParser(description="Translate Modelica model to CasADi (via rumoca)")
    ap.add_argument("model_file", type=str, help="Path to .mo file (e.g., examples/bouncingball/bouncingball.mo)",)
    ap.add_argument("--model", type=str, default="", help="Model name (not-activated, rumoca auto-detects from file)")
    ap.add_argument("--run-name", type=str, default="", help="Output directory name under build/translator_runs/(model file stem)")
    ap.add_argument("--build-dir", type=str, default="build", help="Build directory (default: repo build)")
    ap.add_argument("--template", type=str, default="examples/templates/casadi.jinja", help="Jinja template for CasADi DaeBuilder")
    ap.add_argument("--prefer-system", action="store_true", help="Prefer system rumoca binary over native bindings")
    ap.add_argument("--no-json", action="store_true", help="Do not save base_modelica.json")

    args = ap.parse_args()

    model_file = Path(args.model_file).expanduser().resolve()
    if not model_file.exists():
        raise SystemExit(f"Model file not found: {model_file}")

    repo_root = (Path(__file__).resolve().parents[2]).joinpath("submodules/rumoca").resolve()

    run_name = args.run_name or model_file.stem

    path_to_template = repo_root.joinpath(args.template)
    if not path_to_template.exists():
        raise SystemExit(f"Template file not found: {repo_root / args.template}")

    translator = create_casadi_translator(
        repo_root,
        build_dir=Path(args.build_dir) if args.build_dir else repo_root / "build",
        dump_base_json=not args.no_json,
        template_path=path_to_template,
        prefer_system_rumoca=args.prefer_system,
    )

    req = CasadiTranslateRequest(
        model_path=model_file,
        run_name=run_name,
        class_name=args.model.strip() or None,
    )

    res = translator.translate(req)

    print("Translation finished.")
    print("Generated CasADi model:", res.casadi_py_path)
    if res.base_modelica_json_path:
        print("Base Modelica JSON:", res.base_modelica_json_path)
    print("Manifest:", res.manifest_path)


if __name__ == "__main__":
    main()