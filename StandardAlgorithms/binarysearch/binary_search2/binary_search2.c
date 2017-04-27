
#include "binary_search2.h"
#include "binarysearch.h"

bool binary_search(const value_type* a, size_type n, value_type val)
{
  const size_type i = lower_bound(a, n, val);

  return i < n && a[i] <= val;
}

