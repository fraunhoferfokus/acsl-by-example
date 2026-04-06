
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cassert>
#include "is_heap.h"


int main(int, char**)
{
  std::vector<value_type> a(10);
  std::iota(a.begin(), a.end(), 0);

  std::make_heap(a.begin(), a.end());
  assert(is_heap(a.data(), a.size()));
  assert(std::is_heap(a.begin(), a.end()));

  return EXIT_SUCCESS;
}

