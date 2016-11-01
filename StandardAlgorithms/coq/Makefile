compile: WP_basics.vo
	# use an old date so make won't think that something needs to be
	# remade just because the coq files were recompiled
	touch -t 197001020000 driver

proof: FORCE
	@(coqide -R $(FRAMAC_SHARE)/wp/coqwp -as "" WP_basics.v &)

%.vo:%.v
	coqc -R $(FRAMAC_SHARE)/wp/coqwp -as "" $<

clean: FORCE
	@$(RM)	lia.cache
	@$(RM)	WP_basics.glob
	@$(RM)	WP_basics.vo
	@$(RM)  driver

FORCE:

