#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "lower_bound.h"

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

  int value = 3;

  std::vector<int>::iterator it = std::lower_bound(a.begin(), a.end(), value);

  int  pos = lower_bound(&a[0], a.size(), value);

  assert(it - a.begin() == pos);

  assert(*it == a[pos]);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
