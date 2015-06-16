
#include <stack>
#include <iostream>
#include <cassert>

#include "stack/stack.h"

int main(int argc, char** argv)
{
  std::stack<value_type> a;

  value_type storage[8];
  Stack b;
  stack_init(&b, storage, 8);

  assert(a.empty() == 1);
  assert(stack_empty(&b) == 1);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
