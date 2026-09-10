# FIRE_CP_Glimpse

FIRE_CP_Glimpse is a Python-based co-simulation framework for multi-fidelity
cyber-physical system (CPS) simulations, including drones, rovers, and other
platforms. The current implementation focuses on an FMU-based workflow:
Modelica models are exported as Functional Mock-up Units (FMUs) and executed
from a Python simulation loop.

## ⚠️ Important

This repository is under active development. Future work is expected to extend
the backend architecture toward direct Modelica execution, Rumoca backends, model reformatting, and tighter integration with Rumoca.

## Repository Structure

```text
.
├── docker/              # Docker image definition
├── docs/                # Dependency and delivery documentation
├── environment.yml      # Validated conda environment definition
├── environment-linux-64.lock # Exact validated Linux x86_64 conda packages
├── examples/            # Latest notebook-based simulation and analysis examples
├── legacy/              # Legacy code for reproducing previous GSdrone and NGCrover results
├── models/              # Modelica source files (.mo)
├── scenarios/           # Scenario configuration files (.yaml and .toml)
├── src/cp_glimpse_py/   # CP Glimpse Python package
├── tests/               # Automated unit and end-to-end smoke tests
└── setup.sh             # Local conda environment setup script
```

## Environment Setup

### Local Install

From the repository root, create the conda environment and install this package
in editable mode:

```bash
source setup.sh
```

Use `--recreate` for a clean environment rebuild:

```bash
source setup.sh --recreate
```

The generated conda environment is named `cp-glimpse-py312`.

```bash
conda activate cp-glimpse-py312
conda deactivate
```

Optional sanity check:

```bash
cp-glimpse --help
```

`environment.yml` is the supported environment source of truth. It includes
the optional PyFMI backend and the explicit pytest dependency used for STR
validation. A fully resolved `environment-linux-64.lock` is also supplied for
exact Linux x86_64 recreation. Dependency roles, tested versions, and the
lock-file workflow are documented in [docs/DEPENDENCIES.md](docs/DEPENDENCIES.md).

### OpenModelica

OpenModelica is required when you need to export or re-export FMUs from
Modelica source files. If you already have the required `.fmu` files, you can
skip the OpenModelica installation.

On Ubuntu/Debian systems, `setup.sh` can install OpenModelica for you:

```bash
source setup.sh --openmodelica-only
```

This also verifies or installs the Modelica Standard Library used by FMU
translation.

The host validation used OpenModelica `1.25.0~2-ge56b89b` and Modelica Standard
Library `4.0.0`. Clean installation pins the compiler-only Ubuntu package
`omc=1.25.0-1` from the official OpenModelica 1.25.0 HTTPS release repository;
the matching `omlibrary=1.25.0-1` package supplies the offline Modelica library
cache. See the dependency document for platform and signing-key details.

To install OpenModelica and set up the Python environment in one step:

```bash
source setup.sh --install-openmodelica
```

To install OpenModelica and recreate the Python environment in one step:

```bash
source setup.sh --recreate --install-openmodelica
```

Verify OpenModelica:

```bash
omc --version
```

For non-Debian platforms, install OpenModelica manually from the official site:

https://openmodelica.org/

## Docker

The Docker image uses a digest-pinned Ubuntu 24.04 (Noble) base, installs the
checksum-pinned Miniforge 24.11.3-0 release, and creates the same
`cp-glimpse-py312` environment used by the local setup script. Ubuntu 20.04 is
not used because the current OpenModelica focal package index is empty.

Build the default release image. OpenModelica is installed by default, the
repository is copied into the image, and the Modelica integrator STR smoke test
is run during the build:

```bash
docker build -f docker/Dockerfile --target release -t cp-glimpse:release .
```

The release build fails if `omc`, the Modelica Standard Library, the console
entry point, or `tests/test_integrator_smoke.py` fails. Docker uses the same
`setup.sh --install-openmodelica` installation path as local setup.

Only when an image will execute prebuilt `.fmu` files and never materialize a
Modelica source may OpenModelica be explicitly omitted:

```bash
docker build -f docker/Dockerfile --target release -t cp-glimpse:no-openmodelica \
  --build-arg INSTALL_OPENMODELICA=false \
  .
```

That opt-out build skips the Modelica-dependent STR check and cannot generate
an FMU from a `.mo` file.

Build a smaller development image. This target only copies the files needed to
create the environment, and expects the repository to be bind-mounted at run
time:

```bash
docker build -f docker/Dockerfile --target dev -t cp-glimpse-dev .
```

