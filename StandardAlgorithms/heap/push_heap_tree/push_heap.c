
#include "push_heap.h"
#include "assert.h"
#include "../is_heap/is_heap.h"
#include <stdio.h>
#include "create_graph.h"

void push_heap(value_type* a, size_type n)
{
  create_graph_init(a, n);
  size_type hole = n - 1;
  value_type val = a[n - 1];
  while (hole > 0) {
    const size_type parent = (hole - 1) / 2;
    if (a[parent] < val) {
      if (hole == n-1) {
        create_graph(a, n, hole);
      } else {
        create_graph_afterfirst(a, n, hole, val);
      }
      a[hole] = a[parent];
      create_graph_post(a, n, hole, val);
      hole = parent;
    } else {
      if (hole == n-1) {
        create_graph(a, n, hole);
      } else {
        create_graph_afterfirst(a, n, hole, val);
      }
      break;
    }
  }
  a[hole] = val;
  create_graph_finish(a, n, hole);
}

