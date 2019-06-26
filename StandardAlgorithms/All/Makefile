
MAKEFLAGS += --silent --no-print-directory

SHELL=/bin/bash
#Variables for counting invalid and valid proof goals; used in make-report targets

export TOP_DIR=..
export SCRIPT_DIR=$(TOP_DIR)/Scripts
export DRIVER_DIR=$(TOP_DIR)/drivers

NONMUTATING = $(TOP_DIR)/nonmutating
NONMUTATING_EXAMPLES =	find2 find_first_of adjacent_find mismatch equal
#search search_n find_end count find
NONMUTATING_DIRS = $(addprefix $(NONMUTATING)/, $(NONMUTATING_EXAMPLES))

#MAXMIN = $(TOP_DIR)/maxmin
#MAXMIN_EXAMPLES = operators max_element2 min_element max_seq 
# max_element
#MAXMIN_DIRS = $(addprefix $(MAXMIN)/, $(MAXMIN_EXAMPLES))

#BINARYSEARCH=$(TOP_DIR)/binarysearch
#BINARYSEARCH_EXAMPLES = lower_bound upper_bound equal_range binary_search
#equal_range2 binary_search2
#BINARYSEARCH_DIRS = $(addprefix $(BINARYSEARCH)/, $(BINARYSEARCH_EXAMPLES))

#MUTATING = $(TOP_DIR)/mutating
#MUTATING_EXAMPLES = fill swap swap_ranges copy replace_copy copy_backward reverse_copy reverse replace rotate_copy rotate remove remove_copy random_shuffle
#remove_copy2  
#MUTATING_DIRS = $(addprefix $(MUTATING)/, $(MUTATING_EXAMPLES))

#NUMERIC = $(TOP_DIR)/numeric
#NUMERIC_EXAMPLES = iota accumulate inner_product partial_sum adjacent_difference partial_sum_inv adjacent_difference_inv
#NUMERIC_DIRS = $(addprefix $(NUMERIC)/, $(NUMERIC_EXAMPLES))

#HEAP = $(TOP_DIR)/heap
#HEAP_EXAMPLES = is_heap push_heap make_heap sort_heap
#HEAP_DIRS = $(addprefix $(HEAP)/, $(HEAP_EXAMPLES))

#CLASSIC_SORTING = $(TOP_DIR)/classic-sorting
#CLASSIC_SORTING_EXAMPLES = selection_sort insertion_sort heap_sort
#CLASSIC_SORTING_DIRS = $(addprefix $(CLASSIC_SORTING)/, $(CLASSIC_SORTING_EXAMPLES))

#STACK = $(TOP_DIR)/stack
#STACK_EXAMPLES = stack_init stack_equal stack_size stack_empty stack_full stack_top stack_push stack_pop
#STACK_DIRS = $(addprefix $(STACK)/, $(STACK_EXAMPLES))

#STACK_WD = $(TOP_DIR)/stack_wd
#STACK_WD_EXAMPLES = stack_size_wd stack_empty_wd stack_top_wd stack_push_wd stack_pop_wd
#STACK_WD_DIRS = $(addprefix $(STACK_WD)/, $(STACK_WD_EXAMPLES))

#STACK_AXIOM = $(TOP_DIR)/stack_axiom
#STACK_AXIOM_EXAMPLES = axiom_size_of_init axiom_top_of_push axiom_size_of_push axiom_size_of_pop axiom_push_of_pop_top axiom_pop_of_push  
#STACK_AXIOM_DIRS = $(addprefix $(STACK_AXIOM)/, $(STACK_AXIOM_EXAMPLES))

VPATH = $(TOP_DIR)
VPATH += $(TOP_DIR)/Logic
VPATH += $(NONMUTATING_DIRS)
VPATH += $(MAXMIN_DIRS)
VPATH += $(BINARYSEARCH_DIRS)
VPATH += $(MUTATING_DIRS)
VPATH += $(NUMERIC_DIRS)
VPATH += $(HEAP_DIRS)
VPATH += $(CLASSIC_SORTING_DIRS)
VPATH += $(STACK_DIRS)
VPATH += $(STACK_WD_DIRS)
VPATH += $(STACK_AXIOM_DIRS)

