#include <iostream>
#include <limits.h>
#include "graph.h"
#include "minimumheap.h"
using namespace std;

//Define The Vertices
const int V = 9;

//Utility Functions
void printSolution(int dist[]);
void dijkstra(int graph[V][V], int source);


int main()
{
    int graph[V][V] = {{0,4,0,0,0,0,0,8,0},
                       {4,0,8,0,0,0, 0, 11,0},
                       {0,8,0,7,0,4,0,0,2},
                       {0,0,7,0,9,14,0,0,0},
                       {0,0,0,9,0,10,0,0,0},
                       {0,0,4,14,10,0,2,0,0},
                       {0,0,0,0,0,2,0,1,6},
                       {8,11,0,0,0,0,1,0,7},
                       {0,0,2,0,0,0,6,7,0}
                       };
    dijkstra(graph, 0);
    cout << endl;
    minHeap heap1;
    heap1.Insert(10);
    heap1.Insert(5);
    heap1.Insert(6);
    heap1.Insert(13);
    heap1.Insert(1);
    cout << heap1.Remove();
    cout << heap1.Remove();
    cout << heap1.Remove();
    cout << heap1.Remove();
    cout << heap1.Remove();
    return 0;
}


/*Print Function this function will print out the distance array
    Incoming Data: the distance array
    Outgoing Data: NONE
*/
void printSolution(int dist[])
{
    cout << "Vertex Distance From Source: " << endl;
    for(int i = 0; i < V; i++)
    {
        cout << i << "\t\t\t\t" << dist[i] << endl;
    }
}

/*Function to implement the dijkstra's algo for a graph represented by an adjacency matrix
    Incoming Data: 2-D array for our graph and int for the source node
    Outgoing Data: None
*/
void dijkstra(int graph[V][V], int source)
{
    //Output array; dist[i] will hold the shortest distance form the source to dist[i]
    int dist[V];
    Events events[V];
    int path[V];
    int cost[V];
    int weight;

    //sptSet[i] will be set true iff the vertex i is in the shortest path tree
    //or shortest distance from the src to i is finalized
    bool sptSet[V];

    //Initialize all distances to inf and the sptSet to false
    for(int i =0; i < V; i++)
    {
        dist[i] = INT_MAX, sptSet[i] = false; heap1.Insert(node[i]);
    }

    //Set the source node's distance to 0
    dist[source] = 0;

    //Look for shortest path for all vertices
    while(heap1)
    {
        Vertex currentvertex = heap1.Remove();

        for()
        {
            weight = node[currentvertex]
            cost[i] = //current v->distance + weight

            //if shortest path is found update the adj vertex distance and predecessor
            if(cost[i] < adjv->distance)
            {
                node[i]->distance = path[v];
                node[i]->predV = currentvertex;
            }

        }
    }
    for(int count = 0; count < V-1; count++)
    {
        //Find the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        //Update vertex as true to represent it has been visited
        sptSet[u] = true;

        //Update the distance value of other adjacent vertices of the picked vetex
        for(int v = 0; v < V; v++)
        {
            //Only update dist[v] if it is not in sptSet, there is an edge u to v
            //and the weight of the path from the source to v is smaller than the
            //value of dist[v]

        if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist);
}

