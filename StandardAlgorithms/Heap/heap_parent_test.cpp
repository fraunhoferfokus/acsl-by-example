
#include <cassert>
#include <cstdlib>

#include "heap_parent.h"

// The contract of heap_parent promises \result == HeapParent(child), which
// Logic/HeapNodes.acsl defines as (child - 1) / 2, with HeapParent(0) == 0.

int main(int, char**)
{
  assert(heap_parent(0) == 0);

  for (size_type child = 1; child <= 1000; ++child) {
    assert(heap_parent(child) == (child - 1) / 2);
    // The parent of a node precedes it, so a sift-up terminates.
    assert(heap_parent(child) < child);
  }

  // Both children of p report p as their parent.
  for (size_type p = 0; p < 500; ++p) {
    const size_type left  = 2 * p + 1;
    const size_type right = left + 1;
    assert(heap_parent(left)  == p);
    assert(heap_parent(right) == p);
  }

  return EXIT_SUCCESS;
}
