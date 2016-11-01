
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include "push_heap.h"

int main(int argc, char** argv)
{
  std::vector<int> a(10);

  for (size_t i = 0; i < a.size(); i++) {
    a[i] = 2 * i;
  }

  std::make_heap(a.begin(), a.end());
  a.push_back(15);

  std::vector<int> b = a;

  std::push_heap(a.begin(), a.end());

  push_heap(&b[0], b.size());

  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
}

