
# Config/dispatch.mk --- reusable recursion/dispatch helpers.

DIRLIST ?= subdirs.list
SUBDIRS ?= $(strip $(shell test -f "$(DIRLIST)" && cat "$(DIRLIST)"))

DISPATCH_TARGETS ?= lib tests check format clean results reports distclean

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

