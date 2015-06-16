

#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "copy.h"

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

  std::vector<int> a_backup(a);

  std::vector<int> b(a.size());
  copy(&a[0], a.size(), &b[0]);

  assert(a == a_backup);
  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
