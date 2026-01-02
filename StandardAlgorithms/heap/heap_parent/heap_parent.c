
#include "heap_parent.h"

size_type
heap_parent(size_type child)
{
  return (0u < child) ?  (child - 1u) / 2u : 0u;
}

