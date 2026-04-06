# internal.mk --- helper for internal (non-leaf) directories.

SUBDIRS_FILE ?= subdirs.list

# If SUBDIRS is not set by the caller, read it from SUBDIRS_FILE (if present).
ifeq ($(origin SUBDIRS),undefined)
  SUBDIRS := $(strip $(if $(wildcard $(SUBDIRS_FILE)),$(file <$(SUBDIRS_FILE)),))
endif

.PHONY: $(SUBDIRS) \
        lib lib-local lib-subdirs \
        tests tests-local tests-subdirs \
        check check-local check-subdirs \
        format format-local format-subdirs \
        reports reports-local reports-subdirs \
        results results-local results-subdirs \
        clean clean-local clean-subdirs \
        clean-results clean-results-local clean-results-subdirs \
        distclean distclean-local distclean-subdirs

define _dispatch
set -e; \
for d in $(SUBDIRS); do \
  printf " -- %s  %s -- \n" "$$d" "$(1)"; \
  $(MAKE) -C "$$d" $(1); \
done
endef

lib-subdirs:
	@$(call _dispatch,lib)

tests-subdirs:
	@$(call _dispatch,tests)

check-subdirs:
	@$(call _dispatch,check)

format-subdirs:
	@$(call _dispatch,format)

reports-subdirs:
	@$(call _dispatch,reports)

results-subdirs:
	@$(call _dispatch,results)

clean-results-subdirs:
	@$(call _dispatch,clean-results)

clean-subdirs:
	@$(call _dispatch,clean)

distclean-subdirs:
	@$(call _dispatch,distclean)

lib: lib-local lib-subdirs
tests: tests-local tests-subdirs
check: check-local check-subdirs
format: format-local format-subdirs
reports: reports-local reports-subdirs
results: results-local results-subdirs
clean-results: clean-results-local clean-results-subdirs

clean:: clean-local
clean:: clean-subdirs

distclean: distclean-local distclean-subdirs
