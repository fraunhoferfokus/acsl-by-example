
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "mismatch.h"
#include "test_data.hpp"

// mismatch returns the first index at which the two arrays differ, or their
// common length if they are equal.
void test_mismatch(const std::vector<value_type>& a, const std::vector<value_type>& b)
{
  assert(a.size() == b.size());

  const auto pair = std::mismatch(a.begin(), a.end(), b.begin());
  const size_type expected = static_cast<size_type>(pair.first - a.begin());

  assert(mismatch(a.data(), a.size(), b.data()) == expected);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_mismatch(a, a);

    // A difference in any one position, and in every pair of positions, so
    // that the *first* one is the one reported.
    for (size_type i = 0; i < a.size(); ++i) {
      std::vector<value_type> b = a;
      b[i] = absent_value();
      test_mismatch(a, b);

      for (size_type j = i + 1; j < a.size(); ++j) {
        std::vector<value_type> c = b;
        c[j] = absent_value();
        test_mismatch(a, c);
      }
    }
  }

  return EXIT_SUCCESS;
}
