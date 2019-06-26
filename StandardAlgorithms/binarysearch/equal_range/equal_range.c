
#include "../lower_bound/lower_bound.h"
#include "../upper_bound/upper_bound.h"
#include "equal_range.h"

size_type_pair
equal_range(const value_type* a, size_type n, value_type val)
{
  size_type first  = lower_bound(a, n, val);
  size_type second = upper_bound(a, n, val);
  //@ assert aux: second < n  ==>  val < a[second];
  return make_pair(first, second);
}

