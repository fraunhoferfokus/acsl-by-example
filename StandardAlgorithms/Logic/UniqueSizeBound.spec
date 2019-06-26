
#ifndef UNIQUESIZEBOUND_SPEC_INCLUDED
#define UNIQUESIZEBOUND_SPEC_INCLUDED

#include "UniqueSize.spec"

/*@
  lemma UniqueSizeBound:
    \forall value_type *a, integer n;
      0 <= n  ==>  0 <= UniqueSize(a, n) <= n;
*/

#endif /* UNIQUESIZEBOUND_SPEC_INCLUDED */

