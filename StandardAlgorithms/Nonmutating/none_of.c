#include "none_of.h"
#include "find.h"

bool none_of(const value_type* a, size_type n, value_type v)
{
  return find(a, n, v) == n;
}
