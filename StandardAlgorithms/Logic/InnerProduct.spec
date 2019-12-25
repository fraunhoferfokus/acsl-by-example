
#ifndef INNERPRODUCT_SPEC_INCLUDED
#define INNERPRODUCT_SPEC_INCLUDED

#include "UnchangedSection.spec"

/*@
  axiomatic InnerProductAxiomatic
  {
    logic integer
      InnerProduct{L}(value_type* a, value_type* b, integer n,
                      value_type init) =
        n <= 0 ? init : InnerProduct(a, b, n-1, init) + (a[n-1] * b[n-1]);

    lemma
      InnerProductRead{K,L}:
        \forall value_type *a, *b, init, integer n;
          Unchanged{K,L}(a, n) ==>
            Unchanged{K,L}(b, n) ==>
              InnerProduct{K}(a, b, n, init) == InnerProduct{L}(a, b, n, init);
  }
*/

#endif /* INNERPRODUCT_SPEC_INCLUDED */

