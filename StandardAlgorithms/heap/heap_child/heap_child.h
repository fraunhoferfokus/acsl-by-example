
#ifndef HEAP_CHILD_H_INCLUDED
#define HEAP_CHILD_H_INCLUDED

#include "Heap.acsl"

/*@
   requires bounds:  0 <= p < n;
   requires valid:   \valid(a + (0..n-1));
   assigns           \nothing;
   ensures  bounds:  p < \result <= n;
   ensures  parent:  \result < n       ==>  p == HeapParent(\result);
   ensures  parent:  \result < n-1     ==>  HeapLeft(p)  < n-1;
   ensures  parent:  \result < n-1     ==>  HeapRight(p) < n;
   ensures  left:    HeapLeft(p)  < n  ==>  \result < n;
   ensures  right:   HeapRight(p) < n  ==>  \result < n;
   ensures  max:     HeapLeft(p)  < n  ==>  a[HeapLeft(p)]  <= a[\result];
   ensures  max:     HeapRight(p) < n  ==>  a[HeapRight(p)] <= a[\result];
   ensures  none:    \result == n      ==>  n <= HeapLeft(p);
   ensures  none:    \result == n      ==>  n <= HeapRight(p);
*/
size_type
heap_child(const value_type* a, size_type n, size_type p);

#endif /* HEAP_CHILD_H_INCLUDED */

