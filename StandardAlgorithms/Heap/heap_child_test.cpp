
#include <cassert>
#include <cstdlib>
#include <vector>

#include "heap_child.h"
#include "heap_parent.h"

// heap_child(a, n, p) returns the child of p holding the larger value, or n
// if p has no child inside the array. The checks below are the clauses of
// its contract, evaluated for every position of every array given.

void test_heap_child(const std::vector<value_type>& a)
{
  const size_type n = a.size();

  for (size_type p = 0; p < n; ++p) {
    const size_type left  = 2 * p + 1;
    const size_type right = left + 1;
    const size_type c     = heap_child(a.data(), n, p);

    assert(p < c && c <= n);

    if (c < n) {
      assert(c == left || c == right);
      assert(heap_parent(c) == p);
    }
    else {
      // No child inside the array.
      assert(n <= left && n <= right);
    }

    if (left < n) {
      assert(c < n);
      assert(a[left] <= a[c]);
    }

    if (right < n) {
      assert(c < n);
      assert(a[right] <= a[c]);
    }
  }
}

int main(int, char**)
{
  for (size_type n = 1; n <= 20; ++n) {
    std::vector<value_type> increasing(n);
    std::vector<value_type> decreasing(n);
    std::vector<value_type> constant(n, 7);
    std::vector<value_type> mixed(n);

    for (size_type i = 0; i < n; ++i) {
      increasing[i] = static_cast<value_type>(i);
      decreasing[i] = static_cast<value_type>(n - i);
      mixed[i]      = static_cast<value_type>((7 * i) % 5);
    }

    test_heap_child(increasing);
    test_heap_child(decreasing);
    test_heap_child(constant);
    test_heap_child(mixed);
  }

  return EXIT_SUCCESS;
}
