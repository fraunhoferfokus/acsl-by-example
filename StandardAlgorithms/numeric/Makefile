
include ../Makefile.call

clean:: FORCE
	$(RM) libnumeric.a

OBJ :=  accumulate/accumulate.o\
	partial_sum/partial_sum.o\
	adjacent_difference/adjacent_difference.o\

lib: libnumeric.a

libnumeric.a: obj FORCE
	@ar cr  $@ $(OBJ)
	@ranlib  $@

