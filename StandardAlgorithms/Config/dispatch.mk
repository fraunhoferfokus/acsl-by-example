
# Config/dispatch.mk --- reusable recursion/dispatch helpers.

DIRLIST ?= subdirs.list
SUBDIRS ?= $(strip $(shell test -f "$(DIRLIST)" && cat "$(DIRLIST)"))

# Targets forwarded into every subdirectory.
#
# "clean-cache" is deliberately absent: the WP cache is shared by the whole
# project, so recursing would wipe it once per subdirectory. "help" is absent
# too -- it describes the directory you are standing in.
# "clean-results" is absent as well: Results/ is a single shared directory, so
# the top level empties it in one step instead of once per subdirectory.
# "clean-slate" must stay absent for a stronger reason: outside the top level it
# is a rule that calls back up here, so dispatching it would loop.
DISPATCH_TARGETS ?= lib tests check format results reports \
                    clean clean-everything \
                    clean-tests clean-lib clean-proofs clean-format

.PHONY: $(DISPATCH_TARGETS) $(DISPATCH_TARGETS:%=%-subdirs) $(SUBDIRS)

define _dispatch_to_subdirs
set -e; \
for d in $(SUBDIRS); do \
  printf " -- %s  %s -- \n" "$$d" "$(1)"; \
  $(MAKE) -C "$$d" "$(1)"; \
done
endef

# Default: "X-subdirs" forwards X into all immediate subdirectories.
$(DISPATCH_TARGETS:%=%-subdirs):
	@$(call _dispatch_to_subdirs,$(@:%-subdirs=%))

# Convenience: allow "make SomeDir check" at any level.
$(SUBDIRS):
	@$(MAKE) -C "$@" $(filter-out $(SUBDIRS),$(MAKECMDGOALS))

# Silence "No rule to make target" for directory-selection usage.
.PHONY: $(MAKECMDGOALS)

