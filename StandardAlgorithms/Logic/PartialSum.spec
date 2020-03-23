
#ifndef PARTIALSUM_SPEC_INCLUDED
#define PARTIALSUM_SPEC_INCLUDED

#include "AccumulateDefault.spec"

/*@
  axiomatic PartialSum
  {
    predicate
    PartialSum{L}(value_type* a, integer n, value_type* b) =
      \forall integer i; 0 <= i < n  ==>  b[i] == AccumulateDefault(a, i);

    lemma PartialSumSection{K}:
      \forall value_type *a, *b, integer m, n;
      0 <= m <= n             ==>
      PartialSum{K}(a, n, b)  ==>
      PartialSum{K}(a, m, b);

    lemma PartialSumUnchanged{K,L}:
      \forall value_type *a, *b, integer n;
        0 <= n  ==>
        PartialSum{K}(a, n, b)  ==>
        Unchanged{K, L}(a, n)   ==>
        Unchanged{K, L}(b, n)   ==>
        PartialSum{L}(a, n, b);

    lemma PartialSumStep{L}:
      \forall value_type *a, *b, integer n;
        0 <= n                           ==>
        PartialSum(a, n, b)              ==>
        b[n] == AccumulateDefault(a, n)  ==>
        PartialSum(a, n+1, b);
  }
*/

#endif /* PARTIALSUM_SPEC_INCLUDED */

