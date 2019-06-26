
#ifndef PARTIALREORDERPRESERVESLOWERBOUNDS_SPEC_INCLUDED
#define PARTIALREORDERPRESERVESLOWERBOUNDS_SPEC_INCLUDED

#include "Unchanged.spec"
#include "MultisetUnchanged.spec"
#include "ReorderPreservesLowerBound.spec"

/*@
  lemma
    PartialReorderPreservesLowerBounds{K,L}:
      \forall value_type* a, integer m, n;
        0 < m <= n                                 ==>
        (\forall integer k; 0 <= k < m
          ==> LowerBound{K}(a, m, n, \at(a[k],K))) ==>
        MultisetUnchanged{K,L}(a, 0, m)            ==>
        Unchanged{K,L}(a, m, n)                    ==>
        LowerBound{L}(a, m, n, \at(a[0],L));
*/

#endif /* PARTIALREORDERPRESERVESLOWERBOUNDS_SPEC_INCLUDED */

