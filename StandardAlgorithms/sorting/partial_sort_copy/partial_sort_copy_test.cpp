
#include "partial_sort_copy.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include "../../support/vector_io.h"

void test_partial_sort_copy(std::vector<value_type> a, size_type m)
{
  //std::cout << "begin" << std::endl;

  std::vector<value_type> b(m);
  assert(b.size() == m);
  auto c = b;

  //std::cout << a << "\t" << m << "\t" << b << std::endl;
  //std::cout << "\tbefore" << std::endl;
  partial_sort_copy(a.data(), a.size(), b.data(), b.size());
  //std::cout << "\tafter" << std::endl;
  std::partial_sort_copy(a.begin(), a.end(), c.begin(), c.end());


  // compare initial segments
  assert(std::equal(b.begin(), b.end(), c.begin(), c.end()));

  std::partial_sort(a.begin(), a.begin() + m, a.end());
  assert(std::equal(b.begin(), b.end(), a.begin(), a.begin() + m));
  //std::cout << "end" << std::endl;
}


int main(int argc, char** argv)
{
  test_partial_sort_copy(std::vector<value_type>(), 0);
  //test_partial_sort_copy(std::vector<value_type> {1}, 0);
  test_partial_sort_copy(std::vector<value_type> {1}, 1);
  //test_partial_sort_copy(std::vector<value_type> {1, 5}, 0);
  test_partial_sort_copy(std::vector<value_type> {1, 5}, 1);
  test_partial_sort_copy(std::vector<value_type> {1, 5}, 2);
  //test_partial_sort_copy(std::vector<value_type> {5, 1}, 0);
  test_partial_sort_copy(std::vector<value_type> {5, 1}, 1);
  test_partial_sort_copy(std::vector<value_type> {5, 1}, 2);
  test_partial_sort_copy(std::vector<value_type> {5, 3, 6, 1, 4, 5, 2, 1}, 3);

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

