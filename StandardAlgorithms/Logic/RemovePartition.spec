
#ifndef REMOVEPARTITION_SPEC_INCLUDED
#define REMOVEPARTITION_SPEC_INCLUDED

#include "CountFindNotEqual.spec"

/*@
  axiomatic RemovePartition
  {
    logic integer
    NextNotEqual(value_type* a, integer x, integer n, value_type v) =
      x + FindNotEqual(a, x, n, v);

    logic integer
    RemovePartition(value_type* a, integer n, value_type v, integer p) =
      \let c = CountNotEqual(a, n, v);
      \let x = RemovePartition(a, n, v, p-1) + 1;
        p < 0 ? -1 : // 0 <= p
          (n <= 0 ? 0 : // 0 < n
            p < c ? NextNotEqual(a, x, n, v) : n
          );

    lemma RemovePartition_Empty:
      \forall value_type *a, v, integer n, p;
        n <= 0 <= p  ==>
        RemovePartition(a, n, v, p) == 0;

    lemma RemovePartition_Left:
      \forall value_type *a, v, integer n, p;
        p < 0  ==>  RemovePartition(a, n, v, p) == -1;

    lemma RemovePartition_Right:
      \forall value_type *a, v, integer n, p;
        0 <= n                       ==>
        CountNotEqual(a, n, v) <= p  ==>  RemovePartition(a, n, v, p) == n;

    lemma RemovePartition_Next:
      \forall value_type *a, v, integer n, p;
        \let x = RemovePartition(a, n, v, p-1) + 1;
        0 <= n                           ==>
        0 <= p < CountNotEqual(a, n, v)  ==> 
        RemovePartition(a, n, v, p) == x + FindNotEqual(a, x, n, v);

    lemma RemovePartition_Lower:
      \forall value_type *a, v, integer i, n, p;
        0 < n                            ==>
        0 <= p < CountNotEqual(a, n, v)  ==>
        0 <= RemovePartition(a, n, v, p);

    lemma RemovePartition_Core:
      \forall value_type *a, v, integer i, n, p;
        \let R = RemovePartition(a, n, v, p);
        0 < n                            ==>
        0 <= p < CountNotEqual(a, n, v)  ==>
        (R < n      &&
         a[R] != v  &&
         CountNotEqual(a, R, n, v) == CountNotEqual(a, 0, n, v) - p);

    lemma RemovePartition_Upper:
      \forall value_type *a, v, integer i, n, p;
        0 < n                            ==>
        0 <= p < CountNotEqual(a, n, v)  ==>
        RemovePartition(a, n, v, p) < n;

    lemma RemovePartition_NotEqual:
      \forall value_type *a, v, integer n, p;
        0 < n  ==>
        0 <= p < CountNotEqual(a, n, v) < n  ==>
        a[RemovePartition(a, n, v, p)] != v;

    lemma RemovePartition_Count:
      \forall value_type *a, v, integer n, p;
        0 < n                            ==>
        0 <= p < CountNotEqual(a, n, v)  ==>
        CountNotEqual(a, RemovePartition(a, n, v, p), n, v) ==
        CountNotEqual(a, 0, n, v) - p;

    lemma RemovePartition_StrictlyWeakIncreasing:
      \forall value_type *a, v, integer n, p;
        0 < n                           ==>
        0 < p < CountNotEqual(a, n, v)  ==>
        RemovePartition(a, n, v, p-1) < RemovePartition(a, n, v, p);

    lemma RemovePartition_StrictlyIncreasing:
      \forall value_type *a, v, integer n, p, q;
        0 < n                           ==>
        0 <= p < q < CountNotEqual(a, n, v)  ==>
        RemovePartition(a, n, v, p) < RemovePartition(a, n, v, q);

    lemma RemovePartition_Segment:
      \forall value_type *a, v, integer i, n, p;
        0 < n                            ==>
        0 < p <= CountNotEqual(a, n, v)  ==>
          AllEqual(a, RemovePartition(a, n, v, p-1) + 1,
                      RemovePartition(a, n, v, p), v);

    lemma RemovePartition_Extend:
      \forall value_type *a, v, integer n, p;
        0 < n                            ==>
        0 <= p < CountNotEqual(a, n, v)  ==>
        RemovePartition(a, n, v, p) == RemovePartition(a, n+1, v, p);

    lemma RemovePartition_Read{K,L}:
      \forall value_type *a, v, integer n, p;
        Unchanged{K,L}(a, n)  ==>
        RemovePartition{K}(a, n, v, p) == RemovePartition{L}(a, n, v, p);
  }  
*/

#endif /* REMOVEPARTITION_H_INCLUDED */

