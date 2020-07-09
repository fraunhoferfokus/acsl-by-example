
MAKEFLAGS += --silent --no-print-directory

SHELL=/bin/bash

export TOP_DIR    := ../..
export CONFIG_DIR := $(TOP_DIR)/Config
export SCRIPT_DIR := $(TOP_DIR)/Scripts
export DRIVER_DIR := $(TOP_DIR)/Drivers
export VS_DIR     := $(TOP_DIR)/../Misc/VerificationService

EXAMPLE       := $(shell basename $$(pwd))
EXAMPLE_GROUP := $(shell basename $$(cd ..; pwd))

# Latex stuff
ADJUSTNAME  != $(SCRIPT_DIR)/adjust_name.py $(EXAMPLE)
SEC          = $(addprefix sec:, $(ADJUSTNAME))
CMD          = $(addprefix \\,   $(ADJUSTNAME))

DEPENDENCIES  :=

include $(CONFIG_DIR)/config.mk
include $(CONFIG_DIR)/frama-c.mk
include $(CONFIG_DIR)/rules.mk
include $(CONFIG_DIR)/astyle.mk

include depend.mk

EXAMPLE_OUT := $(addsuffix .wp, $(EXAMPLE))
EXAMPLE_TEST := $(addsuffix _test, $(EXAMPLE))

CPPFLAGS += -I.
CPPFLAGS += $(addprefix -I$(TOP_DIR)/, $(DEPENDENCIES))

EXAMPLE_LIBS := $(EXAMPLE_GROUP)
EXAMPLE_LIBS += $(subst /, , $(dir $(DEPENDENCIES)))

LDFLAGS    += $(addprefix -L, $(addprefix $(TOP_DIR)/, $(EXAMPLE_LIBS)))
LIBS       += $(addprefix -l, $(EXAMPLE_LIBS))

export PERL=perl

$(DRIVER): FORCE
	@($(MAKE) compile -sC $(DRIVER_DIR))

define av_why3conf
[main]
running_provers_max = $(AV_PROCESSES)

[strategy]
code = "
start:
  c Alt-Ergo,, 1 2000
  c CVC4,,noBV 1 2000
  c Z3,, 1 2000
  c CVC3,, 1 2000
  c Eprover,, 1 2000
  t split_goal_wp start
  t introduce_premises next1
next1:
  t inline_all next2
next2:
  t eliminate_if next3
next3:
  t remove_triggers start
  c Alt-Ergo,, $(AV_TIMEOUT) 4000
  c CVC4,,noBV $(AV_TIMEOUT) 4000
  c Z3,, $(AV_TIMEOUT) 4000
  c CVC3,, $(AV_TIMEOUT) 4000
  c Eprover,, $(AV_TIMEOUT) 4000"
desc = "Default strategy for ACSL-By-Example"
name = "acslbyexample"
endef
export av_why3conf

$(AV_WHY3_CONF): FORCE
	@if [ -f $@ ]; then                          \
		tfile=$(shell mktemp);               \
		echo "$$av_why3conf" > $$tfile;      \
		diff -q $@ $$tfile > /dev/null || mv $$tfile $@; \
	else echo "$$av_why3conf" > $@; fi

$(EXAMPLE_TEST): $(EXAMPLE_TEST).o
	@$(CXX) -o $@ $< $(LDFLAGS) $(LIBS)

test: $(EXAMPLE_TEST) 
	@./$(EXAMPLE_TEST) $(TEST_DATA)

wp: $(EXAMPLE).wp

wpgui: $(EXAMPLE).wpgui

generate: $(EXAMPLE).why3

$(TOP_DIR)/Results/$(EXAMPLE).report: $(EXAMPLE).c
	. $(SCRIPT_DIR)/script_functions.sh; extract_data_Wp $(EXAMPLE) $(CMD) $(SEC) > $@


report: $(TOP_DIR)/Results/$(EXAMPLE).report
	@. $(SCRIPT_DIR)/script_functions.sh; prettyPrintReport $<

report-clean: clean
	@$(RM) $(TOP_DIR)/Results/$(EXAMPLE).report

qreport: $(TOP_DIR)/Results/$(EXAMPLE).qreport
	@. $(SCRIPT_DIR)/script_functions.sh; prettyPrintReport $<

qreport-clean: clean
	@$(RM) *.qlog
	@$(RM) $(TOP_DIR)/Results/$(EXAMPLE).qreport

$(TOP_DIR)/Results/$(EXAMPLE).qreport: $(EXAMPLE).c
	@ $(SCRIPT_DIR)/qreport.py $(EXAMPLE) $(CMD) $(SEC) $(PROVERS)

# watch out for qed!
WP_SESSION_FLAGS = -wp-session=$(EXAMPLE_OUT) -wp-cache=update
FR_SESSION       = $(FR) $(WP_C_FLAGS) $(WP_TIME_FLAGS) $(WP_SESSION_FLAGS) 
CONSOLE          = $(EXAMPLE).wp/console.log

# I would rather like to use make's "foreach" function here

$(TOP_DIR)/Results/$(EXAMPLE).preport: $(EXAMPLE).c
	@ $(SCRIPT_DIR)/preport.py $(EXAMPLE) $(CMD) $(SEC) $(PROVERS)

preport: $(TOP_DIR)/Results/$(EXAMPLE).preport
	@. $(SCRIPT_DIR)/script_functions.sh; prettyPrintReport $<

preport-clean: clean
	@$(RM) *.plog
	@$(RM) $(TOP_DIR)/Results/$(EXAMPLE).preport
	@$(RM) $(TOP_DIR)/Results/$(EXAMPLE).preport-python
	@$(RM) $(TOP_DIR)/Results/$(EXAMPLE).all



$(TOP_DIR)/Results/$(EXAMPLE).areport: $(AV_WHY3_CONF) $(EXAMPLE).c
	. $(SCRIPT_DIR)/script_functions.sh; extract_data_Av $(EXAMPLE) $(CMD) $(SEC) > $@

areport: $(TOP_DIR)/Results/$(EXAMPLE).areport
	@. $(SCRIPT_DIR)/script_functions.sh; prettyPrintReport $<

areport-clean:
	@$(RM) $(TOP_DIR)/Results/$(EXAMPLE).areport

# cleanup

clean:: FORCE
	@($(MAKE) clean -sC $(DRIVER_DIR))
	@$(RM) -rf  $(EXAMPLE).wp session .frama-c *.jessie *.av *.wp *.wp++ *.ml
	@$(RM) -r $(EXAMPLE).alt-ergo $(EXAMPLE).cvc4 $(EXAMPLE).cvc3 $(EXAMPLE).z3 $(EXAMPLE).coq
	@$(RM) $(EXAMPLE_TEST) *.o *.pp.c *.pp.h *.back *.orig .lia.cache *.log


FORCE:

