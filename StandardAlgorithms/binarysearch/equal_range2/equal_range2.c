
#include "equal_range2.h"
#include "lower_bound.h"
#include "upper_bound.h"
#include "make_pair.h"
#include "ShiftLemmas.spec"

size_type_pair
equal_range2(const value_type* a, size_type n, value_type val)
{
  size_type first  = 0u;
  size_type middle = 0u;
  size_type last   = n;

  /*@
    loop invariant bounds: 0 <= first <= last <= n;
    loop invariant left:   StrictUpperBound(a, 0, first, val);
    loop invariant right:  StrictLowerBound(a, last, n, val);
    loop assigns first, last, middle;
    loop variant last - first;
   */
  while (last > first) {
    middle = first + (last - first) / 2u;

    if (a[middle] < val) {
      first = middle + 1u;
    }
    else if (val < a[middle]) {
      last = middle;
    }
    else {
      break;
    }
  }

  if (first < last) {
    //@ assert increasing: Increasing(a, first, middle);
    size_type left = first + lower_bound(a + first, middle - first, val);
    //@ assert constant: LowerBound(a, left, middle, val);
    //@ assert strict: StrictUpperBound(a, first, left, val);
    ++middle;
    //@ assert increasing: Increasing(a, middle, last);
    size_type right = middle + upper_bound(a + middle, last - middle, val);
    //@ assert constant: UpperBound(a, middle, right, val);
    //@ assert strict: StrictLowerBound(a, right, last, val);
    return make_pair(left, right);
  }
  else {
    return make_pair(first, first);
  }
}

