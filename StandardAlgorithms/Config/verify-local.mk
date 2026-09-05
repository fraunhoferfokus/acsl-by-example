#
# verify-local.mk --- file-oriented Frama-C/WP rules.
# Include alongside libtests-local.mk / format-local.mk in leaf directories.

# Tools (overrideable, but typically fixed).
FR    ?= frama-c
FRGUI ?= ivette
WHY3  ?= why3

# Required configuration (provided by central.mk / the including Makefile).
ifndef SESSION_DIR
  $(error SESSION_DIR is not set (define it before including verify.mk))
endif
ifndef SCRIPT_DIR
  $(error SCRIPT_DIR is not set (define it before including verify.mk))
endif
ifndef RESULT_DIR
  $(error RESULT_DIR is not set (define it before including verify.mk))
endif

# Tuning knobs.
WP_TIMEOUT    ?= 2
SMOKE_TIMEOUT ?= 10

# Prover processes an ordinary WP run may use. Deliberately one: the times in
# Results/*.json feed the book's tables, and contention would make them depend
# on the machine. Smoke runs have their own knob below.
WP_PROCESSES  ?= 1

# Cores this host offers, minus one, so the machine stays usable during a run.
# getconf is portable across macOS and Linux (the GNU-tool workarounds in
# central.mk are not needed here); the clamp covers a single-core host and any
# environment where the query fails. Computed once with ':=', so the '?=' below
# expands to a plain value rather than re-running the shell at every reference.
SMOKE_PROCESSES_DEFAULT := $(shell n=$$(getconf _NPROCESSORS_ONLN 2>/dev/null \
                             || echo 1); \
                             test "$$n" -gt 1 && echo $$((n - 1)) || echo 1)
SMOKE_PROCESSES ?= $(SMOKE_PROCESSES_DEFAULT)

# WP mode: batch (default), edit, command, ...
WP_INTERACTIVE ?= batch

# RTE configuration (override per-directory or per-file if needed).
WP_RTE_FLAGS ?= -warn-unsigned-overflow -warn-unsigned-downcast

# Prover selection (empty means: generate obligations only).
PROVERS ?= alt-ergo Z3 CVC5 Coq
WP_PROVER_FLAGS := $(strip $(foreach p,$(PROVERS),-wp-prover $(p)))

# Smoke tests are deliberately automatic. Interactive Coq proofs have no
# useful script for goals that are expected not to prove.
SMOKE_PROVERS := $(filter-out Coq coq,$(PROVERS))
WP_SMOKE_PROVER_FLAGS := $(strip $(foreach p,$(SMOKE_PROVERS),-wp-prover $(p)))

# Common Frama-C flags.
BASE_FLAGS := -pp-annot
BASE_FLAGS += -no-unicode

WP_BASE_FLAGS = $(BASE_FLAGS)
WP_BASE_FLAGS += -wp
WP_BASE_FLAGS += -wp-rte $(WP_RTE_FLAGS)

# WP's Typed model has no \aligned and no \valid_function, so it drops the RTE
# guards for unaligned pointers and for calls through function pointers, and
# warns once per run that it did. No example casts a pointer or calls through
# one, so those guards were never generated; these two options stop RTE from
# asking for them, and the warnings with them.
#
# Deliberately not part of WP_RTE_FLAGS: that variable is the per-directory
# override point, and Mutating/Makefile replaces it wholesale for random_number,
# which would silently drop both options there.
WP_BASE_FLAGS += -no-warn-unaligned-pointer
WP_BASE_FLAGS += -rte-no-pointer-call
WP_BASE_FLAGS += -wp-model Typed
WP_BASE_FLAGS += -wp-session $(SESSION_DIR)
WP_BASE_FLAGS += -wp-interactive=$(WP_INTERACTIVE)
WP_BASE_FLAGS += -wp-split

# WP proof cache mode, overridable per invocation:
#   update  (default) use the cache, add new results to it
#   rebuild           always run the provers, then update the cache
#   none              ignore the cache entirely
#   cleanup           update mode, plus garbage collection of stale entries
#   replay            update mode, but never write to the cache
#
# The guard matters: WP_BASE_FLAGS feeds wp-c-flags in settings.stamp, so
# adding this flag unconditionally would change every stamp in the project and
# force a full re-verification. Only a non-default mode alters the stamp --
# which is exactly what should force the affected example to run again.
WP_CACHE ?= update
ifneq ($(WP_CACHE),update)
  WP_BASE_FLAGS += -wp-cache $(WP_CACHE)
endif

# Preprocessor flags passed through to Frama-C.
WP_CPP_FLAGS ?= $(CPPFLAGS)
WP_C_FLAGS   = -cpp-extra-args="$(WP_CPP_FLAGS)" $(WP_BASE_FLAGS)

