
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "mismatch.h"

int main(int, char** )
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};
  auto b = a;
  assert(a.size() == mismatch(a.data(), a.size(), b.data()));
  auto c = a;
  c[2] += 1;
  c[5] += 1;
  assert(2 == mismatch(a.data(), a.size(), c.data()));

  return EXIT_SUCCESS;
}

