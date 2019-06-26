
include ../Makefile.group

clean:: FORCE
	$(RM) libunique.a

lib: libunique.a

libunique.a: obj $(OBJ)
	@ar cr  $@ $(OBJ)
	@ranlib  $@

