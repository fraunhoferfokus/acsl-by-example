
#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>

#include "replace.h"

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

  std::vector<int> b = a;
  assert(a == b);

  const int old_value = 3;
  const int new_value = 4;

  replace(&a[0], a.size(), old_value, new_value);
  std::replace(b.begin(), b.end(), old_value, new_value);

  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
}

