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

# Preprocessor flags passed through to Frama-C.
WP_CPP_FLAGS ?= $(CPPFLAGS)
WP_C_FLAGS   = -cpp-extra-args="$(WP_CPP_FLAGS)" $(WP_BASE_FLAGS)

# Time/parallelism.
WP_TIME_FLAGS ?= -wp-timeout $(WP_TIMEOUT)
WP_TIME_FLAGS += -wp-par $(WP_PROCESSES)

# Optional: share path (kept local; not exported).
FRAMAC_SHARE := $(shell $(FR) -print-share-path)

.PHONY: verify-clean verify-clean-sessions results reports clean-results

# --------------------------------------------------------------------
# Main artefacts (file-oriented).
#
#   make foo.wp     run WP and provers, produce foo.wp (WP output dir)
#   make foo.wplog  capture stdout/stderr into foo.wplog (and delete foo.wp)
#   make foo.wpgui  launch Ivette in background for foo.c
#   make foo.json   summarize foo.wplog using wp_summary.py
#   make foo.report emit a human-readable report and print it
# --------------------------------------------------------------------

# Command-line WP run (with provers).
%.wp: %.c
	@$(FR) $(WP_C_FLAGS) $(WP_TIME_FLAGS) $(WP_PROVER_FLAGS) \
	  -wp-out "$*.wp"  "$<"
	@touch "$*.wp"

# Quiet run: capture output; remove the generated WP directory afterwards.
%.wplog: %.c
	@$(FR) $(WP_C_FLAGS) $(WP_TIME_FLAGS) $(WP_PROVER_FLAGS) \
	  -wp-out "$*.wp" \
	  "$<" >"$*.wplog" 2>&1
	@$(RM) -r "$*.wp"

# GUI run (non-blocking launcher).
%.wpgui: %.c
	@($(FRGUI) $(WP_C_FLAGS) $(WP_TIME_FLAGS) $(WP_PROVER_FLAGS) \
	  -wp-out "$*.wp" \
	  "$<" &)

# JSON summary from a captured log.
%.json: %.wplog
	@python3 "$(SCRIPT_DIR)/wp_summary.py" <"$<" >"$@"
	@$(RM) -r "$<"

# Human-readable report file.
# Note: the header is printed to stdout; the file stores the per-example summary.
%.report: %.json
	@python3 "$(SCRIPT_DIR)/print_report_header.py"
	@{ \
	  python3 "$(SCRIPT_DIR)/print_example_summary.py" <"$<"; \
	} >"$@"
	@cat "$@"

# Print one header, then all example summaries (in EXAMPLES order).
reports-local:
	@set -e; \
	python3 "$(SCRIPT_DIR)/print_report_header.py"; \
	for c in $(EXAMPLES); do \
	  $(MAKE) -s "$$c.json"; \
	  python3 "$(SCRIPT_DIR)/print_example_summary.py" <"$$c.json"; \
	done
	printf "\n"

# Copy JSON into RESULT_DIR.
# Usage: make $(RESULT_DIR)/foo.json
$(RESULT_DIR)/%.json: %.json
	@python3 "$(SCRIPT_DIR)/print_example_summary.py" <"$<"
	@$(CP) "$<" "$@"

# All JSON result targets inside RESULT_DIR.
RESULT_JSON := $(addprefix $(RESULT_DIR)/,$(addsuffix .json,$(EXAMPLES)))

results-local: $(RESULT_JSON)

clean-results-local:
	@$(RM) $(addprefix $(RESULT_DIR)/, $(addsuffix .json,$(EXAMPLES)))

# Convenience cleaning (local directory).
clean-local::
	@$(RM) -rf *.wp *.wplog *.json *.report

