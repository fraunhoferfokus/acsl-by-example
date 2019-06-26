
#ifndef UNCHANGEDTRANSITIVE_SPEC_INCLUDED
#define UNCHANGEDTRANSITIVE_SPEC_INCLUDED

#include "Unchanged.spec"

/*@
  lemma
    UnchangedTransitive{K,L,M}:
      \forall value_type *a, integer n;
        Unchanged{K,L}(a, n)  ==>
        Unchanged{L,M}(a, n)  ==>
        Unchanged{K,M}(a, n);
*/

#endif /* UNCHANGEDTRANSITIVE_SPEC_INCLUDED */

