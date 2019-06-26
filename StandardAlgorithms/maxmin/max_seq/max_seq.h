
#ifndef MAX_SEQ_H_INCLUDED
#define MAX_SEQ_H_INCLUDED

#include "typedefs.h"

/*@
  requires n > 0;
  requires \valid_read(p + (0..n-1));

  assigns  \nothing;

  ensures \forall integer i; 0 <= i <= n-1 ==> \result >= p[i];
  ensures \exists integer e; 0 <= e <= n-1 &&  \result == p[e];
*/
value_type
max_seq(const value_type* p, size_type n);

#endif /* MAX_SEQ_H_INCLUDED */
