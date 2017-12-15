
#ifndef REMOVECOUNT_H_INCLUDED
#define REMOVECOUNT_H_INCLUDED

#include "CountLogic.h"

/*@
  logic
    integer RemoveCount{L}(value_type* a, integer n, value_type v) =
      n - Count{L}(a, n, v);

  lemma
    RemoveCountEmpty:
      \forall value_type *a, v, integer n;
        n <= 0  ==>  RemoveCount(a, n, v) == n;

  lemma
    RemoveCountHit:
      \forall value_type *a, v, integer n;
        0 <= n  ==>  a[n] == v  ==> 
        RemoveCount(a, n+1, v) == RemoveCount(a, n, v);

  lemma
    RemoveCountMiss:
     \forall value_type *a, v, integer n;
       0 <= n  ==>  a[n] != v  ==>
       RemoveCount(a, n+1, v) == RemoveCount(a, n, v) + 1;

  lemma
    RemoveCountRead{L1,L2}:
     \forall value_type *a, v, integer n;
       Unchanged{L1,L2}(a, n)  ==>
       RemoveCount{L1}(a, n, v) == RemoveCount{L2}(a, n, v);
*/

#endif /* REMOVECOUNT_H_INCLUDED */

