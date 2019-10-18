
#ifndef IS_HEAP_UNTIL_H_INCLUDED
#define IS_HEAP_UNTIL_H_INCLUDED

#include "IsHeap.spec"

/*@
   requires valid: \valid_read(a + (0..n-1));

   assigns \nothing;

   ensures bound: 0 <= \result <= n;
   ensures heap:  IsHeap(a, \result);
   ensures last:  \forall integer i; \result < i <= n ==> !IsHeap(a, i);
*/
size_type
is_heap_until(const value_type* a, size_type n);

#endif /* IS_HEAP_UNTIL_H_INCLUDED */

