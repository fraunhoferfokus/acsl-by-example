
#ifndef REPLACE_LOGIC_H_INCLUDED
#define REPLACE_LOGIC_H_INCLUDED

#include "typedefs.h"

/*@
  predicate
    Replace{K,L}(value_type* a, integer n, value_type* b,
                 value_type v, value_type w) =
       \forall integer i; 0 <= i < n ==>
         \let ai = \at(a[i],K); \let bi = \at(b[i],L);
              (ai == v ==> bi == w) && (ai != v ==> bi == ai) ;


  predicate
    Replace{K,L}(value_type* a, integer n, value_type v, value_type w) =
      Replace{K,L}(a, n, a, v, w);
*/

#endif /* REPLACE_LOGIC_H_INCLUDED */

