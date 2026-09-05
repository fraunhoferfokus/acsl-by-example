
#include <cassert>
#include <cstdlib>

#include "stack_functions.h"

extern size_type axiom_capacity_of_pop(Stack* s);

// Contract: \result == StackCapacity{Old}(s). Popping empties the stack but
// never changes how much it can hold.
int main(int, char**)
{
  Stack s;
  value_type storage[4];
  stack_init(&s, storage, 4);

  for (value_type v = 1; v <= 4; ++v) {
    stack_push(&s, v);
  }

  while (!stack_empty(&s)) {
    assert(axiom_capacity_of_pop(&s) == 4);
  }

  return EXIT_SUCCESS;
}
