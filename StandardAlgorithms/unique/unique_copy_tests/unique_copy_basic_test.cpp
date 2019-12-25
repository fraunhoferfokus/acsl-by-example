
#include "unique_copy_basic_test.h"
#include <fstream>
#include <cassert>


int main(int argc, char** argv)
{
  assert(argc == 2);
  std::fstream file(argv[1]);
  std::vector<int> v;

  while (true) {
    file >> v;
    if (file) {
      // std::cout << v << std::endl;
      unique_copy_basic_test(v);
      v.clear();
    }
    else {
      break;
    }
  }

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

