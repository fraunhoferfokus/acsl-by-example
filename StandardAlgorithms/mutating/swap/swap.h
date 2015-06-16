
#ifndef SWAP_H_INCLUDED
#define SWAP_H_INCLUDED

#include "typedefs.h"

/*@
  requires \valid(p);
  requires \valid(q);

  assigns *p;
  assigns *q;

  ensures *p == \old(*q);
  ensures *q == \old(*p);
*/
void swap(value_type* p, value_type* q);

#endif /* SWAP_H_INCLUDED */

