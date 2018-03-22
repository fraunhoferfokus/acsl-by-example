#!/bin/bash
# Script to obtain the relation "which lemma was included in the proof
# of which algorithm".
# To be called from directory StandardAlgorithms/ 
# after "make preport" has been run for all altorithms.

find . -name "*_Coq.v" | cut -d "/" -f 3,6 | tr "/" " " | sed s/lemma_// | sed s/_Coq.v//
