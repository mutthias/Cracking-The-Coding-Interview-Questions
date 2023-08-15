#include <iostream>
#include <queue>
#include <vector>
#include "adjacency_list.h"

void bfs(std::vector<std::vector<int>>& graph) {
    if (graph.empty()) {
        return; // Return early if the graph is empty
    }

    int start = 0; // Assuming the start vertex is always 0 in vector-based representation
    std::queue<int> nodes;
    std::vector<bool> visited(graph.size(), false);
    nodes.push(start);
    visited[start] = true;

    while (!nodes.empty()) {
        int curr_node = nodes.front();
        nodes.pop();
        std::cout << curr_node << " "; // Print the current vertex during BFS

        for (int neighbor : graph[curr_node]) {
            if (!visited[neighbor]) {
                nodes.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    std::cout << std::endl; // End the BFS traversal output
}


bool isTherePath(std::vector<std::vector<int>>& graph, int target) {
    if (graph.empty()) {
        return false; // Return early if the graph is empty
    }

    int start = 0; // Assuming the start vertex is always 0 in vector-based representation
    std::queue<int> nodes;
    std::vector<bool> visited(graph.size(), false);
    nodes.push(start);
    visited[start] = true;

    while (!nodes.empty()) {
        int curr_node = nodes.front();
        nodes.pop();
        std::cout << curr_node << " "; // Print the current vertex during BFS
        if (curr_node == target) {
          std::cout << "found!" << std::endl;
          return true;
        }
        for (int neighbor : graph[curr_node]) {
            if (!visited[neighbor]) {
                nodes.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    std::cout << "not found :(" << std::endl; // End the BFS traversal output
    return false;
}

int main() {
    int numVertices = 6; // Assuming 6 vertices in the graph
    std::vector<std::vector<int>> graph(numVertices);

    addEdge(0, 1, graph);
    addEdge(0, 3, graph);
    addEdge(2, 3, graph);
    addEdge(3, 4, graph);
    addEdge(4, 5, graph);
    addEdge(3, 1, graph);
    addEdge(2, 5, graph);

    bfs(graph);
    isTherePath(graph, 4);
    isTherePath(graph, 2);
    isTherePath(graph, 8);


    return 0;
}