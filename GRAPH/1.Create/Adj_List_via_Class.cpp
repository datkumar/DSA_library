// Representation of UNDIRECTED GRAPH using vector

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    // Number of Vertices;
    int n;

    list<int> *l; //Dynamic Adj. List of vertex
    // Each elem. points to the Adj. List of that vertex

public:
    Graph(int n)
    {
        this->n = n;
        l = new list<int>[n];
    }

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printGraph()
    {
        cout << "\nAdjacency List representation of Graph:" << endl;
        for (int v = 0; v < n; v++)
        {
            cout << "Vertex " << v << " :  ";

            for (auto &x : l[v])
                cout << x << " -> ";

            cout << "-" << endl;
        }
    }
};

// Driver code
int main()
{
    //Create Graph of 5 vertices
    Graph G(5);

    G.addEdge(0, 1);
    G.addEdge(0, 4);
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(1, 4);
    G.addEdge(2, 3);
    G.addEdge(3, 4);

    G.printGraph();

    return 0;
}