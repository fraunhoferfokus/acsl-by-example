
#include "stack/stack.h"

/*@
  requires Valid(s);
  requires !Full(s);

  assigns s->size;
  assigns s->obj[s->size];

  ensures Valid(s);
  ensures \result == Size{Old}(s) + 1;
*/
size_type axiom_size_of_push(Stack* s, value_type v)
{
  stack_push(s, v);
  return stack_size(s);
}

