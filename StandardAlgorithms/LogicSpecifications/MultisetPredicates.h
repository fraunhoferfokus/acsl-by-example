
#ifndef MULTISETPREDICATES_H_INCLUDED
#define MULTISETPREDICATES_H_INCLUDED

#include "CountLogic.h"

/*@
  predicate
    MultisetAdd{K,L}(value_type* a, integer n, value_type val) =
      Count{L}(a, n, val) == Count{K}(a, n, val) + 1;

  predicate
    MultisetMinus{K,L}(value_type* a, integer n, value_type val) =
      Count{L}(a, n, val) == Count{K}(a, n, val) - 1;

  predicate
    MultisetUnchangedExcept{K,L}(value_type* a, integer n, value_type val1, value_type val2) =
      \forall value_type i;
        i != val1 ==>
        i != val2 ==>
        Count{L}(a, n, i) == Count{K}(a, n, i);

  predicate
    MultisetUnchangedExcept{K,L}(value_type* a, integer n, value_type val1, value_type val2, value_type val3) =
      \forall value_type i;
        i != val1 ==>
        i != val2 ==>
        i != val3 ==>
        Count{L}(a, n, i) == Count{K}(a, n, i);
*/

#endif /* MULTISETPREDICATES_H_INCLUDED */
