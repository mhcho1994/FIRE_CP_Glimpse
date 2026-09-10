# STR smoke test

Test: Integrator constant-input smoke test

Model:

```text
dy/dt = u
y(0) = 0
```

The scenario supplies the constant external input `u = 1.0` through
`[inputs.constant]`. The simulation interval is `0 <= t <= 5` seconds, so the
analytical expected result is:

```text
y(t) = t
y(5) = 5.0
```

The acceptance criterion is `|y_sim(5) - 5.0| <= 1e-5`. The test also checks
that the CLI writes `result.json`, `summary.json`, `scenario_resolved.json`, and
`outputs.csv`, and verifies the input and final output values in both JSON and
CSV output. Time-series inputs are stored under `result.inputs`; multi-FMU
input names use the `component.variable` form.

From the repository root, run:

```bash
python -m pytest -q tests/test_integrator_smoke.py
```

A successful run ends with `3 passed`: the canonical constant-input CLI test,
a single-FMU time-history input test, and a stop-time grid regression test.
The canonical subprocess resolves and launches the installed `cp-glimpse`
console entry point, so an editable/source import alone is not sufficient.

For the clean Docker acceptance path, run:

```bash
docker build \
  --target release \
  -t cp-glimpse:release \
  -f docker/Dockerfile \
  .
```

OpenModelica installation is enabled by default. The release stage verifies
`omc`, loads the Modelica Standard Library, and runs this test from Modelica
source with no pre-existing `build/` or `results/` cache in the Docker context.

## Input providers

Single-FMU execution applies scenario inputs before every communication step
through the same `set_input_value()`/`set_value()` runner interface used by
multi-FMU execution. The existing constant syntax remains supported:

```toml
[inputs.constant]
u = 1.0
```

The equivalent typed form is:

```toml
[inputs]
type = "constant"

[inputs.values]
u = 1.0
```

A time history can use linear interpolation:

```toml
[inputs]
type = "time_history"
interpolation = "linear"
time = [0.0, 2.0, 5.0]

[inputs.values]
u = [0.0, 1.0, 1.0]
```

Use `interpolation = "zero-order-hold"` for zero-order hold. Values before the first
sample and after the last sample are held at the respective endpoint values.

Run the provider tests with:

```bash
python -m pytest -q tests/test_input_provider.py
```
