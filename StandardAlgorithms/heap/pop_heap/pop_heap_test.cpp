
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cassert>
#include "pop_heap.h"

int main(int argc, char** argv)
{
  std::vector<int> a(10);

  std::iota(a.begin(), a.end(), 0);
  std::make_heap(a.begin(), a.end());
  std::vector<int> b = a;

  std::pop_heap(a.begin(), a.end());

  pop_heap(&b[0], b.size());

  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
}

