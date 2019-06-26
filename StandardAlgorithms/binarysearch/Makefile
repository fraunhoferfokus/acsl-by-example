
include ../Makefile.group

clean:: FORCE
	$(RM) libbinarysearch.a

lib: libbinarysearch.a

libbinarysearch.a: obj $(OBJ)
	@ar cr  $@ $(OBJ)
	@ranlib  $@

