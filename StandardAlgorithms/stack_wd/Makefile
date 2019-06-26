include ../Makefile.group

clean:: FORCE
	$(RM) libstack_wd.a

lib: libstack_wd.a

libstack_wd.a: obj $(OBJ)
	@ar cr $@ $(OBJ)
	@ranlib $@
