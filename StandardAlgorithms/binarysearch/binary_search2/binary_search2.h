
#ifndef BINARY_SEARCH2_H_INCLUDED
#define BINARY_SEARCH2_H_INCLUDED

#include "Sorted.h"
#include "HasValue.h"

/*@
  requires valid:  \valid_read(a + (0..n-1));
  requires sorted: Sorted(a, n);

  assigns  \nothing;

  ensures  result: \result <==> HasValue(a, n, val);
*/
bool binary_search(const value_type* a, size_type n, value_type val);

#endif /* BINARY_SEARCH2_H_INCLUDED */

