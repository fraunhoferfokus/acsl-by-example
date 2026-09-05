
#ifndef REWRITE_ARRAY_NOTHING_H_INCLUDED
#define REWRITE_ARRAY_NOTHING_H_INCLUDED

#include "Unchanged.acsl"

/*@
  requires    \valid(a + (0..n-1));

  terminates  \true;
  exits       \false;
  assigns     \nothing;

  ensures     Unchanged{Pre,Post}(a,0,n);
*/
void rewrite_array(value_type* a, size_type n);

#endif /* REWRITE_ARRAY_NOTHING_H_INCLUDED */

