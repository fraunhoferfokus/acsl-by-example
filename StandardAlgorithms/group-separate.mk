
print-%: ; @echo $*=$($*)

MAKEFLAGS += --silent --no-print-directory

export TOP_DIR    ?= ..

export SCRIPT_DIR := $(TOP_DIR)/Scripts
export DRIVER_DIR := $(TOP_DIR)/drivers

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

include $(TOP_DIR)/config.mk
include $(TOP_DIR)/frama-c.mk
include $(TOP_DIR)/rules.mk

CPPFLAGS += $(addprefix -I$(TOP_DIR)/$(GROUP)/, $(EXAMPLES))
CPPFLAGS += $(addprefix -I$(TOP_DIR)/, $(DEPENDENCIES))


$(DRIVER): FORCE
	@ ($(MAKE) compile -sC $(DRIVER_DIR))

driver: $(DRIVER)

files: FORCE

$(OUTPUT): driver FORCE
	@$(RM) -r $@
	@$(FR) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $@ $(GROUP_SOURCES)

$(GROUP_FILE).wpgui: driver FORCE
	@$(RM) -r $(OUTPUT)
	@($(FRGUI) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(OUTPUT) $(GROUP_SOURCES) &)

group-wp: $(OUTPUT)

group-wpgui: $(GROUP_FILE).wpgui

$(TOP_DIR)/Results/$(GROUP_FILE).report:
	@$(RM) -r $(OUTPUT)
	@ ($(MAKE) compile -sC $(DRIVER_DIR))
	@mkdir $(OUTPUT)
	@touch $(OUTPUT)/console.log
	@$(FR) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(OUTPUT)  $(GROUP_SOURCES) > $(OUTPUT)/console.log
	# directly extract WP data
	@. $(SCRIPT_DIR)/script_functions.sh; extract_raw_data_Wp $(OUTPUT)/console.log > $@
	# set manuale the 'example' in the report
	@$(GNUSED) -i "s/^example.*/example='$(GROUP_FILE)'/" $@

report: $(TOP_DIR)/Results/$(GROUP_FILE).report
	@. $(SCRIPT_DIR)/script_functions.sh; prettyPrintReport $<

report-clean: clean FORCE
	$(RM) $(TOP_DIR)/Results/$(GROUP_FILE).report



clean:: FORCE
	@ ($(MAKE) clean -sC $(DRIVER_DIR))
	@ $(RM) .lia.cache
	@ $(RM) -r $(OUTPUT)

FORCE:

