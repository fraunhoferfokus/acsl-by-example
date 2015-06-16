
include ../Makefile.call

clean:: FORCE
	$(RM) libnumeric.a

OBJ :=  accumulate/accumulate.o\
	partial_sum/partial_sum.o\

lib: libnumeric.a

libnumeric.a: obj FORCE
	@ar cru  $@ $(OBJ)
	@ranlib  $@

