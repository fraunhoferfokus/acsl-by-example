
#ifndef ADJACENTDIFFERENCEINVERSE_H_INCLUDED
#define ADJACENTDIFFERENCEINVERSE_H_INCLUDED

#include "PartialSumLemmas.h"
#include "AdjacentDifferenceLemmas.h"

/*@
  lemma AdjacentDifferenceInverse{K,L}:
    \forall  value_type *a, *b, integer n;
      0 <= n                          ==> 
      AdjacentDifference{K}(a, n, b)  ==>
      Unchanged{K,L}(b, n)            ==>
      PartialSum{L}(b, n, a)          ==>
      Unchanged{K,L}(a, n);
*/

#endif /* ADJACENTDIFFERENCEINVERSE_H_INCLUDED */

