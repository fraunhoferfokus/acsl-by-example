

#include <iostream>
#include <cassert>

#include "stack/stack.h"

int main(int argc, char** argv)
{
  value_type x[] = {14, 15, 3};
  Stack a;
  {
    a.obj = x;
    a.capacity = 3;
    a.size = 2;
  }

  value_type y[] = {14, 15, -1};
  Stack b;
  {
    b.obj = y;
    b.capacity = 3;
    b.size = 2;
  }

  assert(stack_equal(&a, &b));

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}
