
#include "mutating.h"

void rotate_copy(const value_type* a, size_type m, size_type n,
                 value_type* b)
{
  copy(a,  m, b+(n-m));
  copy(a + m, n-m, b);
}
