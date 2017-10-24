
include ../Makefile.group

OBJ := lower_bound/lower_bound.o\
       upper_bound/upper_bound.o\

clean:: FORCE
	$(RM) libbinarysearch.a

lib: libbinarysearch.a

libbinarysearch.a: obj FORCE
	@ar cr  $@ $(OBJ)
	@ranlib  $@

