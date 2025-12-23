
print-%: ; @echo $*=$($*)

MAKEFLAGS += --silent --no-print-directory

export TOP_DIR    ?= ..
export CONFIG_DIR := $(TOP_DIR)/Config
export SCRIPT_DIR := $(TOP_DIR)/Scripts

FILELIST   	:= filelist.path
EXAMPLES	:= $(shell cat $(FILELIST))
GROUP		:= $(shell basename $$(pwd))
GROUP_SOURCES	:= $(join $(addsuffix /,$(EXAMPLES)),$(addsuffix .c,$(EXAMPLES)))
GROUP_HEADERS	:= $(GROUP_SOURCES:.c=.h)

CMD:=\\$(GROUP)
SEC:=cha:$(GROUP)

GROUP_FILE	:= $(addsuffix .separate, $(GROUP))
OUTPUT		:= $(GROUP_FILE).wp

DEPENDENCIES  :=
include $(addsuffix /depend.mk, $(EXAMPLES))

include $(CONFIG_DIR)/config.mk
include $(CONFIG_DIR)/frama-c.mk
include $(CONFIG_DIR)/rules.mk

CPPFLAGS += $(addprefix -I$(TOP_DIR)/$(GROUP)/, $(EXAMPLES))
CPPFLAGS += $(addprefix -I$(TOP_DIR)/, $(DEPENDENCIES))


files: FORCE

$(OUTPUT): driver FORCE
	@$(RM) -r $@
	@$(FR) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $@ $(GROUP_SOURCES)

$(GROUP_FILE).wpgui: driver FORCE
	@$(RM) -r $(OUTPUT)
	@($(FRGUI) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(OUTPUT) $(GROUP_SOURCES) &)

group-wp: $(OUTPUT)

group-wpgui: $(GROUP_FILE).wpgui

report-clean: clean FORCE
	$(RM) $(TOP_DIR)/Results/$(GROUP_FILE).report


clean:: FORCE
	@ $(RM) .lia.cache
	@ $(RM) -r $(OUTPUT)

FORCE:

