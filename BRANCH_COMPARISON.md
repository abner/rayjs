# Branch Comparison: `feat/update-deps-varhar` vs `feat/github-actions-multiplatform`

Generated: 2026-05-19

---

## TL;DR

| Topic | `update-deps-varhar` | `github-actions-multiplatform` |
|---|---|---|
| Origin | Full VarHar fork history (~34+ unique commits) | 7 commits on top of a shared base |
| quickjs-ng | **v0.14.0** | v0.13.0 |
| raylib | 6.0 (same) | 6.0 (same) |
| raygui | Latest master (`b256d455`) | `6d2b28ff` |
| mimalloc | **v3.3.2** (new submodule) | Not present |
| Example JS files | **~170** across all categories | ~27 + TypeScript projects |
| raygui examples | **14 demo scripts + 12 styles** | 1 (`controls_test_suite.js`) |
| CI workflows | 5 workflow files (no weekly) | **5 workflow files incl. weekly + unified multi-platform** |
| macOS OpenGL | Fixed: uses GL 3.3 (not 4.3) | Not fixed |
| CWD fix | **chdir to script dir at startup** | Not present |
| quickjs patch doc | **`src/overrides/quickjs/PATCHES.md`** | Not present |
| Bindings generator | JS-based (no Node/TypeScript/webpack) | TypeScript source remains |
| TypeScript examples | Removed | `ts_dungeon/`, `ts_game/` present |

---

## 1. Git History and Lineage

The two branches **do not have a close merge-base**. `feat/update-deps-varhar` carries the complete VarHar fork history (the original RealVarHar/rayjs rewrite) and all dependency bumps on top of it. `feat/github-actions-multiplatform` was started on a different cut of the repository and only has 7 additional commits.

### Commits exclusive to `update-deps-varhar` (34+)

```
997031a chdir to script directory at startup; document quickjs patches
5ff16a4 Use GRAPHICS_API_OPENGL_33 on macOS (max supported is 4.1, not 4.3)
592077e Bump quickjs-ng → v0.14.0, raylib → 6.0, raygui → latest, mimalloc → v3.3.2
6b86bea Fix more examples; fix allocation in m3d; remove overfreeing ret
172bcb4 Update dependencies
42049c5 Add correct parsing to function comments
bad45ad Implement class reference borrow, deepCCopy, global dynamic temp memory lists,
        malloc overrides for raygui, missing struct size variables
d12a09e New shared jsToC functions saving size; more examples; additional debug functions
a929c53 Fixed .d.ts typings generation; fixed some examples; miscellaneous fixes
af49842 Support more examples; fix unneeded imports; update to newest quickjs and raylib;
        simplify windows build
7747af4 Major cgen.js rewrite (auto-casts, error collection, nicer output); source_parser
        improvements
ef0295f Update to current version of quickjs and raylib
e9621d8 More upstream raylib examples; TypeScript bindings; light fixes
273dfc5 Implement Array proxy (arr[1]=obj); overwrite raylib allocators with mimalloc
ce7a27c Fix audio_mixed_processor.js
c3892ea Rename folders; fix TextFormat memory leak; implement multithreading; fix audio_mixed_processor
74fa480 Update dependencies
7755e91 Remove rextensions hacks; split generation to modules; capture callbacks/aliases/defines;
        remove dependency on raylib_api.json
f713ba0 Cleanup and fix audio_mixed_processor crash
4477969 Implement callback pointer returns
15ec9c5 Add building with mimalloc
28d19a4 Upstream update
cb90226 workflow tests
b0fa9f8 workflow tests
0863e31 nodejs fs compatibility; codegenerator simplify; global config; basic callback support
c15c27f New source file parser; add rlgl
13b7d4c Generator fixes; add config, pointers support, TypedArray type; fix ShaderValue,
        Gui functions, dynamic memory; add error information; implement optional flags
aee8767 Change quickjs source
47a85ef Remove F5 restart; add qjs start flags; allow building bindings with rayjs itself
bfca6e3 Switch to a working tree
... (several more early commits)
5d2bf43 Initial changes: update deps, switch to quickjs-ng, build bindings with quickjs
```

