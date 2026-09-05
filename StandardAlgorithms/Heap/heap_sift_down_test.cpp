
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <vector>

#include "heap_sift_down.h"

// HeapForest(a, m, n) demands the heap property of every parent-child pair
// whose parent index is at least m. This mirrors Logic/HeapForest.acsl.
bool heap_forest(const std::vector<value_type>& a, size_type m)
{
  const size_type n = a.size();

  for (size_type p = m; p < n; ++p) {
    const size_type left  = 2 * p + 1;
    const size_type right = left + 1;

    if (left < n && a[p] < a[left]) {
      return false;
    }

    if (right < n && a[p] < a[right]) {
      return false;
    }
  }

  return true;
}

// A heap whose root value is replaced violates the heap property only in the
// pairs headed by that position, which is exactly the precondition of
// heap_sift_down.
void test_heap_sift_down(size_type n, size_type root, value_type intruder)
{
  std::vector<value_type> a(n);

  for (size_type i = 0; i < n; ++i) {
    a[i] = static_cast<value_type>((11 * i) % 13);
  }

  std::make_heap(a.begin(), a.end());
  a[root] = intruder;
  assert(heap_forest(a, root + 1));

  std::vector<value_type> expected = a;

  heap_sift_down(a.data(), a.size(), root);

  assert(heap_forest(a, root));

  std::sort(a.begin(), a.end());
  std::sort(expected.begin(), expected.end());
  assert(a == expected);
}

int main(int, char**)
{
  for (size_type n = 1; n <= 15; ++n) {
    for (size_type root = 0; root < n; ++root) {
      test_heap_sift_down(n, root, -1);   // sinks to the bottom
      test_heap_sift_down(n, root, 99);   // stays in place
      test_heap_sift_down(n, root, 6);    // sinks part of the way
    }
  }

  return EXIT_SUCCESS;
}
