#!/usr/bin/env python3
import argparse
import os
import re
from pathlib import Path
from collections.abc import Sequence
from typing import List, Dict, Any, Optional, Union
import pandas as pd
import shutil
from OMPython import OMCSessionZMQ

def omc_send(omc: OMCSessionZMQ, expr: str) -> Any:
    """ wrapper for OMC sendExpression """
    return omc.sendExpression(expr)


def omc_get_errors(omc: OMCSessionZMQ) -> str:
    err = omc_send(omc, "getErrorString()")
    return err if isinstance(err, str) else str(err)


def parse_omc_string_list(x: Any) -> List[str]:
    """
    Normalize OMC getClassNames() outputs to list [str].
    Can handle:
      - tuple: (str, ...)
      - list: [str, ...]
      - Modelica array string: '{"str", ...}'
      - Single string
      - None
    """
    if x is None:
        return []
    
    # Check tuple and list
    if isinstance(x, Sequence) and not isinstance(x, (str, bytes)):
        return [str(s) for s in x if s is not None and str(s).strip()]
    
    # Modelica array string and single string
    if isinstance(x, str):
        # try to parse Modelica array string: {"A","B"}
        matches = re.findall(r"\{[^\}]*\}", x)
        if matches:
            s = matches[-1]
            return re.findall(r"\"([^\"]+)\"", s)
        # single name
        s = x.strip()
        return [s] if s else []
    
    return []


def get_restriction(omc: OMCSessionZMQ, cls: str) -> str:
    """
    Returns restriction string such as: model, package, block, record, function, ...
    """
    r = omc.sendExpression(f"getClassRestriction({cls})")
    if isinstance(r, str):
        return r.strip().lower()
    return str(r).strip().lower()


def collect_models_recursive(omc: OMCSessionZMQ, scope: str = "") -> List[str]:
    """
    Recursively collect fully-qualified names whose restriction == 'model'.
    If scope=="" -> top-level.
    """
    raw = omc_send(omc, f"getClassNames({scope})") if scope else omc_send(omc, "getClassNames()")
    names = parse_omc_string_list(raw)
    names = [n for n in names if n and n != "Modelica"]

    models: List[str] = []
    for n in names:
        fq = f"{scope}.{n}" if scope else n
        r = get_restriction(omc, fq)
        if r == "model":
            models.append(fq)
        elif r == "package":
            models.extend(collect_models_recursive(omc, fq))
        else:
            # ignore block/record/function/type/connector/etc
            pass

    return models


def order_candidates(candidates: List[str], model_file: Path) -> List[str]:
    """
    Prefer candidates whose last component equals file stem.
    """
    stem = model_file.stem
    preferred = [c for c in candidates if c.split(".")[-1] == stem]
    others = [c for c in candidates if c not in preferred]
    return preferred + others


def detect_entry_models(omc: OMCSessionZMQ, model_file: Path) -> List[str]:
    """
    Robust detection:
      - collect all 'model' classes recursively through packages
      - order by preference (stem match)
    """
    candidates = collect_models_recursive(omc, scope="")
    return order_candidates(candidates, model_file)


def ensure_workdir_and_cd(omc: OMCSessionZMQ, workdir: Path) -> None:
    """
    Ensure that the working directory exists using Python (pathlib),
    then change OMC's working directory to it.

    Raises RuntimeError if OMC cd() fails.
    """
    workdir = Path(workdir).expanduser().resolve()

    # Create directory using Python standard library
    workdir.mkdir(parents=True, exist_ok=True)

    # Make OMC to use this directory
    ok = omc.sendExpression(f'cd("{workdir.as_posix()}")')
    err = omc.sendExpression("getErrorString()")

    if isinstance(err, str) and err.strip():
        raise RuntimeError(
            f"OMC cd() failed for workdir={workdir}\n{err.strip()}"
        )

    if ok is False:
        raise RuntimeError(
            f"OMC cd() returned False for workdir={workdir}"
        )


def normalize_simflags_override(simflags: str) -> str:
    """
    Normalize only the -override part inside simflags.

    Examples:
      "-override h0 = 10.0"            -> "-override=h0=10.0"
      "-override=h0 = 10.0, e = 0.8"   -> "-override=h0=10.0,e=0.8"
      "-foo -override h0 = 10 -bar"    -> "-foo -override=h0=10 -bar"

    Notes:
      - We ONLY touch '-override' (not -overrideFile, -outputPath, etc.)
      - We do not try to interpret values; we just remove whitespace around '=' and ','.
    """
    s = (simflags or "").strip()
    if not s:
        return s

    # Match '-override <value...>' or '-override=<value...>'
    # Value is captured until the next " <dash><letters>" flag (e.g. " -bar") or end of string.
    pattern = re.compile(r'(?P<prefix>(?:^|\s)-override)(?:\s*=\s*|\s+)(?P<val>.*?)(?=(\s-\w|$))')

    def repl(m: re.Match) -> str:
        prefix = m.group("prefix")
        val = m.group("val").strip()

        # Remove spaces around '=' and ',' inside override assignment list
        val = re.sub(r"\s*=\s*", "=", val)
        val = re.sub(r"\s*,\s*", ",", val)

        # Return in the safest form: -override=<...>
        return f"{prefix}={val}"

    return pattern.sub(repl, s)


def save_result_csv(
    result_path: Path,
    out_csv: Path,
    use_pandas: bool = False
) -> None:

    out_csv.parent.mkdir(parents=True, exist_ok=True)

    if use_pandas: # load and save using pandas, use if post-processing needed
        df = pd.read_csv(result_path)
        df.to_csv(out_csv, index=False)
    else:
        shutil.copy2(result_path, out_csv)


