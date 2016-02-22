
#ifndef HASVALUE_H_INCLUDED
#define HASVALUE_H_INCLUDED

#include "typedefs.h"

/*@
  predicate
    HasValue{A}(value_type* a, integer n, value_type v) =
      \exists integer i; 0 <= i < n && a[i] == v;
*/

#endif /* HASVALUE_H_INCLUDED */
