# Dependency Modernization Plan

This branch tracks a two-phase modernization of the `rayjs` fork:

1. **[Phase 1 — QuickJS → quickjs-ng](./01-quickjs-ng-migration.md)**
   Replace the dormant `bellard/quickjs` pinned at `2021-03-27` with the
   actively-maintained `quickjs-ng/quickjs` fork at `v0.13.0` (or newer).

2. **[Phase 2 — raylib 6.0 upgrade](./02-raylib-6.0-upgrade.md)**
   Move the `raylib` and `raygui` submodules from their current floating
   `main` branch to the `raylib 6.0` release (April 2026), regenerate the
   bindings, and fix everything that breaks.

Each phase is its own branch and its own PR. Do **not** combine them — when
the build breaks (and it will), you want to know which side caused it.

## Why two phases and in this order

- QuickJS first because it's the smaller, more isolated change. If something
  goes wrong, it's almost certainly in `src/` glue code or `CMakeLists.txt`,
  not in the auto-generated raylib bindings.
- raylib second because it's the bigger blast radius: it touches the
  bindings generator output, the `.d.ts` files, the helpers in `src/`, and
  every example. Doing it on top of a known-good QuickJS-NG baseline means
  any breakage you see is raylib-related.

## Branch layout

```
main
└── feat/dependency-modernization          ← this branch (plans only)
    ├── feat/quickjs-ng-migration          ← Phase 1 work
    └── feat/raylib-6.0                    ← Phase 2 work (branches from Phase 1)
```

After Phase 1 merges to `main`, rebase Phase 2 onto it.

## Status checklist

- [ ] Phase 1 — quickjs-ng migration
- [ ] Phase 2 — raylib 6.0 upgrade
- [ ] README updated (drop MinGW caveat, point clone URL at this fork)
- [ ] CI green on Linux, macOS, Windows
- [ ] Examples smoke-tested end-to-end
