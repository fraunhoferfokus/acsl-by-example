
#include <cassert>
#include <cstdlib>

#include "stack_functions.h"

extern size_type axiom_capacity_of_init(Stack* s, value_type* a, size_type capacity);

// Contract: \result == capacity, for whatever capacity the stack is given.
int main(int, char**)
{
  Stack s;
  value_type storage[8];

  assert(axiom_capacity_of_init(&s, storage, 8) == 8);
  assert(axiom_capacity_of_init(&s, storage, 1) == 1);
  assert(axiom_capacity_of_init(&s, storage, 5) == 5);

  return EXIT_SUCCESS;
}
