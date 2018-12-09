
#ifndef UNIQUESIZE_H_INCLUDED
#define UNIQUESIZE_H_INCLUDED

#include "Unchanged.h"

/*@
  axiomatic UniqueSizeAxiomatic
  {
    logic integer UniqueSize(value_type* a, integer n) reads a[0..n-1];

    axiom UniqueSizeEmpty:
      \forall value_type *a, integer n;
        n <= 0  ==>  UniqueSize(a, n) == 0;

    axiom UniqueSizeOne:
      \forall value_type *a, integer n;
        n == 1  ==>  UniqueSize(a, n) == 1;

    axiom UniqueSizeEqual:
      \forall value_type *a, integer n;
        0 < n ==> a[n-1] == a[n] ==> UniqueSize(a, n+1) == UniqueSize(a, n);

    axiom UniqueSizeDiffer:
      \forall value_type *a, integer n;
        0 < n ==> a[n-1] != a[n] ==>  UniqueSize(a, n+1) == UniqueSize(a, n) + 1;

    axiom UniqueSizeRead{K,L}:
      \forall value_type *a, integer n, i;
        Unchanged{K,L}(a, n) ==> UniqueSize{K}(a, n) == UniqueSize{L}(a, n);
  }
*/

#endif /* UNIQUESIZE_H_INCLUDED */

