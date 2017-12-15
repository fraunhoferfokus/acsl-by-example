
#ifndef PARTIAL_SORT_COPY_H_INCLUDED
#define PARTIAL_SORT_COPY_H_INCLUDED

#include "Sorted.h"
#include "Partition.h"
#include "MultisetUnchanged.h"



/*@
  // succeed if v is a member of a[0..m) \ b[0..n)
  predicate IsInComplement(value_type* a, integer m,
			   value_type* b, integer n,
			   value_type  v) =
    ( Count(b, n, v) < Count(a, m, v) );
*/

/*@
  // succeed if b[0..n) is a reordering of the least values in a[0..m)
  predicate IsLeastPartOf(value_type* a, integer m,
			  value_type* b, integer n) =
    ( \forall value_type v, w; 
	Count(b, n, v) > 0            ==>
	IsInComplement(a, m, b, n, w) ==>
	v <= w
    );
*/

/*@
  lemma ReorderPreservesLeastPart{K,L}:
    \forall value_type *a, *b, integer m, n;
      MultisetUnchanged{K,L}(b, n) ==>
              Unchanged{K,L}(a, m) ==>
      IsLeastPartOf{K}(a, m, b, n) ==>
      IsLeastPartOf{L}(a, m, b, n);
*/

/*@
  lemma TrivialLeastPart{L}:
    \forall value_type *a, *b, integer n;
      EqualRanges{L,L}(a, n, b) ==>
      IsLeastPartOf{L}(a, n, b, n);
*/

/*@
  requires valid: \valid_read(a + (0..m-1));
  requires valid: \valid     (b + (0..n-1));
  requires sep:   \separated(a+(0..m-1) , b+(0..n-1));
  requires        0 <= n <= m;		// for now

  assigns  b[0..n-1];

  ensures sorted:    Sorted(b, n);
  ensures subset:    IsLeastPartOf(a, m, b, n);
*/
void partial_sort_copy(const value_type* a, size_type m, 
                             value_type* b, size_type n);

#endif /* PARTIAL_SORT_COPY_H_INCLUDED */