EXAMPLES = $(NONMUTATING_EXAMPLES)
EXAMPLES += $(MAXMIN_EXAMPLES)
EXAMPLES += $(BINARYSEARCH_EXAMPLES)
EXAMPLES += $(MUTATING_EXAMPLES)
EXAMPLES += $(NUMERIC_EXAMPLES)
EXAMPLES += $(HEAP_EXAMPLES)
EXAMPLES += $(CLASSIC_SORTING_EXAMPLES)
EXAMPLES += $(STACK_EXAMPLES)
EXAMPLES += $(STACK_WD_EXAMPLES)
EXAMPLES += $(STACK_AXIOM_EXAMPLES)

SRC=$(addsuffix .c, $(EXAMPLES))

list: $(SRC)
	@echo $(SRC)
	@echo $(VPATH)
	@ls $^

CPPFLAGS += $(addprefix -I, $(VPATH))

#setup some basic flags
INCLUDES  = $(CPPFLAGS)

# PREPROCESSOR

SHARED_FLAGS=-Wall -pedantic -Werror
CFLAGS=-x c++ -std=c++14 $(SHARED_FLAGS)
CXXFLAGS=-std=c++14 $(SHARED_FLAGS)

#setup wp
export WP_TIMEOUT ?= 10
export WP_COQ_TIMEOUT ?= 10
export WP_ALT_ERGO_STEPS ?= 10000
export WP_PROCESSES ?= 1

# flags for when we invoke Frama C directly instead of going
# through script_functions.sh
WP_TIME_FLAGS= \
	-wp-timeout $(WP_TIMEOUT) \
	-wp-coq-timeout $(WP_COQ_TIMEOUT) \
	-wp-steps $(WP_ALT_ERGO_STEPS) \
	-wp-par $(WP_PROCESSES)

#setup coq
SCRIPT?='$(TOP_DIR)/wp0.script' # default script
DRIVER=$(DRIVER_DIR)/driver

# having this as a separate variable allows us to override it in
# algorithm makefiles
WP_RTE_FLAGS ?= -warn-unsigned-overflow -warn-unsigned-downcast

# We differentiate between two types of WP options:
# 1) in WP_FLAGS we collect the general options
# 2) in WP_PROVER_FLAGS we collect the ones where we select the provers
# This allows us, for example, to start the gui very quickly and then
# run the prover(s) on select proof obligtions.

WP_BASE_FLAGS += -pp-annot
WP_BASE_FLAGS += -no-unicode
WP_BASE_FLAGS += -wp
WP_BASE_FLAGS += -wp-rte $(WP_RTE_FLAGS)
#WP_BASE_FLAGS += -wp-split

WP_FLAGS = $(WP_BASE_FLAGS)

WP_FLAGS += -wp-driver $(DRIVER_DIR)/external.driver
WP_FLAGS += -wp-script $(SCRIPT)
WP_FLAGS += -wp-model Typed+ref

#WP_PROVER_FLAGS += -wp-steps $(WP_ALT_ERGO_STEPS)

# provers
WP_PROVER_FLAGS += -wp-prover alt-ergo
WP_PROVER_FLAGS += -wp-prover cvc4-15
WP_PROVER_FLAGS += -wp-prover cvc3
WP_PROVER_FLAGS += -wp-prover z3
WP_PROVER_FLAGS += -wp-prover eprover
#WP_PROVER_FLAGS += -wp-prover coq


#WP_PROVER_FLAGS += -wp-prover gappa
#WP_PROVER_FLAGS += -wp-prover metis

# link binary metit to metitarski
#WP_PROVER_FLAGS += -wp-prover metitarski

#WP_PROVER_FLAGS += -wp-prover princess
#WP_PROVER_FLAGS += -wp-prover psyche

# onnly ppc binary for available for macOS ...
#WP_PROVER_FLAGS += -wp-prover simplify
#WP_PROVER_FLAGS += -wp-prover spass
#WP_PROVER_FLAGS += -wp-prover verit

# yices (version 2.* does not support quantifiers ...)
#WP_PROVER_FLAGS += -wp-prover Yices

export WP=frama-c
export WPGUI=frama-c-gui
export WP_PROVER_FLAGS
export WP_C_FLAGS = -cpp-extra-args="$(INCLUDES)" $(WP_FLAGS)
export WP_CXX_FLAGS = -cxx-clang-command="framaCIRGen $(INCLUDES)"  $(WP_FLAGS)
export WP_C_REPORT=$(WP) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) -wp-par 1

