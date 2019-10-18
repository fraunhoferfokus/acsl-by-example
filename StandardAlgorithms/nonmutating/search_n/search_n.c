
#include "search_n.h"

size_type
search_n(const value_type* a, size_type n, value_type v, size_type p)
{
  if (0u < p) {
    if (p <= n) {
      size_type start = 0u;

      /*@
        loop invariant match:     ConstantRange(a, start, i, v);
        loop invariant start:     0 < start ==> a[start-1] != v;
        loop invariant bound:     start <= i + 1 <= start + p;
        loop invariant not_found: !HasConstantSubRange(a, i, v, p);
        loop assigns i, start;
        loop variant n - i;
      */
      for (size_type i = 0u; i < n; ++i) {
        if (a[i] != v) {
          start = i + 1u;
          //@ assert not_found: !HasConstantSubRange(a, i+1, v, p);
        }
        else {
          //@ assert match: a[i] == v;
          //@ assert match: ConstantRange(a, start, i+1, v);
          if (p == i + 1u - start) {
            //@ assert bound: start + p == i + 1;
            //@ assert match: ConstantRange(a, start, start+p, v);
            //@ assert match: \exists integer k; 0 <= k <= n-p && ConstantRange(a, k, k+p, v);
            //@ assert match: HasConstantSubRange(a, n, v, p);
            return start;
          }
          else {
            //@ assert bound: i + 1 < start + p;
            continue;
          }
        }

        //@ assert not_found: !HasConstantSubRange(a, i+1, v, p);
      }

      //@ assert not_found: !HasConstantSubRange(a, n, v, p);
      return n;
    }
    else {
      //@ assert not_found: n < p;
      //@ assert not_found: !HasConstantSubRange(a, n, v, p);
      return n;
    }
  }
  else {
    //@ assert bound: p == 0;
    //@ assert match: ConstantRange(a, 0, 0, v);
    //@ assert match: HasConstantSubRange(a, n, v, 0);
    return 0u;
  }
}

