#include <iostream>
#include <fstream>
#include "ArgumentManager.h"
#include "Graph.h"

using namespace std;

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
  ifstream fin(am.get("input"));
  ofstream fout(am.get("output"));
  //ifstream fin("input1.txt");
  //ofstream fout("output1.txt");
  
  int numVerts, from, to, weight;
  fin >> numVerts;

  Graph graph(numVerts);

  while (fin >> from >> to >> weight) {
    graph.addEdge(from, to, weight);
  }

  for (int i = 0; i < numVerts; i++)
    graph.Dijkstra(i, fout);

  return 0;
}