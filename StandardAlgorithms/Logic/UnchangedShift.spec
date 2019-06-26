
#ifndef UNCHANGEDSHIFT_SPEC_INCLUDED
#define UNCHANGEDSHIFT_SPEC_INCLUDED

#include "Unchanged.spec"

/*@
  lemma
    UnchangedShift{K,L}:
      \forall value_type *a, integer p, q, r;
        Unchanged{K,L}(a+p, q, r) ==> Unchanged{K,L}(a, p+q, p+r);
*/

#endif /* UNCHANGEDSHIFT_SPEC_INCLUDED */

