
#ifndef HEAP_PARENT_H_INCLUDED
#define HEAP_PARENT_H_INCLUDED

#include "HeapNodes.acsl"

/*@
   terminates          \true;
   exits               \false;
   assigns             \nothing;

   ensures    parent:  \result == HeapParent(child);
 */
size_type
heap_parent(size_type child);

#endif /* HEAP_PARENT_H_INCLUDED */

