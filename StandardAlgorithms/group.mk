
MAKEFLAGS += --silent --no-print-directory

ACTION := group-union
#ACTION := group-separate
#ACTION := group-simple

export TOP_DIR    ?= ..

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

include $(TOP_DIR)/config.mk

CPPFLAGS += $(addprefix -I$(TOP_DIR)/$(GROUP)/, $(EXAMPLES))
CPPFLAGS += $(addprefix -I$(TOP_DIR)/, $(DEPENDENCIES))

EXAMPLE_LIBS := $(GROUP)
EXAMPLE_LIBS += $(subst /, , $(dir $(DEPENDENCIES)))

LDFLAGS    += $(addprefix -L, $(addprefix $(TOP_DIR)/, $(EXAMPLE_LIBS)))

lib: $(LIB)

$(LIB): $(GROUP_OBJECTS)
	@ar cr $@ $(GROUP_OBJECTS)
	@ranlib $(RANLIBFLAGS) $@
	@$(RM) $(GROUP_OBJECTS)

test:: lib
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) test -sC $$i);\
        done

clean:: FORCE
	$(RM) $(LIB)
	@$(RM) $(GROUP_OBJECTS)
	$(MAKE) -f $(TOP_DIR)/$(ACTION).mk clean
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) clean -sC $$i);\
        done

generate:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) generate -sC $$i);\
        done

report:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) report -sC $$i);\
        done

report-clean:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) report-clean -sC $$i);\
        done

preport:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) preport -sC $$i);\
        done

preport-clean:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) preport-clean -sC $$i);\
        done

areport:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) areport -sC $$i);\
        done

areport-clean:
	@for i in $(EXAMPLES);\
        do \
                ($(MAKE) areport-clean -sC $$i);\
        done

format:
	@for i in $(EXAMPLES);\
        do \
                ( $(MAKE) format -sC $$i);\
        done

vs-pipe:
	@for i in $(EXAMPLES);\
        do \
                ( $(MAKE) vs-pipe -sC $$i);\
        done

vs-par:
	@for i in $(EXAMPLES);\
        do \
                ( $(MAKE) vs-par -sC $$i);\
        done

group-files:
	$(MAKE) -f $(TOP_DIR)/$(ACTION).mk files

group-wp: 
	$(MAKE) -f $(TOP_DIR)/$(ACTION).mk group-wp

group-wpgui: 
	$(MAKE) -f $(TOP_DIR)/$(ACTION).mk group-wpgui

group-report: group-files
	$(MAKE) -f $(TOP_DIR)/$(ACTION).mk report

group-report-clean:
	$(MAKE) -f $(TOP_DIR)/$(ACTION).mk report-clean

group-preport: group-files
	$(MAKE) -f $(TOP_DIR)/$(ACTION).mk preport

group-preport-clean:
	$(MAKE) -f $(TOP_DIR)/$(ACTION).mk preport-clean

FORCE:
