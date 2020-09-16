
#include "pop_heap.h"
#include "heap_child.h"
#include "MultisetUpdate.acsl"

void
pop_heap(value_type* a, size_type n)
{
  if (1u < n) {
    //@ assert max:  MaxElement(a, n, 0);
    if (a[n - 1u] < a[0u]) { // otherwise a[0] == a[n-1] and nothing to be done
      size_type p = 0u;
      const value_type v = a[n - 1u];
      a[n - 1u] = a[p];
      //@ assert max:       a[n-1] == a[p];
      //@ assert update:    ArrayUpdate{Pre,Here}(a, n, n-1, a[p]);
      //@ assert heap:      Heap(a, n-1);
      //@ assert reorder:   MultisetParity{Pre,Here}(a, n, a[p], v);

      size_type c = heap_child(a, n - 1u, p);

      /*@
        loop invariant bounds:     0 <= p < c <= n-1;
        loop invariant parent:     c <  n-1 ==> p == HeapParent(c);
        loop invariant child:      c <  n-1 ==> HeapLeft(p) < n-1;
        loop invariant child:      c == n-1 ==> n-1 <= HeapLeft(p);
        loop invariant child:      HeapLeft(p)  < n-1 ==> a[HeapLeft(p)]  <= a[c];
        loop invariant child:      HeapRight(p) < n-1 ==> a[HeapRight(p)] <= a[c];
        loop invariant unchanged:  Unchanged{LoopEntry,Here}(a, p, n);
        loop invariant update:     a[p] == a[HeapParent(p)];
        loop invariant max:        UpperBound(a, n, a[n-1]);
        loop invariant reorder:    MultisetParity{Pre,Here}(a, n, a[p], v);
        loop invariant heap:       v < a[p];
        loop invariant heap:       Heap(a, n-1);
        loop assigns               p, c, a[0..n-2];
        loop variant               n - p;
       */
      for (; c < n - 1u && v < a[c];  p = c, c = heap_child(a, n - 1u, p)) {
        //@ assert max:          a[p] <= a[n-1];
        //@ assert heap:         a[c] <= a[p];
        if (a[c] < a[p]) {
          a[p] = a[c];
          //@ assert update:     ArrayUpdate{LoopCurrent,Here}(a, n, p, a[c]);
          //@ assert update:     ArrayUpdate{LoopCurrent,Here}(a, n-1, p, a[c]);
          //@ assert update:     MultisetUpdate{LoopCurrent,Here}(a, n, p, a[c]);
          //@ assert update:     a[c] == At{LoopCurrent}(a, c);
          //@ assert unchanged:  Unchanged{LoopEntry,Here}(a, p+1, n);
          //@ assert compatible: HeapCompatible(a, n-1, p, a[p]);
          //@ assert reorder:    MultisetParity{Pre,Here}(a, n, a[c], v);
        }
      }

      //@ ghost Epilogue: ;
      //@ assert child:      c == n-1  ||  a[c] <= v;
      //@ assert parent:     p <  n-1  &&  v < a[p];
      //@ assert compatible: HeapCompatible(a, n-1, p, v);
      a[p] = v;
      //@ assert update:     ArrayUpdate{Epilogue,Here}(a, n, p, v);
      //@ assert update:     MultisetUpdate{Epilogue,Here}(a, n, p, v);
      //@ assert reorder:    MultisetReorder{Pre,Here}(a, n);
      //@ assert heap:       Heap(a, n-1);
      //@ assert max:        UpperBound(a, n, a[n-1]);
    }
  }
}

