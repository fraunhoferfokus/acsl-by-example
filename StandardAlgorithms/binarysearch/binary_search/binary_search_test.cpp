
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "binary_search.h"
#include "../lower_bound/lower_bound.h"

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

  bool pos1 = std::binary_search(a.begin(), a.end(), value);
  bool pos2 = binary_search(&a[0], a.size(), value);
  assert(pos1 == pos2);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}


