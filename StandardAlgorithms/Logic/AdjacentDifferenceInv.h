
#ifndef ADJACENTDIFFERENCEINV_H_INCLUDED
#define ADJACENTDIFFERENCEINV_H_INCLUDED

#include "AdjacentDifferenceLemmas.h"
#include "PartialSumLemmas.h"
#include "UnchangedSection.h"

/*@
  lemma
    AdjacentDifferenceInv{K,L}:
      \forall  value_type *a, *b, integer n;
        0 <= n                          ==> 
        AdjacentDifference{K}(a, n, b)  ==>
        Unchanged{K,L}(b, n)            ==>
        PartialSum{L}(b, n, a)          ==>
        Unchanged{K,L}(a, n);
*/

#endif /* ADJACENTDIFFERENCEINV_H_INCLUDED */

