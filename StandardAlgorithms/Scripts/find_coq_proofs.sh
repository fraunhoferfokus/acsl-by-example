#!/bin/bash

find . -name "*_Coq.v" | cut -d "/" -f 3,6 | tr "/" " " | sed s/lemma_// | sed s/_Coq.v//
