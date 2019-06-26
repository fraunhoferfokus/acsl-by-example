
#ifndef DIFFERENCE_SPEC_INCLUDED
#define DIFFERENCE_SPEC_INCLUDED

#include "Unchanged.spec"

/*@
  axiomatic DifferenceAxiomatic
  {
    logic integer
      Difference{L}(value_type* a, integer n) =
        n <= 0 ? a[0] : a[n] - a[n-1];

    lemma
      DifferenceRead{K,L}:
        \forall value_type *a, integer n;
          n >= 0 ==> Unchanged{K,L}(a, 1+n) ==>
            Difference{K}(a, n) == Difference{L}(a, n);
  }
*/

#endif /* DIFFERENCE_SPEC_INCLUDED */

