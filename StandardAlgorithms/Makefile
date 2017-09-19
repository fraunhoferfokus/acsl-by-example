
MAKEFLAGS += --silent --no-print-directory

FILELIST = filelist.path
EXAMPLES := $(shell cat $(FILELIST))

depend:
	@for i in $(EXAMPLES);\
	do \
		(echo "generate dependencies $$i"; $(MAKE) depend -sC $$i);\
	done

depend-clean:
	@for i in $(EXAMPLES);\
	do \
		(echo "depend-clean $$i"; $(MAKE) depend-clean -sC $$i);\
	done

generate:
	@for i in $(EXAMPLES);\
	do \
		(echo "generate $$i"; $(MAKE) generate -sC $$i);\
	done

report:
	@for i in $(EXAMPLES);\
	do \
		(echo "report $$i"; $(MAKE) report -sC $$i);\
	done

report-clean:
	@rm Results/*.report

preport:
	@for i in $(EXAMPLES);\
	do \
		(echo "preport $$i"; $(MAKE) preport -sC $$i);\
	done

preport-clean:
	@rm Results/*.preport

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
	@for i in drivers $(EXAMPLES);\
        do \
                (echo "clean $$i"; $(MAKE) clean -sC $$i);\
        done

format:
	@for i in $(EXAMPLES);\
        do \
                (echo "format $$i"; $(MAKE) format -sC $$i);\
        done

