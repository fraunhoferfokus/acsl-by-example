

#ifndef REMOVEPARTITION_SPEC_INCLUDED
#define REMOVEPARTITION_SPEC_INCLUDED

#include "Unchanged.spec"
#include "RemoveSize.spec"

/*@
  axiomatic RemovePartitionAxiomatic
  {
    logic integer
      RemovePartition(value_type* a, integer m, integer n,
                      value_type  v, integer p) reads a[m..n-1];

    axiom RemovePartitionEmpty:
      \forall value_type *a, v, integer m, n, p;
        n <= m ==> RemovePartition(a, m, n, v, p) == m;

    axiom RemovePartitionLeft:
      \forall value_type *a, v, integer m, n, p;
        p < m < n ==> RemovePartition(a, m, n, v, p) == m;

    axiom RemovePartitionRight:
      \forall value_type *a, v, integer m, n, p;
        m < n ==> RemoveSize(a, m, n, v) <= p ==>
       	  RemovePartition(a, m, n, v, p) == n;

    axiom RemovePartitionMonotone:
      \forall value_type *a, v, integer m, n, p, q;
        m <= p < q <= RemoveSize(a, m, n, v) ==>
          m <= RemovePartition(a, m, n, v, p) < RemovePartition(a, m, n, v, q) < n;
    
    axiom RemovePartitionSegment:
      \forall value_type *a, v, integer i, m, n, p;
         m <= p < RemoveSize(a, m, n, v) ==>
           RemovePartition(a, m, n, v, p) < i < RemovePartition(a, m, n, v, p+1)
	   ==> a[i] == v;

    axiom RemovePartitionInitial:
      \forall value_type *a, v, integer i, m, n, p;
        m <= i < RemovePartition(a, m, n, v, m) ==> a[i] == v;

    axiom RemovePartitionNotValue:
      \forall value_type *a, v, integer m, n, p;
        m <= p < RemoveSize(a, m, n, v) ==>
          a[RemovePartition(a, m, n, v, p)] != v;

    axiom RemovePartitionEqual:
      \forall value_type *a, v, integer m, n1, n2, p;
        m <= n1 < n2 ==>
	  m <= p < RemoveSize(a, n1, v) ==>
	    RemovePartition(a, m, n1, v, p) == RemovePartition(a, m, n2, v, p);

    axiom RemovePartitionRead{K,L}:
      \forall value_type *a, v, integer m, n, p;
        Unchanged{K,L}(a, m, n) ==>
          RemovePartition{K}(a, m, n, v, p) == RemovePartition{L}(a, m, n, v, p);
  }	  

  logic integer
    RemovePartition(value_type* a, integer n, value_type  v, integer p) 
      = RemovePartition(a, 0, n, v, p);
*/

#endif /* REMOVEPARTITION_H_INCLUDED */

