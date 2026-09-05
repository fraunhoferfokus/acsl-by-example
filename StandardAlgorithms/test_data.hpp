
#ifndef TEST_DATA_HPP_INCLUDED
#define TEST_DATA_HPP_INCLUDED

#include "typedefs.h"
#include <vector>

// Test data shared by the example tests.
//
// The file is a .hpp on purpose: the book collects its sources with
// "find ... -name '*.h' -o -name '*.c'" (Tutorial/Makefile), so a .h here
// would be flattened into the listings and fed to the LaTeX macro generator.
// Sorting/sort_test.hpp is kept out of the book for the same reason.


// The array that most of the older tests used, kept so that their cases stay
// recognisable.
inline std::vector<value_type> sample_array()
{
  return std::vector<value_type> {1, 2, 3, 3, 3, 7, 8};
}


// The arrays every algorithm over one array is run on: the empty array
// first -- the case every contract admits and no proof may skip -- then the
// shapes that separate a correct implementation from a plausible one: a
// single element, two in either order, all elements equal, runs of equal
// elements, and the sample array above.
inline std::vector<std::vector<value_type>> test_arrays()
{
  return std::vector<std::vector<value_type>> {
    {},
    {1},
    {1, 1},
    {1, 5},
    {5, 1},
    {3, 3, 3},
    {1, 2, 3, 3, 3, 7, 8},
    {0, 4, 4, 4, 5, 4, 4, 4, 4},
    {8, 2, 43, 4, 43, 6, 7}
  };
}


// A value that occurs in several of those arrays, and one that occurs in
// none of them: together they reach both the found and the not-found branch
// of every search algorithm.
inline value_type present_value()
{
  return 3;
}


inline value_type absent_value()
{
  return 99;
}

#endif /* TEST_DATA_HPP_INCLUDED */
