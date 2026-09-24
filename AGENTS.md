# Agent Instructions — Shared Scene Sample (Unreal)

The Shared Scene Sample is an Unreal Meta Quest reference app that demonstrates a shared mixed-reality experience using Shared Spatial Anchors, Scene, and Passthrough. It is built almost entirely in Blueprint and reuses pieces from the Shared Spatial Anchors and Scene samples.

## Source-of-truth files (read these first, do not duplicate their contents in this file)

For setup, build steps, SDK versions, and project layout, read:

- `README.md` — official setup, prerequisites, editor paths, and Blueprint architecture overview
- `SharedSceneSample.uproject` — engine association and enabled plugins (`OculusXR`, `OculusPlatform`)
- `Config/DefaultEngine.ini` — contains the `[OnlineSubsystemOculus] MobileAppId` and the Android `PackageName` you must edit for your own app
- `LICENSE` — license terms (Meta License covers most of the repo; MIT only for clearly marked files)

## Quest / Horizon-specific notes

- The Meta Quest developer-dashboard setup is **mandatory** — anchor sharing will not work without (1) an app created on the dashboard, (2) **User ID** and **User Profile** platform features added in Data Use Checkup, and (3) `MobileAppId` + `PackageName` in `DefaultEngine.ini` set to match your app. Walk through the README prerequisites before assuming code bugs.
- Do **not** commit your local `MobileAppId` or production `PackageName` back to this repo. Treat those `DefaultEngine.ini` keys as per-developer values.
- `BP_OculusSceneActor` inherits from the engine's `OculusSceneActor` — do not swap its base class; host-side Scene API access depends on it.
- Host and clients must share a LAN; the lobby is LAN-only. Hosting/joining across the internet is out of scope for this sample.
- The Meta License (not MIT) covers most of this repo. Preserve license headers when refactoring.

# Meta Quest tooling

This is a Meta Quest / Horizon OS sample. The bespoke intro above is the source of truth for what this project is and how it's built — use it (and the files it points at) instead of restating facts from memory.

When the user asks anything about Quest device behavior, build / deploy / debug / capture flows, on-device performance, or Horizon OS APIs, reach for these tools instead of generic Unreal answers:

- **`hzdb`** — Quest-aware ADB wrapper (device list, install / launch / stop, logs, screenshots, Perfetto traces, on-device docs search). Already wired up as an MCP server via `.mcp.json`, `.vscode/mcp.json`, and `.cursor/mcp.json`. Also runnable directly: `npx -y @meta-quest/hzdb <subcommand>`.
- **Meta Quest Agentic Tools** — the full skill set, including Unreal-specific skills: <https://github.com/meta-quest/agentic-tools>. Install per your client (Claude Code: `/plugin install meta-vr@meta-quest`; Gemini CLI: `gemini extensions install https://github.com/meta-quest/agentic-tools`; Cursor / VS Code: install the **Meta Horizon** extension from the Marketplace).

A few behavior expectations:

- **Read this repo's files first.** Before answering anything project-specific, read `README.md` and whichever source-of-truth files the intro above points at. Don't restate their contents in chat — quote or link instead.
- **Use `hzdb` for device-side work.** Anything that touches an attached Quest (install, launch, logs, screenshot, capture, manifest inspection) goes through `hzdb`, not raw `adb`.
- **Check live Horizon OS docs before answering API questions.** `hzdb docs search "..."` queries the live docs; training data on Horizon OS APIs goes stale fast.
- **Don't fabricate SDK / engine versions.** If a version isn't visible in this repo's files, say so rather than guessing.
