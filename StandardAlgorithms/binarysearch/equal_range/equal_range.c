
#include "equal_range.h"
#include "lower_bound.h"
#include "upper_bound.h"
#include "make_pair.h"

size_type_pair
equal_range(const value_type* a, size_type n, value_type v)
{
  size_type first  = lower_bound(a, n, v);
  size_type second = upper_bound(a, n, v);
  //@ assert aux: second < n  ==>  v < a[second];
  return make_pair(first, second);
}

