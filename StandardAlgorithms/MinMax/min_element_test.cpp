
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "min_element.h"
#include "test_data.hpp"

// The contract promises the first minimum: every element is at least
// a[\result], and every earlier element is strictly greater.
void test_min_element(const std::vector<value_type>& a)
{
  const size_type pos = min_element(a.data(), a.size());

  if (a.empty()) {
    assert(pos == 0);
    return;
  }

  assert(pos < a.size());
  assert(pos == static_cast<size_type>(std::min_element(a.begin(), a.end()) - a.begin()));

  for (size_type i = 0; i < a.size(); ++i) {
    assert(a[pos] <= a[i]);

    if (i < pos) {
      assert(a[pos] < a[i]);
    }
  }
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_min_element(a);

    // Every suffix of every test array is a test array of its own.
    for (size_type i = 0; i < a.size(); ++i) {
      test_min_element(std::vector<value_type>(a.begin() + i, a.end()));
    }
  }

  // Repeated minima: the first one must win.
  test_min_element({2, 1, 8, 1, 5});
  test_min_element({1, 1, 1});

  return EXIT_SUCCESS;
}
