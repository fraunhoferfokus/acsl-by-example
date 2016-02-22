
#ifndef HASVALUELEMMAS_H_INCLUDED
#define HASVALUELEMMAS_H_INCLUDED

#include "HasValue.h"

/*@
  lemma NotHasValueStep{L}:
    \forall value_type *a, v, integer n;
      \at(a[n],L) != v         ==>
      !HasValue{L}(a, n, v)    ==> 
      !HasValue{L}(a, n+1, v);
*/

#endif /* HASVALUELEMMAS_H_INCLUDED */

