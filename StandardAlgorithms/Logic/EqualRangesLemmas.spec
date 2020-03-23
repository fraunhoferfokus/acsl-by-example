
#ifndef EQUALRANGESLEMMAS_SPEC_INCLUDED
#define EQUALRANGESLEMMAS_SPEC_INCLUDED

#include "EqualRanges.spec"
#include "Increasing.spec"
#include "Count.spec"

/*@
  axiomatic EqualRangeLemmas
  {
    lemma EqualRangesIncreasing{K,L}:
      \forall value_type* a, integer m, n, p;
        Increasing{K}(a, m, n)          ==>
        EqualRanges{K,L}(a, m, n, m+p)  ==>
        Increasing{L}(a, m+p, n+p);

    lemma EqualRangesCount{K,L}:
      \forall value_type *a, v, integer m, n, p;
        0 <= m <= n                   ==>
        EqualRanges{K,L}(a, m, n, p)  ==>
        Count{K}(a, m, n, v) == Count{L}(a, p, p + (n-m), v);
  }
*/

#endif /* EQUALRANGESLEMMAS_SPEC_INCLUDED */

