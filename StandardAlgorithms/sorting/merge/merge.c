
#include "merge.h"
#include "copy.h"
#include "At.acsl"
#include "IncreasingLemmas.acsl"
#include "WeaklyIncreasingLemmas.acsl"

void
merge(const value_type* a, size_type m,
      const value_type* b, size_type n, value_type* c)
{
  //@ assert increasing:  WeaklyIncreasing(a, 0, m);
  size_type i = 0;
  size_type j = 0;
  size_type x = 0;

  if (0 < m || 0 < n) {
    /*@ loop invariant index:       0 <= i <= m;
        loop invariant index:       0 <= j <= n;
        loop invariant index:       x == i+j;
        loop invariant index:       0 <= x <= m+n-1;
        loop invariant upper:       i < m  ==>  UpperBound(c, 0, x, a[i]);
        loop invariant upper:       j < n  ==>  UpperBound(c, 0, x, b[j]);
        loop invariant increasing:  WeaklyIncreasing(c, x);
        loop assigns i, j, x, c[0 .. m+n-1];
        loop variant (m+n) - (i+j);
     */
    while (i < m && j < n) {
      if (a[i] < b[j]) {
        c[x++] = a[i++];
        //@ assert increasing:  WeaklyIncreasing(c, 0, x);
        //@ assert upper:       i < m  ==>  UpperBound(c, 0, x, a[i]);
      }
      else {
        c[x++] = b[j++];
        //@ assert increasing:  WeaklyIncreasing(c, 0, x);
        //@ assert upper:       j < n  ==>  UpperBound(c, 0, x, b[j]);
      }

      //@ assert increasing:  WeaklyIncreasing(c, 0, x);
    }

    //@ ghost  Epilogue: ;
    //@ assert index:       x == i+j;
    //@ assert index:       i == m  ^^  j == n;
    //@ assert index:       i <  m  ^^  j <  n;
    //@ assert increasing:  WeaklyIncreasing(c, 0, x);
    //@ assert unchanged:   Unchanged{Pre,Here}(a, 0, m);
    //@ assert increasing:  WeaklyIncreasing(a, 0, m);

    if (i < m) {
      //@ assert upper:       0 < x  ==>  c[x-1] <= a[i];
      //@ assert increasing:  WeaklyIncreasing(a, i, m);
      //@ assert increasing:  WeaklyIncreasing(a+i, 0, m-i);

      /*@
          assigns             c[x..x+m-i-1];
          ensures  equal:     Equal{Epilogue,Here}(a+i, m-i, c+x);
      */
      copy(a + i, m - i, c + x);
      //@ assert equal:       c[x] == At{Epilogue}(a, i);
      //@ assert equal:       a[i] == At{Epilogue}(a, i);
      //@ assert equal:       c[x] == a[i];
      //@ assert equal:       Equal{Epilogue,Here}(a+i, m-i, c+x);
      //@ assert increasing:  WeaklyIncreasing(c+x, 0, m-i);
      //@ assert index:       m-i+x == m+n;
      //@ assert increasing:  WeaklyIncreasing(c, x, m+n);
    }
    else {
      //@ assert upper:       0 < x  ==>  c[x-1] <= b[j];
      //@ assert unchanged:   Unchanged{Pre,Here}(b, 0, n);
      //@ assert increasing:  WeaklyIncreasing(b, 0, n);
      //@ assert increasing:  WeaklyIncreasing(b+j, 0, n-j);

      /*@
          assigns             c[x..x+n-j-1];
          ensures  equal:     Equal{Epilogue,Here}(b+j, n-j, c+x);
      */
      copy(b + j, n - j, c + x);
      //@ assert equal:       c[x] == At{Epilogue}(b, j);
      //@ assert equal:       b[j] == At{Epilogue}(b, j);
      //@ assert equal:       c[x] == b[j];
      //@ assert equal:       Equal{Epilogue,Here}(b+j, n-j, c+x);
      //@ assert increasing:  WeaklyIncreasing(c+x, 0, n-j);
      //@ assert index:       n-j+x == m+n;
      //@ assert increasing:  WeaklyIncreasing(c, x, m+n);
    }

    //@ assert unchanged:   Unchanged{Epilogue,Here}(c, 0, x);
    //@ assert increasing:  WeaklyIncreasing(c, 0, x);
    //@ assert increasing:  WeaklyIncreasing(c, x, m+n);
    //@ assert increasing:  0 < x  ==>  c[x-1] <= c[x];
    //@ assert increasing:  0 < x  ==>  WeaklyIncreasing(c, x-1, m+n);
    //@ assert increasing:  WeaklyIncreasing(c, 0, m+n);
  }
}

