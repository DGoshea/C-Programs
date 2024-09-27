#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "pQueue.h"
#include "events.h"
class Graph
{
private:
    int V = 0;
    int matrix[5][5];
public:
    Graph(int x);
    void AddEdge(int source, int target, Events event);
    void printSol(int* dist);
    int* dijkstra(int source, int* parent);
    void printPath(int* parent, int event, int source);
};

#endif
