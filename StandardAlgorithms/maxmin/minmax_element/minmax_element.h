
#ifndef MINMAX_ELEMENT_H_INCLUDED
#define MINMAX_ELEMENT_H_INCLUDED

#include "SizeTypePairTrivial.spec"
#include "ArrayExtrema.spec"

/*@
  requires valid:    \valid_read(a + (0..n-1));
  assigns            \nothing;
  ensures result:    0 <= \result.first  <= n;
  ensures result:    0 <= \result.second <= n;

  behavior empty:
    assumes          0 == n;
    assigns          \nothing;
    ensures result:  \result.first == 0;
    ensures result:  \result.second == 0;

  behavior not_empty:
    assumes          0 < n;
    assigns          \nothing;
    ensures result:  0 <= \result.first < n;
    ensures result:  0 <= \result.second < n;

    ensures min:     MinElement(a, n, \result.first);
    ensures first:   StrictLowerBound(a, \result.first, a[\result.first]);
    ensures max:     MaxElement(a, n, \result.second);
    ensures last:    StrictUpperBound(a, \result.second+1, n, a[\result.second]);
*/
size_type_pair
minmax_element(const value_type* a, size_type n);

#endif /* MINMAX_ELEMENT_H_INCLUDED */

