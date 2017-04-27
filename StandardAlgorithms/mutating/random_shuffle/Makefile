
FILE=random_shuffle
CMD=\\randomshuffle
SEC=sec:randomshuffle

#WP_TIMEOUT=20

include ../../Makefile.template

# disable -warn-unsigned-overflow
WP_RTE_FLAGS=-warn-unsigned-downcast
#WP_FLAGS  += -wp-fct random_shuffle
#WP_FLAGS  += -wp-prop reorder
#WP_FLAGS  += -wp-prop MultisetTransposition

#WP_FLAGS += -wp-prop @lemma


TESTOBJ += -lmutating -lc

