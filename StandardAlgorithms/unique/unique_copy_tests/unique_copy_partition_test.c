
#include "unique_copy_partition_test.h"
#include <fstream>

int main(int argc, char** argv)
{
  assert(argc == 2);
  std::fstream file(argv[1]);

  while (true) {
    std::vector<int> v;
    file >> v;
    if (file) {
      // std::cout << v << std::endl;
      unique_copy_partition_test(v);
    }
    else {
      break;
    }
  }

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";

  return EXIT_SUCCESS;
}

