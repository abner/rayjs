# rayjs:ext Built-in Module System

`lib/*.js` files are embedded into the rayjs binary as built-in modules accessible via
`import ... from "rayjs:ext:<stem>"`.

## Purpose

Allows shipping pure-JS library modules (like `tiled.js`) without requiring a separate file
on disk at runtime, while keeping filesystem imports working as a fallback.

## Usage

```js
// Embedded in binary — works on any machine with just the rayjs executable
import { loadTiledMap } from "rayjs:ext:tiled"

// Reads from disk — works during development
import { loadTiledMap } from "../../lib/tiled.js"
```

The module name is the file stem: `lib/mymodule.js` → `rayjs:ext:mymodule`.

## How it works

At cmake configure time (and on every rebuild when `lib/*.js` changes):

1. `cmake/gen_ext_modules.cmake` scans `lib/*.js`
2. Embeds each file as a `uint8_t[]` array in `src/js_ext_modules.h`
3. Builds a `JsExtEntry` lookup table in the same header

At runtime:

- `js_ext_module_loader` in `src/rayjs_base.c` checks if the specifier starts with `rayjs:ext:`
  and looks it up in the table
- `rayjs_module_loader` in `src/rayjs.c` wraps it, falling through to `js_module_loader` for
  all other specifiers

## Key files

| File | Role |
|---|---|
| `cmake/gen_ext_modules.cmake` | Generates `src/js_ext_modules.h` at configure + build time |
| `src/js_ext_modules.h` | Generated header — not committed (regenerated automatically) |
| `src/rayjs_base.c` | `js_ext_module_loader` does the lookup |
| `src/rayjs.c` ~line 550 | Uses `rayjs_module_loader` instead of `js_module_loader` |
| `CMakeLists.txt` | `execute_process` + `add_custom_command` to drive generation |

## Adding a new extension module

1. Create `lib/<name>.js` — a standard ES module. Import raylib via `rayjs:raylib`.
2. Optionally create `lib/<name>.d.ts` — TypeScript declarations for IDE auto-complete
   (no `declare module` wrapper needed; the cmake script wraps it automatically).
3. Re-run cmake or rebuild — no manual registration needed.

See `readme.md` for full details and a worked example.

## Notes

- `src/js_ext_modules.h` is a generated artifact and should be in `.gitignore`.
- TypeScript declarations are generated to `bindings/typings/lib.js_ext_<name>.d.ts` and
  are picked up automatically by the `tsconfig.json` include path.
- If you delete `lib/<name>.js`, the corresponding `.d.ts` is removed by the same script.
