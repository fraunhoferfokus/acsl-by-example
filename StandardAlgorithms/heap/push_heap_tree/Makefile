
FILE=push_heap
CMD=\\pushheap
SEC=sec:pushheap

include ../../Makefile.template

clean::
	$(RM) heap

cleandata:
	$(RM) ./dotheaps/*
	$(RM) ./pdfheaps/*
	$(RM) heapsteps.pdf

heap: heap.o push_heap.o create_graph.o
	$(CXX) -o $@ $+

graph: heap
	mkdir -p ./dotheaps
	mkdir -p ./pdfheaps
	./heap
	python pdfmerge.py

#WP_FLAGS += -wp-prop @lemma
#WP_FLAGS += -wp-prop heap
#WP_FLAGS += -wp-prop isheap
WP_FLAGS += -wp-prop localheap

TESTOBJ += ../is_heap/is_heap.o

