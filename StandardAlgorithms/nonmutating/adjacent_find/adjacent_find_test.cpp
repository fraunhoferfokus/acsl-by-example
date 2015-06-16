
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "adjacent_find.h"

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

  int* first = &a[0];
  int* last  = first + a.size();

  int* pos_std = std::adjacent_find(first, last);
  int  pos = adjacent_find(first, last - first);

  assert(pos_std - first == pos);
  assert(*pos_std == a[pos]);
  assert(*(pos_std + 1) == a[pos + 1]);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
