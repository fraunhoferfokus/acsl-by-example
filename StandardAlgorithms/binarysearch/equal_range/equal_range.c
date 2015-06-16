
#include "binarysearch.h"

/*@
    assigns \nothing;

    ensures \result.first  == first;
    ensures \result.second == second;
*/
size_type_pair make_pair(size_type first, size_type second)
{
  size_type_pair pair;
  pair.first  = first;
  pair.second = second;

  return pair;
}

size_type_pair
equal_range(const value_type* a, size_type n, value_type val)
{
  size_type first  = lower_bound(a, n, val);
  size_type second = upper_bound(a, n, val);
  //@ assert aux: second < n  ==>  val < a[second];

  return make_pair(first, second);
}

