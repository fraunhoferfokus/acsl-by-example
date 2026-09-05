
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "is_heap_until.h"
#include "test_data.hpp"

// is_heap_until returns the length of the longest prefix that is a heap.
void test_is_heap_until(const std::vector<value_type>& a)
{
  const size_type pos = is_heap_until(a.data(), a.size());
  const auto expected = std::is_heap_until(a.begin(), a.end());

  assert(pos == static_cast<size_type>(expected - a.begin()));

  // The prefix really is a heap, and it cannot be extended.
  assert(std::is_heap(a.begin(), a.begin() + pos));

  if (pos < a.size()) {
    assert(!std::is_heap(a.begin(), a.begin() + pos + 1));
  }
}


int main(int, char**)
{
  for (const auto& a : test_arrays()) {
    test_is_heap_until(a);

    std::vector<value_type> heap = a;
    std::make_heap(heap.begin(), heap.end());
    test_is_heap_until(heap);

    // A heap in front, arbitrary values behind: the boundary moves.
    for (size_type i = 0; i <= a.size(); ++i) {
      std::vector<value_type> mixed = a;
      std::make_heap(mixed.begin(), mixed.begin() + i);
      test_is_heap_until(mixed);
    }
  }

  return EXIT_SUCCESS;
}
