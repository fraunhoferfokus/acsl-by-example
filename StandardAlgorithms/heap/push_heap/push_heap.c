
#include "push_heap.h"
#include "CountLemmas.h"
#include "MultisetAdd.h"
#include "MultisetMinus.h"
#include "MultisetUnchangedExcept.h"

void push_heap(value_type* a, size_type n)
{
  // start of prologue

  if (n == 1) {
    return;
  }

  const value_type val = a[n - 1];
  size_type hole = n - 1;

  size_type parent = (hole - 1) / 2;

  if (val > a[parent]) {
    /*@
       requires val:      a[hole] == val;
       assigns  a[hole];
       ensures  newhole:  Unchanged{Old, Here}(a, 0, hole);
       ensures  newhole:  Unchanged{Old, Here}(a, hole+1, n);
       ensures  val:      a[hole] == a[parent];
    */
    a[hole] = a[parent];
    hole = parent;
  }
  //@ assert heap:  IsHeap(a, n);

  if (hole == n - 1) {
    return;
  }

  // end of prologue
  // start of main act

  /*@
     loop invariant bound:    0 <= hole < n-1;
     loop invariant heap:     IsHeap(a, n);
     loop invariant less:     a[hole] < val;
     loop invariant reorder:  MultisetMinus{Pre,Here}(a, n, val);
     loop invariant reorder:  MultisetAdd{Pre,Here}(a, n, a[hole]);
     loop invariant reorder:  MultisetUnchangedExcept{Pre,Here}(a, n, val, a[hole]);
     loop assigns   hole, a[0..n-1];
     loop variant   hole;
  */
  while (hole > 0) {
    const size_type par = (hole - 1) / 2;

    /*@
      requires heap:        IsHeap(a, n);
      assigns  hole, a[hole];
      ensures  heap:        IsHeap(a, n);
      ensures  reorder:     MultisetMinus{Pre,Here}(a, n, val);
      ensures  reorder:     MultisetAdd{Pre,Here}(a, n, a[hole]);
      ensures  reorder:     MultisetUnchangedExcept{Pre,Here}(a, n, val, a[par]);
      ensures  less:        a[hole] < val;
      ensures  decreasing:  hole < \old(hole);
    */
    if (a[par] < val) {
      /*@
         requires heap:       IsHeap(a, n);
         requires heap:       par == HeapParent(hole);
         requires heap:       HeapParent(hole) < hole < n-1;
         assigns  a[hole];
         ensures  heap:       a[hole] == a[HeapParent(hole)];
         ensures  unchanged:  Unchanged{Old,Here}(a, 0, hole);
         ensures  unchanged:  Unchanged{Old,Here}(a, hole+1, n);
         ensures  heap:       IsHeap(a, n);
      */
      a[hole] = a[par];
      /*@
         assigns hole;
         ensures bound:    hole < \old(hole);
         ensures less:     a[hole] < val;
         ensures reorder:  MultisetUnchangedExcept{Pre,Here}(a, n, val, a[hole]);
      */
      hole = par;
      //@ assert reorder:  MultisetUnchangedExcept{Pre,Here}(a, n, val, a[hole]);
    } else {
      break;
    }
    //@ assert heap:  IsHeap(a, n);
  }

  // end of main act
  // start of epilogue

  /*@
     requires val:  a[hole] != val;
     assigns  a[hole];
     ensures  val:  a[hole] == val;
     ensures  val:  Unchanged{Old,Here}(a, 0, hole);
     ensures  val:  Unchanged{Old,Here}(a, hole+1, n);
  */
  a[hole] = val;
  //@ assert heap:     IsHeap(a, n);
  //@ assert reorder:  MultisetUnchanged{Pre,Here}(a, n);

  // end of epilogue
}

