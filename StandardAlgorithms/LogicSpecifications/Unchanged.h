
#ifndef UNCHANGED_H_INCLUDED
#define UNCHANGED_H_INCLUDED

#include "typedefs.h"

/*@
  predicate 
    Unchanged{K,L}(value_type* a, integer first, integer last) =
      \forall integer i; first <= i < last ==>
         \at(a[i],K) == \at(a[i],L);

  predicate
    Unchanged{K,L}(value_type* a, integer n) =
    Unchanged{K,L}(a, 0, n);

  lemma
    UnchangedStep{K,L}:
      \forall value_type *a, integer n;
        0 <= n                      ==>
        Unchanged{K,L}(a, n)        ==>
        \at(a[n],K) == \at(a[n],L)  ==>
        Unchanged{K,L}(a, n+1);

  lemma
    UnchangedSection{K,L}:
      \forall value_type *a, integer m, n;
        0 <= m <= n           ==>
        Unchanged{K,L}(a, n)  ==>
        Unchanged{K,L}(a, m);
*/

#endif /* UNCHANGED_H_INCLUDED */

