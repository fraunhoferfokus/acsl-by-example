
#ifndef BINARY_SEARCH2_H_INCLUDED
#define BINARY_SEARCH2_H_INCLUDED

#include "Increasing.spec"
#include "HasValue.spec"

/*@
  requires valid:      \valid_read(a + (0..n-1));
  requires increasing: Increasing(a, n);
  assigns              \nothing;
  ensures  result:     \result <==> HasValue(a, n, val);
*/
bool
binary_search2(const value_type* a, size_type n, value_type val);

#endif /* BINARY_SEARCH2_H_INCLUDED */

