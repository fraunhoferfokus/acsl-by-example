
#include "rotate.h"
#include "../reverse/reverse.h"
#include "ReverseLemmas.h"

size_type rotate(value_type* a, size_type m, size_type n)
{
  // if one subrange is empty, then nothings needs to be done
  if (0 < m && m < n) {
    reverse(a,  m);
    reverse(a + m, n - m);

    /*@
      requires left:   Reverse{Here,Pre}(a, 0, m, 0);
      requires right:  Reverse{Here,Pre}(a, m, n, m);

      assigns          a[0..n-1];

      ensures left:    Reverse{Here,Old}(a, 0, n-m, m);
      ensures right:   Reverse{Here,Old}(a, n-m, n, 0);
    */
    reverse(a, n);

    //@ assert left:   EqualRanges{Here,Pre}(a, 0, n-m, m);
    //@ assert right:  EqualRanges{Here,Pre}(a, n-m, n, 0);
  }

  return n - m;
}

