
#include "merge.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <functional>
#include <random>


// Both arrays must be increasing, as required by the contract of merge.
void test_merge(std::vector<value_type> a, std::vector<value_type> b)
{
  assert(std::is_sorted(a.begin(), a.end()));
  assert(std::is_sorted(b.begin(), b.end()));
  std::vector<value_type> own(a.size() + b.size());
  std::vector<value_type> expected(a.size() + b.size());

  merge(a.data(), a.size(), b.data(), b.size(), own.data());
  std::merge(a.begin(), a.end(), b.begin(), b.end(), expected.begin());

  assert(std::is_sorted(own.begin(), own.end()));
  assert(own == expected);
}


int main(int, char**)
{
  test_merge(std::vector<value_type>(), std::vector<value_type>());
  test_merge(std::vector<value_type>(), std::vector<value_type> {1, 2});
  test_merge(std::vector<value_type> {1, 2}, std::vector<value_type>());
  test_merge(std::vector<value_type> {1, 3, 5}, std::vector<value_type> {2, 4, 6});
  test_merge(std::vector<value_type> {1, 1, 2}, std::vector<value_type> {1, 2, 2});

  // Two random arrays, so that a failure can be reproduced from the seed.
  std::random_device r;
  const auto seed = r();
  std::mt19937 eng(seed);
  std::uniform_int_distribution<value_type> dist;
  auto generate = std::bind(dist, eng);
  size_type a_size = generate() % 100;
  std::vector<value_type> a(a_size);
  std::generate(a.begin(), a.end(), generate);
  size_type b_size = generate() % 100;
  std::vector<value_type> b(b_size);
  std::generate(b.begin(), b.end(), generate);
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
  std::vector<value_type> own(a_size + b_size);
  std::vector<value_type> expected(a_size + b_size);

  merge(a.data(), a.size(), b.data(), b.size(), own.data());
  std::merge(a.begin(), a.end(), b.begin(), b.end(), expected.begin());

  if (!std::is_sorted(own.begin(), own.end()) || own != expected) {
    std::cerr << "merge failed for seed " << seed
              << " and lengths " << a_size << ", " << b_size << '\n';
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
