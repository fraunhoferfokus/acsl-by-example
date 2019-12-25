
#ifndef DIFFERENCE_SPEC_INCLUDED
#define DIFFERENCE_SPEC_INCLUDED

#include "UnchangedSection.spec"

/*@
  axiomatic DifferenceAxiomatic
  {
    logic integer
      Difference{L}(value_type* a, integer n) =
        n <= 0 ? a[0] : a[n] - a[n-1];

    lemma
      Difference0{L}:
        \forall value_type *a; Difference(a, 0) == a[0];

    lemma
      DifferenceNext{L}:
        \forall value_type *a, integer n;
          0 < n  ==> Difference(a, n) == a[n] - a[n-1];

    lemma
      DifferenceRead{K,L}:
        \forall value_type *a, integer n;
          0 <= n ==> Unchanged{K,L}(a, n+1) ==>
            Difference{K}(a, n) == Difference{L}(a, n);
  }
*/

#endif /* DIFFERENCE_SPEC_INCLUDED */

