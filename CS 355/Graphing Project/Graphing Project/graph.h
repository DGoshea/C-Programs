#include <iostream>
#include <limits>
using namespace std;

class Graph
{
private:
    int V;
    int matrix[V][V] = {};

public:
    Graph(int x)
    {
        V = x;
        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
            {
                matrix[i][j] = -1;
            }
        }
    }
    void AddEdge(int source, int target, Events event)
    {
        matrix[source][target] = event.avgCostForOne;
        matrix[target][source] = event.avgCostForOne;
    }

    void printSol(int dist[])
    {
        for(int i = 0; i < V; i++)
        {
            cout << i << "\t" << dist[i] << endl;
        }
    }
    int* dijkstra(int source, pQueue<Events> minHeap)
{
    //Output array; cost[i] will hold the shortest distance form the source to dist[i]
    int* dist = new int[V];

    //sptSet[i] will be set true iff the vertex i is in the shortest path tree
    //or shortest distance from the src to i is finalized
    bool sptSet[V];

    //Initialize all distances to inf and the sptSet to false
    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }

    //Initialize the source node distance to 0;
    dist[source] = 0;

    minHeap.Insert(event);

    //Look for shortest path for all vertices
    while(!minheap.isEmpty())
    {
        //Get our source event
        Events currentevent = minHeap.Remove();
        int u = currentevent.id;
        double distanceU = currentevent.avgCostForOne;

        //Check if the node is visited
        if(distU > dist[u]) continue;

        for(int v = 0; v < V; v++)
        {
            int weight = matrix[u][v];
            if(weight != -1 && distU + weight < dist[v])
            {
                dist[v] = distanceU + weight;
                minHeap.Insert(Events(v, dist[v]));
            }
        }
    }

    return dist;
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);
    Events event1;
    event1.distance = 2;
    event1.id = 0;
    Events event2;
    event2.distance = 4;
    event2.id = 1;
    Events event3;
    event3.distance = 6;
    event3.id = 2;
    Events event4;
    event4.distance = 3;
    event4.id = 3;
    Events event5;
    event5.distance = 1;
    event5.id = 4;
    // Add edges to the graph
    graph.AddEdge(0, 2, event3);
    graph.AddEdge(0, 4, event5);
    graph.AddEdge(1, 3, event4);
    graph.AddEdge(1, 4, event5);

    // Run Dijkstra's algorithm from vertex 0
    int* distances = graph.dijkstra(0);

    // Output the shortest distances from vertex 0 to all other vertices
    for (int i = 0; i < 5; i++) {
        cout << "Distance from vertex 0 to " << i << " is " << distances[i] << endl;
    }

    delete[] distances;
    return 0;
}
