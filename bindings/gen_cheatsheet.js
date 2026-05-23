// Generates docs/cheatsheet.html from the .d.ts files in
// bindings/typings/ + lib/, with rayjs:raylib functions categorized by the
// section headers in thirdparty/raylib/src/raylib.h.
//
// Usage:  node bindings/gen_cheatsheet.js
//
// The output page is self-contained (CSS inlined) and has six INTRO marker
// comments where editorial prose is hand-written after each regeneration:
//   <!-- INTRO:overview --> <!-- INTRO:raylib --> <!-- INTRO:raygui -->
//   <!-- INTRO:box2d -->    <!-- INTRO:tiled -->  <!-- INTRO:extras -->

import { readFileSync, writeFileSync, existsSync } from "node:fs"
import { join, dirname } from "node:path"
import { fileURLToPath } from "node:url"

const ROOT = join(dirname(fileURLToPath(import.meta.url)), "..")

// ── .d.ts parser ───────────────────────────────────────────────────────────
//
// Quirk: the generated .d.ts files append the JSDoc for the *next* declaration
// to the end of the *previous* line, with no separating newline. e.g.
//   function InitWindow(...): void/** Close window... */
//   function CloseWindow(): void/** Check if app should close... */
// The first thing we do is insert a newline before every `/**` so each JSDoc
// starts a fresh line and a normal line-by-line scan works.

