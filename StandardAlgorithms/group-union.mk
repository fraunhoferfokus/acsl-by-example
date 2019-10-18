
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

GROUP_FILE	:= $(addsuffix .union, $(GROUP))
GROUP_SRC	:= $(addsuffix .c, $(GROUP_FILE))
GROUP_HEADER	:= $(addsuffix .h, $(GROUP_FILE))

GROUP_FILE_CAP	:= $(shell echo $(GROUP_FILE) | tr '[:lower:]' '[:upper:]')
GROUP_GUARD	:= $(addsuffix _H_INCLUDED, $(subst .,_, $(GROUP_FILE_CAP)))

DEPENDENCIES  :=
include $(addsuffix /depend.mk, $(EXAMPLES))
GROUP_DEPENDENCIES = $(sort $(subst /,, $(dir $(DEPENDENCIES))))
DEPENDENCY_HEADERS = $(addsuffix .union.h, $(GROUP_DEPENDENCIES))

include $(TOP_DIR)/config.mk
include $(TOP_DIR)/frama-c.mk
include $(TOP_DIR)/rules.mk

#CPPFLAGS += $(addprefix -I$(TOP_DIR)/$(GROUP)/, $(EXAMPLES))
CPPFLAGS += $(addprefix -I$(TOP_DIR)/, $(GROUP_DEPENDENCIES))

debug: FORCE
	echo $(DEPENDENCY_HEADERS)

# concatenate example source files
$(GROUP_SRC): $(GROUP_SOURCES) 
	@ $(eval TMPF := $(shell mktemp))
	@ trap 'rm "$(TMPF)"' 0
	@ printf "\n"  > $@
	@ printf '#include "$(GROUP_HEADER)"\n' >> $@
	(for f in $(DEPENDENCY_HEADERS); do (printf '#include "'; printf $$f; printf '"\n') >> $@ ; done)
	@ printf "\n"  >> $@
	@ cat $^ | tee -a $(TMPF) | grep '^#include[[:space:]]\+".*\.spec"' | sort -u | cat -s >> $@
	@ cat $(TMPF) | grep -v '^#' | cat -s >> $@

sources: $(GROUP_SRC) FORCE

# concatenate example header files
$(GROUP_HEADER): $(GROUP_HEADERS)
	@ $(eval TMPF := $(shell mktemp))
	@ trap 'rm "$(TMPF)"' 0
	@ printf "\n#ifndef  $(GROUP_GUARD)\n" >> $@
	@ printf "#define  $(GROUP_GUARD)\n\n" >> $@
	@ cat $^ >> $(TMPF)
	@ cat $(TMPF) | grep  '^#include[[:space:]]\+".*\.spec"' | sort -u  >> $@ 
	@ printf "\n" >> $@
	@ cat $(TMPF) | grep -vE '^#' | cat -s >> $@ 
	@ printf "\n" >> $@
	@ printf "#endif  /* $(GROUP_GUARD) */\n\n" >> $@

header: $(GROUP_HEADER) FORCE

files: header sources

driver: FORCE
	@ ($(MAKE) compile -sC $(DRIVER_DIR))

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