### Commits exclusive to `github-actions-multiplatform` (7)

```
94d89d2 Add unified multi-platform CI workflow (Windows x64, Linux x64, macOS x64, macOS ARM64)
f0cb3c4 Add rlEnableWireMode and rlDisableWireMode bindings
3be91fe Add GetMaterialTexture, rlDisableBackfaceCulling, rlEnableBackfaceCulling bindings
888da13 Patch raylib_api.json invalid JSON in generator; add gamepad example
282c93f Upgrade raylib → 6.0 and raygui → 5.0 (Phase 2)
76fa1b0 Migrate QuickJS → quickjs-ng v0.13.0 (Phase 1)
34837cd Add dependency modernization plan (Phase 1: quickjs-ng, Phase 2: raylib 6.0)
```

---

## 2. Submodule Versions

| Submodule | `update-deps-varhar` | `github-actions-multiplatform` |
|---|---|---|
| `thirdparty/quickjs` | `3c051980` — **quickjs-ng v0.14.0** | `dec01236` — quickjs-ng v0.13.0 |
| `thirdparty/raylib` | `dbc56a87` — raylib 6.0 | `dbc56a87` — raylib 6.0 (**same**) |
| `thirdparty/raygui` | `b256d455` — latest master | `6d2b28ff` — raygui 5.0 tag |
| `thirdparty/mimalloc` | `30b2d9d8` — **v3.3.2** (new submodule) | *(not a submodule)* |
| `thirdparty/lightmapper` | `4fd3bf4e` | `4fd3bf4e` (**same**) |

### quickjs-ng v0.13.0 → v0.14.0 differences (relevant to rayjs)

- `JS_SetModuleLoaderFunc` → `JS_SetModuleLoaderFunc2` (adds import attributes parameter)
- New `js_module_check_attributes` callback required
- `cutils.h` moved to `static inline` definitions (was `extern` declarations)
- `quickjs-libc.c` updated to 5018 lines (from ~4736 in v0.13.0 era)

---

## 3. Runtime / Source Changes

### Present only in `update-deps-varhar`

**`src/rayjs.c` — CWD fix**
At startup, the binary resolves the script path to absolute and `chdir`s to its directory.
This means all relative asset paths in scripts (`resources/...`, `../quack.mp3`, etc.) work
regardless of where the binary is invoked from. Critical for running examples without `cd`-ing
first.

```c
if (realpath(filename, _abs_script)) {
    filename = _abs_script;
    js__pstrcpy(_script_dir, sizeof(_script_dir), _abs_script);
}
char *_sep = strrchr(_script_dir, '/');
if (_sep) { *_sep = '\0'; chdir(_script_dir); }
```

**`src/modules/quickjs-libc.c` / `.h`** — updated to v0.14.0 with custom `js_postMessage` helper re-added at end of file (used by audio/stream callbacks in `js_raylib.h`).

**`src/cutils.h`** — replaced with v0.14.0 version (static inline definitions instead of extern declarations). The old version caused a linker error when building against quickjs-ng v0.14.0.

**`src/overrides/quickjs/PATCHES.md`** — documents the `JS_ForceSetOpaque` patch and the `configure_file` override mechanism.

### Present only in `github-actions-multiplatform`

**New rlgl bindings** (in `src/modules/js_rlgl.h`):
- `rlEnableWireMode` / `rlDisableWireMode`
- `rlEnableBackfaceCulling` / `rlDisableBackfaceCulling`

**New raylib bindings** (in `src/modules/js_raylib.h`):
- `GetMaterialTexture`

**Generator fix** — `raylib_api.json` patched for invalid JSON that broke the generator.

---

## 4. Build System (`CMakeLists.txt`)

| Feature | `update-deps-varhar` | `github-actions-multiplatform` |
|---|---|---|
| cmake minimum | 3.10 | 3.1 |
| UNIX `-fPIC -DCONFIG_BIGNUM` | Yes | No |
| mimalloc submodule | Yes (always built; optional allocator override via `RAYJS_USE_MIMALLOC`) | No |
| macOS OpenGL | `GRAPHICS_API_OPENGL_33` | `GRAPHICS_API_OPENGL_43` (incorrect — macOS max is 4.1, and raylib has no 4.1 define) |
| Linux/Win OpenGL | `GRAPHICS_API_OPENGL_43` | `GRAPHICS_API_OPENGL_43` |
| `examples/shapes` include path | Yes (needed for `reasings.h`) | No |
| Link libraries | `quickjs mimalloc-static raylib lightmapper` | `quickjs raylib lightmapper` |

---

## 5. CI / GitHub Actions

Both branches have `.github/workflows/` with `build.yml`, `linux.yml`, `macos.yml`, `windows.yml`. The key differences:

| Workflow | `update-deps-varhar` | `github-actions-multiplatform` |
|---|---|---|
| `weekly.yml` | **Removed** | Present |
| Multi-platform unified workflow | No | **Yes** (`build.yml` — Windows x64, Linux x64, macOS x64, macOS ARM64) |
| Individual platform files | Modified (linux/macos/windows each updated) | Original versions |

The unified multi-platform workflow in `github-actions-multiplatform` is a significant addition — it tests all four target platforms in a single workflow run using a matrix strategy.

---

## 6. Examples Coverage

### JavaScript example scripts per category

| Category | `update-deps-varhar` | `github-actions-multiplatform` |
|---|---|---|
| audio | **8** | 3 |
| core | **34** | 10 |
| lightmapper | 1 (`lightmapper/js_lightmapper.js`) | 1 (`js_lightmapper.js` in root) |
| models | **23** | 3 |
| others | **5** | — |
| raygui | **14 demos + 12 styles** | 1 |
| shaders | **28** | 3 |
| shapes | **18** | 2 |
| text | **12** | 1 |
| textures | **27** | 2 |
| TypeScript projects | — | `ts_dungeon/` + `ts_game/` |
| **Total JS** | **~170** | **~27** |

### Files only in `update-deps-varhar`

<details>
<summary>audio (5 new)</summary>

- `audio/_audio_mixed_processor_worker.js`
- `audio/audio_mixed_processor.js`
- `audio/audio_raw_stream.js`
- `audio/audio_sound_multi.js`
- `audio/audio_stream_effects.js`

</details>

<details>
<summary>core (24 new)</summary>

- `core/_core_loading_thread_worker.js`
- `core/core_2d_camera_mouse_zoom.js`
- `core/core_2d_camera_split_screen.js`
- `core/core_3d_camera_split_screen.js`
- `core/core_3d_picking.js`
- `core/core_automation_events.js`
- `core/core_basic_screen_manager.js`
- `core/core_custom_logging.js`
- `core/core_drop_files.js`
- `core/core_input_gestures_testbed.js`
- `core/core_input_gestures.js`
- `core/core_input_multitouch.js`
- `core/core_input_virtual_controls.js`
- `core/core_loading_thread.js`
- `core/core_random_sequence.js`
- `core/core_random_values.js`
- `core/core_scissor_test.js`
- `core/core_smooth_pixelperfect.js`
- `core/core_storage_values.js`
- `core/core_vr_simulator.js`
- `core/core_window_flags.js`
- `core/core_window_letterbox.js`
- `core/core_window_should_close.js`
- `core/core_world_screen.js`

</details>

<details>
<summary>models (20 new)</summary>

- `models/models_animation_gpu_skinning.js`
- `models/models_animation.js`
- `models/models_billboard.js`
- `models/models_bone_socket.js`
- `models/models_box_collisions.js`
- `models/models_draw_cube_texture.js`
- `models/models_geometric_shapes.js`
- `models/models_heightmap.js`
- `models/models_loading_gltf.js`
- `models/models_loading_m3d.js`
- `models/models_loading_vox.js`
- `models/models_loading.js`
- `models/models_mesh_generation.js` (was `js_mesh_generation.js`)
- `models/models_mesh_picking.js`
- `models/models_orthographic_projection.js`
- `models/models_point_rendering.js`
- `models/models_rlgl_solar_system.js`
- `models/models_skybox.js`
- `models/models_tesseract_view.js`
- `models/models_waving_cubes.js`
- `models/models_yaw_pitch_roll.js`

</details>

<details>
<summary>others (all new)</summary>

- `others/easings_testbed.js`
- `others/embedded_files_loading.js`
- `others/raymath_vector_angle.js`
- `others/rlgl_compute_shader.js`

</details>

<details>
<summary>raygui (all new except controls_test_suite)</summary>

- `raygui/animation_curve/animation_curve.js`
- `raygui/controls_test_suite/controls_test_suite.js` (moved into subdir; old flat file removed)
- `raygui/controls_test_suite/controls_test_suite_old.js`
- `raygui/controls_test_suite/gui_value_box_float.js`
- `raygui/custom_file_dialog/custom_file_dialog.js`
- `raygui/custom_input_box/custom_input_box.js`
- `raygui/custom_sliders/custom_sliders.js`
- `raygui/floating_window/floating_window.js`
- `raygui/image_exporter/image_exporter.js`
- `raygui/image_importer_raw/image_importer_raw.js`
- `raygui/portable_window/portable_window.js`
- `raygui/property_list/property_list.js`
- `raygui/scroll_panel/scroll_panel.js`
- `raygui/style_selector/style_selector.js`
- `raygui/styles/_style_amber.js` … `_style_terminal.js` (12 style files)

</details>

<details>
<summary>shaders (25 new)</summary>

- `shaders/shaders_basic_pbr.js`
- `shaders/shaders_custom_uniform.js`
- `shaders/shaders_deferred_render.js`
- `shaders/shaders_eratosthenes.js`
- `shaders/shaders_fog.js`
- `shaders/shaders_gradient_lighting.js` (was `js_shaders_gradient_lighting.js`)
- `shaders/shaders_hot_reloading.js`
- `shaders/shaders_hybrid_render.js`
- `shaders/shaders_julia_set.js`
- `shaders/shaders_lightmap.js`
- `shaders/shaders_mesh_instancing.js`
- `shaders/shaders_model_shader.js`
- `shaders/shaders_multi_sample2d.js`
- `shaders/shaders_palette_switch.js`
- `shaders/shaders_postprocessing.js`
- `shaders/shaders_rounded_rectangle.js`
- `shaders/shaders_shadowmap.js`
- `shaders/shaders_shapes_textures.js`
- `shaders/shaders_simple_mask.js`
- `shaders/shaders_spotlight.js`
- `shaders/shaders_texture_drawing.js`
- `shaders/shaders_texture_outline.js`
- `shaders/shaders_texture_tiling.js`
- `shaders/shaders_texture_waves.js`
- `shaders/shaders_vertex_displacement.js`
- `shaders/shaders_write_depth.js`

</details>

<details>
<summary>shapes (16 new)</summary>

- `shapes/shapes_basic_shapes.js`
- `shapes/shapes_bouncing_ball.js`
- `shapes/shapes_collision_area.js`
- `shapes/shapes_colors_palette.js`
- `shapes/shapes_draw_rectangle_rounded.js`
- `shapes/shapes_draw_ring.js`
- `shapes/shapes_easings_ball_anim.js`
- `shapes/shapes_easings_box_anim.js`
- `shapes/shapes_easings_rectangle_array.js`
- `shapes/shapes_following_eyes.js`
- `shapes/shapes_lines_bezier.js`
- `shapes/shapes_logo_raylib_anim.js`
- `shapes/shapes_rectangle_advanced.js`
- `shapes/shapes_rectangle_scaling.js`
- `shapes/shapes_splines_drawing.js`
- `shapes/shapes_top_down_lights.js`

</details>

<details>
<summary>text (11 new)</summary>

- `text/text_codepoints_loading.js`
- `text/text_draw_3d.js`
- `text/text_font_filters.js`
- `text/text_font_sdf.js`
- `text/text_font_spritefont.js`
- `text/text_format_text.js`
- `text/text_input_box.js`
- `text/text_raylib_fonts.js`
- `text/text_rectangle_bounds.js`
- `text/text_unicode.js`
- `text/text_writing_anim.js`

</details>

<details>
<summary>textures (25 new)</summary>

