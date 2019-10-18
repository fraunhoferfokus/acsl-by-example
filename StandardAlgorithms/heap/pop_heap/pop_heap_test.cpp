
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <cassert>
#include "pop_heap.h"
#include "is_heap.h"
#include "../../support/vector_io.h"

void
pop_heap_compare(std::vector<value_type> a)
{
  assert(is_heap(a.data(), a.size()));
  assert(std::is_heap(a.begin(), a.end()));
  auto b = a;
  std::pop_heap(a.begin(), a.end());
  pop_heap(b.data(), b.size());
  assert(a.back() == b.back());
  std::sort(a.begin(), a.end() - 1); // sort initial segement
  std::sort(b.begin(), b.end() - 1); // to account for different heap presentations

  if (a != b) {
    std::cout << "std::pop_heap = " << a << std::endl;
    std::cout << "     pop_heap = " << b << std::endl;
    assert(false);
  }
}

int
main(int argc, char** argv)
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
  // another heap
  {
    std::vector<value_type> a{3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1};
    pop_heap_compare(a);
  }
  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
}

