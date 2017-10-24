
#include "heap_sort.h"
#include "../heap/make_heap/make_heap.h"
#include "../heap/sort_heap/sort_heap.h"

void heap_sort(value_type* a, size_type n)
{
  make_heap(a, n);
  sort_heap(a, n);
}

