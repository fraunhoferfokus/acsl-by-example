
#include "StackLogic.spec"
#include "stack_push.h"
#include "stack_size.h"

/*@
  requires valid:    \valid(s) && Invariant(s);
  requires not_full: !Full(s);
  assigns            s->size, s->obj[s->size];
  ensures size:      \result == Size{Old}(s) + 1;
  ensures valid:     Invariant(s);
*/
size_type
axiom_size_of_push(Stack* s, value_type v)
{
  stack_push(s, v);
  return stack_size(s);
}

