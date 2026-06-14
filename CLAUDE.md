# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Plugin Priority

Prefer the configured MCP servers and plugins over their native equivalents. They provide compressed context, current docs, and disciplined workflows. Reach for them first; fall back to native tools only when the plugin tool is unavailable or genuinely wrong for the task.

### lean-ctx — file/shell/search (ALWAYS prefer over native)

| Use this | Instead of | Why |
|---|---|---|
| `ctx_read(path, mode)` | `Read` / `cat` | Cached; ~13 tok re-reads; 10 modes: `full | map | signatures | diff | task | reference | aggressive | entropy | lines:N-M` |
| `ctx_shell(cmd)` | `Bash` (inspection) | 95+ compression patterns. Use `raw=true` only when output must be uncompressed. |
| `ctx_search(pattern, path)` | `Grep` / `rg` | Compact results |
| `ctx_tree(path, depth)` | `ls` / `find` | Compact directory map |

Rules:

- Editing the file? `full` first, `diff` for re-reads. NEVER use `full` for files you won't edit — use `map` or `signatures`.
- Edits stay native (`Edit`, `Write`). Use `ctx_edit(path, old, new)` only when native Edit is unavailable. NEVER loop on Edit failures — switch to `ctx_edit` immediately.
- Call `ctx_overview(task)` at session start. Use `ctx_compress` when context grows large.
- Mutating shell ops (cargo build, git push, etc.) can still go through `ctx_shell` — compression applies to output, not side effects.

### context7 — current crate docs (use over WebSearch)

Invoke `mcp__plugin_context7_context7__resolve-library-id` then `query-docs` for any Rust crate API, config, version migration, or CLI tool: `nalgebra`, `ndarray`, `ode_solvers`, `tch`, `candle`, `burn`, `serde`, `clap`, `tokio`, etc. Use even when you think you know the answer — training data lags real releases.

Skip for: refactoring, debugging business logic, general Rust language concepts, code review.

### superpowers — process discipline (invoke BEFORE acting)

| Skill | When |
|---|---|
| `brainstorming` | Before any creative work — new modules, solver designs, API shape |
| `writing-plans` | Multi-step task before touching code |
| `executing-plans` | Running a written plan in a separate session |
| `test-driven-development` | Implementing any feature or bugfix |
| `systematic-debugging` | Any bug, test failure, or unexpected numerical result |
| `verification-before-completion` | Before claiming work done — evidence before assertions |
| `subagent-driven-development` | Independent tasks dispatched in the same session |
| `dispatching-parallel-agents` | 2+ truly independent tasks with no shared state |

Process skills come first, implementation skills second.

### sentrux — structural health

`sentrux:scan` gives A–F grades across 14 dimensions (coupling, cycles, cohesion, dead code, test coverage). Run before and after non-trivial refactors; use `test_gaps` when adding tests.

### github MCP — repo ops

Prefer `mcp__plugin_github_github__*` tools over the `gh` CLI for issues, PRs, reviews, branches, commits, code search. They return structured data and avoid shell parsing.

## Project

**`geom-ode`** — Riemannian-manifold-constrained Neural ODE solver. Compiled as a single Rust binary.

Current state: bootstrap. Only `README.md`, `LICENSE`, `.gitignore`, and an empty `crates/` workspace directory exist. No `Cargo.toml` yet.

### Conventions implied by `.gitignore`

- Cargo workspace layout (`crates/<name>`)
- `cargo mutants` is in scope — mutation testing output is already ignored

### Commands (once `Cargo.toml` exists)

```
cargo build [--release]
cargo test                       # all
cargo test -p <crate> <name>     # single test in a workspace crate
cargo clippy --workspace --all-targets -- -D warnings
cargo fmt --all
cargo mutants                    # mutation testing
cargo run --bin geom-ode -- <args>
```
