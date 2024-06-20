#include <iostream>
#include <vector>

using namespace std;

class Tree {
    int numVertices;
    vector<vector<int>> adjList;

public:
    Tree(int vertices) {
        numVertices = vertices;
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    void printTree() {
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
    Tree t(5);
    t.addEdge(0, 1);
    t.addEdge(0, 2);
    t.addEdge(1, 3);
    t.addEdge(2, 4);

    t.printTree();

    return 0;
}