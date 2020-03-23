
#ifndef INCREASINGUPPERBOUND_SPEC_INCLUDED
#define INCREASINGUPPERBOUND_SPEC_INCLUDED

#include "Increasing.spec"
#include "ArrayBounds.spec"

/*@
  axiomatic IncreasingUpperBound
  {
    lemma IncreasingUpperBound{L}:
      \forall value_type *a, integer n;
        UpperBound(a, n, a[n])  ==>
        Increasing(a, n)        ==>
        Increasing(a, n+1);
  }
*/

#endif /* INCREASINGUPPERBOUND_SPEC_INCLUDED */

