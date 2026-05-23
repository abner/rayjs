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
    cmd_dist
}

# Copy the HTML shell, loader, and the example_games/ tree into
# build-web/dist/ alongside the cmake-emitted rayjs.js + rayjs.wasm.
# Each example_games/<name>/ subtree mirrors the MEMFS layout that game
# expects (game/main.js, examples/foo.png, ...), and gets served from
# dist/games/<name>/. loader.js reads ?game=<name> to pick which subtree
# to fetch from at runtime; the fetched files are written into MEMFS at
# the same relative path (without the games/<name>/ prefix) so existing
# fopen()/LoadTexture() calls Just Work.
cmd_dist() {
    local DIST="$REPO_ROOT/$BUILD_DIR/dist"
    cp "$SCRIPT_DIR/shell.html" "$DIST/index.html"
    cp "$SCRIPT_DIR/loader.js"  "$DIST/loader.js"
    # Wipe stale payload — both the new layout and any leftovers from
    # the single-game layout that preceded multi-game support.
    rm -rf "$DIST/games" "$DIST/game" "$DIST/examples"
    mkdir -p "$DIST/games"
    cp -R "$SCRIPT_DIR/example_games/." "$DIST/games/"
    echo "Assembled $DIST"
}

cmd_clean() {
    rm -rf "$REPO_ROOT/$BUILD_DIR"
    echo "Removed $REPO_ROOT/$BUILD_DIR"
}

# Serve build-web/dist/ on http://localhost:8080 via npx http-server.
# We don't need SharedArrayBuffer (single-threaded wasm), so no COOP/COEP
# headers required.
cmd_serve() {
    local DIST="$REPO_ROOT/$BUILD_DIR/dist"
    if [[ ! -f "$DIST/index.html" ]]; then
        echo "No dist/index.html — run '$0 all' first." >&2
        exit 1
    fi
    echo "Serving $DIST on http://localhost:8080  (Ctrl-C to stop)"
    # -c-1 disables http-server's default 1-hour cache so wasm/JS reloads
    # pick up rebuilds immediately.
    npx http-server -p 8080 -c-1 "$DIST"
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
    dist)
        cmd_dist
        ;;
    serve)
        cmd_serve
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
        echo "Usage: $0 [all|configure|build|dist|serve|clean|shell]" >&2
        exit 2
        ;;
esac
