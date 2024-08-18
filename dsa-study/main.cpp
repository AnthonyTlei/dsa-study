#include <iostream>
#include <vector>
#include <algorithm>

#include "classes/Test.hpp"
#include "classes/Array.hpp"
#include "classes/DoublyLinkedList.hpp"
#include "classes/Stack.hpp"
#include "classes/Queue.hpp"
#include "classes/PQueue.hpp"
#include "classes/UnionFind.hpp"

// Edge structure to hold graph edges
struct Edge {
    int u, v;
    int weight;
    
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Kruskal's algorithm
std::vector<Edge> kruskal(int n, std::vector<Edge>& edges) {
    UnionFind<int> uf;
    std::vector<Edge> mst; // To store the resulting MST
    
    // Step 1: Initialize UnionFind for all nodes
    for (int i = 0; i < n; ++i) {
        uf.make_set(i);
    }
    
    // Step 2: Sort edges by weight
    std::sort(edges.begin(), edges.end());
    
    // Step 3: Iterate over edges and add them to the MST if they don't form a cycle
    for (const auto& edge : edges) {
        if (!uf.connected(edge.u, edge.v)) {
            uf.union_sets(edge.u, edge.v);
            mst.push_back(edge);
        }
    }
    
    return mst;
}

int main() {
    
    // We're gonna test the union find by trying Kruskal's algorithm
    
    // Define the number of vertices in the graph
    int n = 4;
    
    // Define the edges of the graph (u, v, weight)
    std::vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    
    // Run Kruskal's algorithm
    std::vector<Edge> mst = kruskal(n, edges);
    
    // Print the edges in the MST
    std::cout << "Edges in the Minimum Spanning Tree:" << std::endl;
    for (const auto& edge : mst) {
        std::cout << edge.u << " - " << edge.v << " : " << edge.weight << std::endl;
    }

    return 0;
}
