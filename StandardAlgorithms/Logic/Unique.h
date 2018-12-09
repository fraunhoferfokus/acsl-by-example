
#ifndef UNIQUE_LOGIC_H_INCLUDED
#define UNIQUE_LOGIC_H_INCLUDED

#include "UniquePartition.h"

/*@
  predicate
    Unique(value_type* a, integer n, value_type* b) =
      \forall integer k; 0 <= k < UniqueSize(a, n) ==>
        b[k] == a[UniquePartition(a, n, k)];
*/

#endif /* UNIQUE_LOGIC_H_INCLUDED */

