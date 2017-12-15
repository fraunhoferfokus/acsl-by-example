
#ifndef SWAPPEDINSIDEPRESERVESMULTISETUNCHANGED_H_INCLUDED
#define SWAPPEDINSIDEPRESERVESMULTISETUNCHANGED_H_INCLUDED

#include "SwappedInsideMultisetUnchanged.h"
#include "UnchangedSection.h"

/*@
  lemma
    SwappedInsidePreservesMultisetUnchanged{K,L,M}:
      \forall value_type* a, integer i, k, n;
        MultisetUnchanged{K,L}(a, k)      ==>
        Unchanged{K,L}(a, k, n)           ==>
        SwappedInside{L,M}(a, i, k, n)    ==>
        MultisetUnchanged{K,M}(a, k+1);
*/

#endif /* SWAPPEDINSIDEPRESERVESMULTISETUNCHANGED_H_INCLUDED */

