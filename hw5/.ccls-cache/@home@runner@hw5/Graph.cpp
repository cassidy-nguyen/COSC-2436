#include "Graph.h"

Graph::Graph(int v) {
   vertices = v;
   matrix = vector<vector<int>>(v, vector<int>(v, -1));
}

void Graph::addEdge(int val1, int val2, int value) {
   matrix[val1][val2] = value;
   //matrix[val2][val1] = value;
}

void Graph::print(ofstream& fout) {
   for (int i = 0; i < vertices; i++) {
      for (int j = 0; j < vertices; j++) {
         if (j != 0)
            fout << setw(4);
         else
            fout << setw(3);
         if (matrix[i][j] != -1) {
            fout << matrix[i][j];
         }
         else {
            fout << "--";
         }
         if (j == vertices - 1) {
            fout << " ";
         }
      }
      fout << endl;
   }
}

void Graph::Dijkstra(int startV, ofstream& fout) {
   vector<vertex> dist(vertices, vertex(INT_MAX, -1)); // infinity = INT_MAX
   dist[startV].distance = 0;
   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
   pq.push({0, startV});
  
   while (!pq.empty()) {
      int i = pq.top().second;
      pq.pop();
      for (int j = 0; j < vertices; ++j) {
         if (matrix[i][j] != -1) {
            int weight = matrix[i][j];
            if (dist[i].distance + weight < dist[j].distance) {
               dist[j].distance = dist[i].distance + weight;
               dist[j].predV = i;
               pq.push({dist[j].distance, j});
            }
         }
      }
   }
   for (int i = 0; i < vertices; ++i) {
      fout << setw(3) << dist[i].distance << " ";
   }
   fout << endl;
}