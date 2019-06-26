
#ifndef UNIQUEPRESERVE_SPEC_INCLUDED
#define UNIQUEPRESERVE_SPEC_INCLUDED

#include "Unique.spec"
#include "UniqueSizeBound.spec"
#include "UniquePartitionLemmas.spec"
#include "UnchangedSection.spec"

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

#endif /* UNIQUEPRESERVE_SPEC_INCLUDED */

