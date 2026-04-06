#
# leaf.mk --- helper for leaf directories (no subdirectories).
# All high-level targets delegate to their corresponding *-local targets.

lib: lib-local
tests: tests-local
check: check-local

# Allow multiple clean rules to accumulate.
clean:: clean-local
distclean: distclean-local

format: format-local

reports: reports-local
results: results-local
clean-results: clean-results-local

