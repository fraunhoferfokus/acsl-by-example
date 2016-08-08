
#ifndef CREATE_GRAPH_H_INCLUDED
#define CREATE_GRAPH_H_INCLUDED

#include <vector>
#include "typedefs.h"

void create_graph(value_type* a, size_type n, size_type child);
void create_graph(std::vector<int>& a, size_type child);
void create_graph_afterfirst(value_type* a, size_type n, size_type child, value_type val);
void create_graph_afterfirst(std::vector<int>& a, size_type child, value_type val);
void create_graph_post(value_type* a, size_type n, size_type child, value_type val);
void create_graph_post(std::vector<int>& a, size_type child, value_type val);
void create_graph_finish(value_type* a, size_type n, size_type child);
void create_graph_finish(std::vector<int>& a, size_type child);
void create_graph_init(value_type* a, size_type n);
void create_graph_init(std::vector<int>& a);

#endif /* CREATE_GRAPH_H_INCLUDED */

