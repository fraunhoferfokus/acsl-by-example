
#include "stack_push.h"
#include "stack_size.h"

/*@
  requires valid:    \valid(s) && StackInvariant(s);
  requires not_full: !StackFull(s);
  assigns            s->size, s->obj[s->size];
  ensures size:      \result == StackSize{Old}(s) + 1;
  ensures valid:     StackInvariant(s);
*/
size_type
axiom_size_of_push(Stack* s, value_type v)
{
  stack_push(s, v);
  return stack_size(s);
}