# Keep smoke results independent of normal proof reports and do not let a
# cached result stand in for an actual contradiction search.
WP_SMOKE_C_FLAGS = $(WP_C_FLAGS) -wp-smoke-tests \
                   -wp-smoke-timeout $(SMOKE_TIMEOUT) -wp-cache none

# Time/parallelism.
WP_TIME_FLAGS ?= -wp-timeout $(WP_TIMEOUT)
WP_TIME_FLAGS += -wp-par $(WP_PROCESSES)

# Smoke runs get their own parallelism, from SMOKE_PROCESSES. -wp-par is a
# scheduling knob rather than part of what is proved, so it is passed at the
# call site and stays out of the settings stamp: a host with a different core
# count then does not force a full smoke re-run.
WP_SMOKE_TIME_FLAGS = -wp-timeout $(WP_TIMEOUT)

# Optional: share path (kept local; not exported).
FRAMAC_SHARE := $(shell $(FR) -print-share-path)

# Everything WP is run on: the examples, plus any verify-only sources declared
# in verify.list (see examples.mk).  The distinction matters only here and in
# libtests-local.mk; the pattern rules below are per-file and never needed it.
VERIFIED := $(EXAMPLES) $(VERIFY_ONLY)

# Durable dependency metadata for WP results.
WP_DEP_FILES       := $(addsuffix .wp/dependencies.mk,$(VERIFIED))
WP_SETTINGS_STAMPS := $(addsuffix .wp/settings.stamp,$(VERIFIED))
WP_SMOKE_SETTINGS_STAMPS := $(addsuffix .smoke.wp/settings.stamp,$(VERIFIED))
WP_TOOLCHAIN_STAMP := $(SESSION_DIR)/cache/wp-toolchain.stamp
WP_RULE_VERSION    := 1

.PHONY: results reports smoke clean-results clean-proofs \
        reports-local results-local smoke-local clean-results-local clean-local \
        wp-force

# The shared WP cache lives outside any single example directory; its rule is
# kept in one place so the top-level Makefile and every example directory
# agree on what it does.
include $(CONFIG_DIR)/cache.mk

wp-force:

# Existing depfiles describe both their own input files and the corresponding
# proof-results.json target. Do not remake them just before deleting them.
ifeq ($(filter clean clean-local clean-everything clean-proofs clean-slate,$(MAKECMDGOALS)),)
-include $(wildcard $(WP_DEP_FILES))
endif

# --------------------------------------------------------------------
# Main artefacts (file-oriented).
#
#   make foo.wp     run WP and provers, produce foo.wp (WP output dir)
#   make foo.wplog  copy the preserved WP run log into foo.wplog
#   make foo.wpgui  launch Ivette in background for foo.c
#   make foo.json   summarize foo.wplog using wp_summary.py
#   make foo.report emit a human-readable report and print it
# --------------------------------------------------------------------

# Generate precise, transitive dependencies for project headers and ACSL
# includes. Listing the depfile itself as a target refreshes the include graph
# when an existing header starts including another file.
%.wp/dependencies.mk: %.c
	@mkdir -p "$*.wp"
	@set -eu; \
	  tmp="$@.tmp.$$$$"; \
	  trap '$(RM) "$$tmp"' 0; \
	  trap 'exit 130' 1 2 15; \
	  $(CC) $(WP_CPP_FLAGS) -MM -MP \
	    -MT "$*.wp/proof-results.json" -MT "$@" "$<" >"$$tmp"; \
	  $(MV) "$$tmp" "$@"; \
	  trap - 0 1 2 15

# Track the effective command for each example. Target-specific variables on
# proof-results.json are inherited by this prerequisite.
%.wp/settings.stamp: wp-force
	@mkdir -p "$*.wp"
	@set -eu; \
	  tmp="$@.tmp.$$$$"; \
	  trap '$(RM) "$$tmp"' 0; \
	  trap 'exit 130' 1 2 15; \
	  printf '%s\n' \
	    'rule-version=$(WP_RULE_VERSION)' \
	    'fr=$(FR)' \
	    'wp-cpp-flags=$(WP_CPP_FLAGS)' \
	    'wp-c-flags=$(WP_C_FLAGS)' \
	    'wp-time-flags=$(WP_TIME_FLAGS)' \
	    'wp-prover-flags=$(WP_PROVER_FLAGS)' >"$$tmp"; \
	  if test -r "$@" && cmp -s "$$tmp" "$@"; then \
	    $(RM) "$$tmp"; \
	  else \
	    $(MV) "$$tmp" "$@"; \
	  fi; \
	  trap - 0 1 2 15

