
#ifndef REMOVESIZEPRESERVE_SPEC_INCLUDED
#define REMOVESIZEPRESERVE_SPEC_INCLUDED

#include "RemoveSize.spec"
#include "Unchanged.spec"

/*@
  lemma RemoveSizePreserve{K,L}:
    \forall value_type *a, v, integer n;
      \at(a[n] != v, K) ==>
      Unchanged{K,L}(a, n+1) ==>
      RemoveSize{L}(a, n+1, v) == RemoveSize{K}(a, n, v) + 1;
*/

#endif /* REMOVESIZEPRESERVE_SPEC_INCLUDED */
