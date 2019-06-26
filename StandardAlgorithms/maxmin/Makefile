
include ../Makefile.group

clean:: FORCE
	$(RM) libmaxmin.a

lib: libmaxmin.a

libmaxmin.a: obj $(OBJ)
	@ar cr  $@ $(OBJ)
	@ranlib  $@


