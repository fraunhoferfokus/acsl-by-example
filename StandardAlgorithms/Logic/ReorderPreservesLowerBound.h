
#ifndef REORDERPRESERVESLOWERBOUND_H_INCLUDED
#define REORDERPRESERVESLOWERBOUND_H_INCLUDED

#include "MultisetUnchanged.h"
#include "LowerBound.h"
#include "ReorderImpliesMatch.h"

/*@
  lemma
    ReorderPreservesLowerBound{K,L}:
      \forall value_type* a, integer n, value_type v;
        0 <= n                       ==>
        MultisetUnchanged{K,L}(a, n) ==>
        LowerBound{K}(a, n, v)       ==>
        LowerBound{L}(a, n, v);
*/

#endif /* REORDERPRESERVESLOWERBOUND_H_INCLUDED */

