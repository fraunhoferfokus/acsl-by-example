
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "equal.h"

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

  std::vector<int> b(a);

  assert(std::equal(a.begin(), a.end(), b.begin()));
  assert(equal(&a[0], a.size(), &b[0]));

  std::vector<int> c(a);
  c[0] += 1;

  assert(!std::equal(a.begin(), a.end(), c.begin()));
  assert(!equal(&a[0], a.size(), &c[0]));

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
