
#include <stack>
#include <iostream>
#include <cassert>

#include "stack_init.h"
#include "stack_empty.h"

int main(int, char**)
{
  std::stack<value_type> a;
  value_type storage[8];

  Stack b;
  stack_init(&b, storage, 8);

  assert(a.empty() == 1);
  assert(stack_empty(&b) == 1);

  return EXIT_SUCCESS;
}
