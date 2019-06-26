
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <stdlib.h>

#include "random_shuffle.h"

int
main(int argc, char** argv)
{
  std::vector<value_type> a{8, 2, 43, 4, 43, 6, 7};
  auto b = a;
  random_shuffle(a.begin(), a.end());
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  assert(a == b);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

