
#include <iostream>
#include <cassert>
#include <stack>

#include "stack/stack.h"

int
main(int argc, char** argv)
{
  Stack b;
  value_type storage[6];
  stack_init(&b, storage, 6);
  assert(stack_full(&b) == 0);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

