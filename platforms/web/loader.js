// rayjs web loader
//
// Bootstraps the rayjs wasm runtime in the browser. Runs BEFORE rayjs.js
// (emscripten's glue) loads, so it can define the global `Module` object
// with hooks emscripten checks during startup.
//
// Lifecycle:
//   1. We define Module with `noInitialRun: true` so the runtime is
//      initialised but main() is NOT called automatically.
//   2. preRun fetches game/manifest.json, then each listed asset, and
//      writes them into MEMFS at their declared paths.
//   3. preRun also sets Module.arguments = [manifest.entrypoint], which
//      becomes argv[1] when main() runs.
//   4. The user clicks the "start" button (required so the browser
//      unlocks Web Audio). callMain() then invokes the wasm main(),
//      which reads argv, loads the entrypoint JS via rayjs's existing
//      module loader, and the game's synchronous main loop takes over.
//
// Game selection: ?game=<name> URL param picks which manifest to load
// (default "dino"). Each game lives at games/<name>/ on the HTTP server.
//
// Manifest schema (games/<name>/manifest.json):
//   {
//     "entrypoint": "game/main.js",
//     "files": ["game/main.js", "game/assets/foo.png", ...]
//   }
// `entrypoint` and `files` are MEMFS paths (no `games/<name>/` prefix);
// they're fetched from games/<name>/<path> and written into MEMFS at /<path>
// so existing fopen()/LoadTexture() calls Just Work and a game source
// is unchanged whether it's loaded from dino/ or platformer/.

(() => {
    const $status = document.getElementById("status");
    const $start = document.getElementById("start");
    const $canvas = document.getElementById("canvas");

    const setStatus = (msg) => { if ($status) $status.textContent = msg; };
    const fail = (msg, err) => {
        console.error("rayjs loader:", msg, err);
        setStatus("Error: " + msg + (err ? " — see console" : ""));
    };

    // Pick the game from ?game=<name> (default "dino"). Each game lives
    // under games/<name>/ on the server; the manifest's `files` are
    // MEMFS-relative paths, which we fetch from games/<name>/<path> and
    // write into MEMFS at /<path>.
    const params = new URLSearchParams(window.location.search);
    const gameName = params.get("game") || "dino";
    const gameBase = `games/${gameName}/`;

    async function fetchGame() {
        setStatus(`Fetching ${gameName} manifest…`);
        const res = await fetch(gameBase + "manifest.json");
        if (!res.ok) throw new Error(`manifest fetch ${res.status} for ${gameName}`);
        const manifest = await res.json();
        if (!manifest.entrypoint) throw new Error("manifest missing 'entrypoint'");
        const files = manifest.files || [manifest.entrypoint];
        setStatus(`Fetching ${files.length} file(s)…`);
        const blobs = await Promise.all(files.map(async (path) => {
            const r = await fetch(gameBase + path);
            if (!r.ok) throw new Error(`fetch ${r.status} for ${gameBase}${path}`);
            return { path, buf: new Uint8Array(await r.arrayBuffer()) };
        }));
        return { manifest, blobs };
    }

    window.Module = {
        canvas: $canvas,
        noInitialRun: true,         // we call main() manually after click
        print:    (text) => console.log(text),
        printErr: (text) => console.warn(text),

        preRun: [async () => {
            // Tell emscripten to wait until we've finished fetching files
            // before running anything else (including dependencies, atinit
            // ctors, and the eventual callMain).
            Module.addRunDependency("rayjs-loader");
            try {
                const { manifest, blobs } = await fetchGame();
                for (const { path, buf } of blobs) {
                    const dir = path.substring(0, path.lastIndexOf("/"));
                    if (dir) FS.createPath("/", dir, true, true);
                    FS.writeFile("/" + path, buf);
                }
                Module.arguments = [manifest.entrypoint];
                setStatus("Ready. Click to start.");
                if ($start) $start.hidden = false;
            } catch (err) {
                fail("failed to fetch game", err);
            } finally {
                Module.removeRunDependency("rayjs-loader");
            }
        }],

        onRuntimeInitialized: () => {
            // preRun is done before this fires (because of addRunDependency),
            // so Module.arguments is set. Wait for the user click, then run.
            const start = () => {
                if ($start) $start.hidden = true;
                setStatus("");
                $canvas.focus();
                try { Module.callMain(Module.arguments); }
                catch (err) { fail("wasm main() threw", err); }
            };
            if ($start) $start.addEventListener("click", start, { once: true });
            else start();
        },
    };
})();
