
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "make_heap.h"
#include "sort_heap.h"
#include "test_data.hpp"

// sort_heap turns a heap into an increasing array holding the same values.
void test_sort_heap(std::vector<value_type> a)
{
  std::make_heap(a.begin(), a.end());

  std::vector<value_type> expected = a;

  sort_heap(a.data(), a.size());
  std::sort_heap(expected.begin(), expected.end());

  assert(a == expected);
  assert(std::is_sorted(a.begin(), a.end()));
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_sort_heap(a);

    for (size_type i = 0; i <= a.size(); ++i) {
      test_sort_heap(std::vector<value_type>(a.begin(), a.begin() + i));
    }
  }

  {
    std::vector<value_type> a(10);

    for (size_type i = 0; i < a.size(); ++i) {
      a[i] = static_cast<value_type>(2 * i);
    }

    test_sort_heap(a);
  }

  return EXIT_SUCCESS;
}
