
#include "push_heap.h"
#include "heap_parent.h"
#include "At.acsl"
#include "MultisetOperations.acsl"
#include "PushHeapAdjust.acsl"

void
push_heap(value_type* a, size_type n)
{
  // start of prologue
  if (1u < n) { // otherwise nothings needs to be done
    const value_type v  = a[n - 1u];
    size_type p      = heap_parent(n - 1u);

    if (a[p] < v) {
      a[n - 1u] = a[p];

      //@ assert heap:    Heap(a, n);
      //@ assert adjust:  PushHeapAdjust{Pre,Here}(a, n, a[p], v);
      // end of prologue
      // start of main act
      if (0u < p) {
        size_type parent = heap_parent(p);

        /*@
          loop invariant bound:  0 <= p < n-1;
          loop invariant heap:   Heap(a, n);
          loop invariant heap:   parent == HeapParent(p);
          loop invariant less:   a[p] < v;
          loop invariant adjust: PushHeapAdjust{Pre,Here}(a, n, a[p], v);
          loop assigns           p, parent, a[0..n-1];
          loop variant           p;
        */
        while ((0u < p) && (a[parent] < v)) {
          //@ ghost value_type ap_old =  a[p];
          //@ assert retain:   ap_old == \at(a[p], LoopCurrent);
          if (a[p] < a[parent]) {
            a[p] = a[parent];
            //@ ghost value_type   ap_new = a[p];
            //@ assert bound:      0 <= p < n;
            //@ assert less:       ap_old < v;
            //@ assert less:       ap_new < v;
            //@ assert unchanged:  Unchanged{LoopCurrent,Here}(a, 0, p);
            //@ assert unchanged:  Unchanged{LoopCurrent,Here}(a, p+1, n);
            //@ assert adjust:     PushHeapAdjust{LoopCurrent,Here}(a, n, ap_new, ap_old);
            //@ assert retain:     MultisetRetain{LoopCurrent,Here}(a, n, v);
            //@ assert retain:     MultisetRetain{Pre,Here}(a, n, ap_old);
            //@ assert retain:     MultisetRetainRest{Pre,Here}(a, n, v, ap_new);
            //@ assert adjust:     PushHeapAdjust{Pre,Here}(a, n, ap_new, v);
          }

          p = parent;

          if (0u < p) {
            parent = heap_parent(p);
          }
        }
      }

      //@ assert heap: Heap(a, n);

      // end of main act
      // start of epilogue
      /*@
        requires adjust:     PushHeapAdjust{Pre,Here}(a, n, a[p], v);
        requires less:       a[p] < v;
        assigns              a[p];
        ensures  value:      a[p] == v;
        ensures  unchanged:  Unchanged{Old,Here}(a, 0, p);
        ensures  unchanged:  Unchanged{Old,Here}(a, p+1, n);
      */
      a[p] = v;
      //@ assert reorder:    MultisetUnchanged{Pre,Here}(a, n);
      //@ assert heap:       Heap(a, n);
    }
  }

  // end of epilogue
}

