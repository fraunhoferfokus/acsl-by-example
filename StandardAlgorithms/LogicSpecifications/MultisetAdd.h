
#ifndef MULTISETADD_H_INCLUDED
#define MULTISETADD_H_INCLUDED

#include "CountLogic.h"

/*@
  predicate
    MultisetAdd{K,L}(value_type* a, integer n, value_type val) =
      Count{L}(a, n, val) == Count{K}(a, n, val) + 1;
*/

#endif /* MULTISETADD_H_INCLUDED */

