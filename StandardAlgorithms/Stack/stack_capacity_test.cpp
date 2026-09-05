
#include <cassert>
#include <cstdlib>

#include "stack_capacity.h"
#include "stack_test.hpp"

// Pushing and popping never change how much a stack can hold.
int main(int, char**)
{
  for (const size_type capacity : test_capacities()) {
    walk_stack(capacity, [](const Stack & s, size_type, size_type cap) {
      assert(stack_capacity(&s) == cap);
    });
  }

  return EXIT_SUCCESS;
}
