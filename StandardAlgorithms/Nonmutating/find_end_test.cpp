
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "find_end.h"
#include "test_data.hpp"

// find_end returns the index at which b occurs *last* as a subrange of a, or
// n if it does not occur at all. For the empty pattern the contract leaves
// no room either: no later occurrence may exist, so the result is n, which
// is what std::find_end returns as well.
void test_find_end(const std::vector<value_type>& a, const std::vector<value_type>& b)
{
  const auto it = std::find_end(a.begin(), a.end(), b.begin(), b.end());
  const size_type expected = static_cast<size_type>(it - a.begin());
  const size_type pos = find_end(a.data(), a.size(), b.data(), b.size());

  assert(pos == expected);

  if (pos < a.size() && !b.empty()) {
    assert(std::equal(b.begin(), b.end(), a.begin() + pos));
  }
}


int main(int, char**)
{
  const std::vector<value_type> a{10, 20, 30, 40, 50, 60, 70, 80, 40, 50, 60, 70, 90};

  test_find_end(a, {});                        // the empty pattern
  test_find_end(a, {40, 50, 60, 70});          // occurs twice: the last wins
  test_find_end(a, {10});                      // at the beginning
  test_find_end(a, {90});                      // at the end
  test_find_end(a, {80, 40});                  // spanning the two runs
  test_find_end(a, {1, 2, 3});                 // absent
  test_find_end(a, a);                         // the whole array
  test_find_end({}, {});                       // both empty
  test_find_end({}, {1});                      // pattern longer than the array

  for (const auto& x : test_arrays()) {
    test_find_end(x, {});
    test_find_end(x, {present_value()});
    test_find_end(x, {absent_value()});
    test_find_end(x, x);

    for (size_type i = 0; i < x.size(); ++i) {
      test_find_end(x, std::vector<value_type>(x.begin() + i, x.end()));
      test_find_end(x, std::vector<value_type>(x.begin(), x.begin() + i));
    }
  }

  return EXIT_SUCCESS;
}
