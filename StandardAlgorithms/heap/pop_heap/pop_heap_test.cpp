
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cassert>
#include "pop_heap.h"
#include "../is_heap/is_heap.h"

void pop_heap_compare(std::vector<value_type>& a)
{
  assert(is_heap(a.data(), a.size()));
  assert(std::is_heap(a.begin(), a.end()));

  auto b = a;

  std::pop_heap(a.begin(), a.end());
  pop_heap(b.data(), b.size());

  assert(a == b);
}

int main(int argc, char** argv)
{
  // some heap
  {
    std::vector<value_type> a(10);
    std::iota(a.begin(), a.end(), 0);
    std::make_heap(a.begin(), a.end());

    pop_heap_compare(a);
  }

  // heap of length 1
  {
    std::vector<value_type> a(1);
    pop_heap_compare(a);
  }

  // heap of length 2
  {
    std::vector<value_type> a{3, 1};
    pop_heap_compare(a);
  }

  // heap of length 3
  {
    std::vector<value_type> a{3, 1, 3};
    pop_heap_compare(a);
  }

  // another heap of length 3
  {
    std::vector<value_type> a{3, 3, 1};
    pop_heap_compare(a);
  }

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
}

