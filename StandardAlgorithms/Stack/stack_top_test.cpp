
#include <iostream>
#include <cassert>
#include <stack>

#include "stack_top.h"
#include "stack_init.h"

int main(int, char**)
{
  std::stack<value_type> a;
  a.push(14);
  a.push(15);

  Stack b;
  value_type y[] = {14, 15, -1};
  stack_init(&b, y, 3);

  b.sz = 2;

  assert(a.top() == stack_top(&b));

  return EXIT_SUCCESS;
}

