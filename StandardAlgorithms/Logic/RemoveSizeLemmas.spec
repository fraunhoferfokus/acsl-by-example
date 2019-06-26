
#ifndef REMOVESIZELEMMAS_SPEC_INCLUDED
#define REMOVESIZELEMMAS_SPEC_INCLUDED

#include "RemoveSize.spec"
#include "CountLemmas.spec"
#include "CountBounds.spec"
#include "CountMonotonic.spec"

/*@
  lemma
    RemoveSizeMonotonic:
      \forall value_type *a, v, integer m, n; 0 <= m <= n  ==>
        RemoveSize(a, m, v) <= RemoveSize(a, n, v);

  lemma
    RemoveSizeStrictlyMonotonic:
      \forall value_type *a, v, integer m, n; 0 <= m < n   ==>
        a[m] != v  ==>  RemoveSize(a, m, v) < RemoveSize(a, n, v);
*/

#endif /* REMOVESIZELEMMAS_SPEC_INCLUDED */

