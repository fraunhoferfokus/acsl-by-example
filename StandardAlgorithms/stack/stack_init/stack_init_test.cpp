
#include <iostream>
#include <cassert>
#include <stack>

#include "stack_init.h"

int
main(int argc, char** argv)
{
  Stack b;
  value_type storage[8];
  stack_init(&b, storage, 8);

  std::stack<value_type> a;

  assert(a.size() == 0);
  assert(b.size   == 0);
  assert(b.capacity  == 8);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

