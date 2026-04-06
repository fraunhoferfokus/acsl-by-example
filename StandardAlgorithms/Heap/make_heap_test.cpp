
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include "make_heap.h"
#include "is_heap.h"

int main(int, char**)
{
  std::vector<value_type> a{2, 3, 3, 3, 6, 7, 8, 8, 9, 11, 13, 14};
  auto b = a;
  make_heap(a.data(), a.size());

  assert(is_heap(a.data(), a.size()));
  assert(std::is_heap(a.begin(), a.end()));
  std::make_heap(b.begin(), b.end());
  assert(std::is_heap(b.begin(), b.end()));
  assert(is_heap(b.data(), b.size()));
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  assert(a == b);

  return EXIT_SUCCESS;
}

