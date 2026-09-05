
#include <cassert>
#include <cstdlib>
#include <numeric>
#include <vector>

#include "adjacent_difference.h"
#include "test_data.hpp"

// The destination starts out filled with a value that occurs in no test
// array, so an implementation that writes nothing is caught.
const value_type sentinel = -12345;


void test_adjacent_difference(const std::vector<value_type>& a)
{
  const std::vector<value_type> source = a;
  std::vector<value_type> b(a.size(), sentinel);
  std::vector<value_type> expected(a.size(), sentinel);

  const size_type result = adjacent_difference(a.data(), a.size(), b.data());
  std::adjacent_difference(a.begin(), a.end(), expected.begin());

  assert(result == a.size());
  assert(b == expected);
  assert(a == source);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_adjacent_difference(a);
  }

  test_adjacent_difference({1, 3, -6, 0, 4});
  test_adjacent_difference({5, 5, 5, 5});      // all differences vanish

  return EXIT_SUCCESS;
}
