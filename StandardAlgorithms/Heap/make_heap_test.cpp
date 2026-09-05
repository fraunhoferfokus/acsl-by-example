
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "make_heap.h"
#include "is_heap.h"
#include "test_data.hpp"

// make_heap must produce a heap holding exactly the values it was given.
void test_make_heap(std::vector<value_type> a)
{
  std::vector<value_type> expected = a;

  make_heap(a.data(), a.size());

  assert(is_heap(a.data(), a.size()));
  assert(std::is_heap(a.begin(), a.end()));

  std::sort(a.begin(), a.end());
  std::sort(expected.begin(), expected.end());
  assert(a == expected);
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_make_heap(a);

    // Every prefix, so that every length up to the array's is covered.
    for (size_type i = 0; i <= a.size(); ++i) {
      test_make_heap(std::vector<value_type>(a.begin(), a.begin() + i));
    }
  }

  test_make_heap({2, 3, 3, 3, 6, 7, 8, 8, 9, 11, 13, 14});   // increasing
  test_make_heap({14, 13, 11, 9, 8, 8, 7, 6, 3, 3, 3, 2});   // already a heap

  return EXIT_SUCCESS;
}
