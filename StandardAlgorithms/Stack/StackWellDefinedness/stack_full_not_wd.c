
#include "stack_full.h"

/*@
  requires   valid:  StackValid(s) && StackValid(t);
  requires   equal:  StackEqual{Here,Here}(s, t);
  requires   size:   StackSize(s) == StackCapacity(s);
  requires   cap:    StackCapacity(s) < StackCapacity(t);

  ensures    equal:  \result == false;
*/
bool stack_full_not_wd(const Stack* s, const Stack* t)
{
  //@ assert  StackFull(s);
  //@ assert !StackFull(t);
  return stack_full(s) == stack_full(t);
}

