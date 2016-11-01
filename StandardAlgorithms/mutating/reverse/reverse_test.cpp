
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "reverse.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 5, 7, 6, 9};
  auto a_backup = a;

  std::reverse(&a[0], &a[0] + a.size());
  reverse(&a[0], a.size());
  assert(a == a_backup);

  // now with even size
  a.push_back(8);
  a_backup = a;

  std::reverse(&a[0], &a[0] + a.size());
  reverse(&a[0], a.size());
  assert(a == a_backup);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