Run the container with an interactive shell:

```bash
docker run --rm -it -p 8888:8888 cp-glimpse:release
```

The release image copies the repository into `/home/cpglimpse/cp-glimpse`, so it
can be saved and distributed as a standalone Docker image. The container runs as
a non-root `cpglimpse` user so the OpenModelica server can start safely inside
Docker.

For development, bind-mount your local repository into
`/home/cpglimpse/cp-glimpse` so local edits are visible immediately:

```bash
docker run --rm -it \
  --mount type=bind,src="$PWD",dst=/home/cpglimpse/cp-glimpse \
  cp-glimpse-dev
```

### VS Code Dev Containers

The repository includes a `.devcontainer/devcontainer.json` configuration for
VS Code. Open the repository in VS Code and run:

```text
Dev Containers: Rebuild and Reopen in Container
```

VS Code will build the `dev` target from `docker/Dockerfile`, attach to the
container, and open the workspace at `/home/cpglimpse/cp-glimpse`.

### JupyterLab in Docker

The Docker image does not start JupyterLab automatically. If you want to use
JupyterLab, start it manually from the container shell:

```bash
jupyter lab --ip=0.0.0.0 --port=8888 --no-browser
```

When running the container directly, publish port `8888`:

```bash
docker run --rm -it -p 8888:8888 cp-glimpse:release
```

To distribute the built image as a tar archive:

```bash
docker save cp-glimpse:release -o cp-glimpse.tar
docker load -i cp-glimpse.tar
```

## Simulation Inputs

### Models

Modelica models are stored as `.mo` files under `models/`.

Examples:

```text
models/MFQuadrotor.mo
models/MFRover.mo
models/hybrid_benchmarks/BouncingBall.mo
```

The primary supported workflow is to generate an FMU from a Modelica model and
execute that FMU through the Python simulation backend.

### Scenarios

Scenarios are configured as YAML or TOML files under `scenarios/`.

Examples:

```text
scenarios/bouncingball_single_run.yaml
scenarios/quadrotor_nominal.yaml
scenarios/quadrotor_acoustic_attack.yaml
scenarios/rover_nominal.yaml
```

Both formats use the same normalized scenario structure.

### Backend

The currently supported backend path is FMU-based. A scenario points to a
Modelica model, CP Glimpse generates or reuses an FMU, and the resulting FMU is
simulated through a PyFMI or FMPy runner.

OpenModelica is required when generating `.fmu` artifacts from `.mo` files. If
the FMU artifact already exists, only the FMU execution step is required.

## Run Simulations

### CLI

Run a scenario from the repository root:

```bash
cp-glimpse --scenario scenarios/bouncingball_single_run.yaml
```

Use `--save-dir` to choose where `outputs.csv` is written:

```bash
cp-glimpse --scenario scenarios/quadrotor_nominal.yaml --save-dir results/nominal
```

### STR Smoke Test

Run the canonical Modelica integrator end-to-end smoke test:

```bash
python -m pytest -q tests/test_integrator_smoke.py
```

The analytical expected result is `u = 1` for 5 seconds, producing an
integrator output of `y(5) = 5`. The test launches the actual installed
`cp-glimpse` console command and verifies its JSON/CSV artifacts; see
[tests/README.md](tests/README.md) for the complete acceptance contract.

### Latest Notebook Examples

Use the notebooks under `examples/` for the latest simulation and analysis
workflow.

```text
examples/quadrotor_attack_analysis.ipynb
```

Open the notebook in VS Code or JupyterLab to run scenarios, load generated
results, and plot outputs. When using Docker with JupyterLab, start JupyterLab
manually from the container shell and open the printed URL.

### Legacy Reproduction

Use the `legacy/` folder when you need to reproduce previous GSdrone or
NGCrover results.

```text
legacy/GSdrone/main.ipynb
legacy/NGCrover/main.ipynb
```

Legacy code may differ from the current generalized execution path under
`src/cp_glimpse_py`. For new work, prefer the latest notebooks under
`examples/` and the scenario-driven CLI workflow under `scenarios/`.

## Typical Workflow

1. Prepare Modelica `.mo` files under `models/`.
2. Create YAML or TOML scenarios under `scenarios/`.
3. Set up the runtime with `source setup.sh` or Docker.
4. Run simulations with `cp-glimpse --scenario <scenario.yaml-or-toml>` or the
   notebooks under `examples/`.
5. Inspect generated CSV outputs and notebook plots.
