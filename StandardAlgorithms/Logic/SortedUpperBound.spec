
#ifndef SORTEDUPPERBOUND_SPEC_INCLUDED
#define SORTEDUPPERBOUND_SPEC_INCLUDED

#include "Sorted.spec"
#include "UpperBound.spec"

/*@
  lemma
    SortedUpperBound{L}:
      \forall value_type *a, integer n;
        UpperBound(a, n, a[n])  ==>
        Sorted(a, n)            ==>
        Sorted(a, n+1);
*/

#endif /* SORTEDUPPERBOUND_SPEC_INCLUDED */

