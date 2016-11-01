
#include "remove_copy2.h"
#include "remove_copy_aux.h"
#include "UnchangedStep.h"
#include "MultisetRetainRestUnchanged.h"

size_type
remove_copy(const value_type* a, size_type n, value_type* b, value_type v)
{
  size_type j = 0;

  /*@
    loop invariant bound:      0 <= j <= i <= n;
    loop invariant size:       j == RemoveCount{Pre}(a, i, v);
    loop invariant discard:    !HasValue(b, j, v);
    loop invariant retain:     MultisetRetainRest{Pre,Here}(a, i, b, j, v);
    loop invariant mapping:    RemoveMapping{Here,Here}(a, i, b, v);
    loop invariant unchanged:  Unchanged{Pre,Here}(b, j, n);

    loop assigns i, j, b[0..n-1];
    loop variant n-i;
  */
  for (size_type i = 0; i < n; ++i) {
    j = remove_copy_aux(a, n, i, b, j, v);
  }

  //@ assert size:    j == RemoveCount{Pre}(a, n, v);
  //@ assert retain:  MultisetRetainRest{Pre,Here}(a, n, b, j, v);
  //@ assert retain:  MultisetRetainRest{Here,Here}(a, n, b, j, v);
  return j;
}

