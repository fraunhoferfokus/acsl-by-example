
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "find_if_not.h"

int main(int, char** )
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};
  value_type value = 3;

  auto it = std::find_if_not(a.begin(), a.end(), [value](int i) {
    return i == value;
  });

  auto pos = find_if_not(a.data(), a.size(), value);
  assert(it == a.begin() + pos);
  assert(*it == a[pos]);



  return EXIT_SUCCESS;
}

