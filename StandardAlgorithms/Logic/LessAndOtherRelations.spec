
#ifndef LESSANDOTHERRELATIONS_SPEC_INCLUDED
#define LESSANDOTHERRELATIONS_SPEC_INCLUDED

#include "typedefs.h"

/*@
  lemma
    Greater:
      \forall value_type a, b; (a > b) <==> (b < a);

  lemma
    LessOrEqual:
      \forall value_type a, b; (a <= b) <==> !(b < a);

  lemma
    GreaterOrEqual:
      \forall value_type a, b; (a >= b) <==> !(a < b);
*/

#endif /* LESSANDOTHERRELATIONS_SPEC_INCLUDED */

