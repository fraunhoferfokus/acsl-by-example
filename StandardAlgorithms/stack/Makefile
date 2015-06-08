
include ../Makefile.call

clean:: FORCE
	$(RM) libstack.a

OBJ := \
	stack_init/stack_init.o\
	stack_equal/stack_equal.o\
	stack_size/stack_size.o\
	stack_empty/stack_empty.o\
	stack_full/stack_full.o\
	stack_top/stack_top.o\
	stack_push/stack_push.o\
	stack_pop/stack_pop.o

lib: libstack.a

libstack.a: obj FORCE
	@ar cru  $@ $(OBJ)
	@ranlib  $@

