
#include "make_heap.h"
#include "heap_child.h"
#include "heap_parent.h"
#include "push_heap.h"
#include "MultisetUpdate.acsl"
#include "Unchanged.acsl"

void sift_down(value_type* a, size_type n, size_type root) {
  value_type v = a[root];
  size_type p = root;
  size_type c = heap_child(a, n, p);

  if (c < n && v < a[c]) {
    a[p] = a[c];

    //@ assert update:    ArrayUpdate{Pre,Here}(a, n, root, a[c]);
    //@ assert heap:      HeapFrom(a, root, n);
    //@ assert reorder:   MultisetParity{Pre,Here}(a, n, a[c], v);

    p = c;
    c = heap_child(a, n, p);

    /*@
      loop invariant bounds:     root <= p < c <= n;
      loop invariant ancestor:   HeapAncestor(root, p);
      loop invariant parent:     c <  n ==> p == HeapParent(c);
      loop invariant child:      c <  n ==> HeapLeft(p) < n;
      loop invariant child:      c == n ==> n <= HeapLeft(p);
      loop invariant child:      HeapLeft(p)  < n ==> a[HeapLeft(p)]  <= a[c];
      loop invariant child:      HeapRight(p) < n ==> a[HeapRight(p)] <= a[c];
      loop invariant unchanged:  Unchanged{LoopEntry,Here}(a, p, n);
      loop invariant update:     a[p] == a[HeapParent(p)];
      loop invariant reorder:    MultisetParity{Pre,Here}(a, n, a[p], v);
      loop invariant heap:       HeapFrom(a, root, n);
      loop invariant heap:       v < a[p];
      loop assigns               p, c, a[0..n-1];
      loop variant               n - p;
    */
    for (; c < n && v < a[c];  p = c, c = heap_child(a, n, p)) {
      //@ ghost value_type ac = a[c];
      if (a[c] < a[p]) {
        a[p] = a[c];
        //@ assert update:       ArrayUpdate{LoopCurrent,Here}(a, n, p, ac);
        //@ assert update:       MultisetUpdate{LoopCurrent,Here}(a, n, p, ac);
        //@ assert update:       a[c] == At{LoopCurrent}(a, c);
        //@ assert reorder:      MultisetParity{Pre,Here}(a, n, a[c], v);
      }
      //@assert progress:        p < c;
    }

    //@ ghost Epilogue: ;
    //@ assert compatible:       HeapFromCompatible(a, n, root, p, v);
    a[p] = v;
    //@ assert update:           ArrayUpdate{Epilogue,Here}(a, n, p, v);
    //@ assert update:           MultisetUpdate{Epilogue,Here}(a, n, p, v);
    //@ assert reorder:          MultisetReorder{Pre,Here}(a, n);
    //@ assert heap:             HeapFrom(a, root, n);
  }
}

