
#include "stack_init.h"
#include "stack_capacity.h"

/*@
  requires   valid:    \valid(s);
  requires   valid:    \valid(a + (0..capacity-1));
  requires   sep:      \separated(s, a + (0..capacity-1));
  requires   pos:      0 < capacity;

  ensures    capacity: \result == capacity;
  ensures    valid:    StackValid(s);
*/
size_type axiom_capacity(Stack* s, value_type* a, size_type capacity)
{
  stack_init(s, a, capacity);
  return stack_capacity(s);
}

