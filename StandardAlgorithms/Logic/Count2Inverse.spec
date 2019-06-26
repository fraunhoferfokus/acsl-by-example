
#ifndef COUNT2INVERSE_SPEC_INCLUDED
#define COUNT2INVERSE_SPEC_INCLUDED

#include "Count2.spec"

/*@
  lemma Count2Inverse:
    \forall value_type *a, v, integer n, sum;
      Count2(a, n, v, sum) ==>
        (n <= 0 && sum == 0) ||
        (0 < n && a[n-1] != v && Count2(a, n-1, v, sum)) ||
        (0 < n && a[n-1] == v && Count2(a, n-1, v, sum-1));
*/

#endif /* COUNT2INVERSE_SPEC_INCLUDED */

