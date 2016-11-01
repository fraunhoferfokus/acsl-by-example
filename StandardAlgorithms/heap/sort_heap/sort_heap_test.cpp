
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include "heap.h"

int main(int argc, char** argv)
{
  std::vector<int> a(10);

  for (size_t i = 0; i < a.size(); i++) {
    a[i] = 2 * i;
  }

  make_heap(&a[0], a.size());

  assert(!is_sorted(a.begin(), a.end()));

  sort_heap(&a[0], a.size());

  assert(is_sorted(a.begin(), a.end()));

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

