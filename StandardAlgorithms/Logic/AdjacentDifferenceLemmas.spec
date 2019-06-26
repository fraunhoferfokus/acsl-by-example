
#ifndef ADJACENTDIFFERENCELEMMAS_SPEC_INCLUDED
#define ADJACENTDIFFERENCELEMMAS_SPEC_INCLUDED

#include "AdjacentDifference.spec"

/*@
  lemma
    AdjacentDifferenceStep{K,L}:
      \forall value_type *a, *b, integer n;
        AdjacentDifference{K}(a, n, b)      ==>
        Unchanged{K,L}(b, n)                ==>
        Unchanged{K,L}(a, n+1)              ==>
        \at(b[n],L) == Difference{L}(a, n)  ==>
        AdjacentDifference{L}(a, 1+n, b);

  lemma
    AdjacentDifferenceSection{K}:
      \forall value_type *a, *b, integer m, n;
        0 <= m <= n                     ==>
        AdjacentDifference{K}(a, n, b)  ==>
        AdjacentDifference{K}(a, m, b);
*/

#endif /* ADJACENTDIFFERENCELEMMAS_SPEC_INCLUDED */

