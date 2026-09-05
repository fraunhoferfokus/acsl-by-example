
#include <cassert>
#include <cstdlib>

#include "stack_size.h"
#include "stack_test.hpp"

int main(int, char**)
{
  for (const size_type capacity : test_capacities()) {
    walk_stack(capacity, [](const Stack & s, size_type size, size_type) {
      assert(stack_size(&s) == size);
    });
  }

  return EXIT_SUCCESS;
}
