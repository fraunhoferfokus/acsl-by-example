
#ifndef PARTIALSUMINVERSE_H_INCLUDED
#define PARTIALSUMINVERSE_H_INCLUDED

#include "PartialSum.h"
#include "AdjacentDifference.h"

/*@
  lemma PartialSumInverse{K,L}:
    \forall value_type *a, *b, integer n;
      0 <= n                          ==> 
      PartialSum{K}(a, n, b)          ==>
      Unchanged{K,L}(b, n)            ==>
      AdjacentDifference{L}(b, n, a)  ==>
      Unchanged{K,L}(a, n);
*/

#endif /* PARTIALSUMINVERSE_H_INCLUDED */

