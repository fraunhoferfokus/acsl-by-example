
#include <vector>
#include <numeric>
#include <iostream>
#include <cassert>

#include "partial_sum.h"

int main(int, char**)
{
  std::vector<value_type> a{1, 3, -6, 0, 4};
  std::vector<value_type> result1(a.size());
  std::vector<value_type> result2(a.size());

  partial_sum(a.data(), a.size(), result1.data());
  std::partial_sum(a.begin(), a.end(), result2.begin());
  assert(result1 == result2);

  return EXIT_SUCCESS;
}

