
#ifndef UNCHANGEDSTEP_H_INCLUDED
#define UNCHANGEDSTEP_H_INCLUDED

#include "Unchanged.h"

/*@
  lemma
    UnchangedStep{K,L}:
      \forall value_type *a, integer n;
        Unchanged{K,L}(a, n)        ==>
        \at(a[n],K) == \at(a[n],L)  ==>
        Unchanged{K,L}(a, n+1);
*/

#endif /* UNCHANGEDSTEP_H_INCLUDED */

