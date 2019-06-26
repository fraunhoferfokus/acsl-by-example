
#ifndef STACK_INIT_H_INCLUDED
#define STACK_INIT_H_INCLUDED

#include "stack/stack.h"

/*@
  requires valid:    \valid(s);
  requires capacity: 0 < capacity;
  requires storage:  \valid(storage + (0..capacity-1));
  requires sep:      \separated(s, storage + (0..capacity-1));

  assigns s->obj, s->capacity, s->size;

  ensures valid:     \valid(s);
  ensures invariant: Invariant(s);
  ensures capacity:  Capacity(s) == capacity;
  ensures empty:     Empty(s);
  ensures storage:   Storage(s) == storage;
*/
void
stack_init(Stack* s, value_type* storage, size_type capacity);

#endif /* STACK_INIT_H_INCLUDED */

