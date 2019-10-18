
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cassert>
#include "is_heap_until.h"


int
main(int argc, char** argv)
{
  std::vector<value_type> a(10);

  std::iota(a.begin(), a.end(), 0);
  std::make_heap(a.begin(), a.begin() + a.size() / 2);
  auto result1 = is_heap_until(a.data(), a.size());
  auto result2 = std::is_heap_until(a.begin(), a.end());
  assert(a.begin() + result1 == result2);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
}

