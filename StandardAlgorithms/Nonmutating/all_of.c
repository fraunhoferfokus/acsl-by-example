#include "all_of.h"
#include "find_if_not.h"

bool all_of(const value_type* a, size_type n, value_type v)
{
  return find_if_not(a, n, v) == n;
}
