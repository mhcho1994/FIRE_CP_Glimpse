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
├── examples/            # Latest notebook-based simulation and analysis examples
├── legacy/              # Legacy code for reproducing previous GSdrone and NGCrover results
├── models/              # Modelica source files (.mo)
├── scenarios/           # Scenario configuration files (.yaml)
├── src/cp_glimpse_py/   # CP Glimpse Python package
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

### OpenModelica

OpenModelica is required when you need to export or re-export FMUs from
Modelica source files. If you already have the required `.fmu` files, you can
skip the OpenModelica installation.

On Ubuntu/Debian systems, `setup.sh` can install OpenModelica for you:

```bash
source setup.sh --openmodelica-only
```

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

The Docker image uses the conda-forge Miniforge base image and creates the same
`cp-glimpse-py312` environment used by the local setup script.

Build the default release image. This target copies the repository into the
image, so it can run without a bind mount:

```bash
docker build -f docker/Dockerfile -t cp-glimpse .
```

Build the release image with OpenModelica included:

```bash
docker build -f docker/Dockerfile --target release -t cp-glimpse \
  --build-arg INSTALL_OPENMODELICA=true \
  .
```

The Docker build uses the same `setup.sh --install-openmodelica` path when
`INSTALL_OPENMODELICA=true`.

Build a smaller development image. This target only copies the files needed to
create the environment, and expects the repository to be bind-mounted at run
time:

```bash
docker build -f docker/Dockerfile --target dev -t cp-glimpse-dev .
```

Run the container:

```bash
docker run --rm -p 8888:8888 cp-glimpse
```

The container starts JupyterLab on port `8888`. The release image copies the
repository into `/cp-glimpse`, so it can be saved and distributed as a standalone
Docker image.

For development, bind-mount your local repository into `/cp-glimpse` so local
edits are visible immediately:

```bash
docker run --rm -p 8888:8888 \
  --mount type=bind,src="$PWD",dst=/cp-glimpse \
  cp-glimpse
```

To distribute the built image as a tar archive:

```bash
docker save cp-glimpse -o cp-glimpse.tar
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

Scenarios are configured as YAML files under `scenarios/`.

Examples:

```text
scenarios/bouncingball_single_run.yaml
scenarios/quadrotor_nominal.yaml
scenarios/quadrotor_acoustic_attack.yaml
scenarios/rover_nominal.yaml
```

TOML scenario support is planned for a future release. The currently documented
scenario format is YAML.

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

### Latest Notebook Examples

Use the notebooks under `examples/` for the latest simulation and analysis
workflow.

```text
examples/quadrotor_attack_analysis.ipynb
```

Open the notebook in JupyterLab to run scenarios, load generated results, and
plot outputs. When using Docker, open the JupyterLab URL printed by the
container and run the notebooks under `examples/`.

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
2. Create YAML scenarios under `scenarios/`.
3. Set up the runtime with `source setup.sh` or Docker.
4. Run simulations with `cp-glimpse --scenario <scenario.yaml>` or the
   notebooks under `examples/`.
5. Inspect generated CSV outputs and notebook plots.
