
#include "stack/stack.h"

/*@
  requires \valid(s);
  requires 0 < n;
  requires \valid(a + (0..n-1));
  requires \separated(s, a + (0..n-1));

  assigns s->obj, s->capacity, s->size;

  ensures Valid(s);
  ensures \result == 0;
*/
size_type axiom_size_of_init(Stack* s, value_type* a, size_type n)
{
  stack_init(s, a, n);
  return stack_size(s);
}

