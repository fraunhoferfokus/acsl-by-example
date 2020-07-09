
MAKEFLAGS += --silent --no-print-directory

FILELIST = filelist.path
EXAMPLES := $(shell cat $(FILELIST))
ALLMAKE  := Config/all-action.mk

.PHONY: $(EXAMPLES)

it: lib

lib:			$(EXAMPLES)
test:			$(EXAMPLES)
clean::			$(EXAMPLES)
format:			$(EXAMPLES)
report-clean:		$(EXAMPLES)
qreport-clean:		$(EXAMPLES)
preport-clean:		$(EXAMPLES)
areport-clean:		$(EXAMPLES)
group-files:		$(EXAMPLES)
group-report-clean:	$(EXAMPLES)
group-preport-clean:	$(EXAMPLES)

$(EXAMPLES):
	(echo $@; make -sC $@ $(MAKECMDGOALS))


clean::
	@$(RM) -rf errorlogs
	@$(RM) *.back
	@$(RM) astraver.why3.conf
	@$(MAKE) clean -sC Scripts
	@$(MAKE) clean -sC Drivers
	@$(MAKE) -f $(ALLMAKE) clean

report:
	@for i in $(EXAMPLES);\
	do \
		(echo "report $$i"; $(MAKE) report -sC $$i);\
	done

qreport:
	@for i in $(EXAMPLES);\
	do \
		(echo "qreport $$i"; $(MAKE) qreport -sC $$i);\
	done

preport:
	@for i in $(EXAMPLES);\
	do \
		(echo "preport $$i"; $(MAKE) preport -sC $$i);\
	done

areport:
	@for i in $(EXAMPLES);\
	do \
		(echo "areport $$i"; $(MAKE) areport -sC $$i);\
	done

group-report:
	@for i in $(EXAMPLES);\
	do \
		($(MAKE) group-report -sC $$i);\
	done

group-preport:
	@for i in $(EXAMPLES);\
	do \
		($(MAKE) group-preport -sC $$i);\
	done


all-files: group-files
	$(MAKE) -f $(ALLMAKE) source header

all-report: all-files
	$(MAKE) -f $(ALLMAKE) report

all-report-clean:
	$(MAKE) -f $(ALLMAKE) report-clean

all-preport: all-files
	$(MAKE) -f $(ALLMAKE) preport

all-preport-clean:
	$(MAKE) -f $(ALLMAKE) preport-clean

