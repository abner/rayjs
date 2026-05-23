# Web (Emscripten / WebAssembly) target wiring.
#
# Included from the root CMakeLists.txt only when EMSCRIPTEN is true.
# Exposes two functions invoked at two points in the root CMakeLists.txt:
#
#   rayjs_web_pre()  — called after project(), BEFORE any add_subdirectory().
#                      Sets cache variables that downstream subdirs (raylib,
#                      Box2D) pick up to configure themselves for the web
#                      target.
#
#   rayjs_web_post() — called at the END, after the rayjs target is fully
#                      wired. Applies linker flags (Asyncify, WebGL 2, FS
#                      exports) and adjusts the output to emit .html + .js
#                      + .wasm.
#
# Native builds never see this file — the `if(EMSCRIPTEN)` guard around
# every include() / call() in the root CMakeLists.txt ensures clang/gcc
# toolchains stay completely untouched. See docs/branch_feat_web_wasm.md
# "Asyncify boundary" for the layer-by-layer impact analysis.

message(STATUS "=== rayjs web (wasm) target — cmake/web.cmake loaded ===")

function(rayjs_web_pre)
    message(STATUS "=== rayjs web (wasm) — pre-configuration ===")

    # ---- raylib options (consumed by thirdparty/raylib/CMakeLists.txt) ----
    # PLATFORM=Web switches raylib's CMake branches to use the emscripten
    # GLFW shim, miniaudio's Web Audio backend, and HTML5 input handlers.
    set(PLATFORM "Web" CACHE STRING "raylib platform" FORCE)
    # GLES3 routes raylib's rlgl through GLES3 calls; emscripten translates
    # those to WebGL 2 (the -sUSE_WEBGL2 flag set in rayjs_web_post).
    set(GRAPHICS "GRAPHICS_API_OPENGL_ES3" CACHE STRING "raylib graphics API" FORCE)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

    # ---- Box2D options (consumed by thirdparty/box2d/CMakeLists.txt) ----
    # Samples/benchmarks pull in desktop GLFW + ImGui. We only need the lib.
    set(BOX2D_SAMPLES OFF CACHE BOOL "" FORCE)
    set(BOX2D_BENCHMARKS OFF CACHE BOOL "" FORCE)
    set(BOX2D_UNIT_TESTS OFF CACHE BOOL "" FORCE)
    set(BOX2D_DOCS OFF CACHE BOOL "" FORCE)
    set(BOX2D_VALIDATE OFF CACHE BOOL "" FORCE)

    # ---- rayjs options ----
    # mimalloc on web: skipped. Compiles to wasm in principle, but the
    # default emscripten allocator (dlmalloc/emmalloc) is fine for our
    # scale and avoids extra build complexity. Revisit if profiling shows
    # the allocator is a bottleneck.
    set(RAYJS_USE_MIMALLOC OFF CACHE BOOL "" FORCE)
endfunction()

function(rayjs_web_post)
    message(STATUS "=== rayjs web (wasm) — post-configuration ===")

    set(target ${CMAKE_PROJECT_NAME})

    # RAYJS_NO_MIMALLOC tells src/rayjs_base.c to skip <mimalloc.h> and
    # alias mi_* to standard libc (malloc/calloc/realloc/free). Required
    # because rayjs_base.c has unconditional mi_* calls (memoryStore /
    # memoryClear / opaqueShadow helpers) that would otherwise be
    # unresolved at link time on the web target.
    target_compile_definitions(${target} PRIVATE RAYJS_NO_MIMALLOC=1)

    # Emscripten linker flags.
    # - USE_WEBGL2 / FULL_ES3 / MIN|MAX_WEBGL_VERSION=2: WebGL 2 / GLES3 path.
    # - ASYNCIFY: keeps the synchronous main loop pattern working in the
    #   browser (see docs/branch_feat_web_wasm.md "Asyncify boundary").
    # - ALLOW_MEMORY_GROWTH + INITIAL_MEMORY: start at 64 MB, grow as needed.
    # - FORCE_FILESYSTEM + EXPORTED_RUNTIME_METHODS: expose FS / ccall so
    #   loader.js (Phase 3) can populate MEMFS in Module.preRun before main.
    target_link_options(${target} PRIVATE
        "-sUSE_WEBGL2=1"
        "-sFULL_ES3=1"
        "-sMIN_WEBGL_VERSION=2"
        "-sMAX_WEBGL_VERSION=2"
        "-sASYNCIFY"
        "-sASYNCIFY_STACK_SIZE=32768"
        "-sALLOW_MEMORY_GROWTH=1"
        "-sINITIAL_MEMORY=64MB"
        "-sFORCE_FILESYSTEM=1"
        "-sEXPORTED_RUNTIME_METHODS=['FS','ccall','cwrap']"
    )

    # Emit .html + .js + .wasm into build-web/dist/. The root CMakeLists.txt
    # sets CMAKE_RUNTIME_OUTPUT_DIRECTORY to the source tree so the native
    # binary lands at ./rayjs — that pollutes the repo for the web build,
    # so we override per-target. The default emcc HTML shell is enough for
    # Phase 1 / 4 smoke tests; Phase 3 replaces it with platforms/web/shell.html.
    set_target_properties(${target} PROPERTIES
        SUFFIX ".html"
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist
    )
endfunction()
