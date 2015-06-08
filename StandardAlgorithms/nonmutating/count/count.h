
#ifndef COUNT_H_INCLUDED
#define COUNT_H_INCLUDED

#include "CountAxiomatic.h"

/*@
  requires \valid_read(a + (0..n-1));

  assigns \nothing;

  ensures \result == Count(a, n, val);
  ensures 0 <= \result <= n;
*/
size_type count(const value_type* a, size_type n, value_type val);

#endif /*  COUNT_H_INCLUDED */
