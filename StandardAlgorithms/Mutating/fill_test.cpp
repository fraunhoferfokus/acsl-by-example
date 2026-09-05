
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "fill.h"
#include "test_data.hpp"

void test_fill(std::vector<value_type> a, value_type v)
{
  std::vector<value_type> expected = a;

  fill(a.data(), a.size(), v);
  std::fill(expected.begin(), expected.end(), v);

  assert(a == expected);

  for (size_type i = 0; i < a.size(); ++i) {
    assert(a[i] == v);
  }
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_fill(a, absent_value());       // every element changes
    test_fill(a, present_value());      // some elements were already v
  }

  return EXIT_SUCCESS;
}
