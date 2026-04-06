
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "copy.h"

int main(int, char**)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};

  auto a_backup = a;
  auto b = a;
  copy(a.data(), a.size(), b.data());
  assert(a == a_backup);
  assert(a == b);

  return EXIT_SUCCESS;
}

