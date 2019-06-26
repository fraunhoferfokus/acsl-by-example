
#ifndef FIND_H_INCLUDED
#define FIND_H_INCLUDED

#include "typedefs.h"

/*@
  requires  \valid_read(a + (0..n-1));

  assigns   \nothing;

  ensures   0 <= \result <= n;

  behavior some:
    assumes  \exists integer i; 0 <= i < n && a[i] == val;
    ensures  0 <= \result < n;
    ensures  a[\result] == val;
    ensures  \forall integer i; 0 <= i < \result ==> a[i] != val;

  behavior none:
    assumes  \forall integer i; 0 <= i < n ==> a[i] != val;
    ensures  \result == n;

  complete behaviors;
  disjoint behaviors;
*/
size_type
find(const value_type* a, size_type n, value_type val);

#endif /* FIND_H_INCLUDED */

