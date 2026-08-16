#
# verify-local.mk --- file-oriented Frama-C/WP rules.
# Include alongside libtests-local.mk / format-local.mk in leaf directories.

# Tools (overrideable, but typically fixed).
FR    ?= frama-c
FRGUI ?= ivette

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
WP_TIMEOUT   ?= 2
WP_PROCESSES ?= 1

# WP mode: batch (default), edit, command, ...
WP_INTERACTIVE ?= batch

# RTE configuration (override per-directory or per-file if needed).
WP_RTE_FLAGS ?= -warn-unsigned-overflow -warn-unsigned-downcast

# Prover selection (empty means: generate obligations only).
PROVERS ?= alt-ergo Z3 CVC5 Coq
WP_PROVER_FLAGS := $(strip $(foreach p,$(PROVERS),-wp-prover $(p)))

# Common Frama-C flags.
BASE_FLAGS := -pp-annot
BASE_FLAGS += -no-unicode

WP_BASE_FLAGS = $(BASE_FLAGS)
WP_BASE_FLAGS += -wp
WP_BASE_FLAGS += -wp-rte $(WP_RTE_FLAGS)
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

# Time/parallelism.
WP_TIME_FLAGS ?= -wp-timeout $(WP_TIMEOUT)
WP_TIME_FLAGS += -wp-par $(WP_PROCESSES)

# Optional: share path (kept local; not exported).
FRAMAC_SHARE := $(shell $(FR) -print-share-path)

# Durable dependency metadata for WP results.
WP_DEP_FILES       := $(addsuffix .wp/dependencies.mk,$(EXAMPLES))
WP_SETTINGS_STAMPS := $(addsuffix .wp/settings.stamp,$(EXAMPLES))
WP_TOOLCHAIN_STAMP := $(SESSION_DIR)/cache/wp-toolchain.stamp
WP_RULE_VERSION    := 1

.PHONY: results reports clean-results clean-proofs \
        reports-local results-local clean-results-local clean-local wp-force

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

# Frama-C, the preprocessor, and the configured provers are external inputs.
# The helper preserves the stamp timestamp when none of them changed.
$(WP_TOOLCHAIN_STAMP): wp-force
	@python3 "$(SCRIPT_DIR)/wp_toolchain_stamp.py" \
	  --output "$@" \
	  --frama-c "$(FR)" \
	  --compiler "$(CC)" \
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

# Detailed WP reports produced for all examples in this directory.
WP_REPORT_JSON := $(addsuffix .wp/proof-results.json,$(EXAMPLES))

# Human-readable report file.
# Note: the header is printed to stdout; the file stores the per-example summary.
%.report: %.json
	@python3 "$(SCRIPT_DIR)/print_report_header.py"
	@{ \
	  python3 "$(SCRIPT_DIR)/print_example_summary.py" <"$<"; \
	} >"$@"
	@cat "$@"

# Print one header, then all example summaries (in EXAMPLES order).
reports-local: $(WP_REPORT_JSON)
	@python3 "$(SCRIPT_DIR)/print_report_header.py"
	@set -e; \
	for c in $(EXAMPLES); do \
	  $(MAKE) -s "$$c.json"; \
	done
	@set -e; \
	for c in $(EXAMPLES); do \
	  python3 "$(SCRIPT_DIR)/print_example_summary.py" <"$$c.json"; \
	done
	@printf "\n"

# Copy JSON into RESULT_DIR.
# Usage: make $(RESULT_DIR)/foo.json
$(RESULT_DIR)/%.json: %.json
	@python3 "$(SCRIPT_DIR)/print_example_summary.py" <"$<"
	@$(CP) "$<" "$@"

# All JSON result targets inside RESULT_DIR.
RESULT_JSON := $(addprefix $(RESULT_DIR)/,$(addsuffix .json,$(EXAMPLES)))

# Proof reports and their dependency metadata are durable outputs and must not
# be removed as Make intermediates.
.SECONDARY: $(WP_REPORT_JSON) $(WP_DEP_FILES) $(WP_SETTINGS_STAMPS)

results-local: $(RESULT_JSON) $(WP_REPORT_JSON)

clean-results-local:
	@$(RM) $(addprefix $(RESULT_DIR)/, $(addsuffix .json,$(EXAMPLES)))

clean-proofs:
	@$(RM) -rf *.wp *.wplog *.json *.report

clean-local:: clean-proofs
