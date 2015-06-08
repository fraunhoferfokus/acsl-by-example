
include ../Makefile.call

OBJ := lower_bound/lower_bound.o\
       upper_bound/upper_bound.o\

clean:: FORCE libbinarysearch.a
	$(RM)

lib: libbinarysearch.a

libbinarysearch.a: obj FORCE
	@ar cru  $@ $(OBJ)
	@ranlib  $@

