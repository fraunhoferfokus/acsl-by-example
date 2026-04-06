
# -----------------------------------------------------------------------------
# central.mk --- global defaults shared by all sub-Makefiles.
# -----------------------------------------------------------------------------

# Quiet builds by default.
MAKEFLAGS += --silent

# If you use recursive make, uncomment to suppress "Entering/Leaving directory".
#MAKEFLAGS += --no-print-directory

# Detect host OS (used to choose GNU userland tools on macOS).
OS := $(shell uname -s 2>/dev/null)

CP := cp -f
MV := mv -f

GNUREALPATH=realpath
GNUSED=sed
ifeq ($(OS),Darwin)
        GNUREALPATH=grealpath
        GNUSED=gsed

	# On macOS, ranlib may warn on archives with no symbols.
	# This flag suppresses that warning (if your toolchain supports it).
        RANLIBFLAGS +=  -no_warning_for_no_symbols
endif

export SCRIPT_DIR  := $(TOP_DIR)/Scripts
export RESULT_DIR  := $(TOP_DIR)/Results
export SESSION_DIR := $(TOP_DIR)/Session

