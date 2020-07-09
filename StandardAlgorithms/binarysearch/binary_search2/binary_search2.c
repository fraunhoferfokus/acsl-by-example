
#include "binary_search2.h"
#include "lower_bound.h"

bool
binary_search2(const value_type* a, size_type n, value_type v)
{
  const size_type i = lower_bound(a, n, v);
  return (i < n) && (a[i] <= v);
}