function parseDts(path) {
  if (!existsSync(path)) return null
  let src = readFileSync(path, "utf8")
  src = src.replace(/\/\*\*/g, "\n/**")
  const lines = src.split("\n")
  const out = { interfaces: [], ctors: [], constants: [], functions: [], typeAliases: [] }
  let pendingDoc = ""
  let i = 0
  while (i < lines.length) {
    const raw = lines[i]
    const line = raw.trim()
    if (!line) { i++; continue }

    if (line.startsWith("/**")) {
      let doc = line
      while (!doc.endsWith("*/") && i + 1 < lines.length) {
        i++
        doc += " " + lines[i].trim()
      }
      pendingDoc = doc.replace(/^\/\*\*\s*/, "").replace(/\s*\*\/$/, "")
        .replace(/\s*\*\s*/g, " ").replace(/\s+/g, " ").trim()
      i++; continue
    }

    // function FuncName(args): ReturnType            (also matches `export function`)
    let m = line.match(/^(?:export\s+)?function\s+([A-Za-z_]\w*)\s*\(([^)]*)\)\s*:\s*(.+?);?\s*$/)
    if (m) {
      const name = m[1]
      if (!name.startsWith("_")) {
        out.functions.push({ name, args: m[2], ret: m[3], doc: pendingDoc })
      }
      pendingDoc = ""; i++; continue
    }

    // type Alias = ...
    m = line.match(/^(?:export\s+)?type\s+([A-Za-z_]\w*)\s*=\s*(.+?);?\s*$/)
    if (m) {
      out.typeAliases.push({ name: m[1], def: m[2], doc: pendingDoc })
      pendingDoc = ""; i++; continue
    }

    // var/const/let ClassName: { prototype: X; new(...): X }   (constructor/class)
    m = line.match(/^(?:export\s+)?(?:var|const|let)\s+([A-Za-z_]\w*)\s*:\s*\{/)
    if (m) {
      const name = m[1]
      let block = line
      let depth = countDepth(line)
      while (depth > 0 && i + 1 < lines.length) {
        i++
        block += "\n" + lines[i]
        depth += countDepth(lines[i])
      }
      const isCtor = /\bnew\s*\(/.test(block) || /\bprototype\s*:/.test(block)
      if (isCtor) {
        const nm = block.match(/new\s*\(([^)]*)\)\s*:\s*([A-Za-z_]\w*)/)
        out.ctors.push({ name, ctorArgs: nm ? nm[1] : "", doc: pendingDoc })
      } else {
        // Treated as a namespace-ish constant; skip silently
      }
      pendingDoc = ""; i++; continue
    }

    // var/const/let NAME: type     (constant)         (also matches `export const`)
    m = line.match(/^(?:export\s+)?(?:var|const|let)\s+([A-Za-z_]\w*)\s*:\s*(.+?);?\s*$/)
    if (m) {
      out.constants.push({ name: m[1], type: m[2], doc: pendingDoc })
      pendingDoc = ""; i++; continue
    }

    // interface Name { ... }                          (also matches `export interface`)
    m = line.match(/^(?:export\s+)?interface\s+([A-Za-z_]\w*)(?:\s+extends\s+[\w,\s]+)?\s*\{/)
    if (m) {
      const name = m[1]
      let block = ""
      let depth = countDepth(line)
      while (depth > 0 && i + 1 < lines.length) {
        i++
        block += lines[i] + "\n"
        depth += countDepth(lines[i])
      }
      const fields = []
      let fieldDoc = ""
      for (let fl of block.replace(/\/\*\*/g, "\n/**").split("\n")) {
        fl = fl.trim()
        if (!fl) continue
        if (fl.startsWith("/**")) {
          fieldDoc = fl.replace(/^\/\*\*\s*/, "").replace(/\*\/\s*$/, "")
            .replace(/\s*\*\s*/g, " ").trim()
          continue
        }
        const fm = fl.match(/^([a-z_][\w]*)\??\s*:\s*([^,;]+)[,;]?\s*$/i)
        if (fm) {
          fields.push({ name: fm[1], type: fm[2].trim(), doc: fieldDoc })
          fieldDoc = ""
        }
      }
      out.interfaces.push({ name, fields, doc: pendingDoc })
      pendingDoc = ""; i++; continue
    }

    i++
  }
  return out
}

function countDepth(s) {
  return (s.match(/\{/g) || []).length - (s.match(/\}/g) || []).length
}

// ── raylib.h section map ───────────────────────────────────────────────────

function parseRaylibSections() {
  const src = readFileSync(join(ROOT, "thirdparty/raylib/src/raylib.h"), "utf8")
  const lines = src.split("\n")
  // raylib.h has two kinds of section markers:
  //  (1) module-level banners like:
  //        //--------------
  //        // Window and Graphics Device Functions (Module: core)
  //        //--------------
  //  (2) plain inline subsection comments inside the module like:
  //        // Window-related functions
  //        // Cursor-related functions
  //        // Drawing-related functions
  // We capture (2) because they're the finer-grained categories raylib.com
  // uses in its cheatsheet. The module-level banner lines from (1) usually
  // *also* end with "functions", so the same matcher catches them as a
  // fallback for sections that have no inner subsections.
  const sections = []
  const funcToSection = {}
  let currentSection = null
  const seen = new Set()
  for (const line of lines) {
    // Skip raw banner separators
    if (/^\/\/-{5,}/.test(line)) continue
    // Section header: a `// Some title (lowercase or Capital words) functions` line.
    // Must NOT look like a per-function trailing-comment (those come after RLAPI on
    // the same line, not at column 0).
    // Lazy-match up to the first "functions" word, with an optional
    // ":suffix" (Input-related functions: keyboard) — anything else after
    // (parens, commas, brackets) is ignored as descriptive trailing text.
    const sectMatch = line.match(/^\/\/\s+([A-Z][^\n]*?functions?(?:\s*:\s*\w[\w\s]*)?)(?:\b|$)/)
    if (sectMatch) {
      const raw = sectMatch[1]
      // Reject explanatory comments like "// NOTE: These functions ..." or
      // "// WARNING 2: Some functions ..." — they sit BETWEEN a real section
      // header and the first RLAPI line and would otherwise shadow the
      // real section's name.
      if (/^(NOTE|WARNING|WARN|TODO|FIXME)\b/i.test(raw)) continue
      const title = raw.replace(/\s*functions?\s*$/i, "").trim()
      currentSection = title
      if (!seen.has(title)) { sections.push(title); seen.add(title) }
      continue
    }
    // RLAPI ReturnType FunctionName(args);
    const f = line.match(/^\s*RLAPI\s+[^(]*?(\w+)\s*\(/)
    if (f && currentSection) {
      funcToSection[f[1]] = currentSection
    }
  }
  return { sections, funcToSection }
}

// ── module loader ──────────────────────────────────────────────────────────

const MODULES = [
  { id: "raylib",         module: "rayjs:raylib",            file: "bindings/typings/lib.js_raylib.d.ts" },
  { id: "raygui",         module: "rayjs:raygui",            file: "bindings/typings/lib.js_raygui.d.ts" },
  { id: "box2d",          module: "rayjs:box2d",             file: "bindings/typings/lib.js_box2d.d.ts" },
  { id: "box2d-handbr",   module: "rayjs:box2d (hand-bridged)", file: "bindings/typings/lib.js_box2d_handbridged.d.ts" },
  { id: "tiled-native",   module: "rayjs:ext:tiled (native)",file: "bindings/typings/lib.js_ext_tiled.d.ts" },
  { id: "tiled",          module: "rayjs:ext:tiled (lib wrapper)", file: "lib/tiled.d.ts" },
  { id: "raymath",        module: "rayjs:raymath",           file: "bindings/typings/lib.js_raymath.d.ts" },
  { id: "rcamera",        module: "rayjs:rcamera",           file: "bindings/typings/lib.js_rcamera.d.ts" },
  { id: "reasings",       module: "rayjs:reasings",          file: "bindings/typings/lib.js_reasings.d.ts" },
  { id: "rlgl",           module: "rayjs:rlgl",              file: "bindings/typings/lib.js_rlgl.d.ts" },
  { id: "rlights",        module: "rayjs:rlights",           file: "bindings/typings/lib.js_rlights.d.ts" },
  { id: "rlightmapper",   module: "rayjs:rlightmapper",      file: "bindings/typings/lib.js_rlightmapper.d.ts" },
  { id: "bjson",          module: "rayjs:bjson",             file: "bindings/typings/lib.js_bjson.d.ts" },
  { id: "ext-box2d-ud",   module: "rayjs:ext:box2d_userdata",file: "bindings/typings/lib.js_ext_box2d_userdata.d.ts" },
  { id: "std",            module: "rayjs:std",               file: "bindings/typings/lib.js_std.d.ts" },
  { id: "os",             module: "rayjs:os",                file: "bindings/typings/lib.js_os.d.ts" },
]

// ── HTML rendering ─────────────────────────────────────────────────────────

const esc = (s = "") => String(s).replace(/[&<>]/g, c => ({ "&": "&amp;", "<": "&lt;", ">": "&gt;" }[c]))
const slug = s => s.toLowerCase().replace(/[^a-z0-9]+/g, "-").replace(/^-|-$/g, "")

// Cross-link known type names inside an already-HTML-escaped signature
// fragment. Populated by main() once all modules are parsed so types can
// link across module boundaries (e.g. a box2d function returning a Vector2
// links back into raylib's Types section).
let TYPE_REGISTRY = new Set()
let TYPE_LINK_RE = null
function buildTypeLinkRegex() {
  if (!TYPE_REGISTRY.size) { TYPE_LINK_RE = null; return }
  // Longest names first so e.g. `Texture2D` is matched before `Texture`.
  const names = [...TYPE_REGISTRY].sort((a, b) => b.length - a.length)
  TYPE_LINK_RE = new RegExp(`\\b(${names.map(n => n.replace(/[.*+?^${}()|[\\]\\\\]/g, "\\$&")).join("|")})\\b`, "g")
}
function linkifyTypes(escapedText) {
  if (!TYPE_LINK_RE) return escapedText
  return escapedText.replace(TYPE_LINK_RE, (_, name) => `<a href="#type-${name}">${name}</a>`)
}

function renderInterfaces(interfaces, ctors, typeAliases = [], opaqueTypes = []) {
  const ctorMap = Object.fromEntries(ctors.map(c => [c.name, c]))
  const intf = interfaces.map(({ name, fields, doc }) => {
    const c = ctorMap[name]
    const fieldRows = fields.map(f =>
      `    <span class="f">${esc(f.name)}</span>: <span class="t">${linkifyTypes(esc(f.type))}</span>` +
      (f.doc ? `  <span class="doc">// ${esc(f.doc)}</span>` : "")
    ).join("\n")
    const ctorRow = c ? `\n    <span class="kw">new</span>(${linkifyTypes(esc(c.ctorArgs))}): ${linkifyTypes(esc(name))}` : ""
    return `<pre class="decl" id="type-${esc(name)}"><span class="kw">interface</span> <span class="n">${esc(name)}</span> {\n${fieldRows}${ctorRow}\n}${doc ? `\n<span class="doc">// ${esc(doc)}</span>` : ""}</pre>`
  }).join("\n")
  // Type aliases (e.g. `type Texture2D = Texture`) — small entries with
  // their own anchors so cross-links resolve to them.
  const aliases = typeAliases
    .filter(a => /^[A-Za-z_]\w*$/.test(a.name))
    .map(({ name, def, doc }) =>
      `<pre class="decl" id="type-${esc(name)}"><span class="kw">type</span> <span class="n">${esc(name)}</span> = <span class="t">${linkifyTypes(esc(def))}</span>` +
      (doc ? `  <span class="doc">// ${esc(doc)}</span>` : "") + `</pre>`
    ).join("\n")
  // Opaque types — names that appear in signatures but have no JS-side
  // shape (typically native enums or structs the binding leaves opaque).
  // We still render an anchor so cross-references resolve.
  const opaques = opaqueTypes
    .sort((a, b) => b.refCount - a.refCount)
    .map(({ name, refCount }) =>
      `<pre class="decl" id="type-${esc(name)}"><span class="kw">opaque type</span> <span class="n">${esc(name)}</span>` +
      `  <span class="doc">// native handle/enum — no JS-side fields exposed; referenced by ${refCount} signature${refCount === 1 ? "" : "s"}</span></pre>`
    ).join("\n")
  return [intf, aliases, opaques].filter(Boolean).join("\n")
}

function renderConstants(constants) {
  if (!constants.length) return ""
  // Group by name prefix up to the first underscore (KEY_, MOUSE_, etc.)
  const groups = {}
  for (const c of constants) {
    const g = c.name.match(/^([A-Z][A-Z0-9]*?)(?:_|$)/)?.[1] || "_other"
    ;(groups[g] ??= []).push(c)
  }
  return Object.entries(groups).map(([g, items]) => {
    const rows = items.map(c =>
      `  <span class="n">${esc(c.name)}</span>: <span class="t">${linkifyTypes(esc(c.type))}</span>` +
      (c.doc ? `  <span class="doc">// ${esc(c.doc)}</span>` : "")
    ).join("\n")
    return `<details class="cgroup"><summary>${esc(g)} <span class="count">(${items.length})</span></summary>\n<pre class="decl">${rows}</pre></details>`
  }).join("\n")
}

function renderFunctions(funcs) {
  if (!funcs.length) return `<div class="empty">No functions.</div>`
  return `<pre class="decl">` + funcs.map(f =>
    `<span class="n">${esc(f.name)}</span>(${linkifyTypes(esc(f.args))})<span class="t">: ${linkifyTypes(esc(f.ret))}</span>` +
    (f.doc ? `  <span class="doc">// ${esc(f.doc)}</span>` : "")
  ).join("\n") + `</pre>`
}

// Bucket raylib functions by raylib.h section + emit a "rayjs additions"
// catch-all for anything not present in the C header.
function bucketRaylibFunctions(functions, sections, funcToSection) {
  const buckets = new Map()
  for (const s of sections) buckets.set(s, [])
  const extras = []
  for (const fn of functions) {
    const sec = funcToSection[fn.name]
    if (sec && buckets.has(sec)) buckets.get(sec).push(fn)
    else extras.push(fn)
  }
  const result = []
  for (const [name, items] of buckets) {
    if (items.length) result.push({ section: name, items })
  }
  if (extras.length) result.push({ section: "rayjs additions", items: extras })
  return result
}

// Box2D: group by the part right after `b2`. e.g. b2CreateWorld → World,
// b2Body_GetPosition → Body, b2DistanceJoint_GetLength → DistanceJoint.
function bucketBox2dFunctions(functions) {
  const buckets = new Map()
  for (const fn of functions) {
    let key = "Misc"
    let m = fn.name.match(/^b2([A-Z][A-Za-z0-9]*?)_/)
    if (m) key = m[1]
    else if ((m = fn.name.match(/^b2(World|Body|Shape|Joint|Chain|Filter|Sensor|Polygon|Capsule|Circle|Segment|Math|Ray|Distance|Manifold|Mass|Hex|Profile|Counters|Toi|Aabb|Rotation|Transform|Vec2|Mouse|Motor|Prismatic|Revolute|Weld|Wheel)/))) key = m[1]
    ;(buckets.get(key) || buckets.set(key, []).get(key)).push(fn)
  }
  // Sort keys alphabetically with Misc last
  const keys = [...buckets.keys()].sort((a, b) => a === "Misc" ? 1 : b === "Misc" ? -1 : a.localeCompare(b))
  return keys.map(k => ({ section: k, items: buckets.get(k) }))
}

// ── Editorial intros (substituted into the INTRO:* placeholders) ──────────
//
// To revise an intro, edit it here — the generator will splice it into the
// matching <!-- INTRO:name --> comment on the next run.

const INTROS = {
  overview: `
    <p>This page maps every function, type, and constant rayjs exposes across
       all its modules. It is auto-generated from the TypeScript declarations
       under <code>bindings/typings/</code> and <code>lib/</code>, with raylib
       functions categorized by the section headers in raylib's own
       <code>raylib.h</code> so the layout reads like a port of
       <a href="https://www.raylib.com/cheatsheet/cheatsheet.html">raylib.com/cheatsheet</a>.</p>
    <p>Each entry shows its JS signature and the original JSDoc summary.
       Imports look like <code>import { InitWindow } from "rayjs:raylib"</code> —
       the module name above each section is the one to import from.</p>
  `,
  raylib: `
    <p>The core raylib 6.0 API. Functions, types, and constants follow
       raylib's C names verbatim, but they accept and return JS objects
       (<code>Vector2</code>, <code>Color</code>, <code>Texture2D</code>, …)
       instead of C structs.</p>
    <p>Subsections below mirror the categories from <code>raylib.h</code>.
       Anything that doesn't appear in <code>raylib.h</code> (rayjs-specific
       helpers, wrappers, or additions) goes in the trailing
       <em>rayjs additions</em> bucket. See <code>examples/</code> in the
       repo for runnable usage.</p>
  `,
  raygui: `
    <p>Immediate-mode GUI bindings (the raygui library that ships with
       raylib). Controls render in a stateless per-frame API —
       <code>GuiButton(rect, "Click me")</code> returns <code>true</code>
       on the frame the button is clicked, no listeners.</p>
    <p>Useful for tool UIs, in-game debug panels, level editors. Heavier
       UI work usually wants a full UI toolkit instead.</p>
  `,
  box2d: `
    <p>Box2D <strong>v3.1.1</strong> — the C rewrite, not the original
       C++ Box2D. The API uses opaque handles (<code>b2WorldId</code>,
       <code>b2BodyId</code>, <code>b2ShapeId</code>,
       <code>b2JointId</code>) instead of pointers, which maps cleanly to
       JS values.</p>
    <p>Helpers for attaching arbitrary JS objects to bodies/shapes live
       in <code>rayjs:ext:box2d_userdata</code> (used by the
       <code>examples/box2d/</code> demos). Subsections below cluster by
       the second word of each function (<code>b2World_*</code> →
       <code>b2World*</code>, etc.). The <code>b2Misc*</code> bucket
       collects creation/destruction/math globals that don't follow the
       <code>b2X_method</code> pattern.</p>
  `,
  tiled: `
    <p>Loader for Tiled <code>.tmj</code>/JSON tilemaps + a small render
       API. The higher-level wrapper exported as
       <code>rayjs:ext:tiled</code> is what most code imports — it handles
       tile-animation timing, GID decoding (flip/rotate bits stripped), and
       collision queries against the named tile layers.</p>
    <p>A long-form walkthrough lives at
       <code>docs/tilemap_system.md</code>. For a working example see
       <code>examples/tiled/</code>.</p>
  `,
  extras: `
    <p>Smaller utility modules — math helpers (<code>raymath</code>),
       camera updates (<code>rcamera</code>), tweening curves
       (<code>reasings</code>), the OpenGL-level wrapper
       (<code>rlgl</code>), light setup helpers
       (<code>rlights</code>), the rasterized lightmapper
       (<code>rlightmapper</code>), QuickJS's <code>std</code>/<code>os</code>
       modules, BJSON serialization (<code>bjson</code>), and the
       <code>box2d_userdata</code> helpers used by the box2d examples.</p>
    <p>These are smaller and often single-purpose — most can be skimmed
       in a minute.</p>
  `,
}

// ── CSS (mirrors docs/tilemap_system.html palette + typography) ────────────

const CSS = `
:root {
  --bg:#0f1117; --surface:#1a1d27; --surface2:#22273a; --border:#2e3450;
  --accent:#5b8dee; --accent2:#43d9ad; --accent3:#f7c948; --accent4:#f76e6e;
  --text:#d4d8f0; --text-dim:#7a80a0; --code-bg:#141720;
  --kw:#b48ef7; --type:#43d9ad; --name:#f7c948; --comment:#7a80a0;
}
* { box-sizing:border-box; margin:0; padding:0 }
html { scroll-padding-top: 16px }
body {
  background:var(--bg); color:var(--text);
  font-family:'Segoe UI', system-ui, sans-serif; font-size:14px; line-height:1.55;
}
a { color:var(--accent); text-decoration:none }
a:hover { text-decoration:underline }

.sidebar {
  position:fixed; top:0; left:0; width:280px; height:100vh;
  background:var(--surface); border-right:1px solid var(--border);
  overflow-y:auto; padding:24px 0; z-index:100;
}
.sidebar-title { font-size:11px; font-weight:700; letter-spacing:.12em;
  text-transform:uppercase; color:var(--text-dim); padding:0 20px 12px }
.sidebar-group { font-size:10px; font-weight:700; letter-spacing:.14em;
  text-transform:uppercase; color:var(--accent3); padding:14px 20px 6px;
  border-top:1px solid var(--border); margin-top:8px }
.sidebar nav a { display:block; padding:4px 20px; color:var(--text-dim); font-size:13px }
.sidebar nav a:hover { color:var(--text); background:var(--surface2); text-decoration:none }
.sidebar nav a.sub { padding-left:32px; font-size:12px }

.content { margin-left:280px; padding:32px 48px 80px; max-width:1100px }
h1 { font-size:28px; margin-bottom:4px; color:var(--text); font-weight:600 }
h2 { font-size:22px; margin:48px 0 12px; padding-top:8px; color:var(--accent3); font-weight:600;
     border-bottom:1px solid var(--border); padding-bottom:8px }
h3 { font-size:17px; margin:28px 0 8px; color:var(--accent2); font-weight:600 }
h4 { font-size:14px; margin:16px 0 6px; color:var(--text-dim); font-weight:600;
     text-transform:uppercase; letter-spacing:.06em }
p { margin:8px 0; color:var(--text) }
.tagline { color:var(--text-dim); margin-bottom:24px; font-size:13px }
.intro { background:var(--surface); border-left:3px solid var(--accent); padding:14px 18px;
  margin:12px 0 24px; border-radius:0 4px 4px 0; font-size:14px; color:var(--text) }
.intro p + p { margin-top:8px }
.empty { color:var(--text-dim); font-style:italic; padding:8px 0 }
.count { color:var(--text-dim); font-size:.85em; font-weight:400 }

pre.decl {
  background:var(--code-bg); border:1px solid var(--border);
  padding:10px 14px; margin:6px 0; border-radius:4px;
  font-family:'SF Mono', Menlo, Consolas, monospace; font-size:12.5px; line-height:1.55;
  white-space:pre-wrap; word-break:break-word; color:var(--text);
}
.kw   { color:var(--kw) }
.t    { color:var(--type) }
.t a  { color:inherit; text-decoration:none; border-bottom:1px dotted rgba(67,217,173,0.35) }
.t a:hover { color:var(--accent); border-bottom-color:var(--accent) }
.n    { color:var(--name); font-weight:600 }
.f    { color:var(--text) }
.doc  { color:var(--comment); font-style:italic }
pre.decl[id^="type-"] { scroll-margin-top: 12px }

details.cgroup { margin:6px 0 }
details.cgroup summary { cursor:pointer; padding:6px 10px; background:var(--surface);
  border:1px solid var(--border); border-radius:4px; color:var(--accent2); font-size:13px }
details.cgroup[open] summary { border-bottom-left-radius:0; border-bottom-right-radius:0 }
details.cgroup pre.decl { margin-top:0; border-top-left-radius:0; border-top-right-radius:0 }
`

// ── main ──────────────────────────────────────────────────────────────────

function main() {
  const { sections: raylibSections, funcToSection } = parseRaylibSections()
  const parsed = MODULES.map(m => ({ ...m, parsed: parseDts(join(ROOT, m.file)) }))
    .filter(m => m.parsed)

  // Build cross-module type registry so signatures can link to type defs.
  // Includes interfaces, class-style constructors, and type aliases —
  // filter alias names to valid JS identifiers (the d.ts has a couple of
  // garbled entries like `*ModelAnimPose`).
  const defined = new Set()
  const functionNames = new Set()
  for (const m of parsed) {
    for (const i of m.parsed.interfaces) defined.add(i.name)
    for (const c of m.parsed.ctors)      defined.add(c.name)
    for (const a of m.parsed.typeAliases) {
      if (/^[A-Za-z_]\w*$/.test(a.name)) defined.add(a.name)
    }
    for (const f of m.parsed.functions)  functionNames.add(f.name)
  }
  for (const t of defined) TYPE_REGISTRY.add(t)

  // Second pass: detect "opaque types" — names that appear in type
  // positions (function args, return types, field types) but have no
  // interface / type alias / constructor defined anywhere. These are
  // typically C structs/enums the native binding leaves opaque (e.g.
  // b2DynamicTree, b2BodyType). Generate stub entries so cross-links
  // resolve to *something* and the reader knows the name exists.
  const opaqueRefs = new Map() // name -> { count, firstModuleId }
  // Accept either a capital-leading type (Vector2, Color) or the Box2D
  // `b2Xxx` convention (lowercase b + digit + capital).
  const TYPE_REF_RE = /(?::|=)\s*((?:b\d+[A-Z]|[A-Z])\w*)(?:\[\])?(?=\s*[,)\]\s|;]|$)/g
  const PRIMITIVES = /^(string|number|boolean|void|any|unknown|never|null|undefined|object|bigint|symbol|Array|Promise|true|false|Date|Function|Object|RegExp|Error|Buffer|ArrayBuffer|SharedArrayBuffer|Uint8Array|Uint8ClampedArray|Uint16Array|Uint32Array|Int8Array|Int16Array|Int32Array|Float32Array|Float64Array|BigInt64Array|BigUint64Array|DataView|Map|Set|WeakMap|WeakSet|Symbol)$/
  for (const m of parsed) {
    // Walk every signature occurrence and count it — multiple hits in the
    // same function (e.g. b2DynamicTree appears 19× across its API) inform
    // the rendered "referenced by N signatures" caption.
    const tally = (name) => {
      if (defined.has(name) || functionNames.has(name)) return
      if (PRIMITIVES.test(name)) return
      const ex = opaqueRefs.get(name)
      if (ex) ex.count++
      else opaqueRefs.set(name, { count: 1, firstModuleId: m.id })
    }
    for (const fn of m.parsed.functions) {
      const text = `${fn.args} ): ${fn.ret}`
      for (const mt of text.matchAll(TYPE_REF_RE)) tally(mt[1])
    }
    for (const i of m.parsed.interfaces) {
      for (const f of i.fields) {
        for (const mt of (f.type || "").matchAll(/\b((?:b\d+[A-Z]|[A-Z])\w*)\b/g)) tally(mt[1])
      }
    }
    for (const c of m.parsed.ctors) {
      for (const mt of (`( ${c.ctorArgs} )`).matchAll(TYPE_REF_RE)) tally(mt[1])
    }
  }
  // Attach opaqueTypes per module + register globally.
  for (const m of parsed) m.parsed.opaqueTypes = []
  for (const [name, info] of opaqueRefs) {
    const m = parsed.find(p => p.id === info.firstModuleId)
    if (m) m.parsed.opaqueTypes.push({ name, refCount: info.count })
    TYPE_REGISTRY.add(name)
  }
  buildTypeLinkRegex()

  const counts = parsed.map(m => ({
    module: m.module, file: m.file,
    interfaces: m.parsed.interfaces.length,
    constants: m.parsed.constants.length,
    functions: m.parsed.functions.length,
  }))
  for (const c of counts) {
    console.log(`${c.module.padEnd(40)}  ${c.functions} fns, ${c.interfaces} types, ${c.constants} consts`)
  }

  const raylib = parsed.find(m => m.id === "raylib").parsed
  const raygui = parsed.find(m => m.id === "raygui").parsed
  const box2d  = parsed.find(m => m.id === "box2d").parsed
  const tiledLib = parsed.find(m => m.id === "tiled")?.parsed
  const tiledNat = parsed.find(m => m.id === "tiled-native")?.parsed

  const raylibBuckets = bucketRaylibFunctions(raylib.functions, raylibSections, funcToSection)
  const box2dBuckets  = bucketBox2dFunctions(box2d.functions)

  // Sidebar nav
  const navItems = [
    [`#overview`, "Overview"],
    [`#raylib`, `rayjs:raylib (${raylib.functions.length})`],
    ...raylibBuckets.map(b => [`#raylib-${slug(b.section)}`, `${b.section} (${b.items.length})`, "sub"]),
    [`#raygui`, `rayjs:raygui (${raygui.functions.length})`],
    [`#box2d`, `rayjs:box2d (${box2d.functions.length})`],
    ...box2dBuckets.map(b => [`#box2d-${slug(b.section)}`, `b2${b.section}* (${b.items.length})`, "sub"]),
    [`#tiled`, `rayjs:ext:tiled (${(tiledLib?.functions?.length || 0) + (tiledNat?.functions?.length || 0)})`],
    [`#extras`, `other modules`],
  ]
  const otherIds = ["raymath","rcamera","reasings","rlgl","rlights","rlightmapper","bjson","ext-box2d-ud","std","os"]
  for (const id of otherIds) {
    const m = parsed.find(x => x.id === id)
    if (m) navItems.push([`#${m.id}`, `${m.module} (${m.parsed.functions.length})`, "sub"])
  }

  const nav = navItems.map(([href, label, klass]) =>
    `<a href="${href}" class="${klass || ""}">${esc(label)}</a>`
  ).join("\n")

  // Body
  const sections = []

  sections.push(`<section id="overview">
  <h1>rayjs Cheatsheet</h1>
  <p class="tagline">Auto-generated API reference for rayjs — QuickJS bindings for raylib, raygui, Box2D, and friends.</p>
  <div class="intro">
    <!-- INTRO:overview -->
  </div>
</section>`)

  // rayjs:raylib
  sections.push(`<section id="raylib">
  <h2>rayjs:raylib <span class="count">(${raylib.functions.length} functions, ${raylib.interfaces.length} types, ${raylib.constants.length} constants)</span></h2>
  <div class="intro"><!-- INTRO:raylib --></div>
  <h3>Types</h3>
  ${renderInterfaces(raylib.interfaces, raylib.ctors, raylib.typeAliases, raylib.opaqueTypes)}
  <h3>Constants</h3>
  ${renderConstants(raylib.constants)}
  ${raylibBuckets.map(b => `<h3 id="raylib-${slug(b.section)}">${esc(b.section)} <span class="count">(${b.items.length})</span></h3>
  ${renderFunctions(b.items)}`).join("\n")}
</section>`)

  // rayjs:raygui
  sections.push(`<section id="raygui">
  <h2>rayjs:raygui <span class="count">(${raygui.functions.length} functions)</span></h2>
  <div class="intro"><!-- INTRO:raygui --></div>
  ${raygui.interfaces.length ? `<h3>Types</h3>${renderInterfaces(raygui.interfaces, raygui.ctors, raygui.typeAliases, raygui.opaqueTypes)}` : ""}
  ${raygui.constants.length ? `<h3>Constants</h3>${renderConstants(raygui.constants)}` : ""}
  <h3>Functions</h3>
  ${renderFunctions(raygui.functions)}
</section>`)

  // rayjs:box2d
  sections.push(`<section id="box2d">
  <h2>rayjs:box2d <span class="count">(${box2d.functions.length} functions, ${box2d.interfaces.length} types)</span></h2>
  <div class="intro"><!-- INTRO:box2d --></div>
  ${box2d.interfaces.length ? `<h3>Types</h3>${renderInterfaces(box2d.interfaces, box2d.ctors, box2d.typeAliases, box2d.opaqueTypes)}` : ""}
  ${box2dBuckets.map(b => `<h3 id="box2d-${slug(b.section)}">b2${esc(b.section)}* <span class="count">(${b.items.length})</span></h3>
  ${renderFunctions(b.items)}`).join("\n")}
</section>`)

  // rayjs:ext:tiled
  sections.push(`<section id="tiled">
  <h2>rayjs:ext:tiled <span class="count">(lib wrapper)</span></h2>
  <div class="intro"><!-- INTRO:tiled --></div>
  ${tiledLib ? `<h3>Library API <span class="count">(lib/tiled.d.ts)</span></h3>
  ${tiledLib.interfaces.length ? `<h4>Types</h4>${renderInterfaces(tiledLib.interfaces, tiledLib.ctors, tiledLib.typeAliases, tiledLib.opaqueTypes)}` : ""}
  ${renderFunctions(tiledLib.functions)}` : ""}
  ${tiledNat ? `<h3>Native bindings <span class="count">(bindings/typings/lib.js_ext_tiled.d.ts)</span></h3>
  ${renderFunctions(tiledNat.functions)}` : ""}
</section>`)

  // other modules
  sections.push(`<section id="extras">
  <h2>Other modules <span class="count">(utility &amp; ext)</span></h2>
  <div class="intro"><!-- INTRO:extras --></div>
  ${otherIds.map(id => {
    const m = parsed.find(x => x.id === id)
    if (!m || (!m.parsed.functions.length && !m.parsed.interfaces.length && !m.parsed.constants.length)) return ""
    const p = m.parsed
    return `<h3 id="${m.id}">${esc(m.module)} <span class="count">(${p.functions.length} fns)</span></h3>
    ${p.interfaces.length ? `<h4>Types</h4>${renderInterfaces(p.interfaces, p.ctors, p.typeAliases, p.opaqueTypes)}` : ""}
    ${p.constants.length ? `<h4>Constants</h4>${renderConstants(p.constants)}` : ""}
    ${p.functions.length ? renderFunctions(p.functions) : ""}`
  }).join("\n")}
</section>`)

  const totalFunctions = parsed.reduce((n, m) => n + m.parsed.functions.length, 0)
  const html = `<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>rayjs Cheatsheet</title>
<style>${CSS}</style>
</head>
<body>
<aside class="sidebar">
  <div class="sidebar-title">rayjs cheatsheet</div>
  <nav>${nav}</nav>
</aside>
<main class="content">
${sections.join("\n\n")}
<footer style="margin-top:64px;padding-top:24px;border-top:1px solid var(--border);color:var(--text-dim);font-size:12px;">
  ${totalFunctions} functions documented across ${parsed.length} modules.
  Auto-generated by <code>bindings/gen_cheatsheet.js</code>.
</footer>
</main>
</body>
</html>
`
  // Substitute editorial intros into their placeholder comments.
  const withIntros = html.replace(/<!--\s*INTRO:(\w+)\s*-->/g, (m, key) =>
    INTROS[key] ? INTROS[key].trim() : m
  )

  const outPath = join(ROOT, "docs/cheatsheet.html")
  writeFileSync(outPath, withIntros, "utf8")
  console.log(`\nwrote ${outPath} (${(html.length / 1024).toFixed(1)} KB)`)
  console.log(`total: ${totalFunctions} functions across ${parsed.length} modules`)
}

main()
