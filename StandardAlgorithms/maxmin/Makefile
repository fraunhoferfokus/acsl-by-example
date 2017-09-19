
include ../Makefile.call

OBJ := max_element2/max_element2.o\
       min_element/min_element.o

clean::
	$(RM) libmaxmin.a

lib: libmaxmin.a

libmaxmin.a: obj FORCE
	@ar cr  $@ $(OBJ)
	@ranlib  $@


