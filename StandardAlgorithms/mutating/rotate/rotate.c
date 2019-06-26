
#include "rotate.h"
#include "../reverse/reverse.h"

size_type
rotate(value_type* a, size_type m, size_type n)
{
  // if one subrange is empty, then nothings needs to be done
  if ((0u < m) && (m < n)) {
    reverse(a,  m);
    reverse(a + m, n - m);
    /*@
      requires left:   Reverse{Pre,Here}(a, 0, m, 0);
      requires right:  Reverse{Pre,Here}(a, m, n, m);

      assigns          a[0..n-1];

      ensures left:    Reverse{Old,Here}(a, 0, m, n-m);
      ensures right:   Reverse{Old,Here}(a, m, n, 0);
    */
    reverse(a, n);
    //@ assert left:   EqualRanges{Pre,Here}(a, 0, m, n-m);
    //@ assert right:  EqualRanges{Pre,Here}(a, m, n, 0);
  }

  return n - m;
}