- `textures/texture_generator.js` (moved from `examples/texture_generator.js`)
- `textures/textures_background_scrolling.js`
- `textures/textures_blend_modes.js`
- `textures/textures_bunnymark.js` (was `textures/bunnymark.js`)
- `textures/textures_draw_tiled.js`
- `textures/textures_fog_of_war.js`
- `textures/textures_gif_player.js`
- `textures/textures_image_channel.js`
- `textures/textures_image_drawing.js`
- `textures/textures_image_generation.js`
- `textures/textures_image_kernel.js`
- `textures/textures_image_loading.js`
- `textures/textures_image_processing.js`
- `textures/textures_image_rotate.js`
- `textures/textures_image_text.js`
- `textures/textures_logo_raylib.js`
- `textures/textures_mouse_painting.js`
- `textures/textures_npatch_drawing.js`
- `textures/textures_particles_blending.js`
- `textures/textures_polygon.js`
- `textures/textures_raw_data.js`
- `textures/textures_sprite_anim.js`
- `textures/textures_sprite_button.js`
- `textures/textures_sprite_explosion.js`
- `textures/textures_srcrec_dstrec.js`
- `textures/textures_textured_curve.js`
- `textures/textures_to_image.js`

</details>

### Files only in `github-actions-multiplatform`

- `examples/js_example_project/main.js` — minimal project scaffold
- `examples/ts_dungeon/` — TypeScript dungeon game (webpack, full game with tilemap)
- `examples/ts_game/` — TypeScript game scaffold (editor, entities, ink script support)
- `examples/lib.raylib.d.ts` — TypeScript definitions at examples root
- `examples/tsconfig.json`

---

## 7. Bindings Generator Architecture

| Aspect | `update-deps-varhar` | `github-actions-multiplatform` |
|---|---|---|
| Generator language | **Pure JavaScript** (`qjs` / rayjs itself) | TypeScript source (requires Node + webpack to compile) |
| Entry point | `bindings/src/index.js` (~1128 lines) | `bindings/src/index.ts` (666 lines) |
| Code generator | `bindings/src/cgen.js` (1518 lines, fully rewritten) | Older version |
| Source parser | `bindings/src/source_parser.js` (1650 lines) | Older/different parser |
| quickjs parser | `bindings/src/quickjs.js` (1533 lines) | Older version |
| TypeScript emit | `bindings/src/typescript.js` (285 lines) | Inline |
| Typings output | `bindings/typings/lib.js_*.d.ts` (per module) | `examples/lib.raylib.d.ts` (single file) |
| raylib_api.json | Not used (parses C headers directly) | Used (with JSON patch for invalid entries) |
| Build without Node | **Yes** — run `./rayjs bindings/src/index.js` | No — requires `npm run build` first |

---

## 8. Summary of What Each Branch Needs From the Other

### Things `update-deps-varhar` needs from `github-actions-multiplatform`

- **Unified CI workflow** (`build.yml`) — multi-platform matrix (Windows x64, Linux x64, macOS x64, macOS ARM64) in a single workflow file
- **Weekly CI workflow** (`weekly.yml`) — currently removed
- **`rlEnableWireMode` / `rlDisableWireMode`** bindings
- **`rlEnableBackfaceCulling` / `rlDisableBackfaceCulling`** bindings
- **`GetMaterialTexture`** binding

### Things `github-actions-multiplatform` needs from `update-deps-varhar`

- **quickjs-ng v0.14.0** bump (and the cutils.h / quickjs-libc.c fixes that come with it)
- **mimalloc submodule** (v3.3.2) and optional allocator integration
- **macOS OpenGL 3.3 fix** in CMakeLists.txt (currently uses 4.3, which fails at runtime)
- **CWD fix** in `rayjs.c` (`chdir` to script directory)
- **`src/overrides/quickjs/PATCHES.md`** documentation
- **All ~143 additional example scripts** across every category
- **Full raygui examples suite** (14 demos + 12 styles)
- **Bindings generator rewrite** (pure JS, no Node/webpack dependency)
- **Multithreading / Worker support** fixes
- **Audio processing / stream examples** fixes
- **Array proxy** implementation (`arr[i] = obj` syntax)
- **Class reference borrow** and `deepCCopy` semantics
- **`js_postMessage` helper** in quickjs-libc.c
