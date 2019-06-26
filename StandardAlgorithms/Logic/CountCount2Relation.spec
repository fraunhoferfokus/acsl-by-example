
#ifndef COUNTCOUNT2RELATION_SPEC_INCLUDED
#define COUNTCOUNT2RELATION_SPEC_INCLUDED

#include "Count.spec"
#include "Count2.spec"

/*@
  lemma
    CountCount2Relation{L}:
      \forall value_type *a, v, integer n;
        Count2(a, n, v, Count(a, n, v));
*/

#endif /* COUNTCOUNT2RELATION_SPEC_INCLUDED */

