
#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

#include "typedefs.h"

extern void partial_sum_inv(value_type* a, size_type n, value_type* b);

int main(int, char**)
{
  std::vector<value_type> a(10);
  std::vector<value_type> b(10);

  std::iota(a.begin(), a.end(), 0);
  auto save = a;

  partial_sum_inv(a.data(), a.size(), b.data());
  assert(a == save);

  return EXIT_SUCCESS;
}

