
/*@
   requires bound: 2 <= n <  (UINT_MAX-2)/2;
   requires valid: \valid_read(a + (0..n-1));
   requires bound: 0 <= hole < n;

   assigns \nothing;

   behavior two:
     assumes HeapRight(hole) < n - 1;
     assigns \nothing;
     ensures \result == HeapLeft(hole) || HeapRight(hole);
     ensures a[\result] >= a[HeapLeft(hole)] && a[\result] >= a[HeapRight(hole)];

   behavior one:
     assumes HeapRight(hole) == n - 1;
     assigns \nothing;
     ensures \result == n - 2;

   behavior none:
     assumes HeapRight(hole) > n - 1;
     assigns \nothing;
     ensures \result == n;
*/
size_type find_child(const value_type* a, size_type n, size_type hole)
{
  const size_type back = n - 1u;
  size_type child = 2u * hole + 2u;
  //@ assert heap: child == HeapRight(hole);

  if (child < back) { // case of two children

    if (a[child] < a[child - 1u]) { // select child where larger value resides;
      --child;
    }
    //@ assert heap: child == HeapLeft(hole) || child == HeapRight(hole);

    return child;

  } else {
    //@ assert heap: child >= back;
    // at most one child can exist
    --child;
    //@ assert heap: child == HeapLeft(hole);
    if (child == back - 1u) {
      return child;
    } else {
      return n;
    }
  }
}


