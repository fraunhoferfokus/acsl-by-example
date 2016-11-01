
#ifndef STACK_POP_H_INCLUDED
#define STACK_POP_H_INCLUDED

#include "stack/stack.h"

/*@
  requires Valid(s);

  assigns s->size;

  ensures  Valid(s);

  behavior not_empty:
    assumes !Empty(s);

    assigns s->size;

    ensures Size(s) == Size{Old}(s) - 1;
    ensures !Full(s);
    ensures Unchanged{Pre,Here}(Storage(s), Size(s));
    ensures Storage(s) == Storage{Old}(s);
    ensures Capacity(s) == Capacity{Old}(s);

  behavior empty:
    assumes Empty(s);

    assigns \nothing;

    ensures Empty(s);
    ensures Unchanged{Pre,Here}(Storage(s), Size(s));
    ensures Size(s) == Size{Old}(s);
    ensures Storage(s) == Storage{Old}(s);
    ensures Capacity(s) == Capacity{Old}(s);

  complete behaviors;
  disjoint behaviors;
*/
void stack_pop(Stack* s);

#endif /* STACK_POP_H_INCLUDED */

