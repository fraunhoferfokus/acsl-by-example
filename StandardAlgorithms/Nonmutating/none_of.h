#ifndef NONE_OF_H_INCLUDED
#define NONE_OF_H_INCLUDED

#include "SomeNone.acsl"

/*@
  requires   valid:   \valid_read(a + (0..n-1));

  terminates          \true;
  exits               \false;
  assigns             \nothing;

  ensures    result:  \result <==> NoneEqual(a, n, v);
*/
bool none_of(const value_type* a, size_type n, value_type v);

#endif /* NONE_OF_H_INCLUDED */
