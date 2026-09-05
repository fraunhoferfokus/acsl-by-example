
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <vector>

#include "test_data.hpp"

// partial_sum_inv.h holds no declaration -- the example is the .c file alone.
extern void partial_sum_inv(value_type* a, size_type n, value_type* b);

// partial_sum_inv runs partial_sum into b and adjacent_difference back into
// a. Its contract promises only that a comes out unchanged; the intermediate
// b must be the partial sums, which the earlier test never looked at.
void test_partial_sum_inv(std::vector<value_type> a)
{
  const std::vector<value_type> source = a;
  std::vector<value_type> b(a.size(), -12345);
  std::vector<value_type> expected(a.size());

  partial_sum_inv(a.data(), a.size(), b.data());
  std::partial_sum(source.begin(), source.end(), expected.begin());

  assert(a == source);
  assert(b == expected);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_partial_sum_inv(a);
  }

  {
    std::vector<value_type> a(10);
    std::iota(a.begin(), a.end(), 0);
    test_partial_sum_inv(a);
  }

  return EXIT_SUCCESS;
}
