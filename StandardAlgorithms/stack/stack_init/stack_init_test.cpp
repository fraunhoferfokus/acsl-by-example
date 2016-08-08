
#include <iostream>
#include <cassert>
#include <stack>

#include "stack/stack.h"

int main(int argc, char** argv)
{
  std::stack<value_type> a;

  static value_type storage[8];
  Stack b;
  stack_init(&b, storage, 8);

  assert(a.size() == 0);
  assert(b.size   == 0);
  assert(b.capacity  == 8);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

