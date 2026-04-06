
#include "random_number.h"
#include <cassert>
#include <iostream>

int main(int, char**)
{
  size_type n = 29;
  unsigned short rand[3];
  random_init(rand);

  size_type r = random_number(rand, n);
  assert(r < n);

  return EXIT_SUCCESS;
}