def simulate_model(
    omc: OMCSessionZMQ, 
    model_name: str,
    start_time: float,
    stop_time: float,
    step_size: float,
    method: str,
    simflags: str,
    out_csv: Path,
    workdir: Path
) -> pd.DataFrame:

    # checkModel (optional but useful)
    _ = omc_send(omc, f"checkModel({model_name})")
    err = omc_get_errors(omc)
    if err:
        print("OMC messages after checkModel:\n" + err)

    # change directory for omc model generation
    ensure_workdir_and_cd(omc, workdir)

    # ------------------------------------------------------------------
    # simulate() command
    #
    # Notes:
    # - simflags can be used to pass OpenModelica simulator options, e.g.:
    #     * -override param1=value1,param2=value2
    #     * -csvInput = path/to/input.csv
    #     * compiler / runtime flags supported by omc
    # - The simulation will generate C code, executable, and result files
    #   in the current OMC working directory (set via cd()).
    # ------------------------------------------------------------------
    sim_cmd = (
        f'simulate({model_name}, '
        f'startTime={start_time}, '
        f'stopTime={stop_time}, '
        f'stepSize={step_size}, '
        f'method="{method}", '
        f'outputFormat="csv", '
        f'simflags="{simflags}")'
    )
    res: Union[Dict[str, Any], Any] = omc_send(omc,sim_cmd)

    # Retrieve and print OMC diagnostic messages, if any
    err = omc_get_errors(omc).strip()
    if err:
        print("OMC messages after simulate:\n" + err)

    # Extract result file
    result_file: Optional[str] = None

    if isinstance(res, dict):
        result_file = res.get("resultFile")
        if not result_file:
            # Fallback keys used by some OMC versions
            for k in ("resultfile", "result", "csv"):
                if k in res:
                    result_file = res[k]
                    break
    elif isinstance(res, str):
        # In some cases, simulate() can return the result file path directly
        if os.path.exists(res):
            result_file = res

    if not result_file:
        raise RuntimeError(f"Simulation did not return a resultFile. res={res}")

    # Resolve result file path
    result_path = Path(result_file)
    if not result_path.is_absolute():
        result_path = (workdir / result_path).resolve()

    if not result_path.exists():
        raise RuntimeError(f"Simulation did not produce result CSV: {result_path}\nres={res}")

    # Save result CSV to the requested output location
    save_result_csv(result_path, out_csv, use_pandas=False)
    print(f"Saved: {out_csv}")

    # Load result CSV using pandas and return
    df = pd.read_csv(out_csv)
    return df


def main():
    ap = argparse.ArgumentParser(description="OpenModelica simulation using OMPython")
    ap.add_argument("model_file", type=str, help="Path to .mo file (e.g., examples/bouncingball/bouncingball.mo)")
    ap.add_argument("--model", type=str, default="", help="Fully-qualified model name. If omitted, auto-detect the first model.")
    ap.add_argument("--list", action="store_true", help="Only list detected model candidates, do not simulate")

    ap.add_argument("--start", type=float, default=0.0, help="startTime (default: 0.0)")
    ap.add_argument("--stop", type=float, default=1.0, help="stopTime (default: 1.0)")
    ap.add_argument("--step", type=float, default=0.01, help="stepSize (default: 0.01)")
    ap.add_argument("--method", type=str, default="dassl", help='solver method (default: "dassl")')
    ap.add_argument("--simflags", type=str, default="", help='extra simflags (e.g., -override h0=10.0)')
    ap.add_argument("--workdir", type=str, default="", help="Working directory (default: <cwd>)")
    ap.add_argument("--out", type=str, default="", help="Output CSV path (default: <cwd>/<model>_result.csv)")

    args = ap.parse_args()

    model_file = Path(args.model_file).expanduser().resolve()
    if not model_file.exists():
        raise SystemExit(f"Model file not found: {model_file}")

    workdir = Path(args.workdir).expanduser().resolve() if args.workdir else os.getcwd()

    omc = OMCSessionZMQ()

    load_check = omc_send(omc, f'loadFile("{model_file.as_posix()}")')
    if not load_check:
        raise SystemExit("loadFile failed:\n" + omc_get_errors(omc))

    model_name = args.model.strip()

    if not model_name:
        candidates = detect_entry_models(omc, model_file)

        if args.list:
            print("Detected model candidates (restriction=model):")
            for c in candidates:
                print("  -", c)
            return
        
        if not candidates:
            raise SystemExit(
                "No 'model' found in the file.\n"
                "Instruction: run with --list or provide a model list."
            )

        if len(candidates) > 1:
            msg = "Multiple candidate models found:\n"
            msg += "\n".join([f"  - {c}" for c in candidates[:50]])
            if len(candidates) > 50:
                msg += f"\n  ... ({len(candidates)-50} more)"
            msg += "\n\nIf you want specific model, provide --model <name> or run with --list. " \
                   "If not provided, auto-pick the first model."
            print(msg)
        else:
            msg = "Single model candidate found. "
            print(msg)

        model_name = candidates[0]
        print(f"[auto-pick] using model: {model_name}")

    else:
        if args.list:
            print("You supplied --model, so --list has nothing to do.")
            return

    # Normalize only -override inside simflags to avoid "invalid command line option: ="
    args.simflags = normalize_simflags_override(args.simflags)

    out_csv = Path(args.out).expanduser().resolve() if args.out else Path(os.path.join(os.getcwd(),f"{model_name.replace('.','_')}_result.csv"))

    df = simulate_model(
        omc = omc,
        model_name = model_name,
        start_time = args.start,
        stop_time = args.stop,
        step_size = args.step,
        method = args.method,
        simflags = args.simflags,
        out_csv = out_csv,
        workdir = workdir,
    )

    print("Results preview:", list(df.columns))
    print(df.head())


if __name__ == "__main__":
    main()
