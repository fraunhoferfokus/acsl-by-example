
#ifndef INNERPRODUCTBOUNDS_H_INCLUDED
#define INNERPRODUCTBOUNDS_H_INCLUDED

#include "InnerProduct.h"
#include <limits.h>

/*@
  predicate
    ProductBounds(value_type* a, value_type* b, integer n) =
      \forall integer i; 0 <= i < n ==>
        VALUE_TYPE_MIN <= a[i] * b[i] <= VALUE_TYPE_MAX;

   predicate
     InnerProductBounds(value_type* a, value_type* b, integer n,
                        value_type init) =
       \forall integer i; 0 <= i <= n ==>
          VALUE_TYPE_MIN <= InnerProduct(a, b, i, init) <= VALUE_TYPE_MAX;
*/

#endif /* INNERPRODUCTBOUNDS_H_INCLUDED */

