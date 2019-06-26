
#ifndef SIZE_TYPE_PAIR_H_INCLUDED
#define SIZE_TYPE_PAIR_H_INCLUDED

#include "typedefs.h"

struct size_type_pair {
  size_type first;
  size_type second;
};

typedef struct size_type_pair size_type_pair;


/*@
    assigns \nothing;

    ensures \result.first  == first;
    ensures \result.second == second;
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

#endif // SIZE_TYPE_PAIR_H_INCLUDED

