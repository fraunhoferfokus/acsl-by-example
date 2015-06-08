

#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>


#include "swap_ranges.h"

int main(int argc, char** argv)
{
  std::vector<int> a;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(4);

  std::vector<int> a_backup(a);

  std::vector<int> b;

  b.push_back(11);
  b.push_back(12);
  b.push_back(13);
  b.push_back(14);

  std::swap_ranges(a.begin(), a.end(), b.begin());
  swap_ranges(&b[0], b.size(), &a[0]);

  assert(a == a_backup);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
