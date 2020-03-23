
#ifndef HEAP_SPEC_INCLUDED
#define HEAP_SPEC_INCLUDED

#include "HeapBasics.spec"
#include "ArrayExtrema.spec"
#include "C_Division.spec"

/*@
  axiomatic Heap
  {
    predicate
    Heap{L}(value_type* a, integer n) =
      \forall integer i; 0 < i < n  ==>  a[i] <= a[HeapParent(i)];

    lemma HeapMaximum{L} :
      \forall value_type* a, integer n;
        0 < n       ==>
        Heap(a, n)  ==>
        MaxElement(a, n, 0);
  }
*/

#endif /* HEAP_SPEC_INCLUDED */

