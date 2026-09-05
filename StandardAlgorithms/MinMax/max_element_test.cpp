
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "max_element.h"
#include "test_data.hpp"

// The contract promises an index, not a value: every element is at most
// a[\result], and every earlier element is strictly smaller, which pins
// \result to the *first* maximum. Comparing values only, as this test did
// before, cannot tell the first maximum from any other.
void test_max_element(const std::vector<value_type>& a)
{
  const size_type pos = max_element(a.data(), a.size());

  if (a.empty()) {
    assert(pos == 0);
    return;
  }

  assert(pos < a.size());
  assert(pos == static_cast<size_type>(std::max_element(a.begin(), a.end()) - a.begin()));

  for (size_type i = 0; i < a.size(); ++i) {
    assert(a[i] <= a[pos]);

    if (i < pos) {
      assert(a[i] < a[pos]);
    }
  }
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_max_element(a);
  }

  // Repeated maxima: the first one must win.
  test_max_element({2, 9, 1, 9, 3});
  test_max_element({9, 9, 9});
  test_max_element({1, 2, 3, 9});
  test_max_element({9, 3, 2, 1});

  return EXIT_SUCCESS;
}
