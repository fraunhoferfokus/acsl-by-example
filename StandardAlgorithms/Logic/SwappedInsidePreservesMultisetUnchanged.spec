
#ifndef SWAPPEDINSIDEPRESERVESMULTISETUNCHANGED_SPEC_INCLUDED
#define SWAPPEDINSIDEPRESERVESMULTISETUNCHANGED_SPEC_INCLUDED

#include "SwappedInsideMultisetUnchanged.spec"
#include "UnchangedSection.spec"

/*@
  lemma
    SwappedInsidePreservesMultisetUnchanged{K,L,M}:
      \forall value_type* a, integer i, k, n;
        MultisetUnchanged{K,L}(a, k)      ==>
        Unchanged{K,L}(a, k, n)           ==>
        SwappedInside{L,M}(a, i, k, n)    ==>
        MultisetUnchanged{K,M}(a, k+1);
*/

#endif /* SWAPPEDINSIDEPRESERVESMULTISETUNCHANGED_SPEC_INCLUDED */