# Smoke runs have their own settings stamp, because their reports must never
# make an ordinary WP report appear current (or vice versa).
%.smoke.wp/settings.stamp: wp-force
	@mkdir -p "$*.smoke.wp"
	@set -eu; \
	  tmp="$@.tmp.$$$$"; \
	  trap '$(RM) "$$tmp"' 0; \
	  trap 'exit 130' 1 2 15; \
	  printf '%s\n' \
	    'rule-version=$(WP_RULE_VERSION)' \
	    'fr=$(FR)' \
	    'wp-cpp-flags=$(WP_CPP_FLAGS)' \
	    'wp-smoke-c-flags=$(WP_SMOKE_C_FLAGS)' \
	    'wp-smoke-time-flags=$(WP_SMOKE_TIME_FLAGS)' \
	    'wp-smoke-prover-flags=$(WP_SMOKE_PROVER_FLAGS)' >"$$tmp"; \
	  if test -r "$@" && cmp -s "$$tmp" "$@"; then \
	    $(RM) "$$tmp"; \
	  else \
	    $(MV) "$$tmp" "$@"; \
	  fi; \
	  trap - 0 1 2 15

# Frama-C, the preprocessor, and the configured provers are external inputs.
# The helper preserves the stamp timestamp when none of them changed.
$(WP_TOOLCHAIN_STAMP): wp-force
	@python3 "$(SCRIPT_DIR)/wp_toolchain_stamp.py" \
	  --output "$@" \
	  --frama-c "$(FR)" \
	  --compiler "$(CC)" \
	  --why3 "$(WHY3)" \
	  $(foreach p,$(PROVERS),--prover "$(p)")

# Run WP once and keep both its detailed JSON report and textual log in the
# generated output directory. Publish both only after a successful run.
%.wp/proof-results.json: %.c %.wp/dependencies.mk %.wp/settings.stamp \
                         $(WP_TOOLCHAIN_STAMP)
	@mkdir -p "$*.wp"
	@set -eu; \
	  report_tmp="$*.wp/proof-results.tmp.json"; \
	  log_tmp="$*.wp/run.log.tmp"; \
	  trap '$(RM) "$$report_tmp" "$$log_tmp"' 0; \
	  trap 'exit 130' 1 2 15; \
	  $(RM) "$$report_tmp" "$$log_tmp"; \
	  $(FR) $(WP_C_FLAGS) $(WP_TIME_FLAGS) $(WP_PROVER_FLAGS) \
	    -wp-out "$*.wp" \
	    -wp-report-json "$$report_tmp" \
	    "$<" >"$$log_tmp" 2>&1; \
	  $(MV) "$$log_tmp" "$*.wp/run.log"; \
	  $(MV) "$$report_tmp" "$@"; \
	  trap - 0 1 2 15

# Separate WP runs for contradiction smoke tests, one per automatic prover.
# Frama-C 33 applies only one prover to smoke goals even with
# -wp-run-all-provers, so the reports are merged before validation. Ordinary
# proof goals are intentionally ignored by check_smoke.py; only entries marked
# "smoke" have the inverted success convention relevant here.
%.smoke.wp/proof-results.json: %.c %.wp/dependencies.mk \
                               %.smoke.wp/settings.stamp \
                               $(WP_TOOLCHAIN_STAMP)
	@mkdir -p "$*.smoke.wp"
	@set -eu; \
	  report_tmp="$*.smoke.wp/proof-results.tmp.json"; \
	  trap '$(RM) "$$report_tmp" \
	    "$*.smoke.wp"/proof-results.*.tmp.json \
	    "$*.smoke.wp"/run.*.log.tmp' 0; \
	  trap 'exit 130' 1 2 15; \
	  $(RM) "$$report_tmp"; \
	  reports=; \
	  for prover in $(SMOKE_PROVERS); do \
	    prover_report="$*.smoke.wp/proof-results.$$prover.json"; \
	    prover_tmp="$*.smoke.wp/proof-results.$$prover.tmp.json"; \
	    log_tmp="$*.smoke.wp/run.$$prover.log.tmp"; \
	    $(RM) "$$prover_tmp" "$$log_tmp"; \
	    $(FR) $(WP_SMOKE_C_FLAGS) $(WP_SMOKE_TIME_FLAGS) \
	      -wp-par $(SMOKE_PROCESSES) \
	      -wp-prover "$$prover" \
	      -wp-out "$*.smoke.wp/$$prover" \
	      -wp-report-json "$$prover_tmp" \
	      "$<" >"$$log_tmp" 2>&1; \
	    $(MV) "$$log_tmp" "$*.smoke.wp/run.$$prover.log"; \
	    $(MV) "$$prover_tmp" "$$prover_report"; \
	    reports="$$reports $$prover_report"; \
	  done; \
	  python3 "$(SCRIPT_DIR)/merge_smoke_reports.py" \
	    "$$report_tmp" $$reports; \
	  $(MV) "$$report_tmp" "$@"; \
	  trap - 0 1 2 15

