
#ifndef UNCHANGED_SPEC_INCLUDED
#define UNCHANGED_SPEC_INCLUDED

#include "typedefs.h"

/*@
  axiomatic Unchanged
  {
    predicate
    Unchanged{K,L}(value_type* a, integer m, integer n) =
      \forall integer i; m <= i < n ==>  \at(a[i],K) == \at(a[i],L);

    predicate
    Unchanged{K,L}(value_type* a, integer n) = Unchanged{K,L}(a, 0, n);
  }
*/

#endif /* UNCHANGED_SPEC_INCLUDED */

