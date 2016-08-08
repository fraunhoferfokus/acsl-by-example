
#include <iostream>
#include <cassert>
#include <stack>

#include "stack/stack.h"

int main(int argc, char** argv)
{
  std::stack<value_type> a;
  a.push(14);
  a.push(15);

  value_type y[] = {14, 15, -1};
  Stack b;
  {
    b.obj = y;
    b.capacity = 3;
    b.size = 2;
  }

  assert(a.top() == stack_top(&b));

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}
