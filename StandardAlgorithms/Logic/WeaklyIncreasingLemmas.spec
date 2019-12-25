
#ifndef WEAKLYINCREASINGLEMMAS_SPEC_INCLUDED
#define WEAKLYINCREASINGLEMMAS_SPEC_INCLUDED

#include "WeaklyIncreasing.spec"
#include "EqualRanges.spec"

/*@
  lemma WeaklyIncreasingAddElement{L}:
    \forall value_type *a, integer m;
      1 < m && WeaklyIncreasing(a, m-1) && a[m-2] <= a[m-1] ==> WeaklyIncreasing(a, m);

  lemma WeaklyIncreasingShift{L}:
    \forall value_type *a, integer n, m;
      WeaklyIncreasing(a + n, 0, m) <==> WeaklyIncreasing(a, n, m + n);

  lemma EqualRangesWeaklyIncreasing{L}:
    \forall value_type *a, *b, integer n, m;
      WeaklyIncreasing(a, n, m) && EqualRanges{L,L}(a, n, m, b) ==>
       WeaklyIncreasing(b, n, m);

  lemma WeaklyIncreasingJoin{L}:
    \forall value_type *a, integer n, m;
      0 < n < m             &&
      WeaklyIncreasing(a, n)    &&
      WeaklyIncreasing(a, n, m) &&
      a[n-1] <= a[n] ==>
        WeaklyIncreasing(a, m);
 */

#endif /* WEAKLYINCREASINGLEMMAS_SPEC_INCLUDED */

