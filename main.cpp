/*
 * main.cpp
 * Copyright (C) 2016 lopespt <lopespt@arch>
 *
 * Distributed under terms of the MIT license.
 */

#include "graph.hpp"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, const char *argv[]) {
  Graph g;
  for (int k = 0; k < 10000; k++)
    g.addNode();

  for (int i = 0; i < 10000; i++) {
    for (int k = 0; k < 1000; k++) {
      Edge &e = g.addEdge(g.getNode(k), g.getNode(i));
      e.s = std::to_string(0) + "->" + to_string(i);
    }
    cout << i << endl;
  }

  Graph::edgeIndex::iterator b, e, i;
  b = g.getBeginEdgesIterator(g.getNode(0));
  e = g.getEndEdgesIterator(g.getNode(2));
  cout << (b == g.edgesTo.end() ? "FIM" : "OK") << endl;
  cout << (e == g.edgesTo.end() ? "FIM" : "OK") << endl;

  /*for (auto &v : g) {
    cout << v->n << endl;
  }

  for (i = b; i != e && i != g.edgesTo.end(); i++) {
    cout << i->second.get().s << endl;
  }*/

  return 0;
}
