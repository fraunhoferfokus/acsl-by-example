
#include "inner_product.h"

value_type
inner_product(const value_type* a, const value_type* b, size_type n,
              value_type init)
{
  value_type result = init;

  /*@
     loop invariant index:   0 <= i <= n;
     loop invariant pre:     result == InnerProduct(a, b, i, init);
     loop assigns i, result;
     loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i)
  {
    result = result + a[i] * b[i];
  }

  return result;
}

