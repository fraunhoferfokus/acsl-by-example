
#ifndef UNIQUEPRESERVE_LOGIC_H_INCLUDED
#define UNIQUEPRESERVE_LOGIC_H_INCLUDED

#include "Unique.h"
#include "UniqueSizeBound.h"
#include "UniquePartitionLemmas.h"
#include "UnchangedSection.h"

/*@
  lemma UniquePreserve{K,L}:
    \forall value_type *a, *b, integer i, k, n; 
      0 <= k <= i < n          ==>
      k == UniqueSize{L}(a, i) ==>
      Unique{K}(a, i, b)       ==>
      Unchanged{K,L}(b, k)     ==>
      Unchanged{K,L}(a, n)     ==>
      Unique{L}(a, i, b);
*/

#endif /* UNIQUEPRESERVE_LOGIC_H_INCLUDED */

