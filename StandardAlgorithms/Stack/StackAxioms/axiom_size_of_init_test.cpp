
#include <cassert>
#include <cstdlib>

#include "stack_functions.h"

// The axiom has no header of its own; the build compiles the C sources as
// C++, so a plain declaration matches.
extern size_type axiom_size_of_init(Stack* s, value_type* a, size_type capacity);

// Contract: \result == 0. An initialised stack is empty, whatever the
// storage held before.
int main(int, char**)
{
  Stack s;
  value_type storage[8] = {1, 2, 3, 4, 5, 6, 7, 8};

  assert(axiom_size_of_init(&s, storage, 8) == 0);
  assert(stack_size(&s) == 0);
  assert(stack_empty(&s));

  return EXIT_SUCCESS;
}
