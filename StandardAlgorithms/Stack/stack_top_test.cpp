
#include <cassert>
#include <cstdlib>

#include "stack_top.h"
#include "stack_test.hpp"

// walk_stack pushes the value i at step i, so on a non-empty stack the top
// is the current size.
int main(int, char**)
{
  for (const size_type capacity : test_capacities()) {
    walk_stack(capacity, [](const Stack & s, size_type size, size_type) {
      if (0 < size) {
        assert(stack_top(&s) == static_cast<value_type>(size));
      }
    });
  }

  return EXIT_SUCCESS;
}
