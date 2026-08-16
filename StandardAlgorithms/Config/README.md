# Config makefiles

For the list of targets, run `make help` in any directory. It prints what *that*
directory actually offers, collected from the `## text` comments on the rules,
so it cannot drift from the makefiles the way a table here would.

This file covers only what `make help` has no room for.

## How the wiring works

Every high-level target splits into `-local` (this directory) and `-subdirs`
(recurse). `examples.mk` chooses automatically: a directory containing a
`subdirs.list` gets `internal.mk` (local + recurse), otherwise `leaf.mk`
(local only). `Stack/` has both a `subdirs.list` and an `examples.list`, so its
aggregates cover its own artifacts *and* its subdirectories.

`clean` and `clean-local` are **double-colon** rules: `libtests-local.mk`,
`verify-local.mk` and `format-local.mk` each contribute one, and all of them
run. The individual pieces are also reachable on their own as `clean-tests`,
`clean-proofs` and `clean-format`, so proofs can be discarded without forcing a
C rebuild.

The `## text` help lives in `leaf.mk`, `internal.mk` and the top-level
`Makefile` — the per-directory front-ends — rather than next to each recipe.
Only one front-end is ever included, so nothing is listed twice and the section
order is controlled in one place.

## The WP proof cache

**Nothing in the clean chain removes it.** `SESSION_DIR` appears in `central.mk`
and `verify-local.mk` only as the `-wp-session` flag. Deleting `*.wp` therefore
does **not** force a real re-proof: the cache still replays, and the times in
`proof-results.json` are the stored ones rather than what just happened.

Two ways to get honest numbers:

- `make WP_CACHE=rebuild <example>.wp` — run the provers for real and refresh
  the cache, without disturbing anything else. `WP_CACHE` also accepts `none`,
  `cleanup` (update plus garbage collection of stale entries) and `replay`
  (use the cache but never write to it).
- `make clean-cache` — delete the whole cache. This is **global**: the cache is
  1501 flat content-hashed files with no per-directory structure, so it cannot
  be scoped. It runs from any directory and prints what it is about to remove.

`clean-cache` is deliberately excluded from `clean-everything` and from
`DISPATCH_TARGETS`: every other clean target removes artifacts the current
directory owns, and recursing a global target would wipe the cache once per
subdirectory.

`clean-slate` is the one target that combines the two, together with
`clean-results`: `clean-everything` + all of `Results/*.json` + the cache. Two
of its three parts are global, so it always means the whole project — run in
`Heap/` it resets everything, not just `Heap/`. Outside the top level it is a
one-line rule that re-invokes make in `$(TOP_DIR)`, which is why it must never
join `DISPATCH_TARGETS`: the top level would forward it into every
subdirectory, and each of those would call straight back up.

`WP_CACHE` is applied only when it differs from `update`:

```make
WP_CACHE ?= update
ifneq ($(WP_CACHE),update)
  WP_BASE_FLAGS += -wp-cache $(WP_CACHE)
endif
```

`WP_BASE_FLAGS` feeds `wp-c-flags` in each `settings.stamp`, and a changed stamp
forces re-verification. Adding the flag unconditionally would therefore
invalidate all 78 examples on the next run. Guarded, a default build produces a
byte-identical stamp, and only an explicit non-default mode forces the affected
example to run again — which is exactly what it should do.

## `make <TAB>` and the shape of the include chain

Shell completion does not ask make for its targets. zsh's `_make` reads the
makefile *text*: it collects lines whose first character is alphanumeric and
that contain a `:` (so `.PHONY` lines and `%` pattern rules are invisible to
it), and it follows an `include` only when the directive starts in column 0
*and* the path expands textually — it understands `$(NAME)` and nothing more.
`ifneq`/`else` it ignores altogether.

Two things in this directory exist to satisfy that parser:

- `CONFIG_DIR` is spelled relative (`../Config`, `../../Config`) in every
  directory Makefile, while `TOP_DIR` stays absolute. An earlier
  `CONFIG_DIR := $(TOP_DIR)/Config` expanded to `$(abspath ..)/Config`, which
  the completer cannot resolve, so it followed nothing and offered plain
  filenames instead of targets. `CONFIG_DIR` is only ever an include prefix,
  and recursion always uses `$(MAKE) -C`, so relative is safe.
- In `examples.mk`, `include $(CONFIG_DIR)/leaf.mk` sits in column 0 and every
  other include is indented. `leaf.mk` is the front-end carrying the documented
  targets, so completion offers exactly what `make help` prints — the same list
  in every directory, `Stack/` included (it runs `internal.mk`, which declares
  the same names). The indented includes keep `lib-local`, `wp-force`,
  `$(LIB_NAME)` and the stamp files out of the list. make ignores the
  indentation.

**Do not enable `zstyle ':completion:*:*:*make*:*:targets' call-command true`.**
It looks like the tidier fix — zsh then asks make instead of guessing — but it
runs `make -nsp --always-make`, and GNU make remakes included makefiles even
under `-n`. Every TAB would rebuild all `*.wp/dependencies.mk` in the current
directory; those are prerequisites of `%.wp/proof-results.json`, so one keypress
would silently schedule a full re-verification.

## Two traps

**Local `*.json` and `Results/*.json` are different things.** `clean-proofs`
deletes `*.json` in the *current* directory (per-example summaries from
`wp_summary.py`); `clean-results` deletes the durable `Results/<example>.json`
that feed the book's tables. Only the latter forces those tables to be
regenerated.

**A `.PHONY` name without a rule succeeds silently.** `verify-clean`,
`verify-clean-sessions` and `distclean` were all listed as phony while having no
recipe, so invoking them exited 0 having done nothing. They have been removed;
keep `.PHONY` lists limited to names that really have a rule, so a typo fails
loudly with `No rule to make target`.

`distclean` is gone — `clean-everything` replaces it, and does more (it also
drops the library and this directory's results); `clean-slate` goes further
still and is the closest thing to what a `distclean` would mean here.
`Tutorial/` is a separate build tree and keeps its own `distclean`, which
`CLAUDE.md` documents.

## Small things

`$(RM)` is never defined in `Config/`; it comes from GNU make's builtin
`rm -f`, which is why traces show `rm -f -rf` and `rm -f -f`.

`help.mk` uses POSIX awk only. macOS ships BSD awk, which lacks gawk's
three-argument `match()` — `central.mk` already works around similar
BSD/GNU differences with `grealpath` and `gsed`.
