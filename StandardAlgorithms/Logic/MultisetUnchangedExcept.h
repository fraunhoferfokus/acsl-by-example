
#ifndef MULTISETUNCHANGEDEXCEPT_H_INCLUDED
#define MULTISETUNCHANGEDEXCEPT_H_INCLUDED

#include "CountLogic.h"

/*@
  predicate
    MultisetUnchangedExcept{K,L}(value_type* a, integer n,
                                 value_type  v, value_type w) =
      \forall value_type x;
        x != v  ==>  x != w  ==>  Count{L}(a, n, x) == Count{K}(a, n, x);
*/

#endif /* MULTISETUNCHANGEDEXCEPT_H_INCLUDED */

