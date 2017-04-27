
#include "stack/stack.h"

/*@
  requires valid:     \valid(s);
  requires size:      0 < n;
  requires valid:     \valid(a + (0..n-1));
  requires separated: \separated(s, a + (0..n-1));

  assigns s->obj, s->capacity, s->size;

  ensures valid: Invariant(s);
  ensures size:  \result == 0;
*/
size_type axiom_size_of_init(Stack* s, value_type* a, size_type n)
{
  stack_init(s, a, n);
  return stack_size(s);
}

