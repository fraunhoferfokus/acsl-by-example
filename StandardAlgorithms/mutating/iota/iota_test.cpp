

#include <cassert>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

#include "iota.h"

int main(int argc, char** argv)
{
  std::vector<int> a(7);
  std::vector<int> b(a.size());

  int value = 0;

  std::iota(a.begin(), a.end(), value);
  iota(&b[0], b.size(), value);

  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}

