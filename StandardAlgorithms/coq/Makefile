
it: compile

proof: FORCE
	@(coqide -R $(FRAMAC_SHARE)/wp/coqwp -as "" WP_basics.v &)


compile: FORCE
	coqc -R $(FRAMAC_SHARE)/wp/coqwp -as "" WP_basics.v


clean: FORCE
	@$(RM)	lia.cache
	@$(RM)	WP_basics.glob
	@$(RM)	WP_basics.vo


FORCE:

