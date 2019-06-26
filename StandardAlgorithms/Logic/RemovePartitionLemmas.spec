
#ifndef REMOVEPARTITIONLEMMAS_SPEC_INCLUDED
#define REMOVEPARTITIONLEMMAS_SPEC_INCLUDED

#include "RemovePartition.spec"

/*@
  lemma RemovePartitionLowerBound:
    \forall value_type *a, v, integer p, n;
      0 < n ==>
      0 <= p < RemoveSize(a, n, v) ==>
      0 <= RemovePartition(a, n, v, p);

  lemma RemovePartitionUpperBound:
    \forall value_type *a, v, integer p, n;
      0 < n ==>
      0 <= p < RemoveSize(a, n, v) ==>
      RemovePartition(a, n, v, p) < n;
*/

#endif /* REMOVEPARTITIONLEMMAS_SPEC_INCLUDED */

