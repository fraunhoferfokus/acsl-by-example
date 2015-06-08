
#ifndef EQUAL3_H_INCLUDED
#define EQUAL3_H_INCLUDED

#include "EqualRanges.h"

/*@
  requires \valid_read(a + (0..n-1));
  requires \valid_read(b + (0..n-1));

  assigns \nothing;

  ensures \result <==> EqualRanges{Here,Here}(a, n, b);
*/
bool equal(const value_type* a, size_type n, const value_type* b);

#endif /* EQUAL3_H_INCLUDED */

