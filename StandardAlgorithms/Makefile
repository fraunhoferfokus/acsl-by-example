
# Top-level Makefile.

include Config/dispatch.mk

.PHONY: all clean-cache clean-results \
        lib tests check format clean results reports distclean

all: lib tests

# Top level is a pure dispatcher, so these are synonyms for -subdirs.
lib tests check format clean results reports distclean: %: %-subdirs ;

clean-cache:
	@$(RM) -r Session/cache

clean-results:
	@$(MAKE) clean -sC Results

