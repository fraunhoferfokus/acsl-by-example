
#ifndef FIND_END_H_INCLUDED
#define FIND_END_H_INCLUDED

#include "HasSubRange.h"

/*@
  requires valid: \valid_read(a + (0..m-1));
  requires valid: \valid_read(b + (0..n-1));

  assigns \nothing;

  behavior has_match:
    assumes HasSubRange(a, 0, m, b, n);
    ensures bound:  0 <= \result <= m-n;
    ensures result: EqualRanges{Here,Here}(a + \result, n, b);
    ensures last:   !HasSubRange(a, \result + 1, m, b, n);

  behavior no_match:
    assumes !HasSubRange(a, 0, m, b, n);
    ensures result: \result == m;

  complete behaviors;
  disjoint behaviors;
*/
size_type find_end(const value_type* a, size_type m,
                   const value_type* b, size_type n);

#endif /* FIND_END_H_INCLUDED */


