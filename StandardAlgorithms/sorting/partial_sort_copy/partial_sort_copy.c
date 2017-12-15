
#include "partial_sort_copy.h"

#include "../../mutating/copy/copy.h"
#include "../../heap/make_heap/make_heap.h"
#include "../../heap/pop_heap/pop_heap.h"
#include "../../heap/push_heap/push_heap.h"
#include "../../heap/sort_heap/sort_heap.h"



//#define DANGEROUS_HYPOTHESES		/* needed for g7,gC,h1,h4,h5 */



#ifdef DANGEROUS_HYPOTHESES
#include "CountBounds.h"
#include "CountLemmas.h"
#include "LowerBound.h"
#include "HeapMaximum.h"

/*@
  lemma HeapMaxCount:
    \forall value_type *b, v, integer n;
      0 <= n           ==>
      IsHeap(b,n)      ==>
      Count(b,n,v) > 0 ==>
      v <= b[0];
*/

/*@
  lemma ReorderRetainsLeastPart{K,L}:
    \forall value_type *a, *b, integer m, n;
      MultisetUnchanged{K,L}(a,m)  ==>
      MultisetUnchanged{K,L}(b,n)  ==>
      IsLeastPartOf{K}(a, m, b, n) ==>
      IsLeastPartOf{L}(a, m, b, n);
*/
#endif



