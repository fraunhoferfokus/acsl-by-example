
#ifndef STACKEQUALITY_SPEC_INCLUDED
#define STACKEQUALITY_SPEC_INCLUDED

#include "StackUtility.spec"
#include "EqualRanges.spec"

/*@
  axiomatic StackEquality
  {
    predicate
    StackEqual{S,T}(Stack* s, Stack* t) =
      StackSize{S}(s) == StackSize{T}(t) &&
      EqualRanges{S,T}(StackStorage{S}(s), StackSize{S}(s), StackStorage{T}(t));

    lemma StackEqualReflexive{S} :
      \forall Stack* s; StackEqual{S,S}(s, s);

    lemma StackEqualSymmetric{S,T} :
      \forall Stack *s, *t;
        StackEqual{S,T}(s, t)  ==>  StackEqual{T,S}(t, s);

    lemma StackEqualTransitive{S,T,U}:
      \forall Stack *s, *t, *u;
        StackEqual{S,T}(s, t)  ==>
        StackEqual{T,U}(t, u)  ==>
        StackEqual{S,U}(s, u);
  }
*/

#endif /* STACKEQUALITY_SPEC_INCLUDED */

