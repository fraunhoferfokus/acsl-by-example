
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include "make_heap.h"
#include "../is_heap/is_heap.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{2, 3, 3, 3, 6, 7, 8, 8, 9, 11, 13, 14};
  auto b = a;
  make_heap(a.data(), a.size());
  assert(is_heap(a.data(), a.size()));
  assert(std::is_heap(a.begin(), a.end()));
  std::make_heap(b.begin(), b.end());
  assert(std::is_heap(b.begin(), b.end()));
  assert(is_heap(b.data(), b.size()));
  /*
  for(size_t i = 0; i < a.size(); ++i) {
    std::cout << i << '\t' << a[i] << '\t' << b[i] << std::endl;
  }
  */
  // a == b currently does not hold, although both are heaps.
  // So we sort both arrays and compare then
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  assert(a == b);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
}

