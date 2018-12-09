#ifndef UNIQUE_MAPPING_H_INCLUDED
#define UNIQUE_MAPPING_H_INCLUDED

#include "UniqueCount.h"

/*@
  predicate
    UniqueMapping{L}(value_type *a, integer n, value_type *b) =
      \forall integer i; 0 <= i < n ==>
        a[i] == b[UniqueCount(a, i)];
*/

#endif /* UNIQUE_MAPPING_H_INCLUDED */

