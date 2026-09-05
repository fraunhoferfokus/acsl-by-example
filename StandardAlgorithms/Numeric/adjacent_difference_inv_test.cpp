
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <vector>

#include "test_data.hpp"

// adjacent_difference_inv.h holds no declaration -- the example is the .c file alone.
extern void adjacent_difference_inv(value_type* a, size_type n, value_type* b);

// adjacent_difference_inv runs adjacent_difference into b and partial_sum
// back into a. Its contract promises only that a comes out unchanged; the
// intermediate b must be the adjacent differences.
void test_adjacent_difference_inv(std::vector<value_type> a)
{
  const std::vector<value_type> source = a;
  std::vector<value_type> b(a.size(), -12345);
  std::vector<value_type> expected(a.size());

  adjacent_difference_inv(a.data(), a.size(), b.data());
  std::adjacent_difference(source.begin(), source.end(), expected.begin());

  assert(a == source);
  assert(b == expected);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_adjacent_difference_inv(a);
  }

  {
    std::vector<value_type> a(20);
    std::iota(a.begin(), a.end(), 0);
    std::reverse(a.begin(), a.end());
    test_adjacent_difference_inv(a);
  }

  return EXIT_SUCCESS;
}
