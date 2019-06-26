
#ifndef REMOVESIZE_SPEC_INCLUDED
#define REMOVESIZE_SPEC_INCLUDED

#include "Count.spec"

/*@
  logic integer
    RemoveSize(value_type* a, integer m, integer n, value_type v) = n - m - Count(a, m, n, v);

  logic integer
    RemoveSize(value_type* a, integer n, value_type v) = RemoveSize(a, 0, n, v);

  lemma
    RemoveSizeEmpty:
      \forall value_type *a, v, integer m, n;
        n <= m  ==>  RemoveSize(a, m, n, v) == n - m;

  lemma
    RemoveSizeHit:
      \forall value_type *a, v, integer m, n;
        m <= n  ==>  a[n] == v  ==> 
        RemoveSize(a, m, n+1, v) == RemoveSize(a, m, n, v);

  lemma
    RemoveSizeMiss:
     \forall value_type *a, v, integer m, n;
       m <= n  ==>  a[n] != v  ==>
       RemoveSize(a, m, n+1, v) == RemoveSize(a, m, n, v) + 1;

  lemma
    RemoveSizeRead{L1,L2}:
     \forall value_type *a, v, integer m, n;
       Unchanged{L1,L2}(a, m, n)  ==>
       RemoveSize{L1}(a, m, n, v) == RemoveSize{L2}(a, m, n, v);
*/

#endif /* REMOVESIZE_H_INCLUDED */

