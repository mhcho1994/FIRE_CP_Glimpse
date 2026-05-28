#!/usr/bin/env bash

cp_glimpse_setup() {
  local root_dir
  root_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)" || return 1
  cd "$root_dir" || return 1

  # CP Glimpse examples currently use PyFMI, so the standard setup path is a
  # conda-forge environment managed by Miniforge/conda.
  local conda_env="${CONDA_ENV:-cp-glimpse-py312}"
  local conda_dir="${CONDA_DIR:-$HOME/.local/share/miniforge3}"
  local recreate=0

  while [[ $# -gt 0 ]]; do
    case "$1" in
      --recreate)
        recreate=1
        ;;
      *)
        echo "Unknown option: $1" >&2
        echo "Usage: source setup.sh [--recreate]" >&2
        return 2
        ;;
    esac
    shift
  done

  cp_glimpse_ensure_conda "$conda_dir" || return 1

  # Enable `conda activate` inside this sourced script.
  eval "$(conda shell.bash hook)" || return 1

  conda config --set channel_priority strict || return 1

  if [[ "$recreate" -eq 1 ]]; then
    conda env remove -y -n "$conda_env" >/dev/null 2>&1 || true
  fi

  if ! conda env list | awk '{print $1}' | grep -qx "$conda_env"; then
    cp_glimpse_create_conda_env "$conda_env" || return 1
  else
    cp_glimpse_update_conda_env "$conda_env" || return 1
  fi

  conda activate "$conda_env" || return 1

  # The third-party dependencies are installed by conda-forge above. Install
  # only this repository in editable mode so local source changes are visible.
  python -m pip install --no-deps -e . || return 1

  cp_glimpse_import_check || return 1

  echo "CP Glimpse conda environment is ready."
  echo "Activate it later with: conda activate $conda_env"
}

cp_glimpse_ensure_conda() {
  local conda_dir="$1"

  if command -v conda >/dev/null 2>&1; then
    return 0
  fi

  if [[ -x "$conda_dir/bin/conda" ]]; then
    export PATH="$conda_dir/bin:$PATH"
    return 0
  fi

  cp_glimpse_install_miniforge "$conda_dir" || return 1
  export PATH="$conda_dir/bin:$PATH"
}

cp_glimpse_install_miniforge() {
  local conda_dir="$1"
  local installer="/tmp/miniforge.sh"
  local url="https://github.com/conda-forge/miniforge/releases/latest/download/Miniforge3-Linux-x86_64.sh"

  if ! command -v curl >/dev/null 2>&1; then
    echo "curl is required to install Miniforge automatically." >&2
    return 1
  fi

  mkdir -p "$(dirname "$conda_dir")" || return 1
  curl -fsSL -o "$installer" "$url" || return 1
  bash "$installer" -b -p "$conda_dir" || return 1
  rm -f "$installer"
}

cp_glimpse_create_conda_env() {
  local conda_env="$1"

  conda create -y -n "$conda_env" -c conda-forge \
    python=3.12 \
    pip \
    setuptools \
    wheel \
    numpy \
    pandas \
    pyyaml \
    matplotlib \
    ompython \
    fmpy \
    pyfmi \
    ipykernel \
    jupyterlab \
    notebook \
    scipy \
    casadi
}

cp_glimpse_update_conda_env() {
  local conda_env="$1"

  conda install -y -n "$conda_env" -c conda-forge \
    python=3.12 \
    pip \
    setuptools \
    wheel \
    numpy \
    pandas \
    pyyaml \
    matplotlib \
    ompython \
    fmpy \
    pyfmi \
    ipykernel \
    jupyterlab \
    notebook \
    scipy \
    casadi
}

cp_glimpse_import_check() {
  python - <<'PY'
import cp_glimpse_py
import pyfmi
PY
}

cp_glimpse_setup "$@"
status=$?

if [[ "${BASH_SOURCE[0]}" == "$0" ]]; then
  exit "$status"
fi

return "$status"
