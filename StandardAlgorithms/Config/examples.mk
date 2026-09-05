
# -----------------------------------------------------------------------------
# examples.mk --- per-directory Makefile glue for example collections.
#
# The indentation of the include directives below is deliberate. Shell
# completion of "make <TAB>" does not ask make what its targets are: zsh's
# _make reads the makefile text, follows an "include" only when it starts in
# column 0 and its path expands textually (which is why CONFIG_DIR is spelled
# relative in every directory Makefile), and ignores ifneq/else entirely.
#
# So: column 0 for leaf.mk, the front-end that declares the documented targets
# -- that is the list completion should offer. Indented for everything else,
# whose targets are internal (*-local, wp-force, the library and stamp files).
# make itself does not care either way. See Config/README.md.
# -----------------------------------------------------------------------------

  include $(CONFIG_DIR)/central.mk

# Relative path from the current directory to the top-level directory.
# Use ':=' so this is computed once (and does not change unexpectedly later).
REL_TOP_DIR := $(shell $(GNUREALPATH) --relative-to="$(CURDIR)" "$(TOP_DIR)")

# List of example basenames.
# - Prefer $(file <...) over spawning 'cat' (faster, no subshell).
# - $(strip ...) removes newlines and extra whitespace.
EXAMPLES := $(strip $(file <examples.list))

# Sources that are verified but are not examples: they are neither compiled
# into the library nor exercised by a test.  A directory declares them in an
# optional verify.list.
#
# The one instance is the rewrite_array pair in Mutating/, which exists to make
# a point about annotations rather than to compute anything: two files with the
# same function name and the same include guard, so they cannot share a library
# in any case.  See Mutating/verify.list.
#
# Unlike examples.list this is read through the shell, because the file carries
# comments and $(file <...) would hand their words straight to make -- a '#'
# arriving from a function expansion does not start a comment.  The subshell
# runs only in a directory that has the file.
VERIFY_ONLY := $(strip $(if $(wildcard verify.list),\
                 $(shell sed -e 's/#.*//' verify.list)))

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
