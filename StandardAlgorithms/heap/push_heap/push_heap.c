
#include "push_heap.h"
#include "heap_parent.h"
#include "MultisetOperations.spec"
#include "MultisetPushHeap.spec"

void
push_heap(value_type* a, size_type n)
{
  // start of prologue
  if (1u < n) { // otherwise nothings needs to be done
    const value_type v  = a[n - 1u];
    size_type hole      = heap_parent(n - 1u);

    if (a[hole] < v) {
      a[n - 1u] = a[hole];

      //@ assert heap:   Heap(a, n);
      //@ assert add:    MultisetAdd{Pre,Here}(a, n, a[hole]);
      //@ assert minus:  MultisetMinus{Pre,Here}(a, n, v);
      //@ assert retain: MultisetRetainRest{Pre,Here}(a, n, v, a[hole]);
      // end of prologue
      // start of main act
      if (0u < hole) {
        size_type parent = heap_parent(hole);

        /*@
          loop invariant bound:  0 <= hole < n-1;
          loop invariant heap:   Heap(a, n);
          loop invariant heap:   parent == HeapParent(hole);
          loop invariant less:   a[hole] < v;
          loop invariant add:    MultisetAdd{Pre,Here}(a, n, a[hole]);
          loop invariant minus:  MultisetMinus{Pre,Here}(a, n, v);
          loop invariant retain: MultisetRetainRest{Pre,Here}(a, n, v, a[hole]);
          loop assigns           hole, parent, a[0..n-1];
          loop variant           hole;
        */
        while ((0u < hole) && (a[parent] < v)) {
          if (a[hole] < a[parent]) {
            a[hole] = a[parent];
            //@ assert less:    \at(a[hole],LoopCurrent) < v;
            //@ assert less:    a[hole] < v;
            //@ assert retain:  MultisetUnchanged{LoopCurrent,Here}(a, 0, hole);
            //@ assert retain:  MultisetUnchanged{LoopCurrent,Here}(a, hole + 1, n);
            //@ assert minus:   MultisetMinus{LoopCurrent,Here}(a, n, \at(a[hole],LoopCurrent));
            //@ assert add:     MultisetAdd{LoopCurrent,Here}(a, n, a[hole]);
            //@ assert retain:  MultisetRetain{LoopCurrent,Here}(a, n, v);
            //@ assert retain:  MultisetRetain{Pre,Here}(a, n, \at(a[hole],LoopCurrent));
            //@ assert retain:  MultisetRetainRest{Pre,Here}(a, n, v, a[hole]);
          }

          hole = parent;

          if (0u < hole) {
            parent = heap_parent(hole);
          }
        }
      }

      // end of main act
      // start of epilogue
      /*@
        requires value:      a[hole] != v;
        assigns              a[hole];
        ensures  value:      a[hole] == v;
        ensures  unchanged:  MultisetUnchanged{Old,Here}(a, 0, hole);
        ensures  unchanged:  MultisetUnchanged{Old,Here}(a, hole+1, n);
      */
      a[hole] = v;
      //@ assert reorder:    MultisetUnchanged{Pre,Here}(a, n);
    }
  }

  // end of epilogue
}

