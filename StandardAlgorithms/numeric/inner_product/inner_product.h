
#ifndef INNER_PRODUCT_H_INCLUDED
#define INNER_PRODUCT_H_INCLUDED

#include "InnerProductAxiomatic.h"
#include "limits.h"

/*@
    requires valid_a: \valid_read(a + (0..n-1));
    requires valid_b: \valid_read(b + (0..n-1));
    requires bounds:  \forall integer i; 0 <= i < n ==>
                   INT_MIN <= a[i] * b[i] <= INT_MAX;
    requires bounds:  \forall integer i; 0 <= i <= n ==>
                   INT_MIN <= InnerProduct(a, b, i, init) <= INT_MAX;

    assigns \nothing;

    ensures result:    \result == InnerProduct(a, b, n, init);
    ensures unchanged: EqualRanges{Here,Pre}(a, n);
    ensures unchanged: EqualRanges{Here,Pre}(b, n);
*/
value_type
inner_product(const value_type* a, const value_type* b, size_type n,
              value_type init);

#endif /* INNER_PRODUCT_H_INCLUDED */
