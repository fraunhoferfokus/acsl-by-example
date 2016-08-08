
#ifndef FIND2_H_INCLUDED
#define FIND2_H_INCLUDED

#include "HasValue.h"

/*@
  requires  valid: \valid_read(a + (0..n-1));

  assigns  \nothing;

  behavior some:
    assumes  HasValue(a, n, val);
    ensures  bound:   0 <= \result < n;
    ensures  result:  a[\result] == val;
    ensures  first:   !HasValue(a, \result, val);

  behavior none:
    assumes  !HasValue(a, n, val);
    ensures  result:  \result == n;

  complete behaviors;
  disjoint behaviors;
*/
size_type find(const value_type* a, size_type n, value_type val);

#endif /* FIND2_H_INCLUDED */

