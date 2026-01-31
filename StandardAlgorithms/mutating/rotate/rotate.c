
#include "rotate.h"
#include "reverse.h"

size_type
rotate(value_type* a, size_type p, size_type n)
{
  // if one subrange is empty, then nothings needs to be done
  if ((0u < p) && (p < n)) {
    reverse(a,  p);
    reverse(a + p, n - p);
    reverse(a, n);
    //@ assert rotate:   Rotate{Pre,Here}(a, p, n);
  }

  return n - p;
}

