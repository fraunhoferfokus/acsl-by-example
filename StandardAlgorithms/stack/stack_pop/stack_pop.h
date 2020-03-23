
#ifndef STACK_POP_H_INCLUDED
#define STACK_POP_H_INCLUDED

#include "Stack.spec"

/*@
  requires valid: \valid(s) && StackInvariant(s);
  assigns         s->size;
  ensures  valid: \valid(s) && StackInvariant(s);

  behavior empty:
    assumes            StackEmpty(s);
    assigns            \nothing;
    ensures empty:     StackEmpty(s);
    ensures unchanged: StackUnchanged{Old,Here}(s);

  behavior not_empty:
    assumes            !StackEmpty(s);
    assigns            s->size;
    ensures size:      StackSize(s) == StackSize{Old}(s) - 1;
    ensures full:      !StackFull(s);
    ensures storage:   StackStorage(s) == StackStorage{Old}(s);
    ensures capacity:  StackCapacity(s) == StackCapacity{Old}(s);
    ensures unchanged: Unchanged{Old,Here}(StackStorage(s), StackSize(s));

  complete behaviors;
  disjoint behaviors;
*/
void
stack_pop(Stack* s);

#endif /* STACK_POP_H_INCLUDED */

