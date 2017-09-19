
#ifndef SEARCH_N_H_INCLUDED
#define SEARCH_N_H_INCLUDED

#include "HasConstantSubRange.h"

/*@
  requires valid: \valid_read(a + (0..m-1));

  assigns  \nothing;

  ensures  result:  0 <= \result <= m;

  behavior has_match:
    assumes HasConstantSubRange(a, m, n, b);
    ensures result:  0 <= \result <= m-n;
    ensures match:   ConstantRange(a, \result, \result+n, b);
    ensures first:   !HasConstantSubRange(a, \result+n-1, n, b);

  behavior no_match:
    assumes !HasConstantSubRange(a, m, n, b);
    ensures result:  \result == m;

  complete behaviors;
  disjoint behaviors;
*/
size_type
search_n(const value_type* a, size_type m, size_type n, value_type b);

#endif /* SEARCH_N_H_INCLUDED */

