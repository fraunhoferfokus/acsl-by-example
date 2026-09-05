
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "find_first_of.h"
#include "test_data.hpp"

// find_first_of returns the index of the first element of a that occurs in
// b, or m if no element of a does -- which includes an empty b.
void test_find_first_of(const std::vector<value_type>& a, const std::vector<value_type>& b)
{
  const auto it = std::find_first_of(a.begin(), a.end(), b.begin(), b.end());
  const size_type expected = static_cast<size_type>(it - a.begin());
  const size_type pos = find_first_of(a.data(), a.size(), b.data(), b.size());

  assert(pos == expected);

  if (pos < a.size()) {
    assert(std::find(b.begin(), b.end(), a[pos]) != b.end());

    // No earlier element of a occurs in b.
    for (size_type i = 0; i < pos; ++i) {
      assert(std::find(b.begin(), b.end(), a[i]) == b.end());
    }
  }
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_find_first_of(a, {});                       // nothing to find
    test_find_first_of(a, {absent_value()});         // no element occurs
    test_find_first_of(a, {present_value()});
    test_find_first_of(a, a);                        // the first element wins
    test_find_first_of({}, a);                       // nowhere to look

    for (size_type i = 0; i < a.size(); ++i) {
      test_find_first_of(a, {a[i]});
      test_find_first_of(a, {absent_value(), a[i]});
    }
  }

  return EXIT_SUCCESS;
}
