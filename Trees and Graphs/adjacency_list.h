#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST

#include <vector>
#include <unordered_map>

void addEdge(int u, int v, std::vector<std::vector<int>>& map) {
  map[u].push_back(v);
  // map[v].push_back(u);
}


#endif