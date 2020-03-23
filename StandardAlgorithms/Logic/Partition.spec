
#ifndef PARTITION_SPEC_INCLUDED
#define PARTITION_SPEC_INCLUDED

#include "typedefs.h"

/*@
  axiomatic Partition
  {
    predicate
    Partition{L}(value_type* a, integer m, integer n) =
      0 <= m <= n  ==>
      \forall integer i, k; 0 <= i < m <= k < n  ==>  a[i] <= a[k];
  }
*/

#endif /* PARTITION_SPEC_INCLUDED */

