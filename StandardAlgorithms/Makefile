
MAKEFLAGS += --silent --no-print-directory

FILELIST = filelist.path
EXAMPLES := $(shell cat $(FILELIST))

.PHONY: $(EXAMPLES)

it: lib

lib:			$(EXAMPLES)
test:			$(EXAMPLES)
clean::			$(EXAMPLES)
format:			$(EXAMPLES)

$(EXAMPLES):
	(echo $@; make -sC $@ $(MAKECMDGOALS))


clean::
	@$(RM) -rf errorlogs
	@$(RM) *.back
	@$(MAKE) clean -sC Scripts
	@$(MAKE) clean -sC Drivers


dist-clean: clean
	@$(RM) -rf cache
	

wp:
	@for i in $(EXAMPLES);\
	do \
		(echo "wp $$i"; $(MAKE) wp -sC $$i);\
	done

report:
	@for i in $(EXAMPLES);\
	do \
		(echo "report $$i"; $(MAKE) report -sC $$i);\
	done

result:
	@for i in $(EXAMPLES);\
	do \
		(echo "result $$i"; $(MAKE) result -sC $$i);\
	done

result-clean:
	@$(RM) Results/*.json


