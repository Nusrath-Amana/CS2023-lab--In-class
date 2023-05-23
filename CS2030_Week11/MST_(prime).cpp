#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Vertex {
    int key;
    int parent;
    bool visited;
};

// Function to implement Prim's algorithm and obtain the MST
void MST_prim(vector<vector<int>>& graph, int startNode) {
    int vertices_count = graph.size();

    // Create a vector of Vertex structures to store the key values, parent vertices, and visited status
    vector<Vertex> vertices(vertices_count);
    for (int i = 0; i < vertices_count; ++i) {
        vertices[i].key = INT_MAX;
        vertices[i].parent = -1;
        vertices[i].visited = false;
    }

    // Set the key and parent of the start node
    vertices[startNode].key = 0;

    // Create a priority queue named "mst" to store vertices and their key values
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mst;

    // Start with the given startNode
   mst.push({0, startNode});

    while (!mst.empty()) {
	  // Extract the vertex with the minimum key value
        int u = mst.top().second;
        mst.pop();
        vertices[u].visited = true;

        // Traverse all adjacent vertices of u
        for (int v = 0; v < vertices_count; ++v) {
		
		// Check if v is adjacent to u, not visited, and has a lower weight
            if (graph[u][v] != 0 && !vertices[v].visited && graph[u][v] < vertices[v].key) {
                vertices[v].parent = u;
                vertices[v].key = graph[u][v];
                mst.push({vertices[v].key, v});
            }
        }
    }

    // Print the MST
    cout << "Minimum Spanning Tree (MST):\n";
    for (int i = 1; i < vertices_count; ++i) {
        cout << vertices[i].parent << " - " << i << "\n";
    }
}

int main() {
    // Example adjacency matrix representation of the graph
    vector<vector<int>> graph = {
        {0, 3, 0, 0, 0, 1},
        {3, 0, 2, 1, 10, 0},
        {0, 2, 0, 3, 0, 5},
        {0, 1, 3, 0, 5, 0},
        {0, 10, 0, 5, 0, 4},
        {1, 0, 5, 0, 4, 0}
    };

    // Start node for MST (Node 0 in this case)
    int startNode = 0;

    // Call the Prim's MST function
    MST_prim(graph, startNode);

    return 0;
}