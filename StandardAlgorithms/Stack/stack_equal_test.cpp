
#include <iostream>
#include <cassert>

#include "stack_equal.h"
#include "stack_init.h"

int main(int, char**)
{
  Stack a;
  value_type x[] = {14, 15, 3};
  stack_init(&a, x, 3);

  Stack b;
  value_type y[] = {14, 15, -1};
  stack_init(&b, y, 3);

  a.sz = 2;
  b.sz = 2;

  assert(stack_equal(&a, &b));

  return EXIT_SUCCESS;
}

