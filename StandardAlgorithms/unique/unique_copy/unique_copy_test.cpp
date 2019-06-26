
#include "unique_copy_compare_test.h"
#include <fstream>

int
main(int argc, char** argv)
{
  assert(argc == 2);
  std::fstream file(argv[1]);

  while (true) {
    std::vector<int> input, expected;
    file >> input;
    file >> expected;

    if (file) {
      // std::cout << input    << "\t" << expected << std::endl;
      unique_copy_compare_test(input, expected);
    }
    else {
      break;
    }
  }

  std::cout << "\tsuccessful execution of " << argv[0] << "\n";
  return EXIT_SUCCESS;
}

