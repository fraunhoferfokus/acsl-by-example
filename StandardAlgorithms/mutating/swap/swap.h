
#ifndef SWAP_H_INCLUDED
#define SWAP_H_INCLUDED

#include "typedefs.h"

/*@
  requires valid:    \valid(p);
  requires valid:    \valid(q);
  assigns            *p;
  assigns            *q;
  ensures  exchange: *p == \old(*q);
  ensures  exchange: *q == \old(*p);
*/
void
swap(value_type* p, value_type* q);

#endif /* SWAP_H_INCLUDED */

