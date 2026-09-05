
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "is_heap.h"
#include "test_data.hpp"

void test_is_heap(const std::vector<value_type>& a)
{
  assert(is_heap(a.data(), a.size()) == std::is_heap(a.begin(), a.end()));
}


int main(int, char**)
{
  // Arrays that are heaps, and the same arrays before they were made into
  // one: the corpus contains both kinds.
  for (const auto& a : test_arrays()) {
    test_is_heap(a);

    std::vector<value_type> heap = a;
    std::make_heap(heap.begin(), heap.end());
    test_is_heap(heap);
    assert(is_heap(heap.data(), heap.size()));

    // Breaking the heap at any one position must be noticed.
    for (size_type i = 1; i < heap.size(); ++i) {
      std::vector<value_type> broken = heap;
      broken[i] = broken[0] + 1;
      test_is_heap(broken);
      assert(!is_heap(broken.data(), broken.size()));
    }
  }

  test_is_heap({});
  test_is_heap({1});
  test_is_heap({1, 2});      // not a heap
  test_is_heap({2, 1});      // a heap

  return EXIT_SUCCESS;
}
