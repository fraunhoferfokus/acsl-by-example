

#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "max_seq.h"

int main(int argc, char** argv)
{

  std::vector<int> a;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(9);
  a.push_back(3);
  a.push_back(7);
  a.push_back(8);

  assert(not a.empty());

  std::vector<int>::const_iterator max_it  = std::max_element(a.begin(), a.end());
  int  max = max_seq(&a[0], a.size());

  assert(*max_it == max);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
