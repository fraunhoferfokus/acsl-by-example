
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "count.h"

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

  int count_value = 3;

  int c1 = std::count(a.begin(), a.end(), count_value);
  int c2 = count(&a[0], a.size(), count_value);

  assert(c1 = c2);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
