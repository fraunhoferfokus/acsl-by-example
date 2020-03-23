
#ifndef STACKLEMMAS_SPEC_INCLUDED
#define STACKLEMMAS_SPEC_INCLUDED

#include "Stack.spec"

/*@
  axiomatic StackLemmas
  {
    lemma StackPush_Equal{K,L}:
      \forall Stack *s, *t;
        StackEqual{K,K}(s,t)                     ==>
        StackSize{L}(s) == StackSize{K}(s) + 1   ==>
        StackSize{L}(s) == StackSize{L}(t)       ==>
        StackTop{L}(s)  == StackTop{L}(t)        ==>
        EqualRanges{L,L}(StackStorage{L}(s),
                         StackSize{K}(s),
                         StackStorage{L}(t))     ==>
        StackEqual{L,L}(s,t);
  }
*/

#endif /* STACKLEMMAS_SPEC_INCLUDED */

