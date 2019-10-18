
#include "is_heap.h"
#include "is_heap_until.h"

bool
is_heap(const value_type* a, size_type n)
{
  return is_heap_until(a, n) == n;
}

