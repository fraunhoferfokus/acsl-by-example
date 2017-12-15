
#ifndef STACKPUSHEQUAL_H_INCLUDED
#define STACKPUSHEQUAL_H_INCLUDED

#include "StackEqual.h"

/*@
  lemma
    StackPushEqual{K,L}:
      \forall Stack *s, *t;
         Equal{K,K}(s,t)              ==>
         Size{L}(s) == Size{K}(s) + 1 ==>
         Size{L}(s) == Size{L}(t)     ==>
         Top{L}(s)  == Top{L}(t)      ==>
         EqualRanges{L,L}(Storage{L}(s), Size{K}(s), Storage{L}(t)) ==>
         Equal{L,L}(s,t);
*/

#endif /* STACKPUSHEQUAL_H_INCLUDED */

