
#ifndef ACCUMULATE_SPEC_INCLUDED
#define ACCUMULATE_SPEC_INCLUDED

#include "Unchanged.spec"

/*@
  axiomatic AccumulateAxiomatic
  {
    logic integer
      Accumulate{L}(value_type* a, integer n, value_type init) =
        n <= 0 ? init : Accumulate(a, n-1, init) + a[n-1];

    lemma
      AccumulateRead{K,L}:
        \forall value_type *a, init, integer n;
          Unchanged{K,L}(a, n) ==>
            Accumulate{K}(a, n, init) == Accumulate{L}(a, n, init);
  }
*/

#endif /* ACCUMULATE_SPEC_INCLUDED */

