
#include "merge_sort.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <functional>
#include <random>


void test_merge_sort(std::vector<value_type> a)
{
  auto expected = a;
  std::sort(expected.begin(), expected.end());
  std::vector<value_type> buffer(a.size());
  merge_sort(a.data(), a.size(), buffer.data());
  assert(a == expected);
}


int main(int, char**)
{
  test_merge_sort(std::vector<value_type>());
  test_merge_sort(std::vector<value_type> {1});
  test_merge_sort(std::vector<value_type> {1, 5});
  test_merge_sort(std::vector<value_type> {5, 1});
  test_merge_sort(std::vector<value_type> {0, 1, 3, 5, 7, 9});
  test_merge_sort(std::vector<value_type> {9, 1, 3, 5, 7, 0});
  test_merge_sort(std::vector<value_type> {1, 1, 2, 4, 5, 6, 6, 7, 8});

  // One random array, so that a failure can be reproduced from the seed.
  std::random_device r;
  const auto seed = r();
  std::mt19937 eng(seed);
  std::uniform_int_distribution<value_type> dist;
  auto generate = std::bind(dist, eng);
  size_type a_size = generate() % 100;
  std::vector<value_type> a(a_size);
  std::generate(a.begin(), a.end(), generate);
  std::vector<value_type> expected(a);
  std::vector<value_type> buffer(a_size);

  merge_sort(a.data(), a.size(), buffer.data());
  std::sort(expected.begin(), expected.end());

  if (a != expected) {
    std::cerr << "merge_sort failed for seed " << seed
              << " and length " << a_size << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
