
#include "is_heap.h"

#include "SortedDownIsHeap.h"

bool is_heap(const value_type* a, size_type n)
{
  size_type parent = 0u;
  /*@
    loop invariant bound:  0 <= parent < child <= n+1;
    loop invariant parent: parent == HeapParent(child);
    loop invariant heap:   IsHeap(a, child);

    loop assigns child, parent;
    loop variant n - child;
  */
  for (size_type child = 1u; child < n; ++child) {
    if (a[parent] < a[child]) {
      return false;
    }

    if ((child % 2u) == 0u) {
      ++parent;
    }
  }

  return true;
}

