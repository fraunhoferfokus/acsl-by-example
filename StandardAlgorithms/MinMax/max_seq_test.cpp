
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "max_seq.h"
#include "test_data.hpp"

// max_seq returns the maximum value itself, so comparing values is right
// here; the contract requires a non-empty array.
void test_max_seq(const std::vector<value_type>& a)
{
  assert(!a.empty());

  const value_type max = max_seq(a.data(), a.size());

  assert(max == *std::max_element(a.begin(), a.end()));

  for (size_type i = 0; i < a.size(); ++i) {
    assert(a[i] <= max);
  }

  assert(std::find(a.begin(), a.end(), max) != a.end());
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    if (!a.empty()) {
      test_max_seq(a);
    }
  }

  test_max_seq({2, 9, 1, 9, 3});
  test_max_seq({9, 9, 9});
  test_max_seq({-5, -1, -3});

  return EXIT_SUCCESS;
}
