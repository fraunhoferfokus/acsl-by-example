

#include "vector_io.h"
#include <fstream>
#include <cassert>

int main()
{
  std::vector<int> a{-3, 2};

  std::cout << a << std::endl;

  std::fstream file("data.txt");
  while (file) {
    std::vector<int> v;
    file >> v;
    if (file) {
      std::cout << v << std::endl;
    }
  }


  return EXIT_SUCCESS;
}

