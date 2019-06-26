
#ifndef UNIQUESIZE_SPEC_INCLUDED
#define UNIQUESIZE_SPEC_INCLUDED

#include "Unchanged.spec"

/*@
  axiomatic UniqueSizeAxiomatic
  {
    logic integer UniqueSize(value_type* a, integer n) =
      n <= 0 ? 0 : (n == 1 ? 1 : UniqueSize(a, n-1) + (a[n-1] == a[n-2] ? 0 : 1));

    lemma UniqueSizeEmpty:
      \forall value_type *a, integer n;
        n <= 0  ==>  UniqueSize(a, n) == 0;

    lemma UniqueSizeOne:
      \forall value_type *a;
        UniqueSize(a, 1) == 1;

    lemma UniqueSizeEqual:
      \forall value_type *a, integer n;
        0 < n ==> a[n-1] == a[n] ==> UniqueSize(a, n+1) == UniqueSize(a, n);

    lemma UniqueSizeDiffer:
      \forall value_type *a, integer n;
        0 < n ==> a[n-1] != a[n] ==>  UniqueSize(a, n+1) == UniqueSize(a, n) + 1;

    lemma UniqueSizeRead{K,L}:
      \forall value_type *a, integer n, i;
        Unchanged{K,L}(a, n) ==> UniqueSize{K}(a, n) == UniqueSize{L}(a, n);
  }
*/

#endif /* UNIQUESIZE_SPEC_INCLUDED */

