

#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "fill.h"

int main(int argc, char** argv)
{
  std::vector<int> a;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(3);
  a.push_back(3);
  a.push_back(7);
  a.push_back(8);

  std::vector<int> b(a.size());

  int value = 9;

  std::fill(&a[0], &a[0] + a.size(), value);
  fill(&b[0], b.size(), value);

  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
