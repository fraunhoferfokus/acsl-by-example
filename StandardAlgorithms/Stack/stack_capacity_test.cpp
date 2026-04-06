
#include <iostream>
#include <cassert>
#include <vector>

#include "stack_capacity.h"
#include "stack_init.h"

int main(int, char**)
{
  std::vector<value_type> a(1);
  Stack stack_a;
  stack_init(&stack_a, a.data(), a.size());
  assert(stack_capacity(&stack_a) == a.size());

  std::vector<value_type> b(10);
  Stack stack_b;
  stack_init(&stack_b, b.data(), b.size());
  assert(stack_capacity(&stack_b) == b.size());

  return EXIT_SUCCESS;
}

