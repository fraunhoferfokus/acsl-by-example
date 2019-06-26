

# add special targets to enable testing with pop_heap

clean:: FORCE
	$(RM) libheap.a


include ../Makefile.group

lib: libheap.a

libheap.a: obj $(OBJ)
	@ar cr  $@ $(OBJ)
	@ranlib  $@

