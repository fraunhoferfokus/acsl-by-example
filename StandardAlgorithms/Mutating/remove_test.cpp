
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "remove.h"
#include "test_data.hpp"

// remove returns the length of the prefix that survives; the elements beyond
// it are unspecified, so only that prefix may be compared.
void test_remove(std::vector<value_type> a, value_type v)
{
  std::vector<value_type> expected = a;

  const size_type kept = remove(a.data(), a.size(), v);
  const auto last = std::remove(expected.begin(), expected.end(), v);

  assert(kept == static_cast<size_type>(last - expected.begin()));
  assert(std::equal(expected.begin(), last, a.begin()));
  assert(std::find(a.begin(), a.begin() + kept, v) == a.begin() + kept);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_remove(a, present_value());
    test_remove(a, absent_value());       // nothing is removed

    for (size_type i = 0; i < a.size(); ++i) {
      test_remove(a, a[i]);
    }
  }

  test_remove({3, 3, 3}, 3);              // everything is removed

  return EXIT_SUCCESS;
}
