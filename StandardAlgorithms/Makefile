
MAKEFLAGS += --silent --no-print-directory

FILELIST = filelist.path
EXAMPLES := $(shell cat $(FILELIST))

report:
	@for i in $(EXAMPLES);\
	do \
		(echo "verify $$i"; $(MAKE) report -sC $$i);\
	done

report-clean:
	@for i in $(EXAMPLES);\
	do \
		(echo "report-clean $$i"; $(MAKE) report-clean -sC $$i);\
	done

log:
	@($(MAKE) report > results.txt)

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

