
include ../Makefile.group

clean:: FORCE
	$(RM) libmutating.a

OBJ :=  fill/fill.o\
	swap/swap.o\
	swap_ranges/swap_ranges.o\
	copy/copy.o\
	reverse_copy/reverse_copy.o\
	reverse/reverse.o\
	rotate_copy/rotate_copy.o\
	rotate/rotate.o\
	replace_copy/replace_copy.o\
	random_shuffle/random_shuffle.o

lib: libmutating.a

libmutating.a: obj FORCE
	@ar cr  $@ $(OBJ)
	@ranlib  $@

