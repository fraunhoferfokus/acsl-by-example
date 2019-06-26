

#include "unique_copy.h"

size_type
unique_copy(const value_type* a, size_type n, value_type* b)
{
  if (n == 0u) {
    return n;
  }
  else {
    size_type k = 0u;
    b[k] = a[0];

    for (size_type i = 1u; i < n; ++i) {
      const value_type val = a[i];

      if (b[k] != val) {
        b[++k] = val;
      }
    }

    return ++k;
  }
}


