
#ifndef COUNTINDIMPLICIT_SPEC_INCLUDED
#define COUNTINDIMPLICIT_SPEC_INCLUDED

#include "CountInd.spec"
#include "UnchangedLemmas.spec"

/*@
  axiomatic CountIndImplicit
  {
    lemma CountInd_Empty{L}:
      \forall value_type *a, v, integer n;
       n <= 0  ==>  CountInd(a, n, v, 0);

    lemma CountInd_Hit{L}:
      \forall value_type *a, v, integer n, sum;
        0 < n                     ==>
        a[n-1] == v               ==>
        CountInd(a, n-1, v, sum)  ==>
        CountInd(a,   n, v, sum+1);

    lemma CountInd_Miss{L}:
      \forall value_type *a, v, integer n, sum;
        0 < n                     ==>
        a[n-1] != v               ==>
        CountInd(a, n-1, v, sum)  ==>
        CountInd(a,   n, v, sum);

    lemma CountInd_Read{K,L}:
      \forall value_type *a, v, integer n, sum;
        Unchanged{K,L}(a, n)  ==>
        (CountInd{K}(a, n, v, sum)  <==>  CountInd{L}(a, n, v, sum));
  }
*/

#endif /* COUNTINDIMPLICIT_SPEC_INCLUDED */
