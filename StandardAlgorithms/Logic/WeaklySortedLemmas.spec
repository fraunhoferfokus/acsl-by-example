
#ifndef WEAKLYSORTEDLEMMAS_SPEC_INCLUDED
#define WEAKLYSORTEDLEMMAS_SPEC_INCLUDED

#include "WeaklySorted.spec"
#include "EqualRanges.spec"

/*@
  lemma WeaklySortedAddElement{L}:
    \forall value_type *a, integer m;
      1 < m && WeaklySorted(a, m-1) && a[m-2] <= a[m-1] ==> WeaklySorted(a, m);

  lemma WeaklySortedShift{L}:
    \forall value_type *a, integer n, m;
      WeaklySorted(a + n, 0, m) <==> WeaklySorted(a, n, m + n);

  lemma EqualRangesWeaklySorted{L}:
    \forall value_type *a, *b, integer n, m;
      WeaklySorted(a, n, m) && EqualRanges{L,L}(a, n, m, b) ==>
       WeaklySorted(b, n, m);

  lemma WeaklySortedJoin{L}:
    \forall value_type *a, integer n, m;
      0 < n < m             &&
      WeaklySorted(a, n)    &&
      WeaklySorted(a, n, m) &&
      a[n-1] <= a[n] ==>
        WeaklySorted(a, m);
 */

#endif /* WEAKLYSORTEDLEMMAS_SPEC_INCLUDED */

