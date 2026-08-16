
# -----------------------------------------------------------------------------
# help.mk --- self-documenting targets.
#
# Document a target by appending "## text" to its rule:
#
#     clean-proofs:  ## remove WP output of this directory
#
# and group targets with a "##@ Section" line. "make help" collects both from
# every makefile that the current directory actually includes, so it lists what
# this directory can really do rather than a fixed list.
#
# Kept out of DISPATCH_TARGETS on purpose: help describes the directory you are
# standing in, so recursing would only repeat it.
# -----------------------------------------------------------------------------

ifndef HELP_MK_INCLUDED
HELP_MK_INCLUDED := 1

.PHONY: help

##@ Help

# POSIX awk only. macOS ships BSD awk, which lacks gawk's three-argument
# match(); this project already works around such differences in central.mk.
help:  ## show this list of targets
	@awk -F'## ' ' \
	  /^##@ /  { printf "\n%s\n", substr($$0, 5); next } \
	  /^[a-zA-Z0-9_-]+::?([^#]*)?## / { \
	      t = $$0; sub(/::?.*/, "", t); \
	      printf "  %-16s %s\n", t, $$2 } \
	  ' $(MAKEFILE_LIST)
	@printf '\nRun "make help" in any directory. See Config/README.md for details.\n'

endif
