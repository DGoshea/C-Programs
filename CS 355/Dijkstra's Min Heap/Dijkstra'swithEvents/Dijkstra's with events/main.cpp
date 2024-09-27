//References GreeksForGeeks, C++.com, Zybooks
#include <iostream>
#include <limits>
#include "graph.h"
#include "pQueue.h"
using namespace std;

int main() {
    // Create a graph with 5 vertices
    int V = 5;
    Graph graph(V);

    //HardCode events to test
    Events event1(0,1);
    Events event2(1,2);
    Events event3(2,8);
    Events event4(3,9);
    Events event5(4,11);


    // Add edges to the graph
    graph.AddEdge(0, 2, event1);
    graph.AddEdge(0, 4, event2);
    graph.AddEdge(1, 3, event3);
    graph.AddEdge(2, 1, event4);
    graph.AddEdge(1, 4, event5);

    //Define a source vertex and parent array
    int source = 0;
    int* parent = new int[V];

    // Run Dijkstra's algorithm from event 1 (0)
    int* distances = graph.dijkstra(source, parent);

    //Print shortest path from event 1 to 5
    for(int i = 0; i < V; i++)
    {
        graph.printPath(parent, i, source);
    }

    //Free Memory
    delete[] distances;
    delete[] parent;
    return 0;
}
