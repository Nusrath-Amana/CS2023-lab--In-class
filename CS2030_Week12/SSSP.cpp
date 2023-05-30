#include <iostream>
#include <limits>
using namespace std;

// Number of vertices in the graph
#define V 6

double average_time[V] = { 0 };

// A utility function to find the vertex with the minimum
// distance value, from the set of vertices not yet included
// in the shortest path tree
int min_time(double time_taken[], bool sptSet[])
{
    // Initialize min value
    double min = numeric_limits<double>::max();
    int min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && time_taken[v] <= min)
            min = time_taken[v], min_index = v;

    return min_index;
}

// A utility function to print the constructed distance
// array
void printSolution(double time_taken[], int src)
{
    double total = 0;
    cout << "Vertex \t Time from Source" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << " \t\t\t" << time_taken[i] << endl;
        total += time_taken[i];
    }
    average_time[src] = total / (V - 1);

}

// Function that implements Dijkstra's single source
// shortest path algorithm for a graph represented using
// adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
    double time_taken[V]; // The output array. time_taken[i] will hold the
                          // shortest time from src to i

    bool sptSet[V]; // sptSet[i] will be true if vertex i is
                    // included in the shortest path tree or
                    // the shortest time from src to i is finalized

    // Initialize all times as INFINITE and sptSet[] as false
    for (int i = 0; i < V; i++)
        time_taken[i] = numeric_limits<double>::max(), sptSet[i] = false;

    // Time taken from the source vertex to itself is always 0
    time_taken[src] = 0;

    // Find the shortest time for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the vertex with the minimum time from the set of
        // vertices not yet processed.
        int u = min_time(time_taken, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update time_taken value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < V; v++)
            // Update time_taken[v] only if it is not in sptSet,
            // there is an edge from u to v, and the total
            // time from src to v through u is
            // smaller than the current value of time_taken[v]
            if (!sptSet[v] && graph[u][v] &&
                time_taken[u] != numeric_limits<double>::max() &&
                time_taken[u] + graph[u][v] < time_taken[v])
                time_taken[v] = time_taken[u] + graph[u][v];
    }

    // Print the constructed time array
    printSolution(time_taken, src);
}

int main()
{
    // Create the weighted adjacency matrix for the graph
    int graph[V][V] = {
        { 0, 10, 0, 0, 15, 5 },
        { 10, 0, 10, 30, 0, 0 },
        { 0, 10, 0, 12, 5, 0 },
        { 0, 30, 12, 0, 0, 20 },
        { 15, 0, 5, 0, 0, 0 },
        { 5, 0, 0, 20, 0, 0 }
    };

    // Perform Dijkstra's algorithm for each city as the source
    for (int src = 0; src < V; ++src) {
        cout << "Shortest time from City " << src << ":\n";
        dijkstra(graph, src);
        cout << endl;
    }

    // Print the average time of each city
    cout << "Average time from each city to the other cities:\n";
    for (int i = 0; i < V; ++i) {
        cout << "City " << i << ": " << average_time[i] << endl;
    }

    // Find the city with the smallest average time
    double min_avg_time = average_time[0];
    for (int i = 1; i < V; ++i) {
        if (average_time[i] < min_avg_time)
            min_avg_time = average_time[i];
    }

    // Print the city/cities with the smallest average time
    cout << "\nCity/Cities with the smallest average time:\n";
    for (int i = 0; i < V; ++i) {
        if (average_time[i] == min_avg_time)
            cout << "City " << i << endl;
    }

    return 0;
}
