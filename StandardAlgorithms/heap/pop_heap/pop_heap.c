
#include "pop_heap.h"


void pop_heap(value_type* a, size_type n)
{
  if (1u < n) { // otherwise nothings needs to be done

    size_type hole = 0;
    const value_type v = a[hole];
    //@ assert max:  UpperBound(a, 0, n, v);

    const size_type last = n - 1u;

    size_type right = 2u * hole + 2u;

    /*@
       loop invariant bounds:    0 <= hole < n;
       loop invariant heap:      IsHeap(a, last);
       loop invariant max:       UpperBound(a, 0, n, v);
       loop invariant max:       hole < last ==> a[HeapParent(hole)] >= a[last];
       loop invariant unchanged:  \at(a[last],Pre) == a[last];

       loop assigns hole, right, a[0..last];
       loop   variant n - hole;
    */
    do  {
      right = 2u * hole + 2u;
      const size_type left  = right - 1u;
      //@ assert heap: right == HeapRight(hole);
      //@ assert heap:  left == HeapLeft(hole);
      size_type child = right;

      if (right < last) { // case of two childs

        // select child where larger value resides;
        child = a[right] < a[left] ? left : right;
        //@ assert heap: child == HeapLeft(hole) || child == HeapRight(hole);
        //@ assert heap: child < last;

      } else {
        //@ assert heap: right >= last;
        //@ assert heap: left == HeapLeft(hole);
        //@ assert heap: left >= last - 1;
        // at most one child can exist
        child = left;
      }

      if (right <= last) {
        if (a[child] > a[last]) {
          //@ assert heap: hole < last;
          a[hole] = a[child];
          //@ assert heap: \at(a[last],Pre) == a[last];
          hole = child;
        } else {
          break;
        }
      }

    } while (right < last);

    //@  assert heap: hole < last ==> a[HeapParent(hole)] >= a[last];
    a[hole] = a[last];
    // assert hole < last ==> a[hole] == a[last] == \at(a[last],Pre) == a[last];
    a[last]  = v;

    //@ assert heap:    IsHeap(a, last);
  }
}

