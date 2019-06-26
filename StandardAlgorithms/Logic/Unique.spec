
#ifndef UNIQUE_SPEC_INCLUDED
#define UNIQUE_SPEC_INCLUDED

#include "UniquePartition.spec"

/*@
  predicate
    Unique(value_type* a, integer n, value_type* b) =
      \forall integer k; 0 <= k < UniqueSize(a, n) ==>
        b[k] == a[UniquePartition(a, n, k)];
*/

#endif /* UNIQUE_SPEC_INCLUDED */

