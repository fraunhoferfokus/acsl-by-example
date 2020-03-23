
#ifndef FIND2_H_INCLUDED
#define FIND2_H_INCLUDED

#include "SomeNone.spec"

/*@
  requires valid:    \valid_read(a + (0..n-1));
  assigns            \nothing;
  ensures result:    0 <= \result <= n;

  behavior some:
    assumes          SomeEqual(a, n, val);
    assigns          \nothing;
    ensures  bound:  0 <= \result < n;
    ensures  result: a[\result] == val;
    ensures  first:  NoneEqual(a, \result, val);

  behavior none:
    assumes          NoneEqual(a, n, val);
    assigns          \nothing;
    ensures  result: \result == n;

  complete behaviors;
  disjoint behaviors;
*/
size_type
find2(const value_type* a, size_type n, value_type val);

#endif /* FIND2_H_INCLUDED */

