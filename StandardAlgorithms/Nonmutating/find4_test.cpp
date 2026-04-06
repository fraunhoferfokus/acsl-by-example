
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "find4.h"

int main(int, char** )
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};
  value_type value = 3;

  auto it = std::find(a.begin(), a.end(), value);
  auto pos = find4(a.data(), a.size(), value);
  assert(it == a.begin() + pos);
  assert(*it == a[pos]);



  return EXIT_SUCCESS;
}

