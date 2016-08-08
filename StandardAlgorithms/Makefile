
MAKEFLAGS += --silent --no-print-directory

EXAMPLES := nonmutating maxmin binarysearch mutating numeric heap stack

report:
	@for i in $(EXAMPLES);\
	do \
		(echo "verify $$i"; $(MAKE) report -sC $$i);\
	done

log:
	@(time $(MAKE) report > results.txt)


tex:
	@for i in $(EXAMPLES);\
	do \
		(echo "verify $$i"; $(MAKE) tex -sC $$i);\
	done


test: lib
	@for i in $(EXAMPLES);\
	do \
		(echo "test $$i"; cd "$$i"; $(MAKE) -s test || break);\
	done

lib:
	@for i in $(EXAMPLES);\
	do \
		(echo "make lib $$i"; $(MAKE) lib -sC $$i);\
	done

clean:
	@($(RM) -rf errorlogs);\
	$(RM) *.back
	@(echo "clean coq"; $(MAKE) clean -sC coq);
	@for i in $(EXAMPLES);\
        do \
                (echo "clean $$i"; $(MAKE) clean -sC $$i);\
        done
			

format:
	@for i in $(EXAMPLES);\
        do \
                (echo "format $$i"; $(MAKE) format -sC $$i);\
        done

