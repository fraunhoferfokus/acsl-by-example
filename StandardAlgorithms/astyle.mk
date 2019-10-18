
ASTYLEOPTIONS += --quiet
ASTYLEOPTIONS += --style=stroustrup
ASTYLEOPTIONS += --indent=spaces=2
ASTYLEOPTIONS += --indent-col1-comments
ASTYLEOPTIONS += --min-conditional-indent=0
ASTYLEOPTIONS += --lineend=linux
ASTYLEOPTIONS += --break-return-type
ASTYLEOPTIONS += --break-return-type-decl
ASTYLEOPTIONS += --add-braces
ASTYLEOPTIONS += --break-closing-braces
ASTYLEOPTIONS += --break-one-line-headers
ASTYLEOPTIONS += --break-blocks
#ASTYLEOPTIONS += --delete-empty-lines
ASTYLEOPTIONS += --pad-oper
ASTYLEOPTIONS += --pad-header

format: FORCE
	@astyle $(ASTYLEOPTIONS) *.c *.cpp *.h

