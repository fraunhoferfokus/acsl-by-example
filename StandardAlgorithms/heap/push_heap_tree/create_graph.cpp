
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "create_graph.h"

static int counter = 0;

void create_graph(value_type* a, size_type n, size_type child)
{
  std::vector<int> b;
  b.assign(a, a+n);
  create_graph(b, child);
}

void create_graph_afterfirst(value_type* a, size_type n, size_type child, value_type val)
{
  std::vector<int> b;
  b.assign(a, a+n);
  create_graph_afterfirst(b, child, val);
}

void create_graph_post(value_type* a, size_type n, size_type child, value_type val)
{
  std::vector<int> b;
  b.assign(a, a+n);
  create_graph_post(b, child, val);
}

void create_graph_finish(value_type* a, size_type n, size_type child)
{
  std::vector<int> b;
  b.assign(a, a+n);
  create_graph_finish(b, child);
}

void create_graph_init(value_type* a, size_type n)
{
  std::vector<int> b;
  b.assign(a, a+n);
  create_graph_init(b);
}

void create_graph(std::vector<int>& a, size_type child)
{
  std::ostringstream name;
  name << "dotheaps/" << std::setw(5) << std::setfill('0') << counter++ << ".dot";
  std::ofstream stream;
  stream.open(name.str());
  stream << "digraph {\n\tforcelabels=true;\n";
  for (size_t i = 0; i < a.size(); ++i) {
    if (i == child) {
      stream << "\t" << i << " [label=\"" << a[i] << "\", xlabel=\"" << i << "\", style=filled, fillcolor=steelblue1];\n";
    }
    else if (i == ((child -1) / 2)) {
      stream << "\t" << i << " [label=\"" << a[i] << "\", xlabel=\"" << i << "\", style=filled, fillcolor=springgreen1];\n";
    }
    else {
      stream << "\t" << i << " [label=\"" << a[i] << "\", xlabel=\"" << i << "\"];\n";
    }
  }
  size_t i = 0;
  while (i * 2 + 1 < a.size()) {
    stream << "\t" << i << "->" << 2 * i + 1 << ";\n";
    if (i * 2 + 2 < a.size()) {
      stream << "\t" << i << "->" << 2 * i + 2 << ";\n";
    }
    ++i;
  }
  stream << "}";
  stream.close();
  return;
}

void create_graph_afterfirst(std::vector<int>& a, size_type child, value_type val)
{
  std::ostringstream name;
  name << "dotheaps/" << std::setw(5) << std::setfill('0') << counter++ << ".dot";
  std::ofstream stream;
  stream.open(name.str());
  stream << "digraph {\n\tforcelabels=true;\n";
  for (size_t i = 0; i < a.size(); ++i) {
    if (i == child) {
      stream << "\t" << i << " [label=\"" << a[i] << " (" << val << ")" << "\", xlabel=\"" << i << "\", style=filled, fillcolor=steelblue1];\n";
    }
    else if (i == ((child -1) / 2)) {
      stream << "\t" << i << " [label=\"" << a[i] << "\", xlabel=\"" << i << "\", style=filled, fillcolor=springgreen1];\n";
    }
    else {
      stream << "\t" << i << " [label=\"" << a[i] << "\", xlabel=\"" << i << "\"];\n";
    }
  }
  size_t i = 0;
  while (i * 2 + 1 < a.size()) {
    stream << "\t" << i << "->" << 2 * i + 1 << ";\n";
    if (i * 2 + 2 < a.size()) {
      stream << "\t" << i << "->" << 2 * i + 2 << ";\n";
    }
    ++i;
  }
  stream << "}";
  stream.close();
  return;
}

void create_graph_post(std::vector<int>& a, size_type child, value_type val)
{
  std::ostringstream name;
  name << "dotheaps/" << std::setw(5) << std::setfill('0') << counter++ << ".dot";
  std::ofstream stream;
  stream.open(name.str());
  stream << "digraph {\n\tforcelabels=true;\n";
  for (size_t i = 0; i < a.size(); ++i) {
    if (i == child) {
      stream << "\t" << i << " [label=\"" << a[i] << "\", xlabel=\"" << i << "\", style=filled, fillcolor=springgreen1];\n";
    }
    else if (i == ((child -1) / 2)) {
      stream << "\t" << i << " [label=\"" << a[i] << " (" << val << ")" << "\", xlabel=\"" << i << "\", style=filled, fillcolor=springgreen1];\n";
    }
    else {
      stream << "\t" << i << " [label=\"" << a[i] << "\", xlabel=\"" << i << "\"];\n";
    }
  }
  size_t i = 0;
  while (i * 2 + 1 < a.size()) {
    stream << "\t" << i << "->" << 2 * i + 1 << ";\n";
    if (i * 2 + 2 < a.size()) {
      stream << "\t" << i << "->" << 2 * i + 2 << ";\n";
    }
    ++i;
  }
  stream << "}";
  stream.close();
  return;
}

void create_graph_finish(std::vector<int>& a, size_type child)
{
  std::ostringstream name;
  name << "dotheaps/" << std::setw(5) << std::setfill('0') << counter++ << ".dot";
  std::ofstream stream;
  stream.open(name.str());
  stream << "digraph {\n\tforcelabels=true;\n";
  for (size_t i = 0; i < a.size(); ++i) {
    if (i == child) {
      stream << "\t" << i << " [label=\"" << a[i] << "\", xlabel=\"" << i << "\", style=filled, fillcolor=steelblue1];\n";
    }
    else {
      stream << "\t" << i << " [label=\"" << a[i] << "\", xlabel=\"" << i << "\", style=filled, fillcolor=springgreen1];\n";
    }
  }
  size_t i = 0;
  while (i * 2 + 1 < a.size()) {
    stream << "\t" << i << "->" << 2 * i + 1 << ";\n";
    if (i * 2 + 2 < a.size()) {
      stream << "\t" << i << "->" << 2 * i + 2 << ";\n";
    }
    ++i;
  }
  stream << "}";
  stream.close();
  return;
}

void create_graph_init(std::vector<int>& a)
{
  std::stringstream name;
  name << "dotheaps/" << std::setw(5) << std::setfill('0') << counter++ << ".dot";
  std::ofstream stream;
  stream.open(name.str());
  stream << "digraph {\n\tforcelabels=true;\n";
  for (size_t i = 0; i+1 < a.size(); ++i) {
    stream << "\t" << i << " [label=\"" << a[i] << "\", xlabel=\"" << i << "\", style=filled, fillcolor=springgreen1];\n";
  }
    stream << "\t" << a.size()-1 << " [label=\"" << a[a.size()-1] << "\", xlabel=\"" << a.size()-1 << "\", style=filled, fillcolor=steelblue1];\n";
  size_t i = 0;
  while (i * 2 + 1 < a.size()) {
    stream << "\t" << i << "->" << 2 * i + 1 << ";\n";
    if (i * 2 + 2 < a.size()) {
      stream << "\t" << i << "->" << 2 * i + 2 << ";\n";
    }
    ++i;
  }
  stream << "}";
  stream.close();
  return;
}

