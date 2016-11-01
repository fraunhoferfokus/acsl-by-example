
#ifndef STACK_INIT_H_INCLUDED
#define STACK_INIT_H_INCLUDED

#include "stack/stack.h"

/*@
  requires \valid(s);
  requires 0 < capacity;
  requires \valid(storage + (0..capacity-1));
  requires \separated(s, storage + (0..capacity-1));

  assigns s->obj;
  assigns s->capacity;
  assigns s->size;

  ensures Valid(s);
  ensures Capacity(s) == capacity;
  ensures Size(s) == 0;
  ensures Empty(s);
  ensures Storage(s) == storage;
*/
void stack_init(Stack* s, value_type* storage, size_type capacity);

#endif /* STACK_INIT_H_INCLUDED */

