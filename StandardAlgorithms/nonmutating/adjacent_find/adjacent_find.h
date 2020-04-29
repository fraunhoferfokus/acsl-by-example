
#ifndef ADJACENT_FIND_H_INCLUDED
#define ADJACENT_FIND_H_INCLUDED

#include "HasEqualNeighbors.acsl"

/*@
  requires valid:       \valid_read(a + (0..n-1));
  assigns               \nothing;
  ensures result:       0 <= \result <= n;

  behavior some:
    assumes             HasEqualNeighbors(a, n);
    assigns             \nothing;
    ensures  result:    0 <= \result < n-1;
    ensures  adjacent:  a[\result] == a[\result+1];
    ensures  first:     !HasEqualNeighbors(a, \result);

  behavior none:
    assumes             !HasEqualNeighbors(a, n);
    assigns             \nothing;
    ensures  result:    \result == n;

  complete behaviors;
  disjoint behaviors;
*/
size_type
adjacent_find(const value_type* a, size_type n);

#endif /* ADJACENT_FIND_H_INCLUDED */

