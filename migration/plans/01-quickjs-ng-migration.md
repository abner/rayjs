# Phase 1 — Migrate QuickJS → quickjs-ng

## Goal

Replace the dormant `bellard/quickjs` submodule pinned at `2021-03-27` with
[`quickjs-ng/quickjs`](https://github.com/quickjs-ng/quickjs) at a tagged
release (`v0.13.0` at planning time — check for newer before starting).

## Why quickjs-ng

- Active maintenance, frequent releases, security fixes.
- Ships its own CMake build — we can drop the hand-rolled file list in
  `CMakeLists.txt` and just `add_subdirectory()` it.
- Better Windows / MSVC support → **kills the "QuickJS needs MinGW on
  Windows" caveat in the README**.
- Defines `QUICKJS_NG` macro so any source-level differences can be
  conditionally handled if needed.
- API is mostly source-compatible with Bellard's; only a small number of
  internals have moved.

## Target versions

| Component  | From                                 | To                                            |
| ---------- | ------------------------------------ | --------------------------------------------- |
| QuickJS    | `bellard/quickjs` @ `2021-03-27`     | `quickjs-ng/quickjs` @ `v0.13.0` (or latest)  |

> **Before starting**, check https://github.com/quickjs-ng/quickjs/releases
> for a newer tag. Pin to a tag, not a branch.

## Branch

```
git checkout main
git pull
git checkout -b feat/quickjs-ng-migration
```

## Step-by-step

### 1. Swap the submodule

The submodule currently lives at `thirdparty/quickjs`. We'll deinit the old
one and re-add against the new upstream so the working tree stays clean.

```bash
# Record where we are
git status

# Remove the old submodule cleanly
git submodule deinit -f thirdparty/quickjs
git rm -f thirdparty/quickjs
rm -rf .git/modules/thirdparty/quickjs

# Add the new one, pinned to a tag
git submodule add https://github.com/quickjs-ng/quickjs.git thirdparty/quickjs
cd thirdparty/quickjs
git fetch --tags
git checkout v0.13.0       # or newer — verify before running
cd ../..
git add .gitmodules thirdparty/quickjs
```

Verify `.gitmodules` shows the new URL with no `branch =` line (we want a
pinned commit, not a moving branch).

### 2. Rewrite the QuickJS section of `CMakeLists.txt`

**Current block (delete):**

```cmake
message("=== Configure QuickJS ===")
# add quickjs
set(quickjs_version 2021-03-27)
set(quickjs_sources_root ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/quickjs)
set(quickjs_sources
    ${quickjs_sources_root}/quickjs.h
    #${quickjs_sources_root}/quickjs-libc.h
    ${quickjs_sources_root}/quickjs.c
    ${quickjs_sources_root}/libregexp.c
    ${quickjs_sources_root}/libunicode.c
    ${quickjs_sources_root}/libbf.c
    ${quickjs_sources_root}/cutils.c
    #${quickjs_sources_root}/quickjs-libc.c
)
add_library(quickjs STATIC ${quickjs_sources})
target_compile_definitions(quickjs PRIVATE CONFIG_VERSION="${quickjs_version}")
target_include_directories(quickjs PRIVATE ${quickjs_sources_root})
```

**Replace with:**

```cmake
message("=== Configure QuickJS (quickjs-ng) ===")
# quickjs-ng ships its own CMake build, no need to enumerate sources.
# Disable its CLI tools/tests — we only want the library.
set(BUILD_QJS_LIBC      OFF CACHE BOOL "" FORCE)   # we don't use std/os modules
set(BUILD_EXAMPLES      OFF CACHE BOOL "" FORCE)
set(BUILD_QJS           OFF CACHE BOOL "" FORCE)   # don't build the qjs CLI
set(BUILD_QJSC          OFF CACHE BOOL "" FORCE)   # don't build the qjsc compiler
set(BUILD_RUN_TEST262   OFF CACHE BOOL "" FORCE)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/quickjs EXCLUDE_FROM_ALL)
```

> ⚠️ Verify the exact option names by checking the quickjs-ng
> `CMakeLists.txt` at the tag you pinned. Names occasionally shift between
> releases (e.g. `BUILD_QJS_LIBC` vs `QJS_BUILD_LIBC`). Run
> `cmake -LH ../thirdparty/quickjs` to list them.

The `target_link_libraries(... quickjs ...)` line near the bottom should
still work — quickjs-ng exports a target named `qjs` or `quickjs`. Check
which and update if needed.

### 3. Audit `src/` for QuickJS API usage

The public `JS_*` API is mostly stable, but spot-check the following.
Greppable list:

```bash
grep -rnE 'JS_(NewClass|GetOpaque|SetOpaque|GetClassID|NewClassID|NewAtom|FreeAtom|GetGlobalObject|NewCFunction[A-Za-z]*|SetProperty[A-Za-z]*|GetProperty[A-Za-z]*|NewObject[A-Za-z]*|NewArray|FreeValue|DupValue|ToInt[36][24]|ToFloat64|ToBool|IsException|GetException|Throw[A-Za-z]*|VALUE_GET_[A-Z]+|MKVAL|MKPTR)' src/ include/
```

Known things to watch for:

- **`JS_NewClass` / `JS_GetOpaque` / `JS_SetOpaque`** — signatures unchanged.
- **`JSCFunctionListEntry` and `JS_CFUNC_DEF` macros** — unchanged.
- **`JS_FreeValue` / `JS_DupValue`** — in newer quickjs-ng these have moved
  from being macros to being inline functions in some places. If you get
  "redefinition" or "implicit declaration" warnings, the fix is usually to
  just include `<quickjs.h>` and stop touching internals.
- **`JS_VALUE_GET_TAG`, `JS_MKVAL`, `JS_TAG_*`** — unchanged.
- **BigInt API** — if rayjs uses `JS_NewBigInt64`/`JS_NewBigUint64` or
  `JS_ToBigInt64`, these are still present.
- **`JS_NewArrayBuffer` / `JS_GetArrayBuffer`** — unchanged. Critical for
  the `meshCopy`/`meshMerge`/mesh-from-ArrayBuffer helpers.
- **`JS_SetModuleLoaderFunc`** — unchanged.
- **`CONFIG_VERSION` define** — remove our manual `-DCONFIG_VERSION=...`,
  quickjs-ng manages its own version string. Search for any code that
  reads it.

### 4. Build

```bash
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . -j
```

Expected outcome: clean build, single `rayjs` binary in the repo root (the
existing `set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})`
controls that).

If compilation fails on QuickJS-internal headers, the most common cause is
quickjs-ng having reorganized private headers. **Don't include private
headers from `src/`** — only `<quickjs.h>`.

### 5. Smoke-test

Run, in order, easiest to hardest:

```bash
./rayjs main.js                              # basic window
./rayjs examples/js_mesh_generation.js       # exercises ArrayBuffer plumbing
./rayjs examples/shaders/js_shaders_gradient_lighting.js
./rayjs examples/js_lightmapper.js           # exercises the C-side helpers
./rayjs examples/ts_dungeon                  # bundled TS
./rayjs examples/ts_game                     # Inkjs integration — heaviest JS surface
```

If `ts_game` and `ts_dungeon` work, the engine swap is almost certainly
clean.

### 6. CI

- `.github/workflows/*.yml` — if Windows job uses MinGW specifically for
  QuickJS, switch it to MSVC. quickjs-ng supports MSVC out of the box.
- Bump `actions/checkout` to include `submodules: recursive` if it isn't
  already (it should be — confirm).
- Keep macOS arm64+x86_64 fat builds (the `CMAKE_OSX_ARCHITECTURES` in
  root `CMakeLists.txt` already handles this).

### 7. README

Defer the README cleanup to the end of Phase 2 so we only touch it once.
But note for later:

- Remove: *"Please note that QuickJS needs Mingw in order to compile
  correctly on Windows"*
- Change clone URL: `https://github.com/mode777/rayjs.git` →
  `https://github.com/abner/rayjs.git`

## Done criteria

- [ ] `thirdparty/quickjs` points at `quickjs-ng/quickjs` at a tagged release
- [ ] `.gitmodules` has no `branch = ` line for quickjs
- [ ] `CMakeLists.txt` uses `add_subdirectory` instead of hand-rolled file list
- [ ] Manual `CONFIG_VERSION` define is gone
- [ ] All examples in `examples/` run without regressions
- [ ] CI green on Linux, macOS, Windows (MSVC, not MinGW)
- [ ] No new compiler warnings in `src/`

## Rollback

If something goes badly wrong:

```bash
git checkout main
git branch -D feat/quickjs-ng-migration
```

The submodule changes are recorded in the branch's commits; main is
untouched.

## Notes / scratchpad

_(Use this section while you work)_
