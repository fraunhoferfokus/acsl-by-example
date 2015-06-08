
#ifndef UNCHANGED_H_INCLUDED
#define UNCHANGED_H_INCLUDED

#include "typedefs.h"

/*@
  predicate 
    Unchanged{A,B}(value_type* a, integer first, integer last) =
      \forall integer i; first <= i < last
         ==> \at(a[i], A) == \at(a[i], B);
*/

#endif /* UNCHANGED_H_INCLUDED */

