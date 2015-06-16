

#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "swap.h"

int main(int argc, char** argv)
{
  std::vector<int> a;

  a.push_back(1);
  a.push_back(2);

  std::vector<int> b(a);
  assert(a == b);

  std::iter_swap(&a[0], &a[1]);
  swap(&b[0], &b[1]);

  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
