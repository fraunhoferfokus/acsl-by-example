
FILE=stack_full
CMD=\\stackfull
SEC=sec:stackfull

include ../../Makefile.template

TESTOBJ += -lstack

check_full: check_full.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -o $@ $< -L.. -lstack -L../../nonmutating -lnonmutating

clean::
	$(RM) check_full
