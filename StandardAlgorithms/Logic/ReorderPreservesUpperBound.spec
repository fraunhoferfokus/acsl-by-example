
#ifndef REORDERPRESERVESUPPERBOUND_SPEC_INCLUDED
#define REORDERPRESERVESUPPERBOUND_SPEC_INCLUDED

#include "MultisetUnchanged.spec"
#include "UpperBound.spec"

/*@
  lemma
    ReorderPreservesUpperBound{K,L}:
      \forall value_type* a, integer n, value_type v;
        0 <= n                       ==>
        MultisetUnchanged{K,L}(a, n) ==>
        UpperBound{K}(a, n, v)       ==>
        UpperBound{L}(a, n, v);
*/

#endif /* REORDERPRESERVESUPPERBOUND_SPEC_INCLUDED */

