# Containerised Emscripten toolchain for rayjs web builds.
#
# We pin to an explicit emsdk image tag so every machine produces the same
# wasm artifact. To bump emscripten, change the tag here, rebuild via
# `platforms/web/build.sh`, and commit the new tag.
#
# Image catalog: https://hub.docker.com/r/emscripten/emsdk/tags
#
# See docs/branch_feat_web_wasm.md for the full plan.

FROM emscripten/emsdk:3.1.74

# The image ships with cmake 3.22.1, but raylib 6 requires >= 3.25.
# pip-installed cmake lands in /usr/local/bin which precedes /usr/bin
# on PATH, so the newer version wins without uninstalling the old one.
RUN pip install --no-cache-dir cmake==3.30.5 \
    && cmake --version

# The repo is mounted at /src by build.sh; CMake out-of-source build dir
# (build-web/) ends up on the host because /src is a bind mount.
WORKDIR /src

# Default to an interactive shell so `docker run -it ... bash` works for
# debugging. build.sh overrides this with the actual build command.
CMD ["bash"]
