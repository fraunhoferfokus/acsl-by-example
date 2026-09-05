
#include <cassert>
#include <cstdlib>

#include "stack_empty.h"
#include "stack_test.hpp"

// StackEmpty holds exactly when the stack has no elements -- on the way up
// and on the way down.
int main(int, char**)
{
  for (const size_type capacity : test_capacities()) {
    walk_stack(capacity, [](const Stack & s, size_type size, size_type) {
      assert(stack_empty(&s) == (size == 0));
    });
  }

  return EXIT_SUCCESS;
}
