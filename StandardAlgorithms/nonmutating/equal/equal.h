
#ifndef EQUAL2_H_INCLUDED
#define EQUAL2_H_INCLUDED

#include "Equal.acsl"

/*@
  requires valid:  \valid_read(a + (0..n-1));
  requires valid:  \valid_read(b + (0..n-1));
  assigns          \nothing;
  ensures result:  \result <==> Equal{Here,Here}(a, n, b);
*/
bool
equal(const value_type* a, size_type n, const value_type* b);

#endif /* EQUAL2_H_INCLUDED */

