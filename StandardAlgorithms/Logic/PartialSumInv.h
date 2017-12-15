
#ifndef PARTIALSUMINV_H_INCLUDED
#define PARTIALSUMINV_H_INCLUDED

#include "PartialSum.h"
#include "AdjacentDifference.h"

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

#endif /* PARTIALSUMINV_H_INCLUDED */

