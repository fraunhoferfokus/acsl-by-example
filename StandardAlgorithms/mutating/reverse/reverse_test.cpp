

#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "reverse.h"

int main(int argc, char** argv)
{
  std::vector<int> a;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(5);
  a.push_back(6);
  a.push_back(7);
  a.push_back(9);

  std::vector<int> a_backup(a);

  std::reverse(&a[0], &a[0] + a.size());
  reverse(&a[0], a.size());
  assert(a == a_backup);

  // now with even size
  a.push_back(8);
  a_backup = a;

  std::reverse(&a[0], &a[0] + a.size());
  reverse(&a[0], a.size());
  assert(a == a_backup);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
