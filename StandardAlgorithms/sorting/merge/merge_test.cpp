
#include "merge.h"

#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <functional>
#include <random>


int
main(int argc, char** argv)
{
  std::random_device r;
  std::seed_seq      seed{r(), r(), r(), r(), r(), r(), r(), r()};
  std::mt19937       eng(seed);
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
  std::vector<value_type> own_res(a_size + b_size);
  std::vector<value_type> std_res(a_size + b_size);
  merge(a.data(), a.size(), b.data(), b.size(), own_res.data());
  assert(std::is_sorted(own_res.begin(), own_res.end()));
  std::merge(a.begin(), a.end(), b.begin(), b.end(), std_res.begin());
  assert(own_res == std_res);
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

