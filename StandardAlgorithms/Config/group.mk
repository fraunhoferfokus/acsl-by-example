
MAKEFLAGS += --silent --no-print-directory


export TOP_DIR     ?= ..
export CONFIG_DIR  := $(TOP_DIR)/Config
export GROUPMAKE   := $(CONFIG_DIR)/group-union.mk

FILELIST   	:= filelist.path
GROUP		:= $(shell basename $$(pwd))
LIB		:= $(addprefix lib, $(addsuffix .a, $(GROUP)))
EXAMPLES        := $(shell cat $(FILELIST))
GROUP_SOURCES	:= $(join $(addsuffix /,$(EXAMPLES)),$(addsuffix .c,$(EXAMPLES)))

# We need to change the variable GROUP_OBJECTS for some examples (see
# unique_copy). If a variable is declared with ':=' it is just expanded and not
# recursively expanded (as it is the case for
# '=' and '+=' for example).
# Therefore we need to use '+=' to ensure, that we can add something to the
# definition of GROUP_OBJECTS. Otherwise we would have to redefine the whole
# variable.
GROUP_OBJECTS	+= $(GROUP_SOURCES:.c=.o)

DEPENDENCIES  :=
include $(addsuffix /depend.mk, $(EXAMPLES))

include $(CONFIG_DIR)/config.mk

CPPFLAGS += $(addprefix -I$(TOP_DIR)/$(GROUP)/, $(EXAMPLES))
CPPFLAGS += $(addprefix -I$(TOP_DIR)/, $(DEPENDENCIES))

EXAMPLE_LIBS := $(GROUP)
EXAMPLE_LIBS += $(subst /, , $(dir $(DEPENDENCIES)))

.PHONY: $(EXAMPLES)

lib: $(LIB)
test:: lib

test::		$(EXAMPLES)
clean::		$(EXAMPLES)
format:		$(EXAMPLES)
generate:	$(EXAMPLES)
report-clean:	$(EXAMPLES)
preport-clean:	$(EXAMPLES)
areport-clean:	$(EXAMPLES)

$(EXAMPLES):
	make -sC $@ $(MAKECMDGOALS)

LDFLAGS    += $(addprefix -L, $(addprefix $(TOP_DIR)/, $(EXAMPLE_LIBS)))


$(LIB): $(GROUP_OBJECTS)
	@ar cr $@ $(GROUP_OBJECTS)
	@ranlib $(RANLIBFLAGS) $@
	@$(RM) $(GROUP_OBJECTS)

clean:: FORCE
	$(RM) $(LIB)
	@$(RM) $(GROUP_OBJECTS)
	$(MAKE) -f $(GROUPMAKE) clean

report:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) report -sC $$i);\
        done

preport:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) preport -sC $$i);\
        done

areport:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) areport -sC $$i);\
        done

group-files:
	$(MAKE) -f $(GROUPMAKE) files

group-wp: 
	$(MAKE) -f $(GROUPMAKE) group-wp

group-wpgui: 
	$(MAKE) -f $(GROUPMAKE) group-wpgui

group-report: group-files
	$(MAKE) -f $(GROUPMAKE) report

group-report-clean:
	$(MAKE) -f $(GROUPMAKE) report-clean

group-preport: group-files
	$(MAKE) -f $(GROUPMAKE) preport

group-preport-clean:
	$(MAKE) -f $(GROUPMAKE) preport-clean

FORCE:
