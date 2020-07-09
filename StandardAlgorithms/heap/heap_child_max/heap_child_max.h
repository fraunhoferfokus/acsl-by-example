
#ifndef HEAP_CHILD_MAX_H_INCLUDED
#define HEAP_CHILD_MAX_H_INCLUDED

#include "Heap.acsl"

/*@
   requires bounds:  0 <= p < n-1;
   requires valid:   \valid(a + (0..n-1));
   assigns           \nothing;
   ensures  bounds:  p < \result <= n;
   ensures  parent:  \result < n       ==>  p == HeapParent(\result);
   ensures  max:     HeapLeft(p)  < n  ==>  a[HeapLeft(p)]  <= a[\result];
   ensures  max:     HeapRight(p) < n  ==>  a[HeapRight(p)] <= a[\result];
   ensures  none:    \result == n      ==>  n <= HeapLeft(p);
   ensures  none:    \result == n      ==>  n <= HeapRight(p);
*/
size_type
heap_child_max(const value_type* a, size_type n, size_type p);

#endif /* HEAP_CHILD_MAX_H_INCLUDED */

