
#ifndef PARTITION_H_INCLUDED
#define PARTITION_H_INCLUDED

#include "typedefs.h"

/*@
  predicate
    Partition{L}(value_type* a, integer m, integer n) =
      0 <= m <= n ==>
      \forall integer i, k; 0 <= i < m <= k < n ==> a[i] <= a[k];
*/

#endif /* PARTITION_H_INCLUDED */

