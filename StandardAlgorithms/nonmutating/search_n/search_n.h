
#ifndef SEARCH_N_H_INCLUDED
#define SEARCH_N_H_INCLUDED

#include "HasConstantSubRange.spec"

/*@
  requires valid:     \valid_read(a + (0..n-1));
  assigns             \nothing;
  ensures  result:    0 <= \result <= n;

  behavior has_match:
    assumes           HasConstantSubRange(a, n, v, p);
    assigns           \nothing;
    ensures result:   0 <= \result <= n-p;
    ensures match:    ConstantRange(a, \result, \result+p, v);
    ensures first:    !HasConstantSubRange(a, \result+p-1, v, p);

  behavior no_match:
    assumes           !HasConstantSubRange(a, n, v, p);
    assigns           \nothing;
    ensures result:   \result == n;

  complete behaviors;
  disjoint behaviors;
*/
size_type
search_n(const value_type* a, size_type n, value_type v, size_type p);

#endif /* SEARCH_N_H_INCLUDED */

