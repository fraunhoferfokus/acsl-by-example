
#ifndef REORDERPRESERVESLOWERBOUND_SPEC_INCLUDED
#define REORDERPRESERVESLOWERBOUND_SPEC_INCLUDED

#include "MultisetUnchanged.spec"
#include "LowerBound.spec"
#include "ReorderImpliesMatch.spec"

/*@
  lemma
    ReorderPreservesLowerBound{K,L}:
      \forall value_type* a, integer n, value_type v;
        0 <= n                       ==>
        MultisetUnchanged{K,L}(a, n) ==>
        LowerBound{K}(a, n, v)       ==>
        LowerBound{L}(a, n, v);
*/

#endif /* REORDERPRESERVESLOWERBOUND_SPEC_INCLUDED */

