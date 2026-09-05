
#include <cassert>
#include <cstdlib>

#include "stack_functions.h"

extern size_type axiom_capacity_of_push(Stack* s, value_type v);

// Contract: \result == \old(StackCapacity(s)). Pushing fills the stack but
// never changes how much it can hold.
int main(int, char**)
{
  Stack s;
  value_type storage[4];
  stack_init(&s, storage, 4);

  while (!stack_full(&s)) {
    assert(axiom_capacity_of_push(&s, 42) == 4);
  }

  assert(stack_size(&s) == 4);

  return EXIT_SUCCESS;
}
