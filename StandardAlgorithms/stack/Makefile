
include ../Makefile.group

clean:: FORCE
	$(RM) libstack.a

lib: libstack.a

libstack.a: obj $(OBJ)
	@ar cr  $@ $(OBJ)
	@ranlib  $@

