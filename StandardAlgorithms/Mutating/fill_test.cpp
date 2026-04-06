
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "fill.h"

int main(int, char**)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};

  auto b = a;
  value_type value = 9;
  std::fill(a.data(), a.data() + a.size(), value);
  fill(b.data(), b.size(), value);
  assert(a == b);

  return EXIT_SUCCESS;
}

