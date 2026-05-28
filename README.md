# FIRE_CP_Glimpse  

## ⚠️ Important

This repository is currently under active development to generalize the physical simulation backends toward a platform-agnostic architecture (e.g., drone, rover, and other CPS platforms).

This transition aims to:

- Reduce the number of redundant vehicle-specific models (as suggested by IV&V)
- Support multiple simulation backends (e.g., direct Modelica execution, FMU-based simulation, CasADi-generated models)
- Enable seamless integration with CP-Explore

To reproduce example simulation results, run:
`examples/<platform>/main.py`
Replace `<platform>` with the desired vehicle type (e.g., `GSdrone`, `NGCrover`).

### Cyber-Physical Co-Simulation of Drone and Rover via FMUs
This repository provides **Python-based orchestration and co-simulation scripts** for **cyber-physical models of drones and rovers**. Each model is exported from **Modelica** as an **FMU (Functional Mock-up Unit)** and executed within a **Python simulation loop** that integrates control, sensing, communication, and fault/attack dynamics. The repository is part of the **CyPhER** framework for cyber-physical vulnerability analysis and **CP-Glimpse**, the low-fidelity simulation tool for proactive risk assessment.

---

## Overview
- The **Modelica models** of drone and rover (see [FIRE_CP_Modelica](https://github.com/mhcho1994/FIRE_CP_Modelica)) define the coupled **cyber–physical system models**:  
  - Physical: chassis, tire, rotor, aerodynamic, actuator, and sensor models  
  - Cyber: control laws, state estimation, and network/communication layers  
- These are exported as **FMUs** and loaded into Python through **PyFMI** or **FMPy**.  
- The Python scripts implement a **synchronous step-based co-simulation**, allowing:
  - Integration of multiple FMUs (e.g., dynamics + controller)  
  - Attack and fault injections  
  - Data logging and visualization  
  - Multi-fidelity model comparison (Lo-Fi vs Hi-Fi)  

---

## Repository Structure
TBF

---

## Setup & Dependencies

### 1. Install OpenModelica
OpenModelica can be installed from the **Download** tab on the official site:  
[https://openmodelica.org/](https://openmodelica.org/)

- **Windows / macOS:** Use the installer from the website (recommended).
- **Linux (Ubuntu/Debian):** Use the official repo:

```bash
sudo apt-get update
sudo apt-get install ca-certificates curl gnupg

# Add OpenModelica key & repo
sudo curl -fsSL http://build.openmodelica.org/apt/openmodelica.asc | \
  sudo gpg --dearmor -o /usr/share/keyrings/openmodelica-keyring.gpg

echo "deb [arch=amd64 signed-by=/usr/share/keyrings/openmodelica-keyring.gpg] \
  https://build.openmodelica.org/apt \
  $(cat /etc/os-release | grep "\(UBUNTU\|DEBIAN\|VERSION\)_CODENAME" | sort | cut -d= -f 2 | head -1) \
  stable" | sudo tee /etc/apt/sources.list.d/openmodelica.list

sudo apt update
sudo apt install openmodelica
```

Quick check:
```bash
omc --version
```
> You only need OpenModelica if you plan to **export/re-export FMUs** from your Modelica models. If you already have the `.fmu` files, you can skip this.

### 2. Install Python packages
Create a local Miniforge/conda environment with Python 3.12, PyFMI, Jupyter,
and the notebook dependencies:

```bash
source setup.sh
```

If conda is not already installed, the setup script installs Miniforge under
`$HOME/.local/share/miniforge3` and then creates a `cp-glimpse-py312`
environment. All third-party dependencies, including PyFMI, are installed from
conda-forge; this repository is installed editable with pip.

If an existing environment was left in a broken state, recreate it:

```bash
source setup.sh --recreate
```

Sanity check (optional):
```bash
cp-glimpse --help
```

### 3. Run the simulation
Navigate to the repository root and run a scenario:

```bash
cp-glimpse --scenario scenarios/bouncingball_single_run.yaml
```
Recommend to use a code editor like VS Code.

## Scenario Format

Scenario files can be YAML (`.yaml`, `.yml`) or TOML (`.toml`). YAML remains
the most convenient format while scenarios are still list-heavy and nested.
TOML is useful for stricter, less ambiguous configuration and works well for
stable scalar settings such as `[sim]`, `[outputs]`, and `[parameters]`.

Recommendation: support both formats for now. Keep existing YAML scenarios
working, add TOML examples for new or stable scenarios, and avoid a full
migration until the scenario schema settles.

## Docker

The Docker image uses the official conda-forge Miniforge base image and creates
the same `cp-glimpse-py312` conda environment used by local setup:

```bash
docker build -f docker/Dockerfile -t cp-glimpse .
docker run --rm -p 8888:8888 -v "$PWD:/app" cp-glimpse
```

Optional build arguments:

```bash
docker build -f docker/Dockerfile -t cp-glimpse \
  --build-arg INSTALL_OPENMODELICA=true \
  .
```

The `examples/GSdrone/main.ipynb` and `examples/NGCrover/main.ipynb` notebooks
use the legacy `examples/*/fmu.py` modules, which import PyFMI. The setup and
Docker paths install PyFMI by default. The Docker command above bind-mounts the
current repository into `/app`, so changes to notebooks and example files are
visible inside the container immediately.
