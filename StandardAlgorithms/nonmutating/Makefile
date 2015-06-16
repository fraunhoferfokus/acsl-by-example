
include ../Makefile.call

OBJ := equal3/equal3.o\
       mismatch/mismatch.o\
       find2/find2.o\
       find_first_of/find_first_of.o\
       adjacent_find/adjacent_find.o\
       search/search.o count/count.o

clean::
	$(RM) libnonmutating.a

lib: libnonmutating.a

libnonmutating.a: obj FORCE
	@ar cru  $@ $(OBJ)
	@ranlib  $@


