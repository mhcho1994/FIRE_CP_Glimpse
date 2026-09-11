FROM ubuntu:24.04@sha256:224a1869083a311ef3f13648a154ba79832fbef6364d31493642ca03082da254 AS base

ARG INSTALL_VSCODE_SERVER=true
ARG VSCODE_SERVER_COMMIT=4949701c880d4bdb949e3c0e6b400288da7f474b
ARG TARGETARCH

ENV PYTHONUNBUFFERED=1
ENV PYTHONNOUSERSITE=1
ENV CONDA_ENV=cp-glimpse-py312
ENV CONDA_DIR=/opt/conda
ENV HOME=/home/cpglimpse
ENV PATH="/opt/conda/envs/cp-glimpse-py312/bin:/opt/conda/bin:${PATH}"

WORKDIR /home/cpglimpse/cp-glimpse

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        ca-certificates \
        bzip2 \
        curl \
        git \
        gnupg \
        tar \
    && rm -rf /var/lib/apt/lists/*

RUN id -u cpglimpse >/dev/null 2>&1 || useradd --create-home --shell /bin/bash cpglimpse

RUN set -eux; \
    if [ "${INSTALL_VSCODE_SERVER}" = "true" ]; then \
        case "${TARGETARCH:-amd64}" in \
            amd64) VSCODE_SERVER_PLATFORM="server-linux-x64" ;; \
            arm64) VSCODE_SERVER_PLATFORM="server-linux-arm64" ;; \
            *) \
                echo "Unsupported TARGETARCH: ${TARGETARCH}" >&2; \
                exit 1 ;; \
        esac; \
        \
        VSCODE_SERVER_ARCHIVE="/tmp/vscode-server.tar.gz"; \
        VSCODE_SERVER_URL="https://update.code.visualstudio.com/commit:${VSCODE_SERVER_COMMIT}/${VSCODE_SERVER_PLATFORM}/stable"; \
        \
        curl -fL \
            --retry 5 \
            --retry-delay 5 \
            --retry-all-errors \
            --connect-timeout 30 \
            --max-time 600 \
            -o "${VSCODE_SERVER_ARCHIVE}" \
            "${VSCODE_SERVER_URL}"; \
        \
        mkdir -p "/root/.vscode-server/bin/${VSCODE_SERVER_COMMIT}"; \
        tar -xzf "${VSCODE_SERVER_ARCHIVE}" \
            --strip-components=1 \
            -C "/root/.vscode-server/bin/${VSCODE_SERVER_COMMIT}"; \
        \
        rm -f "${VSCODE_SERVER_ARCHIVE}"; \
    else \
        echo "Skipping VS Code Server installation"; \
    fi

FROM base AS runtime

ARG INSTALL_OPENMODELICA=true

COPY pyproject.toml README.md setup.sh environment.yml ./
COPY src ./src

RUN chmod +x setup.sh \
    && if [ "$INSTALL_OPENMODELICA" = "true" ]; then \
        bash setup.sh --recreate --install-openmodelica; \
    else \
        bash setup.sh --recreate; \
    fi \
    && cp-glimpse --help >/dev/null \
    && cp-glimpse-viewer --help >/dev/null \
    && rm -rf /var/lib/apt/lists/* \
    && conda clean -afy

RUN chown -R cpglimpse:cpglimpse /home/cpglimpse

FROM runtime AS dev

USER cpglimpse

EXPOSE 8000 8888

CMD ["bash"]

FROM runtime AS release

ARG INSTALL_OPENMODELICA=true

COPY . .

RUN chown -R cpglimpse:cpglimpse /home/cpglimpse

USER cpglimpse

RUN if [ "$INSTALL_OPENMODELICA" = "true" ]; then \
        command -v omc \
        && omc --version \
        && python -c "from OMPython import OMCSessionZMQ; omc = OMCSessionZMQ(); assert omc.sendExpression('loadModel(Modelica)'); print('Modelica Standard Library', omc.sendExpression('getVersion(Modelica)'))" \
        && cp-glimpse --help >/dev/null \
        && cp-glimpse-viewer --help >/dev/null \
        && pytest -q tests/test_integrator_smoke.py; \
    fi

EXPOSE 8000 8888

CMD ["bash"]
