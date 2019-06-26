
#ifndef LESSTHANCOMPARABLE_SPEC_INCLUDED
#define LESSTHANCOMPARABLE_SPEC_INCLUDED

#include "typedefs.h"

/*@
  lemma
    LessIrreflexivity:
      \forall value_type a; !(a < a);

  lemma
    LessAntisymmetry:
      \forall value_type a, b; (a < b) ==> !(b < a);

  lemma
    LessTransitivity:
      \forall value_type a, b, c; (a < b) && (b < c) ==> (a < c);
*/

#endif /* LESSTHANCOMPARABLE_SPEC_INCLUDED */

