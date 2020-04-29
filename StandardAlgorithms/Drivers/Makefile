FRAMAC_SHARE:=$(shell frama-c -print-share-path)

compile: Shift_lemmas.vo
	# use an old date so make won't think that something needs to be
	# remade just because the coq files were recompiled
	touch -t 197001020000 driver

proof: FORCE
	@(coqide -R $(FRAMAC_SHARE)/wp/coqwp "" Shift_lemmas.v &)

%.vo:%.v
	coqc -R $(FRAMAC_SHARE)/wp/coqwp "" $<

clean: FORCE
	@$(RM)	.lia.cache .*.aux *.glob *.vo driver

FORCE:

