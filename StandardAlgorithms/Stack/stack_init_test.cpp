
#include <iostream>
#include <cassert>
#include <stack>

#include "stack_init.h"

int main(int, char**)
{
  Stack b;
  value_type storage[8];
  stack_init(&b, storage, 8);

  std::stack<value_type> a;

  assert(a.size() == 0);
  assert(b.sz     == 0);
  assert(b.cap    == 8);


  return EXIT_SUCCESS;
}

