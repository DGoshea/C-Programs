#include <iostream>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a weighted edge
struct Edge {
    int target;
    int weight;
    Edge(int target, int weight) : target(target), weight(weight) {}
};

// Structure to represent a node in the graph
struct Node {
    int id;
    int distance;
    Node(int id, int distance) : id(id), distance(distance) {}
};

// Custom comparator for the priority queue
struct NodeComparator {
    bool operator()(const Node& a, const Node& b) const {
        return a.distance > b.distance;
    }
};

class Graph {
private:
    int** adjacencyMatrix;
    int numVertices;

public:
    Graph(int n) : numVertices(n) {
        adjacencyMatrix = new int*[n];
        for (int i = 0; i < n; ++i) {
            adjacencyMatrix[i] = new int[n];
            for (int j = 0; j < n; ++j) {
                adjacencyMatrix[i][j] = -1; // -1 represents absence of edge
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < numVertices; ++i) {
            delete[] adjacencyMatrix[i];
        }
        delete[] adjacencyMatrix;
    }

    // Add an edge to the graph
    void addEdge(int source, int target, int weight) {
        adjacencyMatrix[source][target] = weight;
    }

    // Dijkstra's algorithm
    int* dijkstra(int source) {
        int* distances = new int[numVertices];
        for (int i = 0; i < numVertices; ++i) {
            distances[i] = numeric_limits<int>::max();
        }
        distances[source] = 0;

        priority_queue<Node, vector<Node>, NodeComparator> minHeap;
        minHeap.push(Node(source, 0));

        while (!minHeap.empty()) {
            Node currentNode = minHeap.top();
            minHeap.pop();

            int u = currentNode.id;
            int distU = currentNode.distance;

            // Check if this node has already been processed
            if (distU > distances[u]) continue;

            for (int v = 0; v < numVertices; ++v) {
                int weightUV = adjacencyMatrix[u][v];
                if (weightUV != -1 && distU + weightUV < distances[v]) {
                    distances[v] = distU + weightUV;
                    minHeap.push(Node(v, distances[v]));
                }
            }
        }

        return distances;
    }
};

int main() {
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges to the graph
    graph.addEdge(0, 1, 4);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 1, 2);
    graph.addEdge(2, 3, 5);
    graph.addEdge(3, 4, 3);

    // Run Dijkstra's algorithm from vertex 0
    int* distances = graph.dijkstra(0);

    // Output the shortest distances from vertex 0 to all other vertices
    for (int i = 0; i < 5; ++i) {
        cout << "Distance from vertex 1 to " << i << " is " << distances[i] << endl;
    }

    delete[] distances;
    return 0;
}
