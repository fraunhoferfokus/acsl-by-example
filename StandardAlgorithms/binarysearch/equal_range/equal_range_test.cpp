#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "equal_range.h"

typedef std::vector<int>::const_iterator iterator;

int main(int argc, char** argv)
{
  std::vector<value_type> a;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(3);
  a.push_back(3);
  a.push_back(7);
  a.push_back(8);

  value_type value = 3;

  std::pair<iterator, iterator> iter_pair = std::equal_range(a.begin(), a.end(), value);

  size_type_pair size_pair = equal_range(&a[0], a.size(), value);

  assert(iter_pair.first - a.begin()  == size_pair.first);
  assert(iter_pair.second - a.begin() == size_pair.second);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
