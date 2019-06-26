
#ifndef SWAPPEDINSIDEMULTISETUNCHANGED_SPEC_INCLUDED
#define SWAPPEDINSIDEMULTISETUNCHANGED_SPEC_INCLUDED

#include "SwappedInside.spec"
#include "MultisetUnchanged.spec"
#include "EqualRangesPreservesCount.spec"

/*@
  lemma
    SwappedInsideMultisetUnchanged{K,L}:
      \forall value_type* a, integer i, k, n;
        SwappedInside{K,L}(a, i, k, n)    ==>
        MultisetUnchanged{K,L}(a, i, k+1);
*/

#endif /* SWAPPEDINSIDEMULTISETUNCHANGED_SPEC_INCLUDED */

