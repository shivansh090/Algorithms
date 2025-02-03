#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(vector<vector<int>>& graph, int source, int numVertices) {
    vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;

    for (int i = 1; i <= numVertices - 1; ++i) {
        for (auto& edge : graph) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    for (auto& edge : graph) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            return {-1}; // Negative cycle detected
        }
    }

    return distance;
}



// ### **Bellman-Ford Algorithm**
// - **Time Complexity:**
//   - ( O(V . E) )

// - **Space Complexity:**
//   - ( O(V) ) for distances and auxiliary arrays.