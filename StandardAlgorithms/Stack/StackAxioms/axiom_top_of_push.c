
#include "stack_push.h"
#include "stack_top.h"

/*@
  requires   valid:    StackValid(s);
  requires   not_full: !StackFull(s);

  ensures    top:      \result == v;
  ensures    valid:    StackValid(s);
*/
value_type axiom_top_of_push(Stack* s, value_type v)
{
  stack_push(s, v);
  return stack_top(s);
}

