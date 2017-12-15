
#ifndef PARTIALSUMLEMMAS_H_INCLUDED
#define PARTIALSUMLEMMAS_H_INCLUDED

#include "PartialSum.h"

/*@
  lemma
    PartialSumSection{K}:
      \forall value_type *a, *b, integer m, n;
      0 <= m <= n            ==>
      PartialSum{K}(a, n, b) ==>
      PartialSum{K}(a, m, b);

  lemma
    PartialSumUnchanged{K,L}:
      \forall value_type *a, *b, integer n;
        0 <= n ==>
        PartialSum{K}(a, n, b) ==>
        Unchanged{K, L}(a, n)  ==>
        Unchanged{K, L}(b, n)  ==>
        PartialSum{L}(a, n, b);

  lemma
    PartialSumStep{L}:
      \forall value_type *a, *b, integer n;
        1 <= n                     ==>
        PartialSum(a, n, b)        ==>
        b[n] == Accumulate(a, n+1) ==>
        PartialSum(a, n+1, b);

  lemma
    PartialSumStep2{K,L}:
      \forall value_type *a, *b, integer n;
        1 <= n                            ==>
        PartialSum{K}(a, n, b)            ==>
        Unchanged{K,L}(a, n+1)            ==>
        Unchanged{K,L}(b, n)              ==>
        \at(b[n] == Accumulate(a, n+1),L) ==>
        PartialSum{L}(a, n+1, b);
*/

#endif /* PARTIALSUMLEMMAS_H_INCLUDED */

