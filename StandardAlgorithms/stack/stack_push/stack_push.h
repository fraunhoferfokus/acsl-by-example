
#ifndef STACK_PUSH_H_INCLUDED
#define STACK_PUSH_H_INCLUDED

#include "Stack.acsl"

/*@
  requires valid:      \valid(s) && StackInvariant(s);
  assigns              s->size, s->obj[s->size];

  behavior full:
    assumes            StackFull(s);
    assigns            \nothing;
    ensures valid:     \valid(s) && StackInvariant(s);
    ensures full:      StackFull(s);
    ensures unchanged: StackUnchanged{Old,Here}(s);

  behavior not_full:
    assumes            !StackFull(s);
    assigns            s->size;
    assigns            s->obj[s->size];
    ensures valid:     \valid(s) && StackInvariant(s);
    ensures size:      StackSize(s) == StackSize{Old}(s) + 1;
    ensures top:       StackTop(s) == v;
    ensures storage:   StackStorage(s) == StackStorage{Old}(s);
    ensures capacity:  StackCapacity(s) == StackCapacity{Old}(s);
    ensures not_empty: !StackEmpty(s);
    ensures unchanged: Unchanged{Old,Here}(StackStorage(s), StackSize{Old}(s));

  complete behaviors;
  disjoint behaviors;
*/
void
stack_push(Stack* s, value_type v);

#endif /* STACK_PUSH_H_INCLUDED */

