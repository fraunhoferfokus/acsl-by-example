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

## What a directory's output looks like

`banner.mk` holds the only `printf` that spells a directory heading, and both
recursion loops -- `dispatch.mk` at the top level, `internal.mk` in `Stack/` --
go through it. The convention it fixes is: **a blank line always precedes a
heading, and nothing follows it.**

Leading rather than trailing is what makes the nesting come out right. `Stack/`
is an internal directory and a leaf at once, so `check` there runs
`check-local` first and then recurses; a trailing separator would have to be
emitted by `check-local`, and every `*-local` recipe would need one. With the
separator in front of the heading, each recursion brings its own, and no
`*-local` recipe prints spacing at all. That is why `check-local` and
`reports-local` no longer end in `printf "\n"`.

Headings come from the dispatch loop only, so a target run inside a directory
(`cd MinMax && make results`) prints its output with no heading -- you already
know where you are.

`results-local` and `reports-local` print the same table, from
`print_report_header.py` and `print_example_summary.py`. `results` covers
`EXAMPLES`, because that is what `Results/` holds; `reports` covers `VERIFIED`,
so it also shows the `verify.list` sources. `results` used to have no header at
all: its rows were a side effect of the `$(RESULT_DIR)/%.json` copy rule, so a
directory showed whichever examples happened to be out of date, and a directory
already current showed nothing under its heading.

The `## text` help lives in `leaf.mk`, `internal.mk` and the top-level
`Makefile` — the per-directory front-ends — rather than next to each recipe.
Only one front-end is ever included, so nothing is listed twice and the section
order is controlled in one place. A directory makefile is read *before* them,
so documenting a target there would print it above the first section heading —
keep directory-local targets internal and reach them from a `-local` rule.

## `examples.list` and `verify.list`

`examples.list` drives everything: the library, the tests, WP, and the
`Results/*.json` the book's tables are generated from.

`verify.list` is optional and names sources that are **verified but are not
examples** — WP runs on them, nothing else does. `EXAMPLES` stays the list of
real examples, `VERIFIED` is the union, and only `VERIFIED` reaches the WP
aggregates. `Results/` deliberately stays on `EXAMPLES`, because
`generate-tables.py` walks `examples.list` and would never read the extra file.

Being in neither list is not the same as being ignored: the WP pattern rules
are per-file, so `make foo.wp` has always worked for any `foo.c`. What did not
work is *keeping* the output — `.SECONDARY` protects only what the aggregates
name, so make deleted `foo.wp/proof-results.json` again as an intermediate.

`Mutating/verify.list` is the only instance. It holds the `rewrite_array` pair
from `unchanged.tex`, which cannot be ordinary examples: both files define
`rewrite_array`, so they would collide in one library. Unlike `examples.list`
it is read through the shell, because it carries comments and `$(file <...)`
would hand their words to make — a `#` arriving from a function expansion does
not start a comment.

Note that one of the two is *expected to fail*: see `Scripts/check_goals.py`
and the `check-rewrite-array` rule in `Mutating/Makefile`, which `results-local`
depends on.

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

## Contradiction smoke tests

`make smoke` runs Frama-C/WP's best-effort checks for inconsistent contracts,
assumptions and loop invariants, plus its dead-code reachability checks. It runs
on the same `VERIFIED` set as ordinary WP verification, including entries from
`verify.list`, and recurses in the same way as `make results`.

Smoke goals have deliberately inverted verdicts: proving one means that the
assumptions imply `\false` and the specification is inconsistent. The
`Scripts/check_smoke.py` validator reads WP's JSON reports, fails on such a
goal, and also fails when a smoke goal has no external-prover attempt. A source
with no applicable precondition, behavior, loop or reachability smoke check is
reported explicitly and accepted, provided WP emitted ordinary goals. A
successful run therefore means only **no contradiction found**; smoke testing
cannot prove that a specification is consistent.

Smoke artifacts use the `foo.smoke.wp/` directory, separate from `foo.wp/`, so
the two modes never overwrite each other's reports. They are covered by
`clean-proofs` because their names still end in `.wp`. The default smoke timeout
is 10 seconds and can be changed per invocation:

```make
make SMOKE_TIMEOUT=20 smoke
```

Smoke is the most expensive target in the tree -- it runs on every `VERIFIED`
source, once per automatic prover, and with `-wp-cache none`, so nothing is ever
replayed. It therefore has its own parallelism knob, `SMOKE_PROCESSES`, which
becomes `-wp-par` for each run and defaults to the host's core count minus one
(`getconf _NPROCESSORS_ONLN`, clamped at 1), leaving one core for the rest of
the machine:

```make
make SMOKE_PROCESSES=4 smoke
```

`WP_PROCESSES` stays at 1 for ordinary verification on purpose: the times in
`Results/*.json` feed the book's tables, and prover contention would make them
depend on the machine that produced them. Smoke times are read by nobody.

The caveat is the inverted verdict. A smoke goal that fails to prove is a pass,
so contention that pushes a goal past `-wp-smoke-timeout` turns a *found*
contradiction into a silent success. Cores-minus-one is chosen to avoid
oversubscribing the machine; if a smoke run ever looks suspiciously clean,
re-run it with `SMOKE_PROCESSES=1`, and possibly a larger `SMOKE_TIMEOUT`,
before believing it.

`-wp-par` is deliberately absent from the smoke `settings.stamp`: it schedules
the work rather than deciding what is proved, so changing the knob -- or moving
to a host with a different core count -- does not by itself force a re-run.

The automatic provers are inherited from `PROVERS`, except for Coq: smoke goals
are expected not to prove and have no interactive proof scripts. Frama-C 33
applies only one prover to smoke goals, so the rule performs an isolated run for
each selected automatic prover and merges their reports before validation.

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
