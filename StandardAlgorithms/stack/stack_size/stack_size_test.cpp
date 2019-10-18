
#include <iostream>
#include <cassert>
#include <stack>

#include "stack_size.h"
#include "stack_init.h"

int
main(int argc, char** argv)
{
  std::stack<value_type> a;
  a.push(14);

  Stack b;
  value_type x[] = {13, 15};
  stack_init(&b, x, 2);

  b.size = 1;

  assert(a.size() == 1);
  assert(stack_size(&b) == 1);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

