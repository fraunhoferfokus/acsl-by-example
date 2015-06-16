
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>

#include "min_element.h"
#include "min_element.h"

int main(int argc, char** argv)
{
  std::vector<int> a;

  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  a.push_back(9);
  a.push_back(0);
  a.push_back(7);
  a.push_back(8);

  std::vector<int> b(a);

  int* first_a = &a[0];
  int* first_b = &b[0];

  int* last_a  = first_a + a.size();

  int* min_a = std::min_element(first_a, last_a);
  int  min_b = min_element(first_b, b.size());

  assert(*min_a == b[min_b]);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return 0;
}
