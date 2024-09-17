#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <queue>
#include <climits>

using namespace std;

struct vertex {
   int distance;
   int predV;
   vertex(int d, int v) : distance(d), predV(v) {}
};

class Graph {
public:
   Graph(int v);
   void addEdge(int val1, int val2, int value);
   void print(ofstream& fout);
   void Dijkstra(int startV, ofstream& fout);
private:
   int vertices;
   vector<vector<int>> matrix;
};

#endif