
#ifndef UNIQUEPARTITIONLEMMAS_SPEC_INCLUDED
#define UNIQUEPARTITIONLEMMAS_SPEC_INCLUDED

#include "UniquePartition.spec"
#include "UnchangedSection.spec"

/*@
  lemma UniquePartitionZero:
     \forall value_type *a, integer n;
       UniquePartition(a, n, 0) == 0;

  lemma UniquePartitionLowerBound:
     \forall value_type *a, integer n, i;
       0 < n ==> 0 <= i < UniqueSize(a, n) ==> 0 <= UniquePartition(a, n, i);

  lemma UniquePartitionUpperBound:
     \forall value_type *a, integer n, i;
       0 < n ==> 0 <= i < UniqueSize(a, n) ==> UniquePartition(a, n, i) < n;

  lemma UniquePartitionDiffer:
    \forall value_type *a, integer i, k, n;
      UniquePartition(a, n, k-1) < i <= UniquePartition(a, n, k) ==>
      a[i-1] != a[i]  ==>  i == UniquePartition(a, n, k);
*/

#endif /* UNIQUEPARTITIONLEMMAS_SPEC_INCLUDED */

