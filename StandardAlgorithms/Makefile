
# Top-level Makefile.

include Config/dispatch.mk
include Config/help.mk
include Config/cache.mk

.PHONY: all clean-results clean-slate

##@ Building and testing

all: lib tests    ## build the libraries and the tests
lib:              ## build the static libraries
tests:            ## build the test executables
check:            ## build and run the tests

##@ Formal verification

# The one dispatch target with work of its own at the top level, so it is
# excluded from the pattern rule below. Which prover version discharged which
# goal is in the WP reports, and those are gitignored; Results/toolchain.json
# is the committed record of it, and GitHub/Scripts/render.py checks the
# report's prover table against it. One aggregation over the whole tree, after
# the dispatch, so that it reads reports that are current.
results: results-subdirs   ## run WP and refresh Results/*.json
	@python3 Scripts/collect_toolchain.py

reports:          ## print the per-example proof reports
smoke:            ## search for inconsistent ACSL specifications

##@ Formatting

format:           ## run astyle over the sources

##@ Cleaning

# The top level is a pure dispatcher, so these are synonyms for *-subdirs.
# "results" is the one exception -- it has work of its own above -- and is
# excluded here rather than dropped from DISPATCH_TARGETS, which is what
# defines results-subdirs.
$(filter-out results,$(DISPATCH_TARGETS)): %: %-subdirs ;

clean:            ## remove test output, WP output and astyle backups
clean-everything: ## remove every artifact the subdirectories own
clean-tests:      ## remove objects, dependency files and test executables
clean-lib:        ## remove the static libraries
clean-proofs:     ## remove WP output (*.wp, *.wplog, *.json, *.report)
clean-format:     ## remove astyle backup files (*.orig)

clean-cache:      ## remove the shared WP proof cache (GLOBAL, all examples)

# Not a dispatch target: Results/ is one shared directory, not one per subdir.
clean-results:    ## remove all of Results/*.json
	@$(MAKE) clean -sC Results

# Not a dispatch target either: the top level would forward it into every
# subdirectory, and each of those calls straight back up here.
clean-slate: clean-everything clean-results clean-cache  ## clean-everything + all of Results/ + the WP cache
