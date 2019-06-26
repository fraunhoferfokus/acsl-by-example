
#ifndef HEAPMAXIMUM_SPEC_INCLUDED
#define HEAPMAXIMUM_SPEC_INCLUDED

#include "MaxElement.spec"
#include "IsHeap.spec"
#include "C_Division.spec"

/*@
  lemma
    HeapMaximum{L} :
      \forall value_type* a, integer n;
        1 <= n ==> IsHeap(a, n) ==> MaxElement(a, n, 0);
*/

#endif /* HEAPMAXIMUM_SPEC_INCLUDED */

