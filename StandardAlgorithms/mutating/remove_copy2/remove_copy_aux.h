
#ifndef REMOVE_COPY_AUX_H_INCLUDED
#define REMOVE_COPY_AUX_H_INCLUDED

#include "RemoveCountLemmas.h"
#include "MultisetRetainRestMiss.h"

/*@
  requires valid:    \valid_read(a + (0..n-1));
  requires valid:    \valid(b + (0..n-1));
  requires sep:      \separated(a + (0..n-1), b+(0..n-1));
  requires bound:    0 <= i < n;
  requires bound:    0 <= j < n;
  requires size:     j == RemoveCount(a, i, v);
  requires discard:  !HasValue(b, j, v);
  requires retain:   MultisetRetainRest{Here,Here}(a, i, b, j, v);
  requires mapping:  RemoveMapping{Here,Here}(a, i, b, v);

  assigns  b[j];

  ensures bound:      0 <= \result <= n;
  ensures size:       \result == RemoveCount(a, i+1, v);
  ensures discard:    !HasValue(b, \result, v);
  ensures retain:     MultisetRetainRest{Old,Here}(a, i+1, b, \result, v);
  ensures mapping:    RemoveMapping{Old,Here}(a, i+1, b, v);
  ensures unchanged:  Unchanged{Old,Here}(b, \result, n);

  behavior active:
    assumes a[i] != v;
    assigns b[j];
    ensures retain:  b[\old(j)] == a[i];

  behavior passive:
    assumes a[i] == v;
    assigns \nothing;

  complete behaviors;
  disjoint behaviors;
*/
static inline size_type
remove_copy_aux(const value_type* a, size_type n, size_type i,
                value_type* b, size_type j, value_type v)
{
  //@ assert retain:  MultisetRetainRest{Pre,Here}(a, i, b, j, v);
  if (a[i] != v) {
    b[j] = a[i];
    //@ assert size:        j+1 == RemoveCount(a, i+1, v);
    //@ assert mapping:     RemoveMapping{Pre,Here}(a, i+1, b, v);
    //@ assert retain_pre:  MultisetRetainRest{Pre,Here}(a, i,   b, j,   v);
    //@ assert retain_now:  MultisetRetainRest{Pre,Here}(a, i+1, b, j+1, v);
    return j + 1;
  }
  else {
    //@ assert size:     j == RemoveCount(a, i+1, v);
    //@ assert retain:   MultisetRetainRest{Pre,Here}(a, i+1, b, j, v);
    //@ assert mapping:  RemoveMapping{Pre,Here}(a, i+1, b, v);
    return j;
  }
}


#endif /* REMOVE_COPY_AUX_H_INCLUDED */

