
ASTYLE ?= astyle

ASTYLEOPTIONS += --quiet
ASTYLEOPTIONS += --style=stroustrup
ASTYLEOPTIONS += --indent=spaces=2
ASTYLEOPTIONS += --indent-col1-comments
ASTYLEOPTIONS += --min-conditional-indent=0
ASTYLEOPTIONS += --lineend=linux
ASTYLEOPTIONS += --attach-return-type
ASTYLEOPTIONS += --attach-return-type-decl
ASTYLEOPTIONS += --add-braces
ASTYLEOPTIONS += --break-closing-braces
ASTYLEOPTIONS += --break-one-line-headers
ASTYLEOPTIONS += --break-blocks
ASTYLEOPTIONS += --pad-oper
ASTYLEOPTIONS += --pad-header

# Format all local C/C++ headers and sources.
FORMAT_FILES := $(wildcard *.c *.cpp *.h)

.PHONY: format-local
format-local:
	$(ASTYLE) $(ASTYLEOPTIONS) $(FORMAT_FILES)

# Remove backup files created by astyle (*.orig).
.PHONY: clean-local
clean-local::
	@$(RM) -f *.orig
