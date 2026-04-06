# libtests-local.mk --- generic rules for leaf directories
#
# Responsibilities:
# - build a static library from modules listed in EXAMPLES
# - build one *_test executable per module
# - run tests in EXAMPLES order

# ---- required inputs (set by including Makefile) ----
# LIB_NAME   : name of the library, e.g. libNonmutating.a
# EXAMPLES   : space-separated basenames
# REL_TOP_DIR: relative path to top-level directory

# Keep intermediate files (notably .o) between invocations.
.SECONDARY:


AR      ?= ar
RANLIB  ?= ranlib
CXX     ?= c++

# Baseline include paths shared by all such directories.
CPPFLAGS += -I. -I$(REL_TOP_DIR) -I$(REL_TOP_DIR)/Logic

CFLAGS   ?= -Wall -Wextra -pedantic -Werror -O2
CXXFLAGS ?= -std=c++23 $(CFLAGS)

# Linker flags are appendable by design.
LDFLAGS  +=
LDLIBS   +=

# Additional sibling libraries (if any).
CPPFLAGS += $(addprefix -I$(REL_TOP_DIR)/,$(ADDITIONAL))
LDFLAGS  += $(addprefix -L$(REL_TOP_DIR)/,$(ADDITIONAL))
LDLIBS   += $(addprefix -l,$(ADDITIONAL))

# Source files derived from EXAMPLES.
SRC      := $(addsuffix .c,$(EXAMPLES))
OBJ      := $(addsuffix .o,$(EXAMPLES))
DEP      := $(addsuffix .d,$(EXAMPLES))

TEST_SRC := $(addsuffix _test.cpp,$(EXAMPLES))
TEST_OBJ := $(addsuffix _test.o,$(EXAMPLES))
TEST_DEP := $(addsuffix _test.d,$(EXAMPLES))
TEST_BIN := $(addsuffix _test,$(EXAMPLES))

.PHONY: all lib tests check clean distclean
all: lib tests

lib-local: $(LIB_NAME)
tests-local: $(TEST_BIN)

# Static library.
$(LIB_NAME): $(OBJ)
	$(AR) rcs $@ $^
	$(RANLIB) $@

# Compile .c files as C++.
%.o: %.c
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -x c++ -MMD -MP -c -o $@ $<

# Compile test sources.
%_test.o: %_test.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c -o $@ $<

# Link each test against the local library.
%_test: %_test.o $(LIB_NAME)
	$(CXX) $(LDFLAGS) -o $@ $< $(LIB_NAME) $(LDLIBS)

# Run tests in EXAMPLES order.
check-local: $(TEST_BIN)
	@set -e; \
	for t in $(TEST_BIN); do \
		printf "\tRunning %s\n" "$$t"; \
		./$$t; \
	done
	printf "\n"

# Auto-generated dependency files.
-include $(DEP) $(TEST_DEP)

clean-local::
	$(RM) $(OBJ) $(DEP) $(TEST_OBJ) $(TEST_DEP) $(TEST_BIN)

distclean-local: clean-local
	$(RM) $(LIB_NAME)

