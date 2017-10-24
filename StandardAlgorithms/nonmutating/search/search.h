
#ifndef SEARCH_H_INCLUDED
#define SEARCH_H_INCLUDED

#include "HasSubRange.h"

/*@
  requires \valid_read(a + (0..m-1));
  requires \valid_read(b + (0..n-1));

  assigns  \nothing;

  ensures  result: 0 <= \result <= m;

  behavior has_match:
    assumes HasSubRange(a, 0, m, b, n);
    ensures bound:  0 <= \result <= m-n;
    ensures result: EqualRanges{Here,Here}(a+\result, n, b);
    ensures first:  !HasSubRange(a, 0, \result+n-1, b, n);

  behavior no_match:
    assumes !HasSubRange(a, 0, m, b, n);
    ensures result: \result == m;

  complete behaviors;
  disjoint behaviors;
*/
size_type search(const value_type* a, size_type m,
                 const value_type* b, size_type n);

#endif /* SEARCH_H_INCLUDED */


