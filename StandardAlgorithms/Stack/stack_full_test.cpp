
#include <cassert>
#include <cstdlib>

#include "stack_full.h"
#include "stack_test.hpp"

// StackFull holds exactly when the stack holds as many elements as it can.
// The earlier test only ever saw an empty stack, where it is false.
int main(int, char**)
{
  for (const size_type capacity : test_capacities()) {
    walk_stack(capacity, [](const Stack & s, size_type size, size_type cap) {
      assert(stack_full(&s) == (size == cap));
    });
  }

  return EXIT_SUCCESS;
}
