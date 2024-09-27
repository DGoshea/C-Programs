#include "graph.h"
#include <iostream>
using namespace std;

/* Graph Constructor
    Incoming Data: and integer to represent the number of vertices in the graph
    Outgoing Data: none
    Author:
*/
Graph::Graph(int x)
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

/*Void function AddEdge to add and edge to the graph stored in a 2-D array
    Incoming data: two integers for the source node in the graph
    the target node in the graph and an event object
    Outgoing Data: none
    Author:
*/
void Graph::AddEdge(int source, int target, Events event)
{
    matrix[source][target] = event.avgCostForOne;
    matrix[target][source] = event.avgCostForOne;
}

/*Void function printSol simply prints out the array of distances from the
  source node to the node at the index of the dist[]
  Incoming Data: and int* array that points to the array of distances from the sourcenode
  Outgoing Data: none
  Author:
*/
void Graph::printSol(int* dist)
{
    for(int i = 0; i < V; i++)
    {
        cout << i << "\t" << dist[i];
    }
}

/* int* Function dijkstra uses an integer for the source node and a templated binary heap
   to run dijkstra's algorithm
   Incoming Data: integer for the source and a templated binary heap
   Outgoing Data: Returns a pointer to an array that stores the shortest distances from the source node
   to that node in the array at that index
   Author:
*/
int* Graph::dijkstra(int source, int* parent)
{
    //Output array; dist[i] will hold the shortest distance form the source event to the
    // event at the index i in dist[i]
    int* dist = new int[V];

    //Initialize all distances to inf
    for(int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }

    //Initialize the source node distance to 0;
    dist[source] = 0;

    //Initalize an array parent that will reconstruct the shortest paths
    for(int i = 0; i < V; i++)
    {
        parent[i] = -1; //Use -1 to represent the absence of a node's parent
    }

    //May need to initialize the pq here and to set source node cost to 0
    pQueue<Events> minHeap;
    minHeap.enQueue(Events(source, 0));

    //Look for shortest path for all events
    while(!minHeap.isEmpty())
    {
        //Get our source event
        Events currentevent = minHeap.deQueue();

        //Get our source events index
        int u = currentevent.id;
        double distanceU = currentevent.avgCostForOne;

        //Check if the event is visited
        if(distanceU > dist[u]) continue; //continue keyword skips to the next iteration of the loop
                                          //if the condition is true

        for(int v = 0; v < V; v++)
        {
            double weight = matrix[u][v];

            //Check for an edge with a shorter path if there is update it and enqueue next eyeball
            if(weight != -1 && distanceU + weight < dist[v])
            {
                dist[v] = distanceU + weight;
                parent[v] = u; //Update the parent of vertex v
                minHeap.enQueue(Events(v, dist[v]));
            }
        }
    }

    return dist;
}

/* Void function printPath uses a while loop to display the path from a passed source node
   to a desired target node. The loop first checks for a valid path between the two vertices.
   If this path exists the loop prints out the parent vertices backwards until the source is reached
   (I.E. the event node == to the source node)
   Incoming Data: an int * that points to the array containing the parent of each vertex
                  an int for the source vertex
                  and an int for the target vertex
   Outgoing data: none
    Author:
*/
void Graph::printPath(int* parent, int event, int source)
{
    if(parent[event] == -1)
    {
        cout << "No path from source to event " << event << endl;
        return;
    }

    cout << "Your shortest path from the event " << source << " to event " << event << " : ";
    while(event != source)
    {
        cout << event;
        event = parent[event];
        if(event != source)
        {
            cout << " --> ";
        }
    }
    cout << " --> " << source << endl;
}

