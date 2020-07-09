
#include "merge.h"
#include "copy.h"
#include "IncreasingLemmas.acsl"
#include "WeaklyIncreasingLemmas.acsl"

void
merge(const value_type* a, size_type m,
      const value_type* b, size_type n, value_type* c)
{
  size_type i = 0;
  size_type j = 0;
  size_type x = 0;

  if (0 < m || 0 < n) {
    /*@ loop invariant increasing:  0 <= i <= m;
        loop invariant increasing:  0 <= j <= n;
        loop invariant increasing:  x == i+j;
        loop invariant increasing:  0 <= x <= m+n-1;
        loop invariant increasing:  \forall integer k;
                                    0 <= k < x ==> i < m  ==>  c[k] <= a[i];
        loop invariant increasing:  \forall integer k;
                                    0 <= k < x ==> j < n  ==>  c[k] <= b[j];
        loop invariant increasing:  WeaklyIncreasing(c, x);
        loop assigns i, j, x, c[0 .. m+n-1];
        loop variant (m+n) - (i+j);
     */
    while (i < m && j < n) {
      if (a[i] < b[j]) {
        c[x++] = a[i++];
      }
      else {
        c[x++] = b[j++];
      }
    }

    //@ assert increasing:  i == m  ^^  j == n;
    //@ assert increasing:  i <  m  ^^  j <  n;
    //@ assert increasing:  WeaklyIncreasing(c, 0, x);

    if (i < m) {
      //@ assert increasing:  0 < x  ==>  c[x-1] <= a[i];
      //@ assert increasing:  WeaklyIncreasing(a+i, 0, m-i);
      copy(a + i, m - i, c + x);
      //@ assert increasing:  c[x] == a[i];
      /*@ assert increasing:  WeaklyIncreasing(a+i, 0, m-i)             ==>
                              EqualRanges{Here,Here}(a+i, 0, m-i, c+x)  ==>
                              WeaklyIncreasing(c+x, 0, m-i);
       */
      //@ assert increasing:  m-i+x == m+n;
    }
    else {
      //@ assert increasing:  0 < x  ==>  c[x-1] <= b[j];
      //@ assert increasing:  WeaklyIncreasing(b, 0, n);
      //@ assert increasing:  WeaklyIncreasing(b+j, 0, n-j);
      copy(b + j, n - j, c + x);
      //@ assert increasing:  c[x] == b[j];
      /*@ assert increasing:  WeaklyIncreasing(b+j, 0, n-j)             ==>
                              EqualRanges{Here,Here}(b+j, 0, n-j, c+x)  ==>
                              WeaklyIncreasing(c+x, 0, n-j);
       */
      //@ assert increasing:  n-j+x == m+n;
    }

    //@ assert increasing:  WeaklyIncreasing(c, x, m+n);
    //@ assert increasing:  0 < x  ==>  c[x-1] <= c[x];
    //@ assert increasing:  0 < x  ==>  WeaklyIncreasing(c, x-1, m+n);
    //@ assert increasing:  WeaklyIncreasing(c, 0, m+n);
  }
  else {
    return;
  }
}

