
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "equal.h"
#include "test_data.hpp"

void test_equal(const std::vector<value_type>& a, const std::vector<value_type>& b)
{
  assert(a.size() == b.size());

  const bool expected = std::equal(a.begin(), a.end(), b.begin());

  assert(equal(a.data(), a.size(), b.data()) == expected);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    // Equal to itself, and to a separate copy.
    test_equal(a, a);
    test_equal(a, std::vector<value_type>(a));

    // A difference in any one position must be found, including the first
    // and the last.
    for (size_type i = 0; i < a.size(); ++i) {
      std::vector<value_type> b = a;
      b[i] = absent_value();
      test_equal(a, b);
      test_equal(b, a);
    }
  }

  return EXIT_SUCCESS;
}
