
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "mismatch.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a{1, 2, 3, 3, 3, 7, 8};

  auto b = a;

  assert(a.size() == mismatch(&a[0], a.size(), &b[0]));

  auto c = a;
  c[2] += 1;
  c[5] += 1;

  assert(2 == mismatch(&a[0], a.size(), &c[0]));

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

