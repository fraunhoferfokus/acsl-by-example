
#ifndef IS_HEAP_UNTIL_H_INCLUDED
#define IS_HEAP_UNTIL_H_INCLUDED

#include "Heap.acsl"

/*@
   requires   valid:  \valid_read(a + (0..n-1));

   terminates         \true;
   exits              \false;
   assigns            \nothing;

   ensures    bound:  0 <= \result <= n;
   ensures    heap:   Heap(a, \result);
   ensures    last:   \result < n  ==>  !Heap(a, \result + 1);
*/
size_type is_heap_until(const value_type* a, size_type n);

#endif /* IS_HEAP_UNTIL_H_INCLUDED */

