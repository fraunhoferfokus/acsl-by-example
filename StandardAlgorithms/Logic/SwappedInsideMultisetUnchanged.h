
#ifndef SWAPPEDINSIDEMULTISETUNCHANGED_H_INCLUDED
#define SWAPPEDINSIDEMULTISETUNCHANGED_H_INCLUDED

#include "SwappedInside.h"
#include "MultisetUnchanged.h"
#include "EqualRangesPreservesCount.h"

/*@
  lemma
    SwappedInsideMultisetUnchanged{K,L}:
      \forall value_type* a, integer i, k, n;
        SwappedInside{K,L}(a, i, k, n)    ==>
        MultisetUnchanged{K,L}(a, i, k+1);
*/

#endif /* SWAPPEDINSIDEMULTISETUNCHANGED_H_INCLUDED */

