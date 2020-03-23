
#ifndef ACCUMULATEDEFAULT_SPEC_INCLUDED
#define ACCUMULATEDEFAULT_SPEC_INCLUDED

#include "Accumulate.spec"

/*@
  axiomatic AccumulateDefault
  {
    logic integer
    AccumulateDefault{L}(value_type* a, integer n) =
      Accumulate(a+1, n, (value_type)(a[0]));

    predicate
    AccumulateDefaultBounds{L}(value_type* a, integer n) =
      \forall integer i; 0 <= i < n  ==>
        VALUE_TYPE_MIN <= AccumulateDefault(a, i) <= VALUE_TYPE_MAX;

    lemma AccumulateDefaultRead{K,L}:
      \forall value_type *a, integer n;
        0 <= n                  ==>
        Unchanged{K,L}(a, n+1)  ==>
        AccumulateDefault{K}(a, n) == AccumulateDefault{L}(a, n);

    lemma AccumulateDefault_Zero{L}:
      \forall value_type* a; AccumulateDefault(a, 0) == a[0];

    lemma AccumulateDefault_One{L}:
      \forall value_type* a; AccumulateDefault(a, 1) == a[0] + a[1];

    lemma AccumulateDefault_Next{L}:
      \forall value_type* a, integer n;
        0 <= n  ==>
        AccumulateDefault(a, n+1) == AccumulateDefault(a, n) + a[n+1];
  }
*/

#endif /* ACCUMULATEDEFAULT_SPEC_INCLUDED */

