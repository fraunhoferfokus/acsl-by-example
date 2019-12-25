
#ifndef MAKE_PAIR_H_INCLUDED
#define MAKE_PAIR_H_INCLUDED

#include "SizeTypePairTrivial.spec"

/*@
    assigns         \nothing;
    ensures result: \result.first  == first;
    ensures result: \result.second == second;
*/
static inline
size_type_pair
make_pair(size_type first, size_type second)
{
  size_type_pair pair;

  pair.first  = first;
  pair.second = second;

  return pair;
}

#endif /* MAKE_PAIR_H_INCLUDED */

