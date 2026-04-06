
# -----------------------------------------------------------------------------
# examples.mk --- per-directory Makefile glue for example collections.
# -----------------------------------------------------------------------------

include $(CONFIG_DIR)/central.mk

# Relative path from the current directory to the top-level directory.
# Use ':=' so this is computed once (and does not change unexpectedly later).
REL_TOP_DIR := $(shell $(GNUREALPATH) --relative-to="$(CURDIR)" "$(TOP_DIR)")

# List of example basenames.
# - Prefer $(file <...) over spawning 'cat' (faster, no subshell).
# - $(strip ...) removes newlines and extra whitespace.
EXAMPLES := $(strip $(file <examples.list))

# Name of the library built in this directory.
# Using := avoids re-evaluating $(CURDIR) repeatedly.
LIB_NAME := lib$(notdir $(CURDIR)).a

# Optional additional libraries (kept empty by default).
ADDITIONAL ?=

# Local overrides/hooks.
# Using -include keeps the build working even if a directory does not provide
# one of these customization files.
-include $(CONFIG_DIR)/libtests-local.mk
-include $(CONFIG_DIR)/verify-local.mk
-include $(CONFIG_DIR)/format-local.mk

# Automatically select internal or leaf make logic.
# We check for a local "subdirs.list" file.
ifneq ($(wildcard subdirs.list),)
  include $(CONFIG_DIR)/internal.mk
else
  include $(CONFIG_DIR)/leaf.mk
endif
