
MAKEFLAGS += --silent --no-print-directory

FILELIST = filelist.path
EXAMPLES := $(shell cat $(FILELIST))

it: lib

clean:
	@($(RM) -rf errorlogs)
	@$(RM) *.back
	@$(RM) astraver.why3.conf
	@ $(MAKE) -f all-action.mk clean
	@for i in drivers $(EXAMPLES);\
        do \
                (echo "clean $$i"; $(MAKE) clean -sC $$i);\
        done

report:
	@for i in $(EXAMPLES);\
	do \
		(echo "report $$i"; $(MAKE) report -sC $$i);\
	done

report-clean:
	@for i in $(EXAMPLES);\
	do \
		(echo "report clean $$i"; $(MAKE) report-clean -sC $$i);\
	done

preport:
	@for i in $(EXAMPLES);\
	do \
		(echo "preport $$i"; $(MAKE) preport -sC $$i);\
	done

preport-clean:
	@for i in $(EXAMPLES);\
	do \
		(echo "preport clean $$i"; $(MAKE) preport-clean -sC $$i);\
	done

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
		(echo "test $$i"; $(MAKE) test -sC $$i || break);\
	done

lib:
	@for i in $(EXAMPLES);\
	do \
		(echo "make lib $$i"; $(MAKE) lib -sC $$i);\
	done

group-files:
	@for i in $(EXAMPLES);\
	do \
		($(MAKE) group-files -sC $$i);\
	done

group-report:
	@for i in $(EXAMPLES);\
	do \
		($(MAKE) group-report -sC $$i);\
	done

group-report-clean:
	@for i in $(EXAMPLES);\
	do \
		($(MAKE) group-report-clean -sC $$i);\
	done

group-preport:
	@for i in $(EXAMPLES);\
	do \
		($(MAKE) group-preport -sC $$i);\
	done

group-preport-clean:
	@for i in $(EXAMPLES);\
	do \
		($(MAKE) group-preport-clean -sC $$i);\
	done


all-files: group-files
	$(MAKE) -f all-action.mk source header

all-report: all-files
	$(MAKE) -f all-action.mk report

all-report-clean:
	$(MAKE) -f all-action.mk report-clean

all-preport: all-files
	$(MAKE) -f all-action.mk preport

all-preport-clean:
	$(MAKE) -f all-action.mk preport-clean

format:
	@for i in $(EXAMPLES);\
        do \
                (echo "format $$i"; $(MAKE) format -sC $$i);\
        done

