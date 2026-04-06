
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include "push_heap.h"
#include "is_heap.h"

int main(int, char**)
{
  std::vector<value_type> a;
  assert(is_heap(a.data(), a.size()));
  std::vector<value_type> b;
  assert(std::is_heap(b.begin(), b.end()));
  const size_t size = 10;

  for (size_t i = 0; i < size; i++) {
    const value_type val = 2 * i;
    assert(is_heap(a.data(), a.size()));
    a.push_back(val);
    push_heap(a.data(), a.size());
    assert(is_heap(a.data(), a.size()));
    assert(std::is_heap(b.begin(), b.end()));
    b.push_back(val);
    std::push_heap(b.begin(), b.end());
    assert(std::is_heap(b.begin(), b.end()));
    assert(a == b);
  }

  return EXIT_SUCCESS;
}

