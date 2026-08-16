
# -----------------------------------------------------------------------------
# cache.mk --- the shared WP proof cache.
#
# Included both by the top-level Makefile and (via verify-local.mk) by every
# example directory, so "make clean-cache" works from anywhere. The guard keeps
# make from warning about a duplicate recipe when both paths lead here in one
# invocation.
# -----------------------------------------------------------------------------

ifndef CACHE_MK_INCLUDED
CACHE_MK_INCLUDED := 1

# central.mk exports SESSION_DIR, but the top-level Makefile does not include
# it; fall back to the session directory next to this project.
SESSION_DIR ?= $(CURDIR)/Session

.PHONY: clean-cache

# Deliberately not part of "clean-everything" and never added to
# DISPATCH_TARGETS: the cache is shared infrastructure rather than an artifact
# of any one directory, and recursing would wipe it once per subdirectory.
clean-cache:
	@printf 'removing shared WP cache: %s\n' "$(SESSION_DIR)/cache"
	@$(RM) -r "$(SESSION_DIR)/cache"

endif
