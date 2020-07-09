
#include "equal_range2.h"
#include "lower_bound.h"
#include "upper_bound.h"
#include "make_pair.h"
#include "ShiftLemmas.acsl"
#include "IncreasingLemmas.acsl"

size_type_pair
equal_range2(const value_type* a, size_type n, value_type v)
{
  size_type first  = 0u;
  size_type middle = 0u;
  size_type last   = n;

  /*@
    loop invariant bounds: 0 <= first <= last <= n;
    loop invariant left:   StrictUpperBound(a, 0, first, v);
    loop invariant right:  StrictLowerBound(a, last, n, v);
    loop assigns first, last, middle;
    loop variant last - first;
   */
  while (last > first) {
    middle = first + (last - first) / 2u;

    if (a[middle] < v) {
      first = middle + 1u;
    }
    else if (v < a[middle]) {
      last = middle;
    }
    else {
      break;
    }
  }

  if (first < last) {
    //@ assert increasing: Increasing(a, first, middle);
    size_type left = first + lower_bound(a + first, middle - first, v);
    //@ assert middle: LowerBound(a, left, middle, v);
    //@ assert left:   StrictUpperBound(a, first, left, v);
    ++middle;
    //@ assert increasing: Increasing(a, middle, last);
    size_type right = middle + upper_bound(a + middle, last - middle, v);
    //@ assert middle: UpperBound(a, middle, right, v);
    //@ assert right:  StrictLowerBound(a, right, last, v);
    //@ assert middle: AllEqual(a, left, right, v);
    return make_pair(left, right);
  }
  else {
    return make_pair(first, first);
  }
}

