
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "adjacent_find.h"
#include "test_data.hpp"

// adjacent_find returns the index of the first of two equal neighbours, or n
// if the array has none -- which includes the empty and the one-element
// array. The earlier test read a[pos + 1] unconditionally, which is out of
// bounds in that case.
void test_adjacent_find(const std::vector<value_type>& a)
{
  const auto it = std::adjacent_find(a.begin(), a.end());
  const size_type expected = static_cast<size_type>(it - a.begin());
  const size_type pos = adjacent_find(a.data(), a.size());

  assert(pos == expected);

  if (pos < a.size()) {
    assert(pos + 1 < a.size());
    assert(a[pos] == a[pos + 1]);
  }
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_adjacent_find(a);
  }

  test_adjacent_find({1, 2, 3});          // no equal neighbours
  test_adjacent_find({1, 1, 2, 2});       // the first pair wins
  test_adjacent_find({1, 2, 2});          // in the middle
  test_adjacent_find({1, 2, 3, 3});       // at the end

  return EXIT_SUCCESS;
}
