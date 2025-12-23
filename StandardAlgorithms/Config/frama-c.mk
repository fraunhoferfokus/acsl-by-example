
export FRAMAC_SHARE:=$(shell frama-c -print-share-path)

export TIMEOUT   ?= 2
export PROCESSES ?= 1

#setup wp
export WP_TIMEOUT        ?= $(TIMEOUT)
#export WP_COQ_TIMEOUT    ?= 10
export WP_PROCESSES      ?= $(PROCESSES)
export WP_SMOKE_TESTS    ?= 0

#setup av
export AV_TIMEOUT   ?= $(TIMEOUT)
export AV_PROCESSES ?= $(PROCESSES)

# flags for when we invoke Frama C directly instead of going
WP_TIME_FLAGS= -wp-timeout $(WP_TIMEOUT)
WP_TIME_FLAGS+= -wp-par $(WP_PROCESSES)
#WP_TIME_FLAGS += -wp-coq-timeout $(WP_COQ_TIMEOUT) -wp-par $(WP_PROCESSES)

# having this as a separate variable allows us to override it in
# algorithm makefiles
WP_RTE_FLAGS ?= -warn-unsigned-overflow -warn-unsigned-downcast

# We differentiate between two types of WP options:
# 1) in WP_FLAGS we collect the general options
# 2) in WP_PROVER_FLAGS we collect the ones where we select the provers
# This allows us, for example, to start the gui very quickly and then
# run the prover(s) on select proof obligtions.

BASE_FLAGS := -pp-annot
BASE_FLAGS += -no-unicode

WP_BASE_FLAGS := $(BASE_FLAGS)
WP_BASE_FLAGS += -wp
WP_BASE_FLAGS += -wp-rte $(WP_RTE_FLAGS)

WP_FLAGS := $(WP_BASE_FLAGS)
WP_FLAGS += -wp-model Typed
WP_FLAGS += -wp-session $(TOP_DIR)

# Default mode
WP_INTERACTIVE ?= batch
# Use the chosen mode to build WP_FLAGS
WP_FLAGS += -wp-interactive=$(WP_INTERACTIVE)

ifeq ($(WP_SMOKE_TESTS),1)
WP_FLAGS += -wp-smoke-tests
endif

# WP_PROVER_FLAGS += -wp-steps $(WP_ALT_ERGO_STEPS)

# provers
PROVERS = alt-ergo Z3 CVC5 Coq
WP_PROVER_FLAGS += $(addprefix -wp-prover , $(PROVERS))
#WP_PROVER_FLAGS += -wp-run-all-provers

export FR    := frama-c
export FRGUI := ivette

export WP_PROVER_FLAGS
export WP_C_FLAGS   = -cpp-extra-args="$(INCLUDES)" $(WP_FLAGS) 
export WP_CXX_FLAGS = -cxx-clang-command="framaCIRGen $(INCLUDES)"  $(WP_FLAGS)

