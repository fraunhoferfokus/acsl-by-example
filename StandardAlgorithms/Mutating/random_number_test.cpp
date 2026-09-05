
#include <cassert>
#include <cstdlib>
#include <vector>

#include "random_number.h"

// random_init installs a fixed seed, so everything here is deterministic:
// the same sequence is drawn on every run.
int main(int, char**)
{
  // The contract promises 0 <= \result < n for every admissible n.
  for (size_type n = 1; n <= 100; ++n) {
    unsigned short state[3];
    random_init(state);

    for (int draw = 0; draw < 100; ++draw) {
      assert(random_number(state, n) < n);
    }
  }

  // n == 1 leaves no choice.
  {
    unsigned short state[3];
    random_init(state);

    for (int draw = 0; draw < 10; ++draw) {
      assert(random_number(state, 1) == 0);
    }
  }

  // The same seed yields the same sequence, and the generator does not get
  // stuck on one value.
  {
    unsigned short first_state[3];
    unsigned short second_state[3];
    random_init(first_state);
    random_init(second_state);

    std::vector<size_type> drawn;

    for (int draw = 0; draw < 100; ++draw) {
      const size_type r = random_number(first_state, 1000);
      assert(r == random_number(second_state, 1000));
      drawn.push_back(r);
    }

    bool all_equal = true;

    for (const size_type r : drawn) {
      all_equal = all_equal && (r == drawn.front());
    }

    assert(!all_equal);
  }

  return EXIT_SUCCESS;
}
