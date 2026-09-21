# AGENTS.md — ktccpp

Canonical, tool-neutral instructions for this repository.

**Manifest:** [`capsize.json`](capsize.json) · **Standards:** CAPSIZE 1.x

## What this repository is

`ktccpp` is a small C++23 command-line implementation of a keyword
transposition cipher. CMake is the build authority and `src/main.cpp` is the
interactive entry point.

## Hard rules

1. Preserve the C++23/CMake build contract and the GPL-3.0-only license.
2. Treat `build/` and `cmake-build-*` as generated output; do not commit
   binaries or build trees.
3. Review changes to cipher ordering, key handling, and decrypt/encrypt
   symmetry against the existing interactive behavior.
4. The repository currently has no automated test suite. Its public CI
   workflow runs on GitHub-hosted Actions; do not report coverage or other CI
   results that were not actually run.

## Task interface

Use `just` for the canonical local tasks:

```text
just setup    # configure a Debug CMake tree
just build   # compile ktccpp
just test    # report the current lack of automated tests
just run     # run the interactive binary
just ci      # configure, build, lint, and record test status
```

No separate C++ formatter or static type checker is configured, so those
recipes report the gap explicitly. The compiler build is the current warning
and compile gate.
