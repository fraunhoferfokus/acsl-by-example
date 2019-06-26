
MAKEFLAGS += --silent --no-print-directory

FILELIST = filelist.path
EXAMPLES := $(shell cat $(FILELIST))

it: lib

clean:
	@($(RM) -rf errorlogs)
	$(RM) *.back
	$(RM) astraver.why3.conf
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
	@rm -f Results/*.report

preport:
	@for i in $(EXAMPLES);\
	do \
		(echo "preport $$i"; $(MAKE) preport -sC $$i);\
	done

preport-clean:
	@rm -f Results/*.preport

areport:
	@for i in $(EXAMPLES);\
	do \
		(echo "areport $$i"; $(MAKE) areport -sC $$i);\
	done

areport-clean:
	@rm -f Results/*.areport

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

