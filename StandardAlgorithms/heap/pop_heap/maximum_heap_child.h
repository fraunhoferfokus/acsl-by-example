
#ifndef SELECT_CHILD_H_INCLUDED
#define SELECT_CHILD_H_INCLUDED

#include "IsHeap.spec"
#include "HeapMaximumChild.spec"

/*@
   requires bound: 2 <= n;
   requires bound: 0 <= parent < n - 1;
   requires valid: \valid(a + (0..n-1));
   requires heap:  IsHeap(a, n);

   assigns         \nothing;

   ensures heap:   IsHeap(a, n);
   ensures max:    HeapMaximumChild(a, n, parent, \result);
   ensures less:   parent < \result;
   ensures less:   \result < n - 1  ==>  parent == HeapParent(\result);
*/
static inline size_type
maximum_heap_child(const value_type* a, size_type n, size_type parent)
{
  if (parent < (SIZE_TYPE_MAX - 1u) / 2u) {
    const size_type right = 2u * parent + 2u;
    const size_type left  = right - 1u;

    if (right < n - 1u) {
      // case of two children: select child with maximum value
      return a[left] >= a[right] ? left : right;
    }
    else {
      // at most one child that comes before n-1 can exist
      return left;
    }
  }
  else {
    return n;
  }
}

#endif /* SELECT_CHILD_H_INCLUDED */

