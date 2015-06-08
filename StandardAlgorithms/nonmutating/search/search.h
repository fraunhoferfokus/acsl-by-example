
#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include "HasSubRange.h"

/*@
  requires \valid_read(a + (0..m-1));
  requires \valid_read(b + (0..n-1));

  assigns \nothing;

  ensures (n == 0 || m == 0) ==> \result == 0;

  behavior has_match:
    assumes HasSubRange(a, m, b, n);
    ensures 0 <= \result <= m-n;
    ensures EqualRanges{Here,Here}(a+\result, n, b);
    ensures !HasSubRange(a, \result+n-1, b, n);

  behavior no_match:
    assumes !HasSubRange(a, m, b, n);
    ensures \result == m;

  complete behaviors;
  disjoint behaviors;
*/
size_type search(const value_type* a, size_type m,
                 const value_type* b, size_type n);

#endif /* SEARCH_H_INCLUDED */


