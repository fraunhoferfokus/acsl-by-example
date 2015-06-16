
#include <iostream>
#include <cassert>
#include <stack>

#include "stack/stack.h"

int main(int argc, char** argv)
{
  std::stack<value_type> a;
  a.push(14);

  value_type x[] = {13, 15};
  Stack b;
  {
    b.obj = x;
    b.capacity = 2;
    b.size = 1;
  }

  assert(a.size() == 1);
  assert(stack_size(&b) == 1);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}

