
#ifndef MISMTACH_H_INCLUDED
#define MISMTACH_H_INCLUDED

#include "Equal.acsl"

/*@
  requires valid:   \valid_read(a + (0..n-1));
  requires valid:   \valid_read(b + (0..n-1));
  assigns           \nothing;
  ensures  result:  0 <= \result <= n;

  behavior all_equal:
    assumes         Equal{Here,Here}(a, n, b);
    assigns         \nothing;
    ensures result: \result == n;

  behavior some_not_equal:
    assumes         !Equal{Here,Here}(a, n, b);
    assigns         \nothing;
    ensures bound:  0 <= \result < n;
    ensures result: a[\result] != b[\result];
    ensures first:  Equal{Here,Here}(a, \result, b);

  complete behaviors;
  disjoint behaviors;
*/
size_type
mismatch(const value_type* a, size_type n, const value_type* b);

#endif /* MISMTACH_H_INCLUDED */

