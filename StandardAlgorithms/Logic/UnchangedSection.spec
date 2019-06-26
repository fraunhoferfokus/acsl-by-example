
#ifndef UNCHANGEDSECTION_SPEC_INCLUDED
#define UNCHANGEDSECTION_SPEC_INCLUDED

#include "Unchanged.spec"

/*@
  lemma
    UnchangedSection{K,L}:
      \forall value_type *a, integer m, n, p, q;
         m <= p <= q <= n         ==>
         Unchanged{K,L}(a, m, n)  ==>
         Unchanged{K,L}(a, p, q);
*/

#endif /* UNCHANGEDSECTION_SPEC_INCLUDED */

