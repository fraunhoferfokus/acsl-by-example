#
# leaf.mk --- helper for leaf directories (no subdirectories).
# All high-level targets delegate to their corresponding *-local targets.
#
# This file also carries the "## text" help for every target a leaf directory
# offers, so that "make help" lists them in one deliberate order. The recipes
# themselves live in libtests-local.mk, verify-local.mk, format-local.mk and
# cache.mk.

include $(CONFIG_DIR)/help.mk

##@ Building and testing

lib: lib-local          ## build the static library for this directory
tests: tests-local      ## build the test executables
check: check-local      ## build and run the tests

##@ Formal verification

results: results-local  ## run WP and refresh Results/*.json
reports: reports-local  ## print the per-example proof report
smoke: smoke-local      ## search for inconsistent ACSL specifications

##@ Formatting

format: format-local    ## run astyle over the local sources

##@ Cleaning

# Allow multiple clean rules to accumulate: libtests-local.mk, verify-local.mk
# and format-local.mk each contribute one clean-local:: rule.
clean:: clean-local     ## remove test output, WP output and astyle backups
clean-everything: clean clean-lib clean-results  ## remove every artifact this directory owns

clean-tests:            ## remove objects, dependency files and test executables
clean-lib:              ## remove the static library built here
clean-proofs:           ## remove WP output (*.wp, *.wplog, *.json, *.report)
clean-results: clean-results-local  ## remove this directory's Results/*.json
clean-format:           ## remove astyle backup files (*.orig)
clean-cache:            ## remove the shared WP proof cache (GLOBAL, all examples)

# Two of the three parts are global (the cache and all of Results/), so this
# always means the whole project, whichever directory it is run from.
.PHONY: clean-slate
clean-slate:            ## reset the whole project: clean-everything + Results/ + the WP cache
	@$(MAKE) -C "$(TOP_DIR)" clean-slate
