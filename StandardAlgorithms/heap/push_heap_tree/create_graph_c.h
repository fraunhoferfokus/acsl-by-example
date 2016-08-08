
#include <stdio.h>
#include "typedefs.h"

static int counter = 0;

inline void create_graph(value_type* a, size_type n, size_type child)
{
    FILE *print_file;
    char name[100];
    sprintf(name, "dotheaps/temporary%d.dot", counter++);
    print_file = fopen(name, "w");
    fprintf(print_file, "digraph {\n\tforcelabels=true;\n");

    for (size_t i = 0; i < n; ++i) {
      if (i == child) {
        fprintf(print_file, "\t%lu [label=\"%d\", xlabel=\"%lu\", style=filled, fillcolor=springgreen1];\n", i, a[i], i);
      }
      else if (i == ((child - 1 )/ 2)) {
        fprintf(print_file, "\t%lu [label=\"%d\", xlabel=\"%lu\", style=filled, fillcolor=steelblue1];\n", i, a[i], i);
      }
      else {
        fprintf(print_file, "\t%lu [label=\"%d\", xlabel=\"%lu\"];\n", i, a[i], i);
      }
    }

    size_t i = 0;
    while (i*2+1 < n) {
      fprintf(print_file, "\t%lu -> %lu;\n", i, 2*i+1);
      if (i*2+2 < n) {
        fprintf(print_file, "\t%lu -> %lu;\n", i, 2*i+2);
      }
      ++i;
    }

    fputs("}", print_file);

    fclose(print_file);

    return;
}

