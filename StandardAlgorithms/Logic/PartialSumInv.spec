
#ifndef PARTIALSUMINV_SPEC_INCLUDED
#define PARTIALSUMINV_SPEC_INCLUDED

#include "PartialSum.spec"
#include "AdjacentDifference.spec"

/*@
  lemma
    PartialSumInv{K,L}:
      \forall value_type *a, *b, integer n;
        0 <= n                          ==>
        PartialSum{K}(a, n, b)          ==>
        Unchanged{K,L}(b, n)            ==>
        AdjacentDifference{L}(b, n, a)  ==>
        Unchanged{K,L}(a, n);
*/

#endif /* PARTIALSUMINV_SPEC_INCLUDED */

