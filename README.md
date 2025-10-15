# FIRE_CP_Glimpse  
### Cyber-Physical Co-Simulation of Drone and Rover via FMUs

This repository provides **Python-based orchestration and co-simulation scripts** for **cyber-physical models of drones and rovers**.  
Each model is exported from **Modelica** as an **FMU (Functional Mock-up Unit)** and executed within a **Python simulation loop** that integrates control, sensing, communication, and fault/attack dynamics.  
The repository is part of the **CyPhER** framework for cyber-physical vulnerability analysis and **CP-Glimpse**, the low-fidelity simulation tool for proactive risk assessment.

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

---

## Setup & Dependencies
Typical dependencies:
fmpy or pyfmi – FMU simulation
numpy, scipy – numerical operations
pandas – structured logging
matplotlib / seaborn – plotting
(optional) casadi – optimization or reachability