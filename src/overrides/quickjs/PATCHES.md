# quickjs patches

Files in this directory are patched copies of `thirdparty/quickjs/quickjs.h` and
`thirdparty/quickjs/quickjs.c`. CMakeLists.txt deploys them into the submodule via
`configure_file` at configure time:

```cmake
configure_file(src/overrides/quickjs/quickjs.h thirdparty/quickjs/quickjs.h @ONLY)
configure_file(src/overrides/quickjs/quickjs.c thirdparty/quickjs/quickjs.c @ONLY)
```

This means `thirdparty/quickjs` will always appear dirty (`M quickjs.c`, `M quickjs.h`)
after a CMake configure run. That is expected and intentional — the submodule itself is
never committed with these changes.

## Patches applied on top of quickjs-ng v0.14.0

### `JS_ForceSetOpaque`

**Why:** `JS_SetOpaque` only works on objects whose class was registered with an opaque
size. rayjs needs to attach C pointers to plain JS objects (e.g. structs returned from
raylib) whose class was not set up with an opaque slot. `JS_ForceSetOpaque` bypasses the
class check and writes directly to `p->u.opaque`.

**`quickjs.h`** — declaration added after `JS_SetOpaque`:
```c
/* Force-sets opaque on any object regardless of class; returns 0 on success < 0 otherwise. */
JS_EXTERN int JS_ForceSetOpaque(JSValueConst obj, void *opaque);
```

**`quickjs.c`** — implementation added after `JS_SetOpaque`:
```c
int JS_ForceSetOpaque(JSValueConst obj, void *opaque)
{
    JSObject *p;
    if (JS_VALUE_GET_TAG(obj) == JS_TAG_OBJECT) {
        p = JS_VALUE_GET_OBJ(obj);
        p->u.opaque = opaque;
        return 0;
    }
    return -1;
}
```

## Updating quickjs-ng

When bumping the `thirdparty/quickjs` submodule to a new version:

1. Copy the new `quickjs.h` and `quickjs.c` from the submodule into this directory.
2. Re-apply the patches above.
3. Run CMake configure so the patched files are deployed back into the submodule.
4. Rebuild and verify.
