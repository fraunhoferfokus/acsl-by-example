
MAKEFLAGS += --silent --no-print-directory

FILELIST = filelist.path
EXAMPLES := $(shell cat $(FILELIST))


clean:
	@($(RM) -rf errorlogs);\
	$(RM) *.back
	@for i in drivers $(EXAMPLES);\
        do \
                (echo "clean $$i"; $(MAKE) clean -sC $$i);\
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
	@for i in $(EXAMPLES);\
	do \
		(echo "delete report $$i"; $(MAKE) report-clean -sC $$i);\
	done

preport:
	@for i in $(EXAMPLES);\
	do \
		(echo "preport $$i"; $(MAKE) preport -sC $$i);\
	done

preport-clean:
	@for i in $(EXAMPLES);\
	do \
		(echo "delete preport $$i"; $(MAKE) preport-clean -sC $$i);\
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

format:
	@for i in $(EXAMPLES);\
        do \
                (echo "format $$i"; $(MAKE) format -sC $$i);\
        done

