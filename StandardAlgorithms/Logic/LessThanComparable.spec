
#ifndef LESSTHANCOMPARABLE_SPEC_INCLUDED
#define LESSTHANCOMPARABLE_SPEC_INCLUDED

#include "typedefs.h"

/*@
  axiomatic Less
  {
    lemma Less_Irreflexivity:
      \forall value_type a; !(a < a);

    lemma Less_Antisymmetry:
      \forall value_type a, b; (a < b)  ==>  !(b < a);

    lemma Less_Transitivity:
      \forall value_type a, b, c; (a < b) && (b < c)  ==>  (a < c);

    lemma Greater_Less:
      \forall value_type a, b; (a > b)  <==>  (b < a);

    lemma LessOrEqual_Less:
      \forall value_type a, b; (a <= b)  <==>  !(b < a);

    lemma GreaterOrEqual_Less:
    \forall value_type a, b; (a >= b)  <==> !(a < b);
  }
*/

#endif /* LESSTHANCOMPARABLE_SPEC_INCLUDED */

