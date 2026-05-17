# Phase 3 — Binding Gaps

Functions that remain ignored after the raylib 6.0 upgrade, grouped by the
reason they were skipped and notes on how each could be supported.

## Pointer-return / array-length coupling

These functions return a heap-allocated array whose length is returned via a
separate `int *` out-param, or they accept such arrays as input.  The current
binding system has no way to express "return ArrayBuffer + length as a tuple",
so they are skipped.

| Function | Issue | Approach |
|---|---|---|
| `LoadRandomSequence(count, min, max)` | Returns `int *` (caller must free) | Return `Int32Array` (ArrayBuffer wrapping); call `UnloadRandomSequence` internally |
| `UnloadRandomSequence(sequence)` | Takes `int *` (internal, pair with above) | Can be made internal/auto-freed if `LoadRandomSequence` owns the buffer |
| `LoadTextLines(fileName, count*)` | Returns `char **`, out-param count | Return `string[]` (same pattern as `LoadDirectoryFiles`) |
| `UnloadTextLines(lines, count)` | Takes `char **` + count | Make internal to `LoadTextLines` |
| `MeasureTextCodepoints(codepoints, count)` | Takes `const int *` array | Accept `Int32Array` ArrayBuffer param |

**Recommended approach:** Add an `ArrayBuffer` / typed-array path in `jsToC` and
`jsToJs`, similar to how `LoadImageColors` is handled manually today. Then
`LoadRandomSequence` and `LoadTextLines` can follow the same pattern as
`LoadFileData`/`LoadDirectoryFiles` (custom `body` binding that manages the
pointer lifetime internally).

## Hash / digest functions

| Function | Issue | Approach |
|---|---|---|
| `ComputeMD5(data, dataLength)` | Returns `unsigned int *` (16 bytes) | Return `ArrayBuffer` of 16 bytes; wrap in custom body |
| `ComputeSHA1(data, dataLength)` | Returns `unsigned int *` (20 bytes) | Same |
| `ComputeSHA256(data, dataLength)` | Returns `unsigned int *` (32 bytes) | Same |

**Recommended approach:** Custom `body` binding: call the function, wrap the
returned pointer in `JS_NewArrayBufferCopy` with the known byte length, call
`MemFree` on the pointer (or use the internal allocator the function uses).

## Image functions

| Function | Issue | Approach |
|---|---|---|
| `LoadImageAnimFromMemory(type, data, dataSize, frameCount*)` | Out-param `int *frameCount` | Add `setOutParam` for `frameCount`; the rest are already handled |
| `ExportImageToMemory(image, type, dataSize*)` | Returns `unsigned char *` with out-param size | Custom body: call, wrap in `JS_NewArrayBufferCopy`, free pointer |
| `ImageKernelConvolution(image, kernel, kernelSize)` | Takes `const float *kernel` | Accept `Float32Array` ArrayBuffer param |

## raygui complex controls

| Function | Issue | Approach |
|---|---|---|
| `GuiListViewEx(bounds, text, count, scrollIndex*, active*, focus*)` | Takes `const char **` string array + multiple out-params | Add string-array input support; the int* out-params already have helpers |
| `GuiTabBar(bounds, tabs, tabCount, active*)` | Takes `const char **` string array | Same string-array support needed |
| `GuiGetIcons()` | Returns `unsigned int *` (icon data) | Return `Uint32Array` ArrayBuffer |
| `GuiLoadIcons(fileName, loadIconsName)` | Returns `char **` | Return `string[]` |

**Recommended approach for string arrays:** Add a `setStringArrayParam` helper
that converts a JS `string[]` to a temporary `const char **` on the stack
(bounded by a reasonable max count), then frees the strings after the call.

## Priority order

1. `LoadImageAnimFromMemory` — only needs `setOutParam` for `int *frameCount`; lowest effort
2. Hash functions — small custom bodies, high utility
3. `LoadRandomSequence` / `LoadTextLines` — useful for games; follow `LoadFileData` pattern
4. `ImageKernelConvolution` / `MeasureTextCodepoints` — need typed-array param support
5. `GuiListViewEx` / `GuiTabBar` / icon functions — need string-array param support
