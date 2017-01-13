
#ifndef STACK_PUSH_H_INCLUDED
#define STACK_PUSH_H_INCLUDED

#include "stack/stack.h"

/*@
  requires Valid(s);

  assigns s->size;
  assigns s->obj[s->size];

  behavior not_full:
    assumes !Full(s);

    assigns s->size;
    assigns s->obj[s->size];

    ensures Valid(s);
    ensures Size(s) == Size{Old}(s) + 1;
    ensures Top(s) == v;
    ensures !Empty(s);
    ensures Unchanged{Old,Here}(Storage(s), Size{Old}(s));
    ensures Storage(s) == Storage{Old}(s);
    ensures Capacity(s) == Capacity{Old}(s);

  behavior full:
    assumes Full(s);

    assigns \nothing;

    ensures Valid(s);
    ensures Full(s);
    ensures Unchanged{Old,Here}(Storage(s), Size(s));
    ensures Size(s) == Size{Old}(s);
    ensures Storage(s) == Storage{Old}(s);
    ensures Capacity(s) == Capacity{Old}(s);

  complete behaviors;
  disjoint behaviors;
*/
void stack_push(Stack* s, value_type v);

#endif /* STACK_PUSH_H_INCLUDED */

