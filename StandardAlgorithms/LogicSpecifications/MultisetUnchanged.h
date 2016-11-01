
#ifndef MULTISETUNCHANGED_H_INCLUDED
#define MULTISETUNCHANGED_H_INCLUDED

#include "CountLogic.h"

/*@
  predicate
    MultisetUnchanged{L1,L2}(value_type* a, integer first, integer last) = 
      \forall value_type v;
        Count{L1}(a, first, last, v) == Count{L2}(a, first, last, v);

     
  predicate
    MultisetUnchanged{L1,L2}(value_type* a, integer n) = 
      MultisetUnchanged{L1,L2}(a, 0, n);
*/

#endif /* MULTISETUNCHANGED_H_INCLUDED */

