
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "binary_search.h"

int main(int, char**)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};
  value_type value = 3;

  bool result1 = std::binary_search(a.begin(), a.end(), value);
  assert(result1);
  bool result2 = binary_search(a.data(), a.size(), value);
  assert(result1 == result2);

  return EXIT_SUCCESS;
}


