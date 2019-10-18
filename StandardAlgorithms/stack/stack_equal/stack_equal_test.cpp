
#include <iostream>
#include <cassert>

#include "stack_equal.h"
#include "stack_init.h"

int
main(int argc, char** argv)
{
  Stack a;
  value_type x[] = {14, 15, 3};
  stack_init(&a, x, 3);

  Stack b;
  value_type y[] = {14, 15, -1};
  stack_init(&b, y, 3);

  a.size = 2;
  b.size = 2;

  assert(stack_equal(&a, &b));
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

