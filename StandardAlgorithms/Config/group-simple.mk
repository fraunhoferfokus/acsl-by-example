
MAKEFLAGS += --silent --no-print-directory

export TOP_DIR    ?= ..
export CONFIG_DIR := $(TOP_DIR)/Config
export SCRIPT_DIR := $(TOP_DIR)/Scripts
export DRIVER_DIR := $(TOP_DIR)/Drivers

FILELIST   	:= filelist.path
EXAMPLES	:= $(shell cat $(FILELIST))
GROUP		:= $(shell basename $$(pwd))
GROUP_SOURCES	:= $(join $(addsuffix /,$(EXAMPLES)),$(addsuffix .c,$(EXAMPLES)))
GROUP_OBJECTS	:= $(GROUP_SOURCES:.c=.o)

CMD:=\\$(GROUP)
SEC:=cha:$(GROUP)

GROUP_FILE	:= $(addsuffix .simple, $(GROUP))
GROUP_SRC	:= $(addsuffix .c, $(GROUP_FILE))
GROUP_HEADER	:= $(addsuffix .h, $(GROUP_FILE))

GROUP_FILE_CAP	:= $(shell echo $(GROUP_FILE) | tr '[:lower:]' '[:upper:]')
GROUP_GUARD	:= $(addsuffix _H_INCLUDED, $(subst .,_, $(GROUP_FILE_CAP)))

DEPENDENCIES  :=
include $(addsuffix /depend.mk, $(EXAMPLES))

include $(CONFIG_DIR)/config.mk
include $(CONFIG_DIR)/frama-c.mk
include $(CONFIG_DIR)/rules.mk

CPPFLAGS += $(addprefix -I$(TOP_DIR)/$(GROUP)/, $(EXAMPLES))
CPPFLAGS += $(addprefix -I$(TOP_DIR)/, $(DEPENDENCIES))

show-cpp: FORCE
	echo $(CPPFLAGS)

# concatenate example source files
$(GROUP_SRC): $(GROUP_SOURCES)
	@ $(eval TMPF := $(shell mktemp))
	@ trap 'rm "$(TMPF)"' 0
	@ printf "\n"  > $@
	@ printf '#include "$(GROUP_HEADER)"\n' >> $@
	@ cat $^ | tee -a $(TMPF) | grep '^#include[[:space:]]\+".*\.acsl"' >> $@
	@ cat $(TMPF) | grep -v '^#' | cat -s >> $@

sources: $(GROUP_SRC) FORCE

# concatenate example header files
$(GROUP_HEADER): FORCE
	@ $(eval TMPF := $(shell mktemp))
	@ trap 'rm "$(TMPF)"' 0
	@ cat $(GROUP_SOURCES) >> $(TMPF)
	@ printf "\n#ifndef  $(GROUP_GUARD)\n" >> $@
	@ printf "#define  $(GROUP_GUARD)\n\n" >> $@
	@ cat $(TMPF) | grep '^#include[[:space:]]\+".*\.h"' | sort -u >> $@ 
	@ printf "\n" >> $@
	@ printf "#endif  /* $(GROUP_GUARD) */\n\n" >> $@

header: $(GROUP_HEADER) FORCE

files: header sources

$(DRIVER): FORCE
	@ ($(MAKE) compile -sC $(DRIVER_DIR))

driver: $(DRIVER)

$(GROUP_FILE).wp: files driver
	@$(RM) -r $@
	@$(FR) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $@ $(GROUP_SRC)

$(GROUP_FILE).wpgui: files driver
	@$(RM) -r $(GROUP_FILE).wp
	@$(FRGUI) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(GROUP_FILE).wp $(GROUP_SRC)

group-wp: $(GROUP_FILE).wp

group-wpgui: $(GROUP_FILE).wpgui


$(TOP_DIR)/Results/$(GROUP_FILE).report:
	@ ($(MAKE) compile -sC $(DRIVER_DIR))
	@. $(SCRIPT_DIR)/script_functions.sh; extract_data_Wp $(GROUP_FILE) $(CMD) $(SEC) > $@

report: $(TOP_DIR)/Results/$(GROUP_FILE).report
	@. $(SCRIPT_DIR)/script_functions.sh; prettyPrintReport $<

report-clean: clean FORCE
	@$(RM) $(TOP_DIR)/Results/$(GROUP_FILE).report


$(TOP_DIR)/Results/$(GROUP_FILE).preport:
	@. $(SCRIPT_DIR)/script_functions.sh; REPORT_BACKEND=wp_runner extract_data_Wp $(GROUP_FILE) $(CMD) $(SEC) > $@

preport: $(TOP_DIR)/Results/$(GROUP_FILE).preport
	@. $(SCRIPT_DIR)/script_functions.sh; prettyPrintReport $<

preport-clean: clean FORCE
	@$(RM) $(TOP_DIR)/Results/$(GROUP_FILE).preport


clean:: FORCE
	@ ($(MAKE) clean -sC $(DRIVER_DIR))
	@ $(RM) .lia.cache
	@ $(RM) $(GROUP_SRC)
	@ $(RM) $(GROUP_HEADER)
	@ $(RM) -r $(GROUP_FILE).wp

FORCE:

