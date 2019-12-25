

#ifndef REMOVEPARTITION_SPEC_INCLUDED
#define REMOVEPARTITION_SPEC_INCLUDED

#include "RemoveSize.spec"
#include "UnchangedSection.spec"

/*@
  axiomatic RemovePartitionAxiomatic
  {
    logic integer
      RemovePartition(value_type* a,  integer n,
                      value_type  v, integer p) reads a[0..n-1];

    axiom RemovePartitionEmpty:
      \forall value_type *a, v, integer n, p;
        n <= 0 ==> RemovePartition(a, n, v, p) == 0;

    axiom RemovePartitionLeft:
      \forall value_type *a, v, integer n, p;
        p < 0 < n ==> RemovePartition(a, n, v, p) == 0;

    axiom RemovePartitionRight:
      \forall value_type *a, v, integer n, p;
        0 < n ==> RemoveSize(a, n, v) <= p ==> RemovePartition(a, n, v, p) == n;

    axiom RemovePartitionMonotone:
      \forall value_type *a, v, integer n, p, q;
        0 <= p < q <= RemoveSize(a, n, v) ==>
          0 <= RemovePartition(a, n, v, p) < RemovePartition(a, n, v, q) < n;
    
    axiom RemovePartitionSegment:
      \forall value_type *a, v, integer i, n, p;
         0 <= p < RemoveSize(a, n, v) ==>
           RemovePartition(a, n, v, p) < i < RemovePartition(a, n, v, p+1)
           ==> a[i] == v;

    axiom RemovePartitionInitial:
      \forall value_type *a, v, integer i, m, n, p;
        0 <= i < RemovePartition(a, n, v, m) ==> a[i] == v;

    axiom RemovePartitionNotValue:
      \forall value_type *a, v, integer n, p;
        0 <= p < RemoveSize(a, n, v) ==> a[RemovePartition(a, n, v, p)] != v;

    axiom RemovePartitionEqual:
      \forall value_type *a, v, integer n1, n2, p;
        0 <= n1 < n2  ==>  0 <= p  < RemoveSize(a, n1, v)  ==>
        RemovePartition(a, n1, v, p) == RemovePartition(a, n2, v, p);

    axiom RemovePartitionRead{K,L}:
      \forall value_type *a, v, integer n, p;
        Unchanged{K,L}(a, n) ==>
          RemovePartition{K}(a, n, v, p) == RemovePartition{L}(a, n, v, p);
  }  
*/

#endif /* REMOVEPARTITION_H_INCLUDED */

