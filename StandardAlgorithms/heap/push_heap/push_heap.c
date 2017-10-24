
#include "push_heap.h"
#include "../is_heap/heap_aux.h"
#include "CountLemmas.h"
#include "MultisetAdd.h"
#include "MultisetAddDistinct.h"
#include "MultisetMinus.h"
#include "MultisetMinusDistinct.h"
#include "MultisetRetainRest2.h"
#include "MultisetPushHeapRetain.h"
#include "MultisetPushHeapClosure.h"

void push_heap(value_type* a, size_type n)
{
  // start of prologue
  if (1u < n) { // otherwise nothings needs to be done

    const value_type v      = a[n - 1];
    size_type  hole = heap_parent(n - 1);

    if (a[hole] < v) {

      a[n - 1] = a[hole];
      //@ assert heap:   IsHeap(a, n);
      //@ assert add:    MultisetAdd{Pre,Here}(a, n, a[hole]);
      //@ assert minus:  MultisetMinus{Pre,Here}(a, n, v);
      //@ assert retain: MultisetRetainRest{Pre,Here}(a, n, v, a[hole]);

      // end of prologue
      // start of main act
      if (0u < hole) {
        size_type parent = heap_parent(hole);

        /*@
          loop invariant bound:  0 <= hole < n-1;
          loop invariant heap:   IsHeap(a, n);
          loop invariant heap:   parent == HeapParent(hole);
          loop invariant less:   a[hole] < v;
          loop invariant add:    MultisetAdd{Pre,Here}(a, n, a[hole]);
          loop invariant minus:  MultisetMinus{Pre,Here}(a, n, v);
          loop invariant retain: MultisetRetainRest{Pre,Here}(a, n, v, a[hole]);
          loop assigns           hole, parent, a[0..n-1];
          loop variant           hole;
        */
        while (0u < hole && a[parent] < v) {
          //@ ghost Loop: // LoopEntry not yet supported!
          //@ ghost const value_type old_a = a[hole];
          //@ assert reorder:  old_a == \at(a[hole],Loop);

          if (a[hole] < a[parent]) {
            a[hole] = a[parent];
            //@ assert less:    old_a   < v;
            //@ assert less:    a[hole] < v;
            //@ assert retain:  MultisetUnchanged{Loop,Here}(a, 0, hole);
            //@ assert retain:  MultisetUnchanged{Loop,Here}(a, hole + 1, n);
            //@ assert minus:   MultisetMinus{Loop,Here}(a, n, old_a);
            //@ assert add:     MultisetAdd{Loop,Here}(a, n, a[hole]);
            //@ assert retain:  MultisetRetain{Loop,Here}(a, n, v);
            //@ assert retain:  MultisetRetain{Pre,Here}(a, n, old_a);
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

      //@ ghost Epi:
      a[hole] = v;
      //@ assert value:      \at(a[hole],Epi)  != v;
      //@ assert value:      \at(a[hole],Here) == v;
      //@ assert unchanged:  MultisetUnchanged{Epi,Here}(a, 0, hole);
      //@ assert unchanged:  MultisetUnchanged{Epi,Here}(a, hole+1, n);
      //@ assert add:        MultisetAdd{Epi,Here}(a, n, v);
      //@ assert minus:      MultisetMinus{Epi,Here}(a, n, \at(a[hole],Epi));
      //@ assert reorder:    MultisetUnchanged{Pre,Here}(a, n);
    }
  }
  // end of epilogue
}

