
#ifndef STACK_POP_H_INCLUDED
#define STACK_POP_H_INCLUDED

#include "StackPop.acsl"

/*@
  requires  valid:      StackValid(s);
  terminates            \true;
  exits                 \false;
  assigns               s->sz;
  ensures   valid:      StackValid(s);

  behavior  empty:
    assumes             StackEmpty(s);
    assigns             \nothing;
    ensures empty:      StackEmpty(s);
    ensures unchanged:  StackEqual{Old,Here}(s,s);

  behavior  not_empty:
    assumes             !StackEmpty(s);
    assigns             s->sz;
    ensures pop:        StackPop{Old,Here}(s, s);
    ensures not_full:   !StackFull(s);

  complete behaviors;
  disjoint behaviors;
*/
void stack_pop(Stack* s);

#endif /* STACK_POP_H_INCLUDED */

