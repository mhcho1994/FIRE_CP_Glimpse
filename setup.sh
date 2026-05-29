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
  local install_openmodelica=0
  local openmodelica_only=0

  while [[ $# -gt 0 ]]; do
    case "$1" in
      --recreate)
        recreate=1
        ;;
      --install-openmodelica)
        install_openmodelica=1
        ;;
      --openmodelica-only)
        install_openmodelica=1
        openmodelica_only=1
        ;;
      *)
        echo "Unknown option: $1" >&2
        cp_glimpse_print_usage >&2
        return 2
        ;;
    esac
    shift
  done

  if [[ "$install_openmodelica" -eq 1 ]]; then
    cp_glimpse_install_openmodelica || return 1
  fi

  if [[ "$openmodelica_only" -eq 1 ]]; then
    return 0
  fi

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

cp_glimpse_print_usage() {
  echo "Usage: source setup.sh [--recreate] [--install-openmodelica] [--openmodelica-only]"
}

cp_glimpse_install_openmodelica() {
  if command -v omc >/dev/null 2>&1; then
    echo "OpenModelica is already installed: $(omc --version)"
    return 0
  fi

  if [[ ! -r /etc/os-release ]]; then
    echo "OpenModelica automatic installation requires a Debian/Ubuntu-like system with /etc/os-release." >&2
    return 1
  fi

  # shellcheck disable=SC1091
  source /etc/os-release

  case "${ID:-}" in
    ubuntu|debian)
      ;;
    *)
      case " ${ID_LIKE:-} " in
        *" debian "*)
          ;;
        *)
          echo "OpenModelica automatic installation currently supports Debian/Ubuntu-like systems only." >&2
          echo "Install OpenModelica manually from https://openmodelica.org/ for this platform." >&2
          return 1
          ;;
      esac
      ;;
  esac

  local apt_cmd=()
  if [[ "$(id -u)" -eq 0 ]]; then
    apt_cmd=(apt-get)
  else
    if ! command -v sudo >/dev/null 2>&1; then
      echo "sudo is required to install OpenModelica as a non-root user." >&2
      return 1
    fi
    apt_cmd=(sudo apt-get)
  fi

  local install_cmd=()
  if [[ "$(id -u)" -eq 0 ]]; then
    install_cmd=(install)
  else
    install_cmd=(sudo install)
  fi

  local tee_cmd=()
  if [[ "$(id -u)" -eq 0 ]]; then
    tee_cmd=(tee)
  else
    tee_cmd=(sudo tee)
  fi

  local arch
  arch="$(dpkg --print-architecture)" || return 1

  local codename="${VERSION_CODENAME:-${UBUNTU_CODENAME:-}}"
  if [[ -z "$codename" ]]; then
    codename="$(grep -E '^(UBUNTU|DEBIAN|VERSION)_CODENAME=' /etc/os-release | sort | cut -d= -f 2 | head -1)"
  fi
  if [[ -z "$codename" ]]; then
    echo "Could not determine Debian/Ubuntu codename for the OpenModelica repository." >&2
    return 1
  fi

  echo "Installing OpenModelica for ${codename} (${arch})..."
  "${apt_cmd[@]}" update || return 1
  "${apt_cmd[@]}" install -y --no-install-recommends ca-certificates curl gnupg || return 1

  local keyring_tmp_dir
  local keyring_tmp
  keyring_tmp_dir="$(mktemp -d)" || return 1
  keyring_tmp="$keyring_tmp_dir/openmodelica-keyring.gpg"
  curl -fsSL http://build.openmodelica.org/apt/openmodelica.asc \
    | gpg --dearmor -o "$keyring_tmp" \
    || {
      rm -rf "$keyring_tmp_dir"
      return 1
    }
  "${install_cmd[@]}" -D -m 0644 "$keyring_tmp" /usr/share/keyrings/openmodelica-keyring.gpg \
    || {
      rm -rf "$keyring_tmp_dir"
      return 1
    }
  rm -rf "$keyring_tmp_dir"

  printf 'deb [arch=%s signed-by=/usr/share/keyrings/openmodelica-keyring.gpg] https://build.openmodelica.org/apt %s stable\n' "$arch" "$codename" \
    | "${tee_cmd[@]}" /etc/apt/sources.list.d/openmodelica.list >/dev/null \
    || return 1

  "${apt_cmd[@]}" update || return 1
  "${apt_cmd[@]}" install -y --no-install-recommends openmodelica || return 1
  echo "OpenModelica installation complete: $(omc --version)"
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
