//References GreeksForGeeks, C++.com, Zybooks
#include <iostream>
#include <limits>
#include "graph.h"
#include "pQueue.h"
using namespace std;

int main() {
    // Create a graph with 11 vertices (Events) for each city
    int V = 3;
    Graph miamigraph(V);
    Graph losangelesgraph(V);
    Graph atlantagraph(V);
    Graph newyorkgraph(V);

    //Define a source vertex and parent array
    int source = 0;
    int* parent = new int[V];

    //Cout << "What city and event would you like to start from?" << endl;
    //cin >> string choice;
    //cin >> source
    //if (choice == "city") citygraph.dijkstra(source, parent);

//************************************************************************************************

    //Miami
    Events miami, miamisports;
    miami.eventFile("miami.txt");
    miamisports.sportFile("miamiSports.txt");

   cout <<  miami.eventQueue.peek().name << endl;
   cout << miamisports.sportQueue.peek().name << endl;

    // Add edges to the miami graph
   /* miamigraph.AddEdge(0, 0, miamisports.sportQueue.deQueue());
    miamigraph.AddEdge(0, 1, miamisports.sportQueue.deQueue());
    miamigraph.AddEdge(1, 2, miamisports.sportQueue.deQueue());
    miamigraph.AddEdge(2, 3, miami.eventQueue.deQueue());
    miamigraph.AddEdge(3, 4, miami.eventQueue.deQueue());
    miamigraph.AddEdge(3, 5, miami.eventQueue.deQueue());
    miamigraph.AddEdge(4, 6, miami.eventQueue.deQueue());
    miamigraph.AddEdge(3, 7, miami.eventQueue.deQueue());
    miamigraph.AddEdge(6, 8, miami.eventQueue.deQueue());
    miamigraph.AddEdge(8, 9, miami.eventQueue.deQueue());
    miamigraph.AddEdge(2, 10, miami.eventQueue.deQueue();

    //Get the distances array
     int* distances = miamigraph.dijkstra(source, parent);

    //Print shortest path from event 1 to 11 for miami graph
    for(int i = 0; i < V; i++)
    {
        miamigraph.printPath(distances, i, source);
    }

    */

//************************************************************************************************
    //Los Angeles
    Events losangeles, losangelessports;
    losangeles.eventFile("losangeles.txt");
    losangelessports.sportFile("losangelessports.txt");

    cout << losangeles.eventQueue.peek().name << endl;
    cout << losangelessports.sportQueue.peek().name << endl;
/*
    //Add edges to the losangeles graph
    losangelesgraph.AddEdge(0, 1, losangeles.eventQueue.deQueue());
    losangelesgraph.AddEdge(4, 2, losangeles.eventQueue.deQueue());
    losangelesgraph.AddEdge(3, 3, losangeles.eventQueue.deQueue());
    losangelesgraph.AddEdge(1, 4, losangeles.eventQueue.deQueue());
    losangelesgraph.AddEdge(6, 5, losangeles.eventQueue.deQueue());
    losangelesgraph.AddEdge(8, 6, losangeles.eventQueue.deQueue());
    losangelesgraph.AddEdge(4, 7, losangeles.eventQueue.deQueue());
    losangelesgraph.AddEdge(2, 8, losangeles.eventQueue.deQueue());
    losangelesgraph.AddEdge(2, 9, losangelessports.eventQueue.deQueue());
    losangelesgraph.AddEdge(9, 10, losangelessports.eventQueue.deQueue());
    losangelesgraph.AddEdge(1, 11, losangelessports.eventQueue.deQueue());

    distances = losangelesgraph.dijkstra(source, parent);

    //Print shortest path from event 1 to 11 for miami graph
    for(int i = 0; i < V; i++)
    {
        miamigraph.printPath(distances, i, source);
    }

    */


//************************************************************************************************
    //New York City
    Events NewYorkCity, NewYorkCitysports;
    NewYorkCity.eventFile("NewYorkCity.txt");
    NewYorkCitysports.sportFile("NewYorkCitySports.txt");

    cout << NewYorkCity.eventQueue.peek().name << endl;
    cout << NewYorkCitysports.sportQueue.peek().name << endl;

  /*  //Add Edges to lA graph
    newyorkgraph.AddEdge(0, 1, NewYorkCity.eventQueue.deQueue());
    newyorkgraph.AddEdge(0, 2, NewYorkCity.eventQueue.deQueue());
    newyorkgraph.AddEdge(1, 3, NewYorkCity.eventQueue.deQueue());
    newyorkgraph.AddEdge(1, 4, NewYorkCity.eventQueue.deQueue());
    newyorkgraph.AddEdge(2, 5, NewYorkCity.eventQueue.deQueue());
    newyorkgraph.AddEdge(2, 6, NewYorkCity.eventQueue.deQueue());
    newyorkgraph.AddEdge(4, 7, NewYorkCity.eventQueue.deQueue());
    newyorkgraph.AddEdge(6, 8, NewYorkCity.eventQueue.deQueue());
    newyorkgraph.AddEdge(1, 9, NewYorkCitysports.sportQueue.deQueue());
    newyorkgraph.AddEdge(7, 10, NewYorkCitysports.sportQueue.deQueue());
    newyorkgraph.AddEdge(8, 11, NewYorkCitysports.sportQueue.deQueue());

    distances = newyorkgraph.dijkstra(source, parent);

    //Print shortest path from event 1 to 11 for newyork graph
    for(int i = 0; i < V; i++)
    {
        newyorkgraph.printPath(distances, i, source);
    }

*/

//************************************************************************************************
    //Atlanta
    Events atlanta, atlantasports;
    atlanta.eventFile("atlanta.txt");
    atlantasports.sportFile("atlantasports.txt");

    cout << atlanta.eventQueue.deQueue().name << endl;
    cout << atlantasports.sportQueue.deQueue().name << endl;
/*
    //Add edges to atlanta graph
    atlantagraph.AddEdge(0, 1, atlanta.eventQueue.deQueue());
    atlantagraph.AddEdge(0, 2, atlanta.eventQueue.deQueue());
    atlantagraph.AddEdge(0, 3, atlanta.eventQueue.deQueue());
    atlantagraph.AddEdge(0, 4, atlanta.eventQueue.deQueue());
    atlantagraph.AddEdge(0, 5, atlanta.eventQueue.deQueue());
    atlantagraph.AddEdge(0, 6, atlanta.eventQueue.deQueue());
    atlantagraph.AddEdge(0, 7, atlanta.eventQueue.deQueue());
    atlantagraph.AddEdge(0, 8, atlanta.eventQueue.deQueue());
    atlantagraph.AddEdge(2, 9, atlantasports.sportQueue.deQueue());
    atlantagraph.AddEdge(2, 10, atlantasports.sportQueue.deQueue());
    atlantagraph.AddEdge(2, 11, atlantasports.sportQueue.deQueue());

    distances = atlantagraph.dijkstra(source, parent);

    //Print shortest path from event 1 to 11 for newyork graph
    for(int i = 0; i < V; i++)
    {
        atlantagraph.printPath(distances, i, source);
    }
    */


    //Free Memory
    delete[] parent;
    //delete[] distances;
    return 0;
}

