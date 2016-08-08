

#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>

#include "remove.h"

int main(int argc, char** argv)
{
  std::vector<int> a;

  a.push_back(1);
  a.push_back(3);
  a.push_back(2);
  a.push_back(8);
  a.push_back(3);
  a.push_back(3);
  a.push_back(7);

  std::vector<int> b = a;

  const int value = 3;

  int* last_b = std::remove(&b[0], &b[0] + a.size(), value);
  int  size_a =      remove(&a[0], a.size(), value);

  assert(size_a == last_b - &b[0]);
  assert(a == b);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

}
