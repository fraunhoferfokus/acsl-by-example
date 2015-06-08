
#ifndef ADJACENT_FIND_H_INCLUDED
#define ADJACENT_FIND_H_INCLUDED

#include "HasEqualNeighbors.h"

/*@
  requires \valid_read(a + (0..n-1));

  assigns \nothing;

  behavior some:
    assumes  HasEqualNeighbors(a, n);
    ensures  0 <= \result < n-1;
    ensures  a[\result] == a[\result+1];
    ensures  !HasEqualNeighbors(a, \result);

  behavior none:
    assumes  !HasEqualNeighbors(a, n);
    ensures  \result == n;

  complete behaviors;
  disjoint behaviors;
*/
size_type adjacent_find(const value_type* a, size_type n);

#endif /* ADJACENT_FIND_H_INCLUDED */
