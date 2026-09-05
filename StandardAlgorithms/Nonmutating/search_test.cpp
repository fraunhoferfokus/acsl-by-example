
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "search.h"
#include "test_data.hpp"

// search returns the index at which b first occurs as a subrange of a, or n
// if it does not occur at all.
void test_search(const std::vector<value_type>& a, const std::vector<value_type>& b)
{
  const auto it = std::search(a.begin(), a.end(), b.begin(), b.end());
  const size_type expected = static_cast<size_type>(it - a.begin());
  const size_type pos = search(a.data(), a.size(), b.data(), b.size());

  assert(pos == expected);

  if (pos < a.size() || b.empty()) {
    assert(std::equal(b.begin(), b.end(), a.begin() + pos));
  }
}


int main(int, char**)
{
  const std::vector<value_type> a{10, 20, 30, 40, 50, 60, 70, 80, 40, 50, 60, 70, 90};

  test_search(a, {});                          // the empty pattern
  test_search(a, {40, 50, 60, 70});            // occurs twice: the first wins
  test_search(a, {10});                        // at the beginning
  test_search(a, {90});                        // at the end
  test_search(a, {80, 40});                    // spanning the two runs
  test_search(a, {40, 50, 60, 70, 90});        // only the second occurrence fits
  test_search(a, {1, 2, 3});                   // absent
  test_search(a, a);                           // the whole array
  test_search({}, {});                         // both empty
  test_search({}, {1});                        // pattern longer than the array

  for (const auto& x : test_arrays()) {
    test_search(x, {});
    test_search(x, {present_value()});
    test_search(x, {absent_value()});
    test_search(x, x);

    for (size_type i = 0; i < x.size(); ++i) {
      test_search(x, std::vector<value_type>(x.begin() + i, x.end()));
      test_search(x, std::vector<value_type>(x.begin(), x.begin() + i));
    }
  }

  return EXIT_SUCCESS;
}
