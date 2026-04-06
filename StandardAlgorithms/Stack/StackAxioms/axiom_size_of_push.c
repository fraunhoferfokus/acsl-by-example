
#include "stack_push.h"
#include "stack_size.h"

/*@
  requires   valid:    StackValid(s);
  requires   not_full: !StackFull(s);

  ensures    size:     \result == \old(StackSize(s)) + 1;
  ensures    valid:    StackValid(s);
*/
size_type axiom_size_of_push(Stack* s, value_type v)
{
  stack_push(s, v);
  return stack_size(s);
}

