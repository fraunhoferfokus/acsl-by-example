include ../Makefile.group

OBJ := \
	stack_empty_wd/stack_empty_wd.o\
	stack_pop_wd/stack_pop_wd.o\
	stack_push_wd/stack_push_wd.o\
	stack_size_wd/stack_size_wd.o\
	stack_top_wd/stack_top_wd.o

clean::
	$(RM) libstack_wd.a

lib: libstack_wd.a

libstack_wd.a: obj FORCE
	@ar cr $@ $(OBJ)
	@ranlib $@
