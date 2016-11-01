
#ifndef MULTISETMINUS_H_INCLUDED
#define MULTISETMINUS_H_INCLUDED

#include "CountLogic.h"

/*@
  predicate
    MultisetMinus{K,L}(value_type* a, integer n, value_type val) =
      Count{L}(a, n, val) == Count{K}(a, n, val) - 1;
*/

#endif /* MULTISETMINUS_H_INCLUDED */

