
#include <cassert>
#include <cstdlib>

#include "stack_functions.h"

extern size_type axiom_size_of_pop(Stack* s);

// Contract: \result == StackSize{Old}(s) - 1.
int main(int, char**)
{
  Stack s;
  value_type storage[8];
  stack_init(&s, storage, 8);

  for (value_type v = 1; v <= 8; ++v) {
    stack_push(&s, v);
  }

  // From full down to empty, one pop at a time.
  while (!stack_empty(&s)) {
    const size_type before = stack_size(&s);
    assert(axiom_size_of_pop(&s) == before - 1);
    assert(stack_size(&s) == before - 1);
  }

  assert(stack_size(&s) == 0);

  return EXIT_SUCCESS;
}
