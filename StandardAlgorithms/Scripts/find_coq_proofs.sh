#!/bin/bash
# find all proof obligations that have been verified with coq

find . -name console.log -exec grep -w Coq {} \; | grep Valid | cut -d ' ' -f 5 | sed 's/typed_external_lemma_//' | sort -u 

# Show pairs of algorithm and verified lemma 
#find . -name console.log -exec grep -H Coq {} \; | grep Valid | cut -d '/' -f 3,5 | cut -d ' ' -f 1,5 | sed 's/\// /' | cut -d ' ' -f 1,3 | sed 's/typed_external_lemma_//' | sort
