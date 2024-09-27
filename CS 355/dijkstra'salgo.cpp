#include <iostream>
#include <queue>
#include <limits>

struct Events {
    int id;
    double avgCostForOne;
    Events(int _id, double _avgCostForOne) : id(_id), avgCostForOne(_avgCostForOne) {}
};

class Graph {
private:
    int V;
    int** matrix;

public:
    Graph(int vertices) : V(vertices) {
        // Initialize the adjacency matrix with -1 (no edge)
        matrix = new int*[V];
        for(int i = 0; i < V; i++) {
            matrix[i] = new int[V];
            for(int j = 0; j < V; j++) {
                matrix[i][j] = -1;
            }
        }
    }

    // Destructor to deallocate memory
    ~Graph() {
        for(int i = 0; i < V; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        matrix[u][v] = weight;
        matrix[v][u] = weight; // If the graph is undirected, add both edges
    }

    int* dijkstra(int source, int* parent) {
        // Output array; dist[i] will hold the shortest distance from the source event to the event at the index i in dist[i]
        int* dist = new int[V];

        // Initialize all distances to inf
        for(int i = 0; i < V; i++) {
            dist[i] = std::numeric_limits<int>::max();
        }

        // Initialize the source node distance to 0;
        dist[source] = 0;

        // Initialize the parent array to track shortest paths
        for(int i = 0; i < V; i++) {
            parent[i] = -1; // -1 represents no parent
        }

        // Initialize the priority queue
        std::priority_queue<Events, std::vector<Events>, std::greater<Events>> minHeap;
        minHeap.push(Events(source, 0));

        // Look for shortest path for all events
        while(!minHeap.empty()) {
            // Get the source event
            Events currentevent = minHeap.top();
            minHeap.pop();

            // Get the source event's index
            int u = currentevent.id;
            double distanceU = currentevent.avgCostForOne;

            // Check if the event is visited
            if(distanceU > dist[u]) continue;

            for(int v = 0; v < V; v++) {
                int weight = matrix[u][v];

                // Check for an edge with a shorter path
                if(weight != -1 && distanceU + weight < dist[v]) {
                    dist[v] = distanceU + weight;
                    parent[v] = u; // Update parent of vertex v
                    minHeap.push(Events(v, dist[v]));
                }
            }
        }

        return dist;
    }
};

// Function to print the shortest path from the source to a given vertex
void printShortestPath(int* parent, int vertex, int source) {
    if(parent[vertex] == -1) {
        std::cout << "No path exists from the source to vertex " << vertex << std::endl;
        return;
    }

    std::cout << "Shortest path from the source to vertex " << vertex << ": ";
    while(vertex != source) {
        std::cout << vertex;
        vertex = parent[vertex];
        if(vertex != source) std::cout << " -> ";
    }
    std::cout << source << std::endl;
}

int main() {
    int V = 5; // Number of vertices
    Graph g(V);

    // Add edges to the graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 1);

    int source = 0; // Source vertex

    int* parent = new int[V];
    int* dist = g.dijkstra(source, parent);

    // Print shortest paths from the source to all vertices
    for(int i = 0; i < V; i++) {
        printShortestPath(parent, i, source);
    }

    delete[] dist;
    delete[] parent;

    return 0;
}
