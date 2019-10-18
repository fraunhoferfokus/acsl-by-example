
#ifndef STACK_PUSH_H_INCLUDED
#define STACK_PUSH_H_INCLUDED

#include "StackLogic.spec"

/*@
  requires valid: \valid(s) && Invariant(s);

  assigns s->size;
  assigns s->obj[s->size];

  behavior not_full:
    assumes !Full(s);

    assigns s->size;
    assigns s->obj[s->size];

    ensures valid:     \valid(s) && Invariant(s);
    ensures size:      Size(s) == Size{Old}(s) + 1;
    ensures top:       Top(s) == v;
    ensures not_empty: !Empty(s);
    ensures unchanged: Unchanged{Old,Here}(Storage(s), Size{Old}(s));
    ensures storage:   Storage(s) == Storage{Old}(s);
    ensures capacity:  Capacity(s) == Capacity{Old}(s);

  behavior full:
    assumes Full(s);

    assigns \nothing;

    ensures valid:     \valid(s) && Invariant(s);
    ensures full:      Full(s);
    ensures unchanged: Unchanged{Old,Here}(Storage(s), Size(s));
    ensures size:      Size(s) == Size{Old}(s);
    ensures storage:   Storage(s) == Storage{Old}(s);
    ensures capacity:  Capacity(s) == Capacity{Old}(s);

  complete behaviors;
  disjoint behaviors;
*/
void
stack_push(Stack* s, value_type v);

#endif /* STACK_PUSH_H_INCLUDED */

