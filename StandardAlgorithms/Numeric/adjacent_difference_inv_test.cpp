
#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <vector>

#include "typedefs.h"

extern void adjacent_difference_inv(value_type* a, size_type n, value_type* b);

int main(int, char**)
{
  std::vector<value_type> a(20);
  std::vector<value_type> b(20);

  std::iota(a.begin(), a.end(), 0);
  std::reverse(a.begin(), a.end());
  auto save = a;

  adjacent_difference_inv(a.data(), a.size(), b.data());
  assert(a == save);

  return EXIT_SUCCESS;
}

