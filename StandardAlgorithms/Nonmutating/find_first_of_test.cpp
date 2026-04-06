
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "find_first_of.h"

int main(int, char** )
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};
  std::vector<value_type> b{0, 3, 9};
  auto it = std::find_first_of(a.data(), a.data() + a.size(), b.data(), b.data() + b.size());
  auto pos = find_first_of(a.data(), a.size(), b.data(), b.size());
  assert(it == a.data() + pos);
  assert(*it == a[pos]);

  return EXIT_SUCCESS;
}

