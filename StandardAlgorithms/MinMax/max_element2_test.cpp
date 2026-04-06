
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "max_element2.h"

int main(int, char**)
{
  std::vector<value_type> a{1, 2, 3, 9, 3, 7, 8};

  auto max_it  = std::max_element(a.begin(), a.end());
  auto max_pos = max_element2(a.data(), a.size());
  assert(*max_it == a[max_pos]);

  return EXIT_SUCCESS;
}

