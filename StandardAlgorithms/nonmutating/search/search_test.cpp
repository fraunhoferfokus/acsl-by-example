#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "search.h"

int main(int argc, char** argv)
{
  std::vector<int> a, b;

  // a = [10, 20, 30, 40, 50, 60, 70, 80, 90]
  for (int i = 10; i < 100; i += 10) {
    a.push_back(i);
  }

  // b = [40, 50, 60, 70]
  for (int i = 40; i < 80; i += 10) {
    b.push_back(i);
  }

  std::vector<int>::iterator it = std::search(a.begin(), a.end(), b.begin(), b.end());

  int pos = search(&a[0], 9, &b[0], 4);
  assert(pos == it - a.begin());

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
