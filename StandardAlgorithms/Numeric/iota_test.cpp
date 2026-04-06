
#include <cassert>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#include "iota.h"

int main(int, char**)
{
  std::vector<value_type> a(7);
  std::vector<value_type> b(a.size());
  const value_type value = 0;

  std::iota(a.begin(), a.end(), value);
  iota(b.data(), b.size(), value);
  assert(a == b);

  return EXIT_SUCCESS;
}

