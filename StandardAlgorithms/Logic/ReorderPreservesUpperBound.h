
#ifndef REORDERPRESERVESUPPERBOUND_H_INCLUDED
#define REORDERPRESERVESUPPERBOUND_H_INCLUDED

#include "MultisetUnchanged.h"
#include "UpperBound.h"

/*@
  lemma
    ReorderPreservesUpperBound{K,L}:
      \forall value_type* a, integer n, value_type v;
        0 <= n                       ==>
        MultisetUnchanged{K,L}(a, n) ==>
        UpperBound{K}(a, n, v)       ==>
        UpperBound{L}(a, n, v);
*/

#endif /* REORDERPRESERVESUPPERBOUND_H_INCLUDED */

