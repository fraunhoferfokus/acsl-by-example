
MAKEFLAGS += --silent --no-print-directory


export TOP_DIR     ?= ..
export CONFIG_DIR  := $(TOP_DIR)/Config
export SCRIPT_DIR := $(TOP_DIR)/Scripts

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
qreport-clean:	$(EXAMPLES)
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

wp:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) wp -sC $$i);\
        done

result:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) result -sC $$i);\
        done

result-clean:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) result-clean -sC $$i);\
	done

report:
	@python3 $(SCRIPT_DIR)/print_report_header.py
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) json-report -sC $$i);\
        done

FORCE:

