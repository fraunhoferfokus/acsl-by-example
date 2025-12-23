
MAKEFLAGS += --silent --no-print-directory

SHELL=/bin/bash

export TOP_DIR    := ../..
export CONFIG_DIR := $(TOP_DIR)/Config
export RESULT_DIR := $(TOP_DIR)/Results
export SCRIPT_DIR := $(TOP_DIR)/Scripts
export VS_DIR     := $(TOP_DIR)/../Misc/VerificationService

EXAMPLE       := $(shell basename $$(pwd))
EXAMPLE_GROUP := $(shell basename $$(cd ..; pwd))

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

# The flags are sorted because the sort function removes duplicates that
# for some strange reason appear in examples that call other examples.
LDFLAGS	+= $(sort $(addprefix -L, $(addprefix $(TOP_DIR)/, $(EXAMPLE_LIBS))))
LIBS	+= $(sort $(addprefix -l, $(EXAMPLE_LIBS)))

$(EXAMPLE_TEST): $(EXAMPLE_TEST).o
	@$(CXX) -o $@ $< $(LDFLAGS) $(LIBS)

test: $(EXAMPLE_TEST) 
	@./$(EXAMPLE_TEST) $(TEST_DATA)

# before $(EXAMPLE).wp was a dependency but this lead to discrepancies 
wp: 
	$(MAKE) $(EXAMPLE).wp


$(EXAMPLE).json: $(EXAMPLE).c
	@set -e; \
	$(MAKE) wp | python3 $(SCRIPT_DIR)/wp_summary.py > $@

json-report: $(EXAMPLE).json
	@python3 $(SCRIPT_DIR)/print_example_summary.py < $<

report: $(EXAMPLE).json 
	@python3 $(SCRIPT_DIR)/print_report_header.py 
	$(MAKE) json-report


json: $(EXAMPLE).json

wpgui: $(EXAMPLE).wpgui

generate: $(EXAMPLE).why3


$(RESULT_DIR)/$(EXAMPLE).json: json-report
	@$(CP) $(EXAMPLE).json $(RESULT_DIR)

result: $(RESULT_DIR)/$(EXAMPLE).json

result-clean: 
	@$(RM) $(RESULT_DIR)/$(EXAMPLE).json

# watch out for qed!
WP_SESSION_FLAGS = -wp-session=$(EXAMPLE_OUT) -wp-cache=update
FR_SESSION       = $(FR) $(WP_C_FLAGS) $(WP_TIME_FLAGS) $(WP_SESSION_FLAGS) 
CONSOLE          = $(EXAMPLE).wp/console.log

# cleanup

clean:: FORCE
	@$(RM) -rf  $(EXAMPLE).wp session .frama-c *.jessie *.av *.wp *.wp++ *.ml
	@$(RM) -r $(EXAMPLE).alt-ergo $(EXAMPLE).cvc4 $(EXAMPLE).cvc3 $(EXAMPLE).z3 $(EXAMPLE).coq
	@$(RM) $(EXAMPLE_TEST) *.o *.pp.c *.pp.h *.back *.orig .lia.cache *.log *.json *.wplog


FORCE:

