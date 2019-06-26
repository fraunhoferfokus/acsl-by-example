
include ../Makefile.group

clean:: FORCE
	$(RM) libnonmutating.a

lib: libnonmutating.a

libnonmutating.a: obj $(OBJ)
	@ar cr  $@ $(OBJ)
	@ranlib  $@

