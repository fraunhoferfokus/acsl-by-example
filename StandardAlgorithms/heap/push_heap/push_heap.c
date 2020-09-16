
#include "push_heap.h"
#include "heap_parent.h"
#include "MultisetUpdate.acsl"

void
push_heap(value_type* a, size_type n)
{
  if (1u < n) { // otherwise nothings needs to be done
    size_type c = n - 1u;
    size_type p = heap_parent(c);
    //@ assert parent: p == HeapParent(c);

    if (a[p] < a[c]) {
      const value_type v  = a[c];
      a[c] = a[p];
      //@ assert update:   ArrayUpdate{Pre,Here}(a, n, c, a[p]);
      //@ assert heap:     Heap(a, n);
      //@ assert reorder:  MultisetParity{Pre,Here}(a, n, a[p], v);

      /*@
        loop invariant bound:      0 <= c < n-1;
        loop invariant heap:       Heap(a, n);
        loop invariant less:       a[c] < v;
        loop invariant parent:     p == HeapParent(c);
        loop invariant reorder:    MultisetParity{Pre,Here}(a, n, a[c], v);
        loop invariant unchanged:  Unchanged{Pre,Here}(a, c);
        loop assigns               c, p, a[0..n-1];
        loop variant               c;
      */
      for (c = p, p = heap_parent(c); 0u < c && a[p] < v;
           c = p, p = heap_parent(c)) {
        //@ ghost value_type ac =  a[c];
        if (a[c] < a[p]) {
          a[c] = a[p];
          //@ assert update:     ArrayUpdate{LoopCurrent,Here}(a, n, c, a[p]);
          //@ assert update:     MultisetUpdate{LoopCurrent,Here}(a, n, c, a[p]);
          //@ assert bound:      0 <= c < n;
          //@ assert less:       ac < a[c] < v;
          //@ assert reorder:    MultisetParity{Pre,Here}(a, n, a[c], v);
        }
      }

      //@ ghost Epilogue: ;
      //@ assert heap: 0 == c || v <= a[HeapParent(c)];
      //@ ghost  value_type  ac = a[c];
      //@ assert update:     ac == At{Epilogue}(a, c) < v;
      //@ assert reorder:    MultisetParity{Pre,Here}(a, n, ac, v);
      a[c] = v;
      //@ assert update:   ArrayUpdate{Epilogue,Here}(a, n, c, v);
      //@ assert heap:     HeapCompatible(a, n, c, v);
      //@ assert heap:     Heap(a, n);
      //@ assert update:   MultisetUpdate{Epilogue,Here}(a, n, c, v);
      //@ assert reorder:  MultisetParity{Epilogue,Here}(a, n, v, ac);
      //@ assert reorder:  MultisetReorder{Pre,Here}(a, n);
    }
  }
}

