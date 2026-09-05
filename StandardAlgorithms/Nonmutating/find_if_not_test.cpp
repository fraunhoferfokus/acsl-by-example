
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "find_if_not.h"
#include "test_data.hpp"

// find_if_not returns the index of the first element different from v, or n
// if every element equals v -- which includes the empty array.
void test_find_if_not(const std::vector<value_type>& a, value_type v)
{
  const auto it = std::find_if_not(a.begin(), a.end(), [v](value_type x) {
    return x == v;
  });

  assert(find_if_not(a.data(), a.size(), v) ==
         static_cast<size_type>(it - a.begin()));
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    std::vector<value_type> values = a;
    values.push_back(present_value());
    values.push_back(absent_value());

    for (const value_type v : values) {
      test_find_if_not(a, v);
    }
  }

  // Every element equals v: the result must be the length.
  test_find_if_not({}, 3);
  test_find_if_not({3}, 3);
  test_find_if_not({3, 3, 3}, 3);

  return EXIT_SUCCESS;
}
