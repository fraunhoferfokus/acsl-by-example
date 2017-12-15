
#include "MaxElement.h"
#include "MinElement.h"
#include "Partition.h"

/*@
  lemma MaxLeMinImpliesPartition:
    \forall value_type* a, integer m, n, maxL, minR;
      0 <= m <= n                ==>
      MaxElement(a+0, m-0, maxL) ==>
      MinElement(a+m, n-m, minR) ==>
      maxL <= minR               ==>
      Partition(a, m, n);
*/

/*@
  lemma PartitionImpliesMaxLeMin:
    \forall value_type* a, integer m, n, maxL, minR;
      0 <= m <= n                ==>
      Partition(a, m, n)         ==>
      MaxElement(a+0, m-0, maxL) ==>
      MinElement(a+m, n-m, minR) ==>
      maxL <= minR;
*/

#include "MultisetUnchanged.h"

/*@
  lemma ReorderPreservesMax{L,M}:
    \forall value_type* a, integer n, max;
      MultisetUnchanged{L,M}(a, n) ==>
      MaxElement{L}(a, n, max) ==>
      MaxElement{M}(a, n, max);
*/

/*@
  lemma ReorderPreservesMin{L,M}:
    \forall value_type* a, integer n, min;
      MultisetUnchanged{L,M}(a, n) ==>
      MinElement{L}(a, n, min) ==>
      MinElement{M}(a, n, min);
*/

/*@
  lemma ReorderPerservesMaxLeMin{L,M}:
    \forall value_type* a, integer m, n, maxLL, minRL, maxLM, minRM;
      0 <= m <= n ==>
      MaxElement{L}(a+0, m-0, maxLL) ==>
      MinElement{L}(a+m, n-m, minRL) ==>
      MaxElement{M}(a+0, m-0, maxLM) ==>
      MinElement{M}(a+m, n-m, minRM) ==>
      MultisetUnchanged{L,M}(a+0, m-0) ==>
      MultisetUnchanged{L,M}(a+m, n-m) ==>
      maxLL == maxLM && minRL == minRM;
*/

#include "ReorderPreservesPartition.h"


