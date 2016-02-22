
#include "remove_copy.h"
#include "RetainAllButOneLemmas.h"
#include "HasValueLemmas.h"

size_type remove_copy(const value_type* a, size_type n,
                      value_type* b, value_type v)
{
  size_type j = 0;

  /*@
    loop invariant bound:      0 <= j <= i <= n;
    loop invariant result:     j == i - Count(a, i, v);
    loop invariant retain:     RetainAllButOne(a, i, b, j, v);
    loop invariant discard:    !HasValue(b, j, v);
    loop invariant unchanged:  Unchanged{Here,Pre}(b, j, n);

    loop assigns i, j, b[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i) {
    /*@
       requires discard:    !HasValue(b, j, v);
       requires bound:      0 <= j <= i < n;
       assigns              j, b[j];
       ensures  bound:      0 <= j <= i+1 <= n;
       ensures  result:     j == i+1 - Count(a, i+1, v);
       ensures  discard:    !HasValue(b, \old(j), v);
       ensures  retain:     RetainAllButOne(a, i+1, b, j, v);
       ensures  unchanged:  Unchanged{Here,Pre}(b, j, n);

       behavior not_equal:
         assumes  a[i] != v;
         assigns  j, b[j];
         ensures  discard: j == \old(j) + 1;
         ensures  discard: b[\old(j)] == a[i];
         ensures  discard: b[\old(j)] != v;
         ensures  discard: !HasValue(b, \old(j), v);
         ensures  retain:  RetainAllButOne(a, i+1, b, j, v);

       behavior equal:
         assumes  a[i] == v;
         assigns  \nothing;
         ensures  discard: !HasValue(b, j, v);
         ensures  retain:  RetainAllButOne(a, i+1, b, j, v);

       complete behaviors;
       disjoint behaviors;
    */
    if (a[i] != v) {
      b[j++] = a[i];
    }
    //@ assert retain:    a[i] != v ==> RetainAllButOne(a, i+1, b, j, v);
    //@ assert discard:   a[i] != v ==> b[j-1] != v;
    //@ assert discard:   a[i] != v ==> !HasValue(b, j, v);
  }

  return j;
}

