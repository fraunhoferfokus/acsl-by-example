
#include <cassert>
#include <cstdlib>

#include "stack_functions.h"

extern value_type axiom_top_of_push(Stack* s, value_type v);

// Contract: \result == v. The value just pushed is the one on top, whatever
// lies below it.
int main(int, char**)
{
  Stack s;
  value_type storage[4];
  stack_init(&s, storage, 4);

  assert(axiom_top_of_push(&s, 14) == 14);
  assert(axiom_top_of_push(&s, -3) == -3);
  assert(axiom_top_of_push(&s, 14) == 14);
  assert(stack_top(&s) == 14);
  assert(stack_size(&s) == 3);

  return EXIT_SUCCESS;
}
