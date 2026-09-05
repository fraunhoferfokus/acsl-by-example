
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "minmax_element.h"
#include "test_data.hpp"

// The contract asks for the *first* minimum and the *last* maximum, which is
// what std::minmax_element promises as well.
void test_minmax_element(const std::vector<value_type>& a)
{
  const size_type_pair pos = minmax_element(a.data(), a.size());

  if (a.empty()) {
    assert(pos.first == 0 && pos.second == 0);
    return;
  }

  const auto expected = std::minmax_element(a.begin(), a.end());

  assert(pos.first  == static_cast<size_type>(expected.first  - a.begin()));
  assert(pos.second == static_cast<size_type>(expected.second - a.begin()));

  for (size_type i = 0; i < a.size(); ++i) {
    assert(a[pos.first] <= a[i]);
    assert(a[i] <= a[pos.second]);

    if (i < pos.first) {
      assert(a[pos.first] < a[i]);
    }

    if (pos.second < i) {
      assert(a[i] < a[pos.second]);
    }
  }
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_minmax_element(a);
  }

  // Repeated extrema: the first minimum and the last maximum must win.
  test_minmax_element({2, 1, 8, 1, 5, 6, 8, 7, 7});
  test_minmax_element({4, 4, 4, 4});
  test_minmax_element({1, 9, 1, 9});

  return EXIT_SUCCESS;
}
