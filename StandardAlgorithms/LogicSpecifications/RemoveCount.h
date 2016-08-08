
#ifndef REMOVECOUNT_H_INCLUDED
#define REMOVECOUNT_H_INCLUDED

#include "CountLogic.h"

/*@
  logic
    integer RemoveCount{L}(value_type* a, integer i, value_type v) =
      i - Count{L}(a, i, v);

  lemma RemoveCountEmpty:
     \forall value_type *a, v, integer i;
        i <= 0 ==> RemoveCount(a, i, v) == i;

  lemma RemoveCountHit:
     \forall value_type *a, v, integer i; a[i] == v ==>
       RemoveCount(a, i+1, v) == RemoveCount(a, i, v);

  lemma RemoveCountMiss:
     \forall value_type *a, v, integer i; a[i] != v ==>
        RemoveCount(a, i+1, v) == RemoveCount(a, i, v) + 1;

  lemma RemoveCountRead{L1,L2}:
     \forall value_type *a, v, integer i; Unchanged{L1,L2}(a, i) ==>
        RemoveCount{L1}(a, i, v) == RemoveCount{L2}(a, i, v);
*/

#endif /* REMOVECOUNT_H_INCLUDED */

