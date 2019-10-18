
#ifndef POPHEAPUPDATE_SPEC_INCLUDED
#define POPHEAPUPDATE_SPEC_INCLUDED

#include "HeapChildMax.spec"
#include "Unchanged.spec"
#include "IsHeap.spec"

/*@
  lemma
    PopHeapUpdate{K,L}:
      \forall value_type* a, integer p, c, n;
        IsHeap{K}(a, n)                 ==>
        0 < p < c < n-1                 ==>
        HeapChildMax{K}(a, n, p, c) ==>
        \at(a[p] == a[c],L)             ==>
        Unchanged{K,L}(a, 0, p)         ==>
        Unchanged{K,L}(a, p+1, n)       ==>
        IsHeap{L}(a, n);
*/

#endif /* POPHEAPUPDATE_SPEC_INCLUDED */

