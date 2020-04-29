
#ifndef FIND3_H_INCLUDED
#define FIND3_H_INCLUDED

#include "Find.acsl"


/*@
  requires valid:    \valid_read(a + (0..n-1));
  assigns            \nothing;
  ensures result:    0 <= \result <= n;
  ensures result:    \result == Find(a, n, v);
*/
size_type
find3(const value_type* a, size_type n, value_type v);

#endif /* FIND3_H_INCLUDED */

