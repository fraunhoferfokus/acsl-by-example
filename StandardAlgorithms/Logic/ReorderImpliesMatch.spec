
#ifndef REORDERIMPLIESMATCH_SPEC_INCLUDED
#define REORDERIMPLIESMATCH_SPEC_INCLUDED

#include "HasValueImpliesPositiveCount.spec"
#include "PositiveCountImpliesHasValue.spec"

/*@
  lemma
    ReorderImpliesMatch{K,L}:
      \forall value_type *a, integer i, n;
        0 <= i < n                    ==>
        MultisetUnchanged{K,L}(a, n)  ==>
        HasValue{K}(a, n, \at(a[i],L));
*/

#endif /* REORDERIMPLIESMATCH_SPEC_INCLUDED */

