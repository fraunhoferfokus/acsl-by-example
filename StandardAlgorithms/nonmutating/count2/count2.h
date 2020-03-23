
#ifndef COUNT2_H_INCLUDED
#define COUNT2_H_INCLUDED

#include "CountInd.spec"

/*@
  requires valid: \valid_read(a + (0..n-1));
  assigns         \nothing;
  ensures bound:  0 <= \result <= n;
  ensures count:  CountInd(a, n, val, \result);
*/
size_type
count2(const value_type* a, size_type n, value_type val);

#endif /*  COUNT2_H_INCLUDED */

