
include ../Makefile.group

clean:: FORCE
	$(RM) libnumeric.a

lib: libnumeric.a

libnumeric.a: obj $(OBJ)
	@ar cr  $@ $(OBJ)
	@ranlib  $@

