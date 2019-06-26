
#ifndef INNER_PRODUCT_H_INCLUDED
#define INNER_PRODUCT_H_INCLUDED

#include "InnerProduct.spec"
#include "InnerProductBounds.spec"
#include "Unchanged.spec"

/*@
  requires valid:   \valid_read(a + (0..n-1));
  requires valid:   \valid_read(b + (0..n-1));
  requires bounds:  ProductBounds(a, b, n);
  requires bounds:  InnerProductBounds(a, b, n, init);

  assigns \nothing;

  ensures result:    \result == InnerProduct(a, b, n, init);
  ensures unchanged: Unchanged{Old,Here}(a, n);
  ensures unchanged: Unchanged{Old,Here}(b, n);
*/
value_type
inner_product(const value_type* a, const value_type* b, size_type n,
              value_type init);

#endif /* INNER_PRODUCT_H_INCLUDED */

