

#include "Indexed.h"
#include <fstream>


int main()
{
  Indexed<int> a(-3, 2);

  std::cout << a << std::endl;

  std::fstream file("Indexed.txt");
  while (file) {
    Indexed<int> v;
    file >> v;
    if (file) {
      std::cout << v << std::endl;
    }
  }


  return EXIT_SUCCESS;
}

