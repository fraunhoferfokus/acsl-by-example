
# Makefile (directory-local configuration)

TOP_DIR     ?= $(abspath ..)
CONFIG_DIR  := ../Config

include $(CONFIG_DIR)/examples.mk

# disable -warn-unsigned-overflow
random_number.wp random_number.wplog random_number.wp/proof-results.json: \
  WP_RTE_FLAGS = -no-warn-unsigned-overflow -warn-unsigned-downcast

# The rewrite_array pair carries an expected outcome each way (see
# verify.list).  The "assigns \nothing" variant is a counterexample: it must
# stay unproved, and no ordinary target would ever notice if it stopped being
# one.
#
# Internal, like the other *-local targets, so it stays out of "make help":
# results-local depends on it, so "make results" asserts it without anyone
# having to remember the name.
REWRITE_ARRAY_UNCHANGED := rewrite_array_unchanged.wp/proof-results.json
REWRITE_ARRAY_NOTHING   := rewrite_array_nothing.wp/proof-results.json

.PHONY: check-rewrite-array
check-rewrite-array: $(REWRITE_ARRAY_UNCHANGED) $(REWRITE_ARRAY_NOTHING)
	@python3 "$(SCRIPT_DIR)/check_goals.py" --complete $(REWRITE_ARRAY_UNCHANGED)
	@python3 "$(SCRIPT_DIR)/check_goals.py" --unproved rewrite_array_assigns \
	  $(REWRITE_ARRAY_NOTHING)
	@echo "rewrite_array: unchanged proves, nothing fails its assigns goal"

results-local: check-rewrite-array
