FROM ubuntu:20.04

ARG TARGETARCH

RUN apt-get update && apt-get install -y \
    curl \
    gnupg \
    unzip \
    bash \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

RUN curl -Lo /usr/local/bin/bazel https://github.com/bazelbuild/bazelisk/releases/download/v1.17.0/bazelisk-linux-${TARGETARCH} && \
    chmod +x /usr/local/bin/bazel

RUN bazel --version

WORKDIR /workspace
ENTRYPOINT [ "/bin/bash" ]
