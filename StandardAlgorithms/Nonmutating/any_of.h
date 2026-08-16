#ifndef ANY_OF_H_INCLUDED
#define ANY_OF_H_INCLUDED

#include "SomeNone.acsl"

/*@
  requires   valid:   \valid_read(a + (0..n-1));

  terminates          \true;
  exits               \false;
  assigns             \nothing;

  ensures    result:  \result <==> SomeEqual(a, n, v);
*/
bool any_of(const value_type* a, size_type n, value_type v);

#endif /* ANY_OF_H_INCLUDED */
