
#ifndef EQUAL_H_INCLUDED
#define EQUAL_H_INCLUDED

#include "typedefs.h"

/*@
  requires \valid_read(a + (0..n-1));
  requires \valid_read(b + (0..n-1));

  assigns \nothing;

  behavior all_equal:
    assumes \forall integer i; 0 <= i < n ==> a[i] == b[i];
    ensures \result;

  behavior some_not_equal:
    assumes \exists integer i; 0 <= i < n && a[i] != b[i];
    ensures !\result;

  complete behaviors;
  disjoint behaviors;
*/
bool equal(const value_type* a, size_type n, const value_type* b);

#endif // EQUAL_H_INCLUDED

