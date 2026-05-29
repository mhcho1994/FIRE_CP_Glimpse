FROM condaforge/miniforge3:latest AS base

ARG VSCODE_SERVER_COMMIT=4949701c880d4bdb949e3c0e6b400288da7f474b
ARG TARGETARCH

ENV PYTHONUNBUFFERED=1
ENV CONDA_ENV=cp-glimpse-py312
ENV CONDA_DIR=/opt/conda
ENV HOME=/home/cpglimpse
ENV PATH="/opt/conda/envs/cp-glimpse-py312/bin:/opt/conda/bin:${PATH}"

WORKDIR /cp-glimpse

RUN apt-get update \
    && apt-get install -y --no-install-recommends \
        ca-certificates \
        curl \
        git \
        gnupg \
        tar \
    && rm -rf /var/lib/apt/lists/*

RUN groupadd --gid 1000 cpglimpse \
    && useradd --uid 1000 --gid 1000 --create-home --shell /bin/bash cpglimpse

RUN case "${TARGETARCH:-amd64}" in \
        amd64) VSCODE_SERVER_PLATFORM="server-linux-x64" ;; \
        arm64) VSCODE_SERVER_PLATFORM="server-linux-arm64" ;; \
        *) echo "Unsupported TARGETARCH for VS Code Server: ${TARGETARCH}" >&2; exit 1 ;; \
    esac \
    && mkdir -p "/root/.vscode-server/bin/${VSCODE_SERVER_COMMIT}" \
    && curl -fsSL "https://update.code.visualstudio.com/commit:${VSCODE_SERVER_COMMIT}/${VSCODE_SERVER_PLATFORM}/stable" \
        | tar -xz --strip-components=1 -C "/root/.vscode-server/bin/${VSCODE_SERVER_COMMIT}"

FROM base AS runtime

ARG INSTALL_OPENMODELICA=false

COPY pyproject.toml README.md setup.sh ./
COPY src ./src

RUN chmod +x setup.sh \
    && if [ "$INSTALL_OPENMODELICA" = "true" ]; then \
        bash setup.sh --recreate --install-openmodelica; \
    else \
        bash setup.sh --recreate; \
    fi \
    && rm -rf /var/lib/apt/lists/* \
    && conda clean -afy

RUN chown -R cpglimpse:cpglimpse /cp-glimpse /home/cpglimpse

FROM runtime AS dev

USER cpglimpse

EXPOSE 8888

CMD ["jupyter", "lab", "--ip=0.0.0.0", "--port=8888", "--no-browser"]

FROM runtime AS release

COPY . .

RUN chown -R cpglimpse:cpglimpse /cp-glimpse /home/cpglimpse

USER cpglimpse

EXPOSE 8888

CMD ["jupyter", "lab", "--ip=0.0.0.0", "--port=8888", "--no-browser"]
