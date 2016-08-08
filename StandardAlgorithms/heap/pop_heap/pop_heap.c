
#include "pop_heap.h"

void pop_heap(value_type* a, size_type n)
{
  size_type hole = 0;
  const value_type max_value  = a[0];

  /*@
     loop invariant bounds:    0 <= hole < n;
     loop invariant heap:      IsHeap(a, n-1);
     loop invariant max:       UpperBound(a, 0, n, max_value);
     loop invariant max:       hole < n-1 ==> a[HeapParent(hole)] >= a[n-1];
     loop invariant unchanged:  \at(a[n-1],Pre) == a[n-1];

     loop assigns hole, a[0..n-1]; 
     loop   variant n - hole;
  */
  while (true) {
    size_type child = 2 * hole + 2;

    if (child < n - 1) {
      if (a[child] < a[child - 1]) {
        child--;
      }

      //@ assert child == HeapLeft(hole) || child == HeapRight(hole);
      if (a[child] > a[n - 1]) {
        //@ assert hole < n-1;
        a[hole] = a[child];
        //@ assert \at(a[n-1],Pre) == a[n-1];
        hole = child;
      } else {
        break;
      }
    } else {
      child = 2 * hole + 1;

      if (child == n - 2 && a[child] > a[n - 1]) {
        //@ assert hole < n-1;
        a[hole] = a[child];
        //@ assert \at(a[n-1],Pre) == a[n-1];
        hole = child;
      }

      break;
    }
  }

  //@  assert hole < n-1 ==> a[HeapParent(hole)] >= a[n-1];
  a[hole] = a[n - 1];
  // assert hole < n-1 ==> a[hole] == a[n-1] == \at(a[n-1],Pre) == a[n-1];
  a[n - 1]  = max_value;

  //@ assert heap:    IsHeap(a, n-1);
  //@ assert reorder: MultisetUnchanged{Pre, Here}(a, n);
}

