
#include "rotate_copy.h"
#include "copy.h"

void rotate_copy(const value_type* a, size_type p, size_type n, value_type* b)
{
  copy(a,  p, b + (n - p));
  copy(a + p, n - p, b);
}

