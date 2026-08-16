# internal.mk --- helper for internal (non-leaf) directories.

SUBDIRS_FILE ?= subdirs.list

# If SUBDIRS is not set by the caller, read it from SUBDIRS_FILE (if present).
ifeq ($(origin SUBDIRS),undefined)
  SUBDIRS := $(strip $(if $(wildcard $(SUBDIRS_FILE)),$(file <$(SUBDIRS_FILE)),))
endif

include $(CONFIG_DIR)/help.mk

.PHONY: $(SUBDIRS) \
        lib lib-local lib-subdirs \
        tests tests-local tests-subdirs \
        check check-local check-subdirs \
        format format-local format-subdirs \
        reports reports-local reports-subdirs \
        results results-local results-subdirs \
        clean clean-local clean-subdirs \
        clean-results clean-results-local clean-results-subdirs \
        clean-tests-subdirs clean-lib-subdirs \
        clean-proofs-subdirs clean-format-subdirs \
        clean-everything clean-everything-subdirs \
        clean-slate

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

clean-tests-subdirs:
	@$(call _dispatch,clean-tests)

clean-lib-subdirs:
	@$(call _dispatch,clean-lib)

clean-proofs-subdirs:
	@$(call _dispatch,clean-proofs)

clean-format-subdirs:
	@$(call _dispatch,clean-format)

clean-everything-subdirs:
	@$(call _dispatch,clean-everything)

##@ Building and testing

lib: lib-local lib-subdirs        ## build the static libraries
tests: tests-local tests-subdirs  ## build the test executables
check: check-local check-subdirs  ## build and run the tests

##@ Formal verification

results: results-local results-subdirs  ## run WP and refresh Results/*.json
reports: reports-local reports-subdirs  ## print the per-example proof reports

##@ Formatting

format: format-local format-subdirs  ## run astyle over the sources

##@ Cleaning

# Stack/ is both an internal directory and a leaf with its own examples, so
# every aggregate here has to cover the local artifacts as well as the
# subdirectories.
clean:: clean-local
clean:: clean-subdirs               ## remove test output, WP output and astyle backups
clean-everything: clean-local clean-lib clean-results-local clean-everything-subdirs  ## remove every artifact these directories own

clean-tests: clean-tests-subdirs    ## remove objects, dependency files and test executables
clean-lib: clean-lib-subdirs        ## remove the static libraries
clean-proofs: clean-proofs-subdirs  ## remove WP output (*.wp, *.wplog, *.json, *.report)
clean-results: clean-results-local clean-results-subdirs  ## remove these directories' Results/*.json
clean-format: clean-format-subdirs  ## remove astyle backup files (*.orig)
clean-cache:                        ## remove the shared WP proof cache (GLOBAL, all examples)

# Two of the three parts are global (the cache and all of Results/), so this
# always means the whole project, whichever directory it is run from.
clean-slate:                        ## reset the whole project: clean-everything + Results/ + the WP cache
	@$(MAKE) -C "$(TOP_DIR)" clean-slate
