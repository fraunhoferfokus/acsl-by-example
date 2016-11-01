
#ifndef HASVALUESECTIONINVERSION_H_INCLUDED
#define HASVALUESECTIONINVERSION_H_INCLUDED

#include "HasValue.h"

/*@
   lemma HasValueSectionInversion{L}:
     \forall value_type *a, v, integer m, n, p, q;
       m <= p <= q <= n       ==>
       !HasValue(a, m, n, v)  ==> 
       !HasValue(a, p, q, v);
*/

#endif /* HASVALUESECTIONINVERSION_H_INCLUDED */

