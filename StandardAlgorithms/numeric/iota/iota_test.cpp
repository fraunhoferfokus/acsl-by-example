
#include <cassert>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#include "iota.h"

int main(int argc, char** argv)
{
  std::vector<value_type> a(7);
  std::vector<value_type> b(a.size());

  const value_type value = 0;

  std::iota(a.begin(), a.end(), value);
  iota(&b[0], b.size(), value);

  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

