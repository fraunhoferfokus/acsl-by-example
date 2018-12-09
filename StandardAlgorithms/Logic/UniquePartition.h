
#ifndef UNIQUEPARTITION_H_INCLUDED
#define UNIQUEPARTITION_H_INCLUDED

#include "UniqueSize.h"
#include "ConstantRange.h"

/*@
  axiomatic UniquePartitionAxiomatic
  {
    logic integer 
      UniquePartition(value_type* a, integer n, integer i) reads a[0..n-1];

    axiom UniquePartitionEmpty:
      \forall value_type *a, integer n, i;
        n <= 0  ==>  UniquePartition(a, n, i) == 0;

    axiom UniquePartitionLeft:
      \forall value_type *a, integer n, i;
        0 < n  ==>  i <= 0  ==>  UniquePartition(a, n, i) == 0;
   
    axiom UniquePartitionRight:
      \forall value_type *a, integer n, i;
        0 < n  ==>  UniqueSize(a, n) <= i  ==>  UniquePartition(a, n, i) == n;

    axiom UniquePartitionMonotone:
      \forall value_type *a, integer n, i, j;
        0 <= i < j <= UniqueSize(a, n)  ==>  
        UniquePartition(a, n, i) < UniquePartition(a, n, j);

    axiom UniquePartitionSegment:
      \forall value_type *a, integer n, i, k;
        0 <= i < UniqueSize(a, n) ==>  
        ConstantRange(a, UniquePartition(a, n, i), UniquePartition(a, n, i+1));

    axiom UniquePartitionMaximal:
      \forall value_type *a, integer n, i;
        0 <= i < UniqueSize(a, n) - 1  ==>  
        a[UniquePartition(a, n, i)] != a[UniquePartition(a, n, i+1)];

    axiom UniquePartitionEqual:
      \forall value_type *a, integer n, m, i;
        n < m  ==>  0 <= i < UniqueSize(a, n)  ==>
        UniquePartition(a, n, i) == UniquePartition(a, m, i);

    axiom UniquePartitionRead{K,L}:
      \forall value_type *a, integer n, i;
        Unchanged{K,L}(a, n) ==>
          UniquePartition{K}(a, n, i) == UniquePartition{L}(a, n, i);
  }
*/

#endif /* UNIQUEPARTITION_H_INCLUDED */

