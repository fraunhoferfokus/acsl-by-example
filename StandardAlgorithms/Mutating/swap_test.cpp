
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "swap.h"

int main(int, char**)
{
  std::vector<value_type> a{1, 2};
  auto b = a;
  assert(a == b);

  std::iter_swap(a.data(), a.data() + 1);
  swap(b.data(), b.data() + 1);
  assert(a == b);

  return EXIT_SUCCESS;
}