# Command-line WP run (with provers).
%.wp: %.wp/proof-results.json
	@touch "$@"

# Recreate the transient log from the copy preserved in the WP directory.
%.wplog: %.wp/proof-results.json
	@$(CP) "$*.wp/run.log" "$@"

# GUI run (non-blocking launcher).
%.wpgui: %.c
	@($(FRGUI) $(WP_C_FLAGS) $(WP_TIME_FLAGS) $(WP_PROVER_FLAGS) \
	  -wp-out "$*.wp" \
	  "$<" &)

# JSON summary from a captured log.
%.json: %.wplog
	@python3 "$(SCRIPT_DIR)/wp_summary.py" <"$<" >"$@"
	@$(RM) -r "$<"

# Detailed WP reports produced for everything verified in this directory.
WP_REPORT_JSON := $(addsuffix .wp/proof-results.json,$(VERIFIED))
WP_SMOKE_REPORT_JSON := $(addsuffix .smoke.wp/proof-results.json,$(VERIFIED))

# Human-readable report file.
# Note: the header is printed to stdout; the file stores the per-example summary.
%.report: %.json
	@python3 "$(SCRIPT_DIR)/print_report_header.py"
	@{ \
	  python3 "$(SCRIPT_DIR)/print_example_summary.py" <"$<"; \
	} >"$@"
	@cat "$@"

# Print one header, then all summaries (examples first, then verify-only).
# No trailing blank line: separating one directory from the next is the dispatch
# loop's job (Config/banner.mk).
reports-local: $(WP_REPORT_JSON)
	@python3 "$(SCRIPT_DIR)/print_report_header.py"
	@set -e; \
	for c in $(VERIFIED); do \
	  $(MAKE) -s "$$c.json"; \
	done
	@set -e; \
	for c in $(VERIFIED); do \
	  python3 "$(SCRIPT_DIR)/print_example_summary.py" <"$$c.json"; \
	done

# Search every verified source in this directory for inconsistent contracts,
# assumptions, loops and reachable code. Frama-C records the inverted result
# in JSON; the checker turns any proved smoke goal into a failing make target.
smoke-local: $(WP_SMOKE_REPORT_JSON)
	@python3 "$(SCRIPT_DIR)/check_smoke.py" $(WP_SMOKE_REPORT_JSON)

# Copy JSON into RESULT_DIR.
# Usage: make $(RESULT_DIR)/foo.json
#
# Silent on purpose. This rule used to print the example's summary, which made
# "make results" report whichever examples happened to be out of date -- rows
# with no header above them, and nothing at all for a directory already current.
# results-local prints the directory's whole table instead.
$(RESULT_DIR)/%.json: %.json
	@$(CP) "$<" "$@"

# All JSON result targets inside RESULT_DIR.
#
# EXAMPLES, not VERIFIED: Results/ feeds the book's verification tables, and
# generate-tables.py walks examples.list, so a verify-only entry there would be
# a file nothing reads.
RESULT_JSON := $(addprefix $(RESULT_DIR)/,$(addsuffix .json,$(EXAMPLES)))

# The per-example summaries results-local reads, in this directory rather than
# in Results/. Naming them keeps them off make's intermediate list, so they are
# still on disk when the recipe runs and afterwards.
LOCAL_JSON := $(addsuffix .json,$(EXAMPLES))

# Proof reports and their dependency metadata are durable outputs and must not
# be removed as Make intermediates.
.SECONDARY: $(WP_REPORT_JSON) $(WP_SMOKE_REPORT_JSON) $(WP_DEP_FILES) \
            $(WP_SETTINGS_STAMPS) $(WP_SMOKE_SETTINGS_STAMPS)

# Refresh Results/*.json, then print this directory's table -- the same header
# and rows as reports-local, over EXAMPLES rather than VERIFIED, because that is
# what Results/ holds (see RESULT_JSON above).
#
# No "$(MAKE) -s $$c.json" loop like the one in reports-local: LOCAL_JSON asks
# make for the same files directly. Each sub-make would re-evaluate FRAMAC_SHARE
# and remake the toolchain stamp -- a frama-c start and a prover probe per
# example, which cost more than the whole rest of an up-to-date run.
results-local: $(RESULT_JSON) $(LOCAL_JSON) $(WP_REPORT_JSON)
	@python3 "$(SCRIPT_DIR)/print_report_header.py"
	@set -e; \
	for c in $(EXAMPLES); do \
	  python3 "$(SCRIPT_DIR)/print_example_summary.py" <"$$c.json"; \
	done

clean-results-local:
	@$(RM) $(addprefix $(RESULT_DIR)/, $(addsuffix .json,$(EXAMPLES)))

clean-proofs:
	@$(RM) -rf *.wp *.wplog *.json *.report

clean-local:: clean-proofs
