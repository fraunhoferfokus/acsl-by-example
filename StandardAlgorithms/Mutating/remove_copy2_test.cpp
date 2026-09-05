
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "remove_copy2.h"
#include "test_data.hpp"

// The destination starts out filled with a value that occurs in no test
// array, so a copy that does nothing cannot pass.
const value_type sentinel = -12345;


void test_remove_copy2(const std::vector<value_type>& a, value_type v)
{
  const std::vector<value_type> source = a;
  std::vector<value_type> b(a.size(), sentinel);
  std::vector<value_type> expected(a.size(), sentinel);

  const size_type kept = remove_copy2(a.data(), a.size(), b.data(), v);
  const auto last = std::remove_copy(a.begin(), a.end(), expected.begin(), v);

  assert(kept == static_cast<size_type>(last - expected.begin()));
  assert(b == expected);
  assert(a == source);
  assert(std::find(b.begin(), b.begin() + kept, v) == b.begin() + kept);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_remove_copy2(a, present_value());
    test_remove_copy2(a, absent_value());        // nothing is removed

    for (size_type i = 0; i < a.size(); ++i) {
      test_remove_copy2(a, a[i]);
    }
  }

  test_remove_copy2({3, 3, 3}, 3);               // everything is removed

  return EXIT_SUCCESS;
}
