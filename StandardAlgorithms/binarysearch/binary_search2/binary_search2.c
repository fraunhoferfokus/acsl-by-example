
#include "binary_search2.h"
#include "../lower_bound/lower_bound.h"

bool
binary_search2(const value_type* a, size_type n, value_type val)
{
  const size_type i = lower_bound(a, n, val);
  return (i < n) && (a[i] <= val);
}

