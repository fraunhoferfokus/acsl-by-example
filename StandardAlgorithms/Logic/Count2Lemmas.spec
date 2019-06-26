
#ifndef COUNT2LEMMAS_SPEC_INCLUDED
#define COUNT2LEMMAS_SPEC_INCLUDED

#include "Count2.spec"
#include "UnchangedSection.spec"

/*@
  axiomatic Count2ImplicitAxiomatic {
    lemma
      Count2Empty{L}:
        \forall value_type *a, v, integer n;
          n <= 0 ==> Count2(a, n, v, 0);

    lemma
      Count2Miss{L}:
        \forall value_type *a, v, integer n, sum;
          0 < n ==> a[n-1] != v ==>
            (Count2(a, n-1, v, sum) ==> Count2(a, n, v, sum));

    lemma
      Count2Hit{L}:
        \forall value_type *a, v, integer n, sum;
          0 < n ==> a[n-1] == v ==>
            (Count2(a, n-1, v, sum) ==> Count2(a, n, v, sum+1));

    lemma
      Count2Read{K,L}:
        \forall value_type *a, v, integer n, sum;
          Unchanged{K,L}(a, n) ==>
            (Count2{K}(a, n, v, sum) <==> Count2{L}(a, n, v, sum));

  }
*/

#endif /* COUNT2LEMMAS_SPEC_INCLUDED */
