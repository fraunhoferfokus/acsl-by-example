
#ifndef CLAMP_H_INCLUDED
#define CLAMP_H_INCLUDED

#include "typedefs.h"

/*@
  requires   bound:  lower < upper;

  terminates         \true;
  exits              \false;
  assigns            \nothing;

  ensures    bound:  lower <= \result <= upper;

  behavior lower_bound:
    assumes          v < lower;
    ensures result:  \result == lower;

  behavior between:
    assumes          lower <= v <= upper;
    ensures result:  \result == v;

  behavior upper_bound:
    assumes          upper < v;
    ensures result:  \result == upper;

  complete behaviors;
  disjoint behaviors;
*/
value_type clamp(value_type v, value_type lower, value_type upper);

#endif /* CLAMP_H_INCLUDED */

