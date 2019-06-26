
#ifndef UNCHANGEDSTEP_SPEC_INCLUDED
#define UNCHANGEDSTEP_SPEC_INCLUDED

#include "Unchanged.spec"

/*@
  lemma
    UnchangedStep{K,L}:
      \forall value_type *a, integer n;
        Unchanged{K,L}(a, n)        ==>
        \at(a[n],K) == \at(a[n],L)  ==>
        Unchanged{K,L}(a, n+1);
*/

#endif /* UNCHANGEDSTEP_SPEC_INCLUDED */

