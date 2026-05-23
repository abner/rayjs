#!/usr/bin/env bash
# Build rayjs.wasm via the containerised Emscripten toolchain.
#
# Usage:
#   platforms/web/build.sh              # configure + build (Release)
#   platforms/web/build.sh configure    # configure only
#   platforms/web/build.sh clean        # remove build-web/
#   platforms/web/build.sh shell        # drop into an interactive container shell
#
# The host machine only needs Docker (or a compatible runtime such as colima).
# All emcc / cmake / python toolchain bits live inside the image.

set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/../.." && pwd)"

IMAGE_TAG="${RAYJS_WEB_IMAGE:-rayjs-web:latest}"
BUILD_DIR="${RAYJS_WEB_BUILD_DIR:-build-web}"
BUILD_TYPE="${RAYJS_WEB_BUILD_TYPE:-Release}"

# Run docker as the host user so generated files in build-web/ are not
# owned by root on the host filesystem.
HOST_UID="$(id -u)"
HOST_GID="$(id -g)"

ensure_image() {
    # Rebuild only when the Dockerfile is newer than the last image tag.
    docker build -t "$IMAGE_TAG" "$SCRIPT_DIR"
}

run_in_container() {
    docker run --rm \
        -u "$HOST_UID:$HOST_GID" \
        -v "$REPO_ROOT":/src \
        -w /src \
        "$IMAGE_TAG" \
        bash -c "$1"
}

cmd_configure() {
    run_in_container "emcmake cmake -S . -B $BUILD_DIR -DCMAKE_BUILD_TYPE=$BUILD_TYPE"
}

cmd_build() {
    run_in_container "cmake --build $BUILD_DIR -j"
}

cmd_clean() {
    rm -rf "$REPO_ROOT/$BUILD_DIR"
    echo "Removed $REPO_ROOT/$BUILD_DIR"
}

cmd_shell() {
    docker run --rm -it \
        -u "$HOST_UID:$HOST_GID" \
        -v "$REPO_ROOT":/src \
        -w /src \
        "$IMAGE_TAG" \
        bash
}

case "${1:-all}" in
    all)
        ensure_image
        cmd_configure
        cmd_build
        ;;
    configure)
        ensure_image
        cmd_configure
        ;;
    build)
        ensure_image
        cmd_build
        ;;
    clean)
        cmd_clean
        ;;
    shell)
        ensure_image
        cmd_shell
        ;;
    *)
        echo "Unknown command: $1" >&2
        echo "Usage: $0 [all|configure|build|clean|shell]" >&2
        exit 2
        ;;
esac
