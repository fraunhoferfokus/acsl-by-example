
#ifndef BINARY_SEARCH_H_INCLUDED
#define BINARY_SEARCH_H_INCLUDED

#include "Increasing.acsl"
#include "SomeNone.acsl"

/*@
  requires   valid:       \valid_read(a + (0..n-1));
  requires   increasing:  Increasing(a, n);

  terminates              \true;
  exits                   \false;
  assigns                 \nothing;

  ensures    result:      \result <==> SomeEqual(a, n, v);
*/
bool binary_search(const value_type* a, size_type n, value_type v);

#endif /* BINARY_SEARCH2_H_INCLUDED */

