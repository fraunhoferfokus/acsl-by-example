
#ifndef REMOVEIMPLIESNOTHASVALUE_SPEC_INCLUDED
#define REMOVEIMPLIESNOTHASVALUE_SPEC_INCLUDED

#include "Remove.spec"
#include "HasValue.spec"

/*@
  lemma RemoveImpliesNotHasValue{A,B}:
    \forall value_type *a, *b, v, integer n;
      Remove{A,B}(a, n, b, v) ==> !HasValue{B}(b, RemoveSize{A}(a, n, v), v);
*/

#endif /* REMOVEIMPLIESNOTHASVALUE_H_INCLUDED */
