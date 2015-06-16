
include ../Makefile.call

clean:: FORCE
	$(RM) libmutating.a

OBJ :=  fill/fill.o\
	swap/swap.o\
	swap_ranges/swap_ranges.o\
	copy/copy.o\
	reverse_copy/reverse_copy.o\
	reverse/reverse.o\
	rotate_copy/rotate_copy.o\
	replace_copy/replace_copy.o\
	remove_copy2/remove_copy2.o\

lib: libmutating.a

libmutating.a: obj FORCE
	@ar cru  $@ $(OBJ)
	@ranlib  $@

