

OS := $(shell uname -s)

#setup some basic preprocessor flags
CPPFLAGS := -I$(TOP_DIR)
CPPFLAGS += -I$(TOP_DIR)/Logic
INCLUDES = $(CPPFLAGS)

RANLIBFLAGS =
GNUSED=sed
ifeq ($(OS),Darwin)
	RANLIBFLAGS +=  -no_warning_for_no_symbols
	GNUSED=gsed
endif

LDFLAGS =


# compiler flags

SHARED_FLAGS = -Wall -pedantic -Werror -O2
CFLAGS       = -x c++ -std=c++17 $(SHARED_FLAGS)
CXXFLAGS     = -std=c++17 $(SHARED_FLAGS)

