
MAKEFLAGS += --silent --no-print-directory

export TOP_DIR    := $(PWD)
export SCRIPT_DIR := $(TOP_DIR)/Scripts
export DRIVER_DIR := $(TOP_DIR)/drivers

export ALL_DIR    ?= $(basename $(TOP_DIR))

FILELIST   	:= filelist.path
GROUPS		:= $(shell cat $(FILELIST))
GROUP_SOURCES	:= $(join $(addsuffix /,$(GROUPS)),$(addsuffix .union.c,$(GROUPS)))
GROUP_HEADERS   := $(GROUP_SOURCES:.c=.h)


CMD:=all.union
SEC:=cha:Introduction

include config.mk
include frama-c.mk
include rules.mk

ALL_SOURCE  := $(addsuffix .c, $(CMD))
ALL_HEADER  := $(addsuffix .h, $(CMD))

ALL_FILE_CAP  := $(shell echo $(CMD) | tr '[:lower:]' '[:upper:]')
ALL_GUARD     := $(addsuffix _H_INCLUDED, $(subst .,_, $(ALL_FILE_CAP)))

#CPPFLAGS += $(addprefix -I, $(ALL_DIRS))

debug:
	echo $(ALL_HEADER)
	echo $(GROUP_SOURCES)

# concatenate example files
$(ALL_SOURCE): $(GROUP_SOURCES)
	@ $(eval TMPF := $(shell mktemp))
	@ trap 'rm "$(TMPF)"' 0
	@ printf "\n"  > $@
	@ printf '#include "$(ALL_HEADER)"\n' >> $@
	@ printf "\n"  >> $@
	@ cat $^ | tee -a $(TMPF) | grep '^#include[[:space:]]\+".*\.spec"' | sort -u | cat -s >> $@
	@ cat $(TMPF) | grep -v '^#' | cat -s >> $@

source: $(ALL_SOURCE) FORCE

$(ALL_HEADER): $(GROUP_HEADERS)
	@ $(eval TMPF := $(shell mktemp))
	@ trap 'rm "$(TMPF)"' 0
	@ printf "\n#ifndef  $(ALL_GUARD)\n" >> $@
	@ printf "#define  $(ALL_GUARD)\n\n" >> $@
	@ cat $^ >> $(TMPF)
	@ cat $(TMPF) | grep  '^#include[[:space:]]\+".*\.spec"' | sort -u  >> $@
	@ printf "\n" >> $@
	@ cat $(TMPF) | grep -vE '^#' | cat -s >> $@
	@ printf "\n" >> $@
	@ printf "#endif  /* $(ALL_GUARD) */\n\n" >> $@

header: $(ALL_HEADER) FORCE

$(DRIVER): FORCE
	@ ($(MAKE) compile -sC $(DRIVER_DIR))

$(TOP_DIR)/Results/$(CMD).report:
	@. $(SCRIPT_DIR)/script_functions.sh; extract_data_Wp $(CMD) $(CMD) $(SEC) > $@

report: $(TOP_DIR)/Results/$(CMD).report
	@. $(SCRIPT_DIR)/script_functions.sh; prettyPrintReport $<

report-clean: clean FORCE
	@$(RM) $(TOP_DIR)/Results/$(CMD).report


$(TOP_DIR)/Results/$(CMD).preport:
	@. $(SCRIPT_DIR)/script_functions.sh; REPORT_BACKEND=wp_runner extract_data_Wp $(CMD)  $(CMD) $(SEC) > $@

preport: $(TOP_DIR)/Results/$(CMD).preport
	@. $(SCRIPT_DIR)/script_functions.sh; prettyPrintReport $<

preport-clean:
	@$(RM) $(TOP_DIR)/Results/$(CMD).preport


clean:: FORCE
	$(RM) .lia.cache
	$(RM) $(ALL_SOURCE)
	$(RM) $(ALL_HEADER)
	$(RM) -r $(CMD).wp

FORCE:

