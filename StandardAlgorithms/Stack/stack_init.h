
#ifndef STACK_INIT_H_INCLUDED
#define STACK_INIT_H_INCLUDED

#include "StackObservers.acsl"

/*@
  requires   valid:      \valid(s);
  requires   capacity:   0 < cap;
  requires   storage:    \valid(data + (0..cap-1));
  requires   sep:        \separated(s, data + (0..cap-1));

  terminates             \true;
  exits                  \false;
  assigns                s->data \from data;
  assigns                s->cap  \from cap;
  assigns                s->sz   \from \nothing;

  ensures    valid:      StackValid(s);
  ensures    storage:    StackData(s)     == data;
  ensures    capacity:   StackCapacity(s) == cap;
  ensures    empty:      StackSize(s)     == 0;
*/
void stack_init(Stack* s, value_type* data, size_type cap);

#endif /* STACK_INIT_H_INCLUDED */

