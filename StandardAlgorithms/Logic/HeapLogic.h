
#ifndef HEAPLOGIC_H_INCLUDED
#define HEAPLOGIC_H_INCLUDED

#include "typedefs.h"

/*@
  logic integer HeapLeft(integer i) = 2*i + 1;

  logic integer HeapRight(integer i) = 2*i + 2;

  logic integer HeapParent(integer i) = (i-1) / 2;

  lemma
    HeapParentOfLeft:
      \forall integer p; 0 <= p ==> HeapParent(HeapLeft(p)) == p;

  lemma
    HeapParentOfRight:
      \forall integer p; 0 <= p ==> HeapParent(HeapRight(p)) == p;

  lemma
    HeapParentChild:
      \forall integer c, p; 
        0 < c ==> HeapParent(c) == p ==>
        (c == HeapLeft(p) || c == HeapRight(p));

  lemma
    HeapChilds:
      \forall integer a, b; 
        0 < a ==> 0 < b ==>
        HeapParent(a) == HeapParent(b) ==>
        (a == b || a+1 == b || a == b+1);

  lemma
    HeapParentBounds:
      \forall integer c; 0 < c ==> 0 <= HeapParent(c) < c;

  lemma
    HeapChildBounds:
      \forall integer p; 
        0 <= p ==> p < HeapLeft(p) < HeapRight(p);
*/

#endif /* HEAPLOGIC_H_INCLUDED */

