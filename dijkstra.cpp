#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int source, int numVertices) {
    vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;

    // Use a priority queue (min-heap) for efficient retrieval of minimum distances.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source}); // {distance, vertex}

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // Optimization: If we've already found a shorter path to u, skip.
        if (d > distance[u]) {
            continue;
        }

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }

    return distance;
}



// - **Time Complexity:**
//   - Adjacency List + Binary Heap: ( O((V + E) log V) )
//   - Adjacency List + Fibonacci Heap: ( O(V log V + E) )
//   - Adjacency Matrix: ( O(V^2) ) or ( O(V^2 log V) ) with binary heap.

// - **Space Complexity:**
//   - Adjacency List: ( O(V + E) )
//   - Adjacency Matrix: ( O(V^2) )
