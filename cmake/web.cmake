# cmake/web.cmake — Emscripten / WebAssembly target wiring.
#
# Included from the root CMakeLists.txt ONLY when `EMSCRIPTEN` is true (i.e.
# when CMake is invoked through `emcmake cmake ...`). Has no effect on the
# native build — its existence is invisible to clang/gcc toolchains.
#
# See docs/branch_feat_web_wasm.md for the full plan.

message(STATUS "=== Configuring rayjs web (wasm) target ===")

# Phase 0: stub only. Real wiring lands in Phase 1+ as documented in
# docs/branch_feat_web_wasm.md.
