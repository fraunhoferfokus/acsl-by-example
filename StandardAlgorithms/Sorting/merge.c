
#include "merge.h"
#include "copy.h"
#include "At.acsl"
#include "IncreasingLemmas.acsl"
#include "WeaklyIncreasingLemmas.acsl"
#include "MultisetUnionLemmas.acsl"

void merge(const value_type* a, size_type m,
           const value_type* b, size_type n, value_type* c)
{
  //@ assert increasing:  WeaklyIncreasing(a, 0, m);
  size_type i = 0;
  size_type j = 0;
  size_type x = 0;

  if (0 < m || 0 < n) {
    /*@ loop invariant bound:       0 <= i <= m;
        loop invariant bound:       0 <= j <= n;
        loop invariant index:       x == i+j;
        loop invariant bound:       0 <= x <= m+n-1;
        loop invariant upper:       i < m  ==>  UpperBound(c, 0, x, a[i]);
        loop invariant upper:       j < n  ==>  UpperBound(c, 0, x, b[j]);
        loop invariant increasing:  WeaklyIncreasing(c, x);
        loop invariant multiset:    MultisetUnion(a, i, b, j, c);
        loop assigns i, j, x, c[0 .. m+n-1];
        loop variant (m+n) - (i+j);
     */
    while (i < m && j < n) {
      //@ ghost Step: ;
      if (a[i] <= b[j]) {
        c[x++] = a[i++];
        //@ assert unchanged:   Unchanged{Step,Here}(a, 0, i-1);
        //@ assert upper:       i < m  ==>  UpperBound(c, 0, x, a[i]);
        //@ assert upper:       j < n  ==>  UpperBound(c, 0, x, b[j]);
        //@ assert unchanged:   Unchanged{Step,Here}(b, 0, j);
        //@ assert unchanged:   Unchanged{Step,Here}(c, 0, (i-1)+j);
        //@ assert increasing:  WeaklyIncreasing(c, 0, x);
        //@ assert multiset:    MultisetUnion(a, i-1, b, j, c);
        //@ assert equal:       At(c, (i-1)+j) == At(a, i-1);
        //@ assert multiset:    MultisetUnion(a, i, b, j, c);
      }
      else {
        c[x++] = b[j++];
        //@ assert unchanged:   Unchanged{Step,Here}(b, 0, j-1);
        //@ assert unchanged:   Unchanged{Step,Here}(a, 0, i);
        //@ assert upper:       j < n  ==>  UpperBound(c, 0, x, b[j]);
        //@ assert upper:       i < m  ==>  UpperBound(c, 0, x, a[i]);
        //@ assert unchanged:   Unchanged{Step,Here}(c, 0, i+(j-1));
        //@ assert increasing:  WeaklyIncreasing(c, 0, x);
        //@ assert multiset:    MultisetUnion(a, i, b, j-1, c);
        //@ assert equal:       At(c, i+(j-1)) == At(b, j-1);
        //@ assert multiset:    MultisetUnion(a, i, b, j, c);
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
    //@ assert multiset:    MultisetUnion(a, i, b, j, c);

    if (i < m) {
      //@ assert upper:       0 < x  ==>  c[x-1] <= a[i];
      //@ assert increasing:  WeaklyIncreasing(a, i, m);
      //@ assert increasing:  WeaklyIncreasing(a+i, 0, m-i);

      copy(a + i, m - i, c + x);
      //@ assert unchanged:   Unchanged{Pre,Here}(a, 0, m);
      //@ assert equal:       c[x] == At{Epilogue}(a, i);
      //@ assert equal:       a[i] == At{Epilogue}(a, i);
      //@ assert equal:       c[x] == a[i];
      //@ assert equal:       Equal{Epilogue,Here}(a+i, m-i, c+x);
      //@ assert index:       m-i+x == m+n;
      //@ assert unchanged:   Unchanged{Pre,Here}(b, 0, n);
      //@ assert increasing:  WeaklyIncreasing(c+x, 0, m-i);
      //@ assert increasing:  WeaklyIncreasing(c, x, m+n);
      //@ assert unchanged:   Unchanged{Epilogue,Here}(a, 0, i);
      //@ assert unchanged:   Unchanged{Epilogue,Here}(b, 0, j);
      //@ assert unchanged:   Unchanged{Epilogue,Here}(c, 0, i+j);
      //@ assert multiset:    MultisetUnion(a, i, b, j, c);
      //@ assert unchanged:   Unchanged{Epilogue,Here}(a, 0, m);
      //@ assert equal:       Equal{Epilogue,Here}(a, i, m, c, i+j);
      //@ assert equal:       Equal{Here,Here}(a, i, m, c, i+j);
      //@ assert multiset:    MultisetUnion(a, m, b, j, c);
    }
    else {
      //@ assert upper:       0 < x  ==>  c[x-1] <= b[j];
      //@ assert unchanged:   Unchanged{Pre,Here}(a, 0, m);
      //@ assert unchanged:   Unchanged{Pre,Here}(b, 0, n);
      //@ assert increasing:  WeaklyIncreasing(b, 0, n);
      //@ assert increasing:  WeaklyIncreasing(b+j, 0, n-j);

      copy(b + j, n - j, c + x);
      //@ assert unchanged:   Unchanged{Epilogue,Here}(b, 0, n);
      //@ assert equal:       c[x] == At{Epilogue}(b, j);
      //@ assert equal:       b[j] == At{Epilogue}(b, j);
      //@ assert equal:       c[x] == b[j];
      //@ assert equal:       Equal{Epilogue,Here}(b+j, n-j, c+x);
      //@ assert index:       n-j+x == m+n;
      //@ assert unchanged:   Unchanged{Epilogue,Here}(c, 0, x);
      //@ assert increasing:  WeaklyIncreasing(c+x, 0, n-j);
      //@ assert increasing:  WeaklyIncreasing(c, x, m+n);
      //@ assert unchanged:   Unchanged{Epilogue,Here}(a, 0, i);
      //@ assert unchanged:   Unchanged{Epilogue,Here}(b, 0, j);
      //@ assert unchanged:   Unchanged{Epilogue,Here}(c, 0, i+j);
      //@ assert multiset:    MultisetUnion(a, i, b, j, c);
      //@ assert multiset:    MultisetUnion(b, j, a, i, c);
      //@ assert equal:       Equal{Epilogue,Here}(b, j, n, c, j+i);
      //@ assert equal:       Equal{Here,Here}(b, j, n, c, j+i);
      //@ assert multiset:    MultisetUnion(b, n, a, i, c);
      //@ assert multiset:    MultisetUnion(a, i, b, n, c);
    }

    //@ assert unchanged:   Unchanged{Epilogue,Here}(c, 0, x);
    //@ assert increasing:  WeaklyIncreasing(c, 0, x);
    //@ assert increasing:  WeaklyIncreasing(c, x, m+n);
    //@ assert increasing:  0 < x  ==>  c[x-1] <= c[x];
    //@ assert increasing:  0 < x  ==>  WeaklyIncreasing(c, x-1, m+n);
    //@ assert increasing:  WeaklyIncreasing(c, 0, m+n);
  }
}

