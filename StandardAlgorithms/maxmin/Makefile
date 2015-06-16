
include ../Makefile.call

OBJ := max_element2/max_element2.o

clean::
	$(RM) libmaxmin.a

lib: libmaxmin.a

libmaxmin.a: obj FORCE
	@ar cru  $@ $(OBJ)
	@ranlib  $@


