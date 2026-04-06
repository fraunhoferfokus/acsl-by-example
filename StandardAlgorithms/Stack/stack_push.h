
#ifndef STACK_PUSH_H_INCLUDED
#define STACK_PUSH_H_INCLUDED

#include "StackPush.acsl"

/*@
  requires  valid:      StackValid(s);
  terminates            \true;
  exits                 \false;
  assigns               s->sz, s->data[s->sz];
  ensures   valid:      StackValid(s);

  behavior  full:
    assumes             StackFull(s);
    assigns             \nothing;
    ensures unchanged:  StackEqual{Old,Here}(s,s);

  behavior  not_full:
    assumes             !StackFull(s);
    assigns             s->sz, s->data[s->sz];
    ensures push:       StackPush{Old,Here}(s, v, s);
    ensures not_empty:  !StackEmpty(s);

  complete behaviors;
  disjoint behaviors;
*/
void stack_push(Stack* s, value_type v);

#endif /* STACK_PUSH_H_INCLUDED */

