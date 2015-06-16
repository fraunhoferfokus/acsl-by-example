

#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "find_first_of.h"

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

  std::vector<int> b;

  b.push_back(0);
  b.push_back(3);
  b.push_back(9);

  int* it = std::find_first_of(&a[0], &a[0] + a.size(),
                               &b[0], &b[0] + b.size());

  int  pos = find_first_of(&a[0], a.size(),
                           &b[0], b.size());

  assert(it == &a[0] + pos);
  assert(*it == a[pos]);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
