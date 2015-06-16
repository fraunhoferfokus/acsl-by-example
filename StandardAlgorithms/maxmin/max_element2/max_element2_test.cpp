

#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "max_element2.h"

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

  std::vector<int>::const_iterator max_it  = std::max_element(a.begin(), a.end());
  int  max_pos = max_element(&a[0], a.size());

  assert(*max_it == a[max_pos]);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
