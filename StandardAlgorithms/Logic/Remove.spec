
#ifndef REMOVE_SPEC_INCLUDED
#define REMOVE_SPEC_INCLUDED

#include "RemovePartition.spec"

/*@
  predicate
    Remove{A,B}(value_type* a, integer n,
                value_type* b, value_type v) =
      \forall integer k; 0 <= k < RemoveSize{A}(a, n, v) ==>
        \at(b[k],B) == \at(a[RemovePartition(a, n, v, k)],A);

  predicate
    Remove{A,B}(value_type* a, integer n, value_type v) =
      Remove{A,B}(a, n, a, v);
*/

#endif // REMOVE_H_INCLUDED

