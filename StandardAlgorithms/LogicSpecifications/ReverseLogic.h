
#ifndef REVERSELOGIC_H_INCLUDED
#define REVERSELOGIC_H_INCLUDED

#include "typedefs.h"

/*@
  predicate 
    Reverse{K,L}(value_type* a, integer m, integer n,
                 value_type* b, integer p) =
      \let s = n - m;
      \let q = p + s;
      \forall integer i; 0 <= i < s ==> \at(a[m+i],K) == \at(b[q-1-i], L);

  predicate 
    Reverse{K,L}(value_type* a, integer m, integer n, value_type* b) =
      Reverse{K,L}(a, m, n, b, m);

  predicate 
    Reverse{K,L}(value_type* a, integer n, value_type* b) =
      Reverse{K,L}(a, 0, n, b);

  predicate 
    Reverse{K,L}(value_type* a, integer m, integer n, integer p) =
      Reverse{K,L}(a, m, n, a, p);

  predicate 
    Reverse{K,L}(value_type* a, integer m, integer n) =
      Reverse{K,L}(a, m, n, a, m);

  predicate 
    Reverse{K,L}(value_type* a, integer n) = Reverse{K,L}(a, 0, n);

*/

#endif /* REVERSELOGIC_H_INCLUDED */

