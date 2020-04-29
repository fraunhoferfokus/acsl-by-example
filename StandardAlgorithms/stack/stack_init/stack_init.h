
#ifndef STACK_INIT_H_INCLUDED
#define STACK_INIT_H_INCLUDED

#include "Stack.acsl"

/*@
  requires valid:     \valid(s);
  requires capacity:  0 < capacity;
  requires storage:   \valid(storage + (0..capacity-1));
  requires sep:       \separated(s, storage + (0..capacity-1));
  assigns             s->obj, s->capacity, s->size;
  ensures  valid:     \valid(s);
  ensures  capacity:  StackCapacity(s) == capacity;
  ensures  storage:   StackStorage(s) == storage;
  ensures  invariant: StackInvariant(s);
  ensures  empty:     StackEmpty(s);
*/
void
stack_init(Stack* s, value_type* storage, size_type capacity);

#endif /* STACK_INIT_H_INCLUDED */

