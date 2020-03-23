
#ifndef SOMECOUNT_SPEC_INCLUDED
#define SOMECOUNT_SPEC_INCLUDED

#include "SomeNone.spec"
#include "Count.spec"

/*@
  axiomatic Some_Count
  {
    lemma SomeEqual_Count{L}:
      \forall value_type *a, v, integer m, n;
        0 <= m < n             ==>
        SomeEqual(a, m, n, v)  ==>
        Count(a, m, n, v) > 0;

    lemma Count_SomeEqual{L}:
      \forall value_type *a, v, integer m, n;
        0 <= m < n             ==>
        Count(a, m, n, v) > 0  ==>
        SomeEqual(a, m, n, v);
  }
*/

#endif /* SOMECOUNT_SPEC_INCLUDED */

