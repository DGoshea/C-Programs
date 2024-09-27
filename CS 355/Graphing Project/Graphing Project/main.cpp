#include <iostream>
#include <limits.h>
#include "pathtoVertex.h"
#include "minimumheap.h"
#include "graph.h"
using namespace std;

//Define The Vertices
const int V = 9;

//Utility Functions
int minDistance(int dist[], bool stArray[]);
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
                       {0,0,2,0,0,0,6,7,0} };
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

/* Helper Function to find the vertex with minimum distance value,
    from the vertices not yet included int the shortest path tree array
    Incoming Data: Int array for the distance and boolean array for the tree set
    Outgoing Data: Returns an int the minimum distance to the next node
*/
int minDistance(int dist[], bool stArray[])
{
    //Initiallize the min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++){
        if(stArray[v] == false && dist[v] <= min)
        {
            min = dist[v], min_index = v;
        }
    }
    return min_index;
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

    //sptSet[i] will be set true iff the vertex i is in the shortest path tree
    //or shortest distance from the src to i is finalized
    bool sptSet[V];

    //Initialize Minheap
    minHeap heap1;

    //Initialize Vertices class
    Vertex vertices[V];
    //Initialize all distances to inf and the sptSet to false
    for(int i =0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        vertices[i] = Vertex(i);
        heap1.Insert(vertces[i]);
    }

    //Set the source node's distance to 0
    dist[source] = 0;

    //Look for shortest path for all vertices
    for(int count = 0; count < V-1; count++) // change to while(heap1){}
    {
        //Find the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);//Change to varianble = heap1.remove()

        //Update vertex as true to represent it has been visited
        sptSet[u] = true;

        // Youtube Dijkstras Algo G-32 you got this


        //Instead we will use our matrix/whatever represents our graph as a conditional

        //Update the distance value of other adjacent vertices of the picked vetex
        for(int v = 0; v < V; v++)
        {
            //Only update dist[v] if it is not in sptSet, there is an edge u to v
            //and the weight of the path from the source to v is smaller than the
            //value of dist[v]

            ////Use the path to vertex class to update the predecessor pointer to the current vertex

            //Not really much to change dont over complicate

        if(!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
        }
    }
    printSolution(dist);
}
