
# used for Frama-Clang
%.cpp:%.c
	cp $< $@

%.check:%.c
	@$(FR) $(WP_C_FLAGS) -wp-check -wp-out $(patsubst %.c,%.wp, $<)  $<

# only generate proof obligations for why3
%.why3:%.c FORCE
	@$(FR) $(WP_C_FLAGS) $(WP_TIME_FLAGS) -wp-prover why3 -wp-gen -wp-out $(patsubst %.c,%.wp, $<) $<

# start FR on command line and run provers
%.wp:%.c 
	@$(FR) $(WP_C_FLAGS) $(WP_TIME_FLAGS) $(WP_PROVER_FLAGS) -wp-out $@ $<

EXTRA_PROP?=
FR_WP_FLAGS = $(FR) $(WP_C_FLAGS) $(EXTRA_PROP) $(WP_TIME_FLAGS)

# the following rules should be unified as much as possible

%.wp++:%.cpp 
	@$(FR) $(WP_CXX_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $@ $<

# start FR GUI and run provers
%.wpgui:%.c FORCE
	@($(FRGUI) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(patsubst %.c,%.wp, $<)  $< &)

%.wpgui++:%.cpp FORCE
	@($(FRGUI) $(WP_CXX_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(patsubst %.cpp,%.wp++, $<)  $< )

%.normal.c : %.c FORCE
	@$(FR) $(WP_C_FLAGS) -wp-no-rte -wp-check -wp-prover none $< -print |\
	$(PERL) -e 'my $$f = join("", <>); $$f =~ s!\A.*(?=/\*@.*\*/[^/]*$*\([^)]++\)\s*+\{)!!s; print $$f;' > $@

%.normal.rte.c : %.c FORCE
	@$(FR) $(WP_C_FLAGS) -wp-check -wp-prover none $< -print |\
	$(PERL) -e 'my $$f = join("", <>); $$f =~ s!\A.*(?=/\*@.*\*/[^/]*$*\([^)]++\)\s*+\{)!!s; print $$f;' > $@

