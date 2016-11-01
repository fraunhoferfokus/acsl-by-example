
#ifndef HEAPLOGIC_INCLUDED
#define HEAPLOGIC_INCLUDED

#include "typedefs.h"

/*@
  logic integer HeapLeft(integer i) = 2*i + 1;

  logic integer HeapRight(integer i) = 2*i + 2;

  logic integer HeapParent(integer i) = (i - 1) / 2;


  lemma HeapParentOfLeft:
    \forall integer i; 0 <= i ==> HeapParent(HeapLeft(i)) == i;

  lemma HeapParentOfRight:
    \forall integer i; 0 <= i ==> HeapParent(HeapRight(i)) == i;

  lemma HeapBounds:
    \forall integer a; 0 <= a  ==>  0 <= a/2 <= a;
*/

#endif /* HEAPLOGIC_H_INCLUDED */

