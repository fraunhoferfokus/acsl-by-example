
#ifndef STACKEQUIVALENCE_H_INCLUDED
#define STACKEQUIVALENCE_H_INCLUDED

#include "StackEqual.h"

/*@
  lemma
    StackEqualReflexive{S} :
      \forall Stack* s; Equal{S,S}(s, s);

  lemma
    StackEqualSymmetric{S,T} :
      \forall Stack *s, *t;
        Equal{S,T}(s, t) ==> Equal{T,S}(t, s);

  lemma
    StackEqualTransitive{S,T,U}:
      \forall Stack *s, *t, *u;
        Equal{S,T}(s, t) && Equal{T,U}(t, u) ==> Equal{S,U}(s, u);
*/ 

#endif /* STACKEQUIVALENCE_H_INCLUDED */

