
#ifndef HEAP_AUX_H_INCLUDED
#define HEAP_AUX_H_INCLUDED

/*@
   requires bound:  0 < child;
   assigns          \nothing;
   ensures  parent: \result == HeapParent(child);
 */
static inline size_type heap_parent(size_type child)
{
  return (child - 1u) / 2u;
}


#endif /* HEAP_AUX_H_INCLUDE */

