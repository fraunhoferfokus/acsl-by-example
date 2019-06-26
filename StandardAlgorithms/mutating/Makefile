
include ../Makefile.group

clean:: FORCE
	$(RM) libmutating.a

lib: libmutating.a

libmutating.a: obj $(OBJ)
	@ar cr  $@ $(OBJ)
	@ranlib  $@

