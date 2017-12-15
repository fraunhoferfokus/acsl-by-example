
#ifndef REORDERIMPLIESMATCH_H_INCLUDED
#define REORDERIMPLIESMATCH_H_INCLUDED

#include "HasValueImpliesPositiveCount.h"
#include "PositiveCountImpliesHasValue.h"

/*@
  lemma
    ReorderImpliesMatch{K,L}:
      \forall value_type *a, integer i, n;
        0 <= i < n                    ==>
        MultisetUnchanged{K,L}(a, n)  ==>
        HasValue{K}(a, n, \at(a[i],L));
*/

#endif /* REORDERIMPLIESMATCH_H_INCLUDED */

