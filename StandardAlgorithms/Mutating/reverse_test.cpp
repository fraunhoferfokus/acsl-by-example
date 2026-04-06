
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "reverse.h"

int main(int, char**)
{
  std::vector<value_type> a{1, 2, 3, 5, 7, 6, 9};
  auto a_backup = a;

  std::reverse(a.data(), a.data() + a.size());
  reverse(a.data(), a.size());
  assert(a == a_backup);

  // now with even size
  a.push_back(8);
  a_backup = a;
  std::reverse(a.data(), a.data() + a.size());
  reverse(a.data(), a.size());
  assert(a == a_backup);

  return EXIT_SUCCESS;
}