TESTOBJ = $(FILE)_test.o $(FILE).o


$(DRIVER): FORCE
	@(cd $(DRIVER_DIR) && $(MAKE) compile)

foo: $(DRIVER)


$(FILE)_test: $(TESTOBJ) FORCE
	@$(CXX) $(LDFLAGS) -o $@ $(TESTOBJ)

test: $(FILE)_test FORCE
	@./$(FILE)_test

%.cpp:%.c
	cp $< $@

abs.why3:abs.c FORCE
	@($(WP) $(WP_C_FLAGS) $(WP_TIME_FLAGS) -wp-prover why3 -wp-gen  -wp-out $(patsubst %.c,%.wp, $<)  $<)

%.why3:%.c driver FORCE
	@($(WP) $(WP_C_FLAGS) $(WP_TIME_FLAGS) -wp-prover why3 -wp-gen  -wp-out $(patsubst %.c,%.wp, $<)  $<)

%.wp_runner:%.c FORCE
	@${SCRIPT_DIR}/wp_runner.sh $< $(WP_C_FLAGS) $(WP_PROVER_FLAGS) -wp-par $(WP_PROCESSES)

%.wpscript:%.c FORCE
	@${SCRIPT_DIR}/wpscript.sh $< $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(notdir $(patsubst %.c,%.wp, $<)) 

%.vs:%.c FORCE
	@${SCRIPT_DIR}/vs.sh $< $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(notdir $(patsubst %.c,%.wp, $<)) 

%.wp:%.c FORCE
	@$(WP) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(patsubst %.c,%.wp, $<) $<

%.wpgui:%.c FORCE
	@$(WPGUI) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(patsubst %.c,%.wp, $<) $<

# start WP GUI and run provers

examples.wpgui: $(SRC)
	@$(WPGUI) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out all.wp $^ 

examples.wp: $(SRC)
	@$(RM) -rf all.wp
	@$(WP) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out all.wp $^ 

examples.why: $(SRC)
	@$(RM) -rf all.wp
	@$(WP) $(WP_C_FLAGS) -wp-out all.wp -wp-prover why3 -wp-gen  $^

all.clean: $(FORCE)
	$(RM) -rf all.wp

all.wp: $(FORCE) examples.wp

all.why: $(FORCE) examples.why


$(TOP_DIR)/Results/$(FILE).report: $(FILE).c
	. ${SCRIPT_DIR}/script_functions.sh; extract_data_Wp $(basename $<) $(CMD) $(SEC) >$@

$(TOP_DIR)/Results/$(FILE).preport: $(FILE).c
	@. ${SCRIPT_DIR}/script_functions.sh; REPORT_BACKEND=wp_runner extract_data_Wp $(basename $<) $(CMD) $(SEC) >$@

%.report-wp: $(TOP_DIR)/Results/$(FILE).report
	@. ${SCRIPT_DIR}/script_functions.sh; prettyPrintReport $<

report: $(TOP_DIR)/Results/$(FILE).report
	@. ${SCRIPT_DIR}/script_functions.sh; prettyPrintReport $<

preport: $(TOP_DIR)/Results/$(FILE).preport
	@. ${SCRIPT_DIR}/script_functions.sh; prettyPrintReport $<

%.check:%.c
	@$(WP) $(WP_C_FLAGS) -wp-check -wp-out $(patsubst %.c,%.wp, $<)  $<


# cleanup

clean:: FORCE
	@(cd $(DRIVER_DIR) && $(MAKE) -s clean)
	@$(RM) *.o
	@$(RM) *.back
	@$(RM) *.orig
	@$(RM) *.exe
	@$(RM) .lia.cache
	@$(RM) -rf  *.debug
	@$(RM) -rf  .frama-c
	@$(RM) -rf  *.jessie
	@$(RM) -rf  *.wp
	@$(RM) -rf  *.wp++
	@$(RM) -rf  *.ml
	@$(RM) $(FILE).cpp
	@$(RM) $(FILE)_test
	@$(RM) $(FILE).tex
	@$(RM) $(FILE).sav


all: clean test report

FORCE:
