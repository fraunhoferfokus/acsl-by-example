
#ifndef PARTIALREORDERPRESERVESLOWERBOUNDS_H_INCLUDED
#define PARTIALREORDERPRESERVESLOWERBOUNDS_H_INCLUDED

#include "Unchanged.h"
#include "MultisetUnchanged.h"
#include "ReorderPreservesLowerBound.h"

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

#endif /* PARTIALREORDERPRESERVESLOWERBOUNDS_H_INCLUDED */

