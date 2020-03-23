
#include "pop_heap.h"
#include "heap_child_max.h"

void
pop_heap(value_type* a, size_type n)
{
  if (1u < n) { // otherwise nothings needs to be done
    const value_type v = a[0u];

    //@ assert max:  MaxElement(a, n, 0);
    if (a[n - 1u] < v) { // otherwise nothings needs to be done
      //@ assert bounds: 2 <= n;
      size_type hole = 0u;
      size_type child = heap_child_max(a, n, hole);

      //@ assert heap: child < n - 1  ==>  hole == HeapParent(child);
      /*@
          loop invariant bounds: 0 <= hole < n-1;
          loop invariant bounds: hole < child;
          loop invariant heap:   Heap(a, n);
          loop invariant heap:   a[n-1] < a[HeapParent(hole)];
          loop invariant heap:   child < n - 1  ==>  hole == HeapParent(child);
          loop invariant child:  HeapChildMax(a, n, hole, child);
          loop invariant max:    UpperBound(a, 0, n, v);
          loop assigns           hole, child, a[0..n-2];
          loop variant           n - hole;
       */
      while ((child < n - 1u) && (a[n - 1u] < a[child])) {
        a[hole] = a[child];
        hole    = child;
        //@ assert heap: Heap(a, n);
        child = heap_child_max(a, n, hole);
      }

      //@ assert child: child < n-1 ==> a[n-1] >= a[child];
      //@ assert child: HeapChildMax(a, n, hole, child);
      //@ assert heap:  Heap(a, n);
      //@ assert heap:  a[n-1] < a[HeapParent(hole)];
      a[hole]   = a[n - 1u];
      //@ assert heap:  Heap(a, n-1);
      a[n - 1u] = v;
      //@ assert heap:  Heap(a, n-1);
    }
  }
}

