
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "replace.h"
#include "test_data.hpp"

void test_replace(std::vector<value_type> a, value_type v, value_type w)
{
  std::vector<value_type> expected = a;

  replace(a.data(), a.size(), v, w);
  std::replace(expected.begin(), expected.end(), v, w);

  assert(a == expected);
  assert(std::count(a.begin(), a.end(), v) == 0 || v == w);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_replace(a, present_value(), 4);      // v occurs in some arrays
    test_replace(a, absent_value(), 4);       // v occurs in none
    test_replace(a, present_value(), present_value());   // v == w

    for (size_type i = 0; i < a.size(); ++i) {
      test_replace(a, a[i], absent_value());
    }
  }

  return EXIT_SUCCESS;
}
