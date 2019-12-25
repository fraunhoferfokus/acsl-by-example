
#include "StackLogic.spec"
#include "stack_init.h"
#include "stack_size.h"

/*@
  requires valid:  \valid(s);
  requires valid:  \valid(a + (0..n-1));
  requires sep:    \separated(s, a + (0..n-1));
  requires pos:    0 < n;
  assigns          s->obj, s->capacity, s->size;
  ensures  size:   \result == 0;
  ensures  valid:  Invariant(s);
*/
size_type
axiom_size_of_init(Stack* s, value_type* a, size_type n)
{
  stack_init(s, a, n);
  return stack_size(s);
}

