#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int numVertices;
    list<int> *adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList = new list<int>[numVertices];
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Adjacency list of vertex " << i << "\n head ";
            for (auto it = adjList[i].begin(); it != adjList[i].end(); ++it) {
                cout << *it << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.printGraph();

    return 0;
}