void partial_sort_copy(const value_type* a, size_type m,
                             value_type* b, size_type n)
{
  if (n > 0u) {

    copy(a, n, b);

    //@ ghost L1:

    //@ assert a1: EqualRanges{Here,Here}(a, n, b);
    //@ assert a2: IsLeastPartOf(a, n, b, n);
    make_heap(b, n);
    //  assert b1: MultisetUnchanged{L1,Here}(b, n);
    //@ assert b2:         Unchanged{L1,Here}(a, n);
    //@ assert b3: IsLeastPartOf(a, n, b, n);

    /*@
      loop invariant c1: 0 <= i <= m;
      loop invariant c2: IsLeastPartOf(a, i, b, n);
      loop invariant c3: IsHeap(b, n);
      loop assigns   c4: b[0..n-1], i;
      loop variant   c5: m-i;
    */
    for (size_type i = n; i < m; ++i) {
      if (a[i] < b[0]) {	// a[i] better than heap root, swap-in
	value_type const old_b0 = b[0];

	//@ ghost L2:

#ifdef DANGEROUS_HYPOTHESES
	//@ assert d1: \forall value_type   w; w!=old_b0 && Count{L2}(b,n,old_b0)>0 && IsInComplement{L2}(a,i,b,n,w) ==> old_b0 <= w;
	//@ assert d2: Count{L2}(b,0,n,b[0])==Count{L2}(b,0,1,b[0]) + Count{L2}(b,1,n,b[0]);
	//@ assert d3: Count{L2}(b,n,old_b0)>0;
	//@ assert d4: MaxElement(b,n,0);
	//@ assert d5: UpperBound(b,n,b[0]);
	//@ assert d6: \forall value_type v; Count(b,n,v)>0 ==> v <= b[0];
#endif

	pop_heap(b, n);

	//@ ghost L3:

	//@ assert e1: Unchanged{L2,Here}(a,m);
	//@ assert e2: MultisetUnchanged{L2,Here}(b,n);
	b[n-1] = a[i];

	//@ ghost L4:

	//@ assert f1: Unchanged{L2,Here}(a,m);
	//@ assert f2: Count{Here}(b,n,a[i])   == Count{L3}(b,n,a[i]) + 1;
	//  assert f3: Count{Here}(b,n,old_b0) == Count{L3}(b,n,old_b0) - 1;
	//@ assert f4: Unchanged{L3,Here}(b,n-1);
	//@ assert f5: \forall value_type v; Count{L3}(b,n-1,v)==Count{Here}(b,n-1,v);
	//@ assert f6: \forall value_type v; v==a[i] || v==old_b0 || Count{L3}(b,n,v)==Count{Here}(b,n,v);
	//@ assert f7: \forall value_type v; v!=old_b0 && v!=a[i] && IsInComplement{Here}(a,i+1,b,n,v) ==> IsInComplement{L3}(a,i,b,n,v);
	//@ assert f8: IsInComplement{Here}(a,i+1,b,n,a[i]) ==> IsInComplement{L3}(a,i,b,n,a[i]);
	//@ assert f9: \forall value_type v; IsInComplement{Here}(a,i+1,b,n,v) ==> IsInComplement{L3}(a,i,b,n,v) || v==old_b0;
	push_heap(b, n);

	//@ ghost L5:

	//  assert g1: MultisetUnchanged{L4,Here}(b, n);
	//@ assert g2: Unchanged{L4,Here}(a,m);
	//@ assert g3:\forall value_type v; Count{Here}(b,n,v)>0 ==> Count{L2}(b,n,v)>0 || v==a[i];
	//@ assert g4: \forall value_type v; IsInComplement{Here}(a,i+1,b,n,v) ==> IsInComplement{L3}(a,i,b,n,v) || v==old_b0;
	//@ assert g5: \forall value_type v; IsInComplement{Here}(a,i+1,b,n,v) ==> IsInComplement{L2}(a,i,b,n,v) || v==old_b0;
	//  assert g6: \forall value_type v,w; v==a[i] && w==old_b0 && Count{Here}(b,n,v)>0 && IsInComplement{Here}(a,i+1,b,n,w) ==> v <= w;
	//@ assert g7: \forall value_type v,w; v==a[i] && w!=old_b0 && Count{Here}(b,n,v)>0 && IsInComplement{Here}(a,i+1,b,n,w) ==> Count{L2}(b,n,old_b0)>0;
	//  assert g8: \forall value_type v,w; v==a[i] && w!=old_b0 && Count{Here}(b,n,v)>0 && IsInComplement{Here}(a,i+1,b,n,w) ==> IsInComplement{L2}(a,i,b,n,w);
	//  assert g9: \forall value_type v,w; v==a[i] && w!=old_b0 && Count{Here}(b,n,v)>0 && IsInComplement{Here}(a,i+1,b,n,w) ==> old_b0 <= w;
	//  assert gA: \forall value_type v,w; v==a[i] && w!=old_b0 && Count{Here}(b,n,v)>0 && IsInComplement{Here}(a,i+1,b,n,w) ==> v <= w;
	//  assert gB: \forall value_type v,w; v!=a[i] && w==old_b0 && Count{Here}(b,n,v)>0 && IsInComplement{Here}(a,i+1,b,n,w) ==> Count{L2}(b,n,v)>0;
	//@ assert gC: \forall value_type v,w; v!=a[i] && w==old_b0 && Count{Here}(b,n,v)>0 && IsInComplement{Here}(a,i+1,b,n,w) ==> v <= w;
	//  assert gD: \forall value_type v,w; v!=a[i] && w!=old_b0 && Count{Here}(b,n,v)>0 && IsInComplement{Here}(a,i+1,b,n,w) ==> v <= w;
	//  assert gE: IsLeastPartOf(a, i+1, b, n);
      } else {
	//  assert h1: UpperBound(b,n,a[i]);
	//@ assert h2: \forall value_type v,w; w!=a[i] ==> Count{Here}(b,n,v)>0 ==> IsInComplement{Here}(a,i+1,b,n,w) ==> IsInComplement{Here}(a,i,b,n,w);
	//@ assert h3: \forall value_type v,w; w!=a[i] ==> Count{Here}(b,n,v)>0 ==> IsInComplement{Here}(a,i  ,b,n,w) ==> v <= w;
	//@ assert h4: \forall value_type v,w; w!=a[i] ==> Count{Here}(b,n,v)>0 ==> IsInComplement{Here}(a,i+1,b,n,w) ==> v <= w;
	//@ assert h5: \forall value_type v,w; w==a[i] && Count{Here}(b,n,v)>0 && IsInComplement{Here}(a,i+1,b,n,w) ==> v <= w;
	//@ assert h6: IsLeastPartOf(a, i+1, b, n);
      }
    }

    //@ ghost L6:

    //@ assert i1: IsLeastPartOf(a, m, b, n);
    sort_heap(b, n);
    //@ assert j1: MultisetUnchanged{L6,Here}(b,n);
    //@ assert j2: Unchanged{L6,Here}(a,m);
    //@ assert j3: MultisetUnchanged{L6,Here}(a,m);
    //@ assert j4: IsLeastPartOf(a, m, b, n);
  }
}

