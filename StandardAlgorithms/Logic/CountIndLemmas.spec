
#ifndef COUNTINDINVERSE_SPEC_INCLUDED
#define COUNTINDINVERSE_SPEC_INCLUDED

#include "CountIndImplicit.spec"
#include "Count.spec"

/*@
  axiomatic CountIndLemmas
  {
    lemma CountInd_Inverse:
      \forall value_type *a, v, integer n, sum;
        CountInd(a, n, v, sum)  ==>
          (n <= 0 && sum == 0) ||
          (0 < n && a[n-1] != v && CountInd(a, n-1, v, sum)) ||
          (0 < n && a[n-1] == v && CountInd(a, n-1, v, sum-1));

    lemma CountInd_NonNegative{L}:
      \forall value_type *a, v, integer n, sum;
        CountInd(a, n, v, sum)  ==>  0 <= sum;

    lemma CountInd_Count{L}:
      \forall value_type *a, v, integer n;
        CountInd(a, n, v, Count(a, n, v));
  }
*/

#endif /* COUNTINDINVERSE_SPEC_INCLUDED */

