// Program to Print Adj.-List representation of Graph (DIRECTED Graph)
#include <iostream>
#include <list>
#include <map>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{
    map<int, list<int>> Adj; // key = vertex ; value = Adj.-List of that vertex

public:
    // Add an edge to graph
    void addEdge(int u, int v)
    {
        Adj[u].push_back(v); // Add v to u’s list.
    }

    void printGraph()
    {
        cout << "\nAdjacency List representation of Graph:" << endl;

        map<int, list<int>>::iterator v;
        for (v = Adj.begin(); v != Adj.end(); v++)
        {
            cout << "Vertex " << v->first << " :  ";

            for (auto &x : v->second)
                cout << x << " -> ";
            cout << "-" << endl;
        }
    }
};

// Driver program
int main()
{
    // Create a graph
    Graph g;

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.printGraph();

    return 0;
}