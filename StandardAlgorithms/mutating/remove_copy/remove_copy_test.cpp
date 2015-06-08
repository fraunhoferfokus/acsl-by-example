

#include <algorithm>
#include <vector>
#include <iostream>
#include <assert.h>

#include "remove_copy.h"

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

  std::vector<int> b(a.size());
  std::vector<int> c(a.size());

  const int value = 3;

  int* last_b = std::remove_copy(&a[0], &a[0] + a.size(), &b[0], value);
  int  size_c =      remove_copy(&a[0], a.size(), &c[0], value);

  assert(size_c == last_b - &b[0]);
  assert(b == c);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

}
