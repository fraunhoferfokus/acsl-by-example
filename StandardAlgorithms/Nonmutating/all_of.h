#ifndef ALL_OF_H_INCLUDED
#define ALL_OF_H_INCLUDED

#include "AllSomeNot.acsl"

/*@
  requires   valid:   \valid_read(a + (0..n-1));

  terminates          \true;
  exits               \false;
  assigns             \nothing;

  ensures    result:  \result <==> AllEqual(a, n, v);
*/
bool all_of(const value_type* a, size_type n, value_type v);

#endif /* ALL_OF_H_INCLUDED */
