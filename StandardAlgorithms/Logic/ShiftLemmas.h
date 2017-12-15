#ifndef SHIFTLEMMAS_H_INCLUDED
#define SHIFTLEMMAS_H_INCLUDED

#include "Sorted.h"
#include "LowerBound.h"
#include "StrictLowerBound.h"
#include "StrictUpperBound.h"
#include "UpperBound.h"

/*@ 
  lemma
    SortedShift{L}:
      \forall value_type *a, integer l, r;
      0 <= l <= r  ==>  Sorted{L}(a, l, r)  ==>  Sorted{L}(a+l, r-l);

  lemma
    LowerBoundShift{L}:
      \forall value_type *a, val, integer b, c, d;
        LowerBound{L}(a+b, c,   d,   val)  ==>
        LowerBound{L}(a,   c+b, d+b, val);

  lemma
    StrictLowerBoundShift{L}:
      \forall value_type *a, val, integer b, c, d;
        StrictLowerBound{L}(a+b, c,   d,   val)  ==>
        StrictLowerBound{L}(a,   c+b, d+b, val);

  lemma
    UpperBoundShift{L}:
    \forall value_type *a, val, integer b, c;
      UpperBound{L}(a+b,  0, c-b, val)  ==>
      UpperBound{L}(a,    b, c,   val);

  lemma
    StrictUpperBoundShift{L}:
      \forall value_type *a, val, integer b, c;
        StrictUpperBound{L}(a+b, 0, c-b, val)  ==>
        StrictUpperBound{L}(a,   b, c,   val);
*/

#endif /* SHIFTLEMMAS_H_INCLUDED */
