
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include "create_graph.h"
#include "push_heap.h"

std::ostream& operator<<(std::ostream& stream, std::vector<int>& a)
{
  for (size_t i = 0; i < a.size(); ++i) {
    stream << '[' << i << ',' << a[i] << ']';
    if (i + 1 < a.size()) {
      stream << ", ";
    }
  }

  return stream;
}

int main()
{
  //std::vector<int> a = {12, 26, 3, 1, 7, 10, 25, 2, 19, 31, 13, 12, 38, 17, 34, 14, 25, 15, 1, 0, 2, 24, 18, 8, 3, 33, 4, 5, 28, 39, 6, 16, 23, 5, 30};
  std::vector<int> a;
  for (int i = 0; i < 70; ++i) {
    int tmp = rand() % 40;
    a.push_back(tmp);
  }
  //std::cout << a << std::endl;
  std::make_heap(a.begin(), a.end());
  a[7] = 29;
  std::make_heap(a.begin(), a.end());
  //std::cout << a << std::endl;
  a.push_back(38);
  push_heap(&a[0], a.size());

  return EXIT_SUCCESS;
}
