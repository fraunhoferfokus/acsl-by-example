
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include "make_heap.h"
#include "sort_heap.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a(10);

  for (size_t i = 0; i < a.size(); i++) {
    a[i] = 2 * i;
  }

  make_heap(a.data(), a.size());
  assert(std::is_heap(a.begin(), a.end()));
  auto b = a;
  sort_heap(a.data(), a.size());
  std::sort_heap(b.begin(), b.end());
  assert(a == b);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

