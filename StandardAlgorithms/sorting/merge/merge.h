
#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

#include "IncreasingLemmas.acsl"
#include "Unchanged.acsl"


/*@
  requires bound:        m + n <= SIZE_TYPE_MAX;
  requires valid:        \valid_read(a + (0..m-1));
  requires valid:        \valid_read(b + (0..n-1));
  requires valid:        \valid(c + (0..m+n-1));
  requires sep:          \separated(a + (0..m-1), c + (0..m+n-1));
  requires sep:          \separated(b + (0..n-1), c + (0..m+n-1));
  requires increasing:   Increasing(a, m);
  requires increasing:   Increasing(b, n);
  assigns                c[0 .. m+n-1];
  ensures  increasing:   Increasing(c, m + n);
  ensures  unchanged:    Unchanged{Old,Here}(a, m);
  ensures  unchanged:    Unchanged{Old,Here}(b, n);
 */
void
merge(const value_type* a, size_type m,
      const value_type* b, size_type n, value_type* c);


#endif /* MERGE_H_INCLUDED */

