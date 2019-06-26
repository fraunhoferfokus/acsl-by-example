
#ifndef ADJACENTDIFFERENCEINV_SPEC_INCLUDED
#define ADJACENTDIFFERENCEINV_SPEC_INCLUDED

#include "AdjacentDifferenceLemmas.spec"
#include "PartialSumLemmas.spec"
#include "UnchangedSection.spec"

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

#endif /* ADJACENTDIFFERENCEINV_SPEC_INCLUDED */

