
#include "pop_heap.h"
#include "heap_child_max.h"
#include "At.acsl"


void
pop_heap(value_type* a, size_type n)
{
  if (1u < n) { // otherwise nothings needs to be done
    const value_type v = a[0u];

    //@ assert max:  MaxElement(a, n, 0);
    if (a[n - 1u] < v) { // otherwise a[n-1] == v and nothings needs to be done
      //@ assert bounds: 2 <= n;
      size_type p = 0u;
      //@ assert less: p < n-1;
      size_type c = heap_child_max(a, n, p);

      /*@
          loop invariant bounds:  0 <= p < n-1;
          loop invariant bounds:  p < c <= n;
          loop invariant heap:    Heap(a, n);
          loop invariant heap:    a[n-1] < a[HeapParent(p)];
          loop invariant parent:  c < n   ==>  p == HeapParent(c);
          loop invariant left:    c == n  ==>  n <= HeapLeft(p);
          loop invariant right:   c == n  ==>  n <= HeapRight(p);
          loop invariant left:    HeapLeft(p)  < n  ==>  a[HeapLeft(p)]  <= a[c];
          loop invariant right:   HeapRight(p) < n  ==>  a[HeapRight(p)] <= a[c];
          loop invariant upper:   UpperBound(a, 0, n, v);
          loop assigns            p, c, a[0..n-2];
          loop variant            n - p;
       */
      while ((c < n - 1u) && (a[n - 1u] < a[c])) {
        a[p] = a[c];
        //@ assert upper:      UpperBound(a, 0, n, v);
        //@ assert unchanged:  Unchanged{LoopCurrent,Here}(a, 0, p);
        //@ assert unchanged:  Unchanged{LoopCurrent,Here}(a, p+1, n);
        //@ assert compatible: HeapCompatible(a, n, p, At{LoopCurrent}(a, c));
        //@ assert heap:       Heap(a, n);
        p = c;
        c = heap_child_max(a, n, p);
      }

      //@ ghost Epilogue: ;
      //@ assert compatible: HeapCompatible(a, n, p, a[n-1]);
      a[p] = a[n - 1u];
      //@ assert unchanged:  Unchanged{Epilogue,Here}(a, 0, p);
      //@ assert unchanged:  Unchanged{Epilogue,Here}(a, p+1, n);
      //@ assert compatible: HeapCompatible(a, n, p, At{Epilogue}(a, n-1));
      //@ assert heap:       Heap(a, n);
      a[n - 1u] = v;
      //@ assert max:        UpperBound(a, 0, n, a[n-1]);
      //@ assert heap:       Heap(a, n-1);
    }
  }
}

