
#include "partial_sort.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include "../../support/vector_io.h"

void test_partial_sort(std::vector<value_type> a, size_type m)
{
  auto b = a;
  auto c = a;
  partial_sort(b.data(), m, b.size());
  std::partial_sort(c.begin(), c.begin() + m, c.end());

  //std::cout << a << "\t" << m << "\t" << b << std::endl;

  // compare initial segments
  assert(std::equal(b.begin(), b.begin() + m, c.begin(), c.begin() + m));

  // sort and compare trailing segments
  std::sort(b.begin() + m, b.end());
  std::sort(c.begin() + m, c.end());
  assert(std::equal(b.begin() + m, b.end(), c.begin() + m, c.end()));
}


int main(int argc, char** argv)
{
  test_partial_sort(std::vector<value_type>(), 0);
  test_partial_sort(std::vector<value_type> {1}, 0);
  test_partial_sort(std::vector<value_type> {1}, 1);
  test_partial_sort(std::vector<value_type> {1, 5}, 0);
  test_partial_sort(std::vector<value_type> {1, 5}, 1);
  test_partial_sort(std::vector<value_type> {1, 5}, 2);
  test_partial_sort(std::vector<value_type> {5, 1}, 0);
  test_partial_sort(std::vector<value_type> {5, 1}, 1);
  test_partial_sort(std::vector<value_type> {5, 1}, 2);
  test_partial_sort(std::vector<value_type> {5, 3, 6, 1, 4, 5, 2, 1}, 3);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

