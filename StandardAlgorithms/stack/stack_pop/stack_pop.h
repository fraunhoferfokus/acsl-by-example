
#ifndef STACK_POP_H_INCLUDED
#define STACK_POP_H_INCLUDED

#include "stack/stack.h"

/*@
  requires valid: \valid(s) && Invariant(s);

  assigns s->size;

  ensures  valid: \valid(s) && Invariant(s);

  behavior not_empty:
    assumes !Empty(s);

    assigns s->size;

    ensures size:      Size(s) == Size{Old}(s) - 1;
    ensures full:      !Full(s);
    ensures unchanged: Unchanged{Old,Here}(Storage(s), Size(s));
    ensures storage:   Storage(s) == Storage{Old}(s);
    ensures capacity:  Capacity(s) == Capacity{Old}(s);

  behavior empty:
    assumes Empty(s);

    assigns \nothing;

    ensures empty:     Empty(s);
    ensures unchanged: Unchanged{Old,Here}(Storage(s), Size(s));
    ensures size:      Size(s) == Size{Old}(s);
    ensures storage:   Storage(s) == Storage{Old}(s);
    ensures capacity:  Capacity(s) == Capacity{Old}(s);

  complete behaviors;
  disjoint behaviors;
*/
void
stack_pop(Stack* s);

#endif /* STACK_POP_H_INCLUDED */

