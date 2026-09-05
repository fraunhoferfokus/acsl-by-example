
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <vector>

#include "partial_sum.h"
#include "test_data.hpp"

// The destination starts out filled with a value that occurs in no test
// array, so an implementation that writes nothing is caught.
const value_type sentinel = -12345;


void test_partial_sum(const std::vector<value_type>& a)
{
  const std::vector<value_type> source = a;
  std::vector<value_type> b(a.size(), sentinel);
  std::vector<value_type> expected(a.size(), sentinel);

  const size_type result = partial_sum(a.data(), a.size(), b.data());
  std::partial_sum(a.begin(), a.end(), expected.begin());

  assert(result == a.size());
  assert(b == expected);
  assert(a == source);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_partial_sum(a);
  }

  test_partial_sum({1, 3, -6, 0, 4});
  test_partial_sum({-1, -1, -1, -1});

  return EXIT_SUCCESS;
}
