
#include <iostream>
#include <cassert>
#include <stack>

#include "stack_size.h"
#include "stack_init.h"

int main(int, char**)
{
  std::stack<value_type> a;
  a.push(14);

  Stack b;
  value_type x[] = {13, 15};
  stack_init(&b, x, 2);

  b.sz = 1;

  assert(a.size() == 1);
  assert(stack_size(&b) == 1);

  return EXIT_SUCCESS;
}

