
#ifndef HEAP_PARENT_H_INCLUDED
#define HEAP_PARENT_H_INCLUDED

#include "HeapNodes.acsl"

/*@
   assigns           \nothing;
   ensures  parent:  \result == HeapParent(child);
 */
static inline size_type
heap_parent(size_type child)
{
  return (0u < child) ?  (child - 1u) / 2u : 0u;
}

#endif /* HEAP_PARENT_H_INCLUDED */

