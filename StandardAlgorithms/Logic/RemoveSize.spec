
#ifndef REMOVESIZE_SPEC_INCLUDED
#define REMOVESIZE_SPEC_INCLUDED

#include "Count.spec"

/*@
  logic integer
    RemoveSize(value_type* a, integer n, value_type v) = n - Count(a, n, v);

  lemma
    RemoveSizeEmpty:
      \forall value_type *a, v, integer n;
        n <= 0  ==>  RemoveSize(a, n, v) == n;

  lemma
    RemoveSizeHit:
      \forall value_type *a, v, integer n;
        0 <= n  ==>  a[n] == v  ==> 
        RemoveSize(a, n+1, v) == RemoveSize(a, n, v);

  lemma
    RemoveSizeMiss:
     \forall value_type *a, v, integer n;
       0 <= n  ==>  a[n] != v  ==>
       RemoveSize(a, n+1, v) == RemoveSize(a, n, v) + 1;

  lemma
    RemoveSizeRead{L1,L2}:
     \forall value_type *a, v, integer n;
       Unchanged{L1,L2}(a, n)  ==>
       RemoveSize{L1}(a, n, v) == RemoveSize{L2}(a, n, v);
*/

#endif /* REMOVESIZE_H_INCLUDED */

