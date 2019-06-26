
#include "stack/stack.h"

/*@
  requires valid:    \valid(s) && Invariant(s);
  requires not_full: !Full(s);

  assigns s->size;
  assigns s->obj[s->size];

  ensures top: \result == v;
*/
value_type
axiom_top_of_push(Stack* s, value_type v)
{
  stack_push(s, v);
  return stack_top(s);
}

