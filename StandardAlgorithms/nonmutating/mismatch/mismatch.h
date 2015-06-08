
#ifndef MISMTACH_H_INCLUDED
#define MISMTACH_H_INCLUDED

#include "EqualRanges.h"

/*@
  requires \valid_read(a + (0..n-1));
  requires \valid_read(b + (0..n-1));

  assigns \nothing;

  behavior all_equal:
    assumes EqualRanges{Here,Here}(a, n, b);
    ensures \result == n;

  behavior some_not_equal:
    assumes !EqualRanges{Here,Here}(a, n, b);
    ensures 0 <= \result < n;
    ensures a[\result] != b[\result];
    ensures EqualRanges{Here,Here}(a, \result, b);

  complete behaviors;
  disjoint behaviors;
*/
size_type mismatch(const value_type* a, size_type n,
                   const value_type* b);

#endif /* MISMTACH_H_INCLUDED */

