
#include "is_sorted.h"
#include "is_sorted_until.h"

bool is_sorted(const value_type* a, size_type n)
{
  return is_sorted_until(a, n) == n;
}

