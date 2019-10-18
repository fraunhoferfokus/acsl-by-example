
# used for Frama-Clang
%.cpp:%.c
	cp $< $@

%.check:%.c
	@$(FR) $(WP_C_FLAGS) -wp-check -wp-out $(patsubst %.c,%.wp, $<)  $<

# only generate proof obligations for why3
%.why3:%.c FORCE
	@$(FR) $(WP_C_FLAGS) $(WP_TIME_FLAGS) -wp-prover why3 -wp-gen -wp-out $(patsubst %.c,%.wp, $<) $<

# start FR on command line and run provers
%.wp:%.c $(DRIVER) FORCE
	@$(FR) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $@ $<

%.wp++:%.cpp FORCE
	@$(FR) $(WP_CXX_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $@ $<

%.vs-par:%.c FORCE
	@$(VS_DIR)/vs.sh -p $< $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(notdir $(patsubst %.c,%.wp, $<))

%.vs-pipe:%.c FORCE
	@$(VS_DIR)/vs.sh -d $< $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(notdir $(patsubst %.c,%.wp, $<))

%.wprunner:%.c FORCE
	@$(SCRIPT_DIR)/wp_runner.sh $< $(WP_C_FLAGS) $(WP_PROVER_FLAGS) -wp-par $(WP_PROCESSES)

%.av:%.c $(AV_WHY3_CONF) FORCE
	@$(AV_C_REPORT) -av-out $@ $<

# GUI
%.avgui:%.c $(AV_WHY3_CONF) FORCE
	@$(FR) $(AV_C_FLAGS) -av-why3-opt " --extra-config $(AV_WHY3_CONF) " -av-out $(patsubst %.c,%.av, $<) $<

# start FR GUI and run provers
%.wpgui:%.c $(DRIVER) FORCE
	@($(FRGUI) $(WP_C_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(patsubst %.c,%.wp, $<)  $< &)

%.wpgui++:%.cpp FORCE
	@($(FRGUI) $(WP_CXX_FLAGS) $(WP_PROVER_FLAGS) $(WP_TIME_FLAGS) -wp-out $(patsubst %.cpp,%.wp++, $<)  $< )

%.normal.c : %.c FORCE
	@$(FR) $(WP_C_FLAGS) -wp-no-rte -wp-check -wp-prover none $< -print |\
	$(PERL) -e 'my $$f = join("", <>); $$f =~ s!\A.*(?=/\*@.*\*/[^/]*$*\([^)]++\)\s*+\{)!!s; print $$f;' > $@

%.normal-rte.c : %.c FORCE
	@$(FR) $(WP_C_FLAGS) -wp-check -wp-prover none $< -print |\
	$(PERL) -e 'my $$f = join("", <>); $$f =~ s!\A.*(?=/\*@.*\*/[^/]*$*\([^)]++\)\s*+\{)!!s; print $$f;' > $@

