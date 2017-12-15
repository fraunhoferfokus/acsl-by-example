
#ifndef SWAPIMPLIESMULTISETUNCHANGED_H_INCLUDED
#define SWAPIMPLIESMULTISETUNCHANGED_H_INCLUDED

#include "MultisetUnchangedLemmas.h"

/*@
  lemma
    SwapImpliesMultisetUnchanged{K,L}:
      \forall value_type *a, integer i, k, n;
        0 <= i <= k < n                    ==>
        \at(a[i],K) == \at(a[k],L)         ==>
        \at(a[k],K) == \at(a[i],L)         ==>
        MultisetUnchanged{K,L}(a, 0,   i)  ==>
        MultisetUnchanged{K,L}(a, i+1, k)  ==>
        MultisetUnchanged{K,L}(a, k+1, n)  ==>
        MultisetUnchanged{K,L}(a, n);
*/

#endif /* SWAPIMPLIESMULTISETUNCHANGED_H_INCLUDED */

