
#ifndef CLAMP_H_INCLUDED
#define CLAMP_H_INCLUDED

#include "typedefs.h"

/*@
  requires bound: lower < upper;

  assigns \nothing;

  ensures bound: lower <= \result <= upper;

  behavior lower_bound:
    assumes v < lower;
    assigns \nothing;
    ensures result: \result == lower;

  behavior between:
    assumes lower <= v <= upper;
    assigns \nothing;
    ensures result: \result == v;

  behavior upper_bound:
    assumes upper < v;
    assigns \nothing;
    ensures result: \result == upper;

  complete behaviors lower_bound, upper_bound, between;
  disjoint behaviors lower_bound, upper_bound, between;
*/
value_type
clamp(value_type v, value_type lower, value_type upper);

#endif /* CLAMP_H_INCLUDED */